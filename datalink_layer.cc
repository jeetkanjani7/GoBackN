//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "datalink_layer.h"

Define_Module(Datalink_layer);

void Datalink_layer::initialize()
{
    id=par("nid");
    pin=gate("pin");
    ain=gate("ain");
    aout=gate("aout");
    pout=gate("pout");
    window_size=5;
    window_fill=0;
    window_sent=0;
    start=0;
    end=start+window_size;
    rec_expected=0;
    send_expected=0;
    send_count=0;
}

void Datalink_layer::handleMessage(cMessage *msg)
{

    if(msg==sender_delay)
    {

        A_pdu *a=check_and_cast<A_pdu*>(app_buf.back());
        app_buf.pop();
        D_pdu *d= new D_pdu();
        d->setId(send_count%window_size);

        d->setAlphabet(a->getAlphabet());
        d->setType(0);
        d->setMsg(a->getMsg());
        d->encapsulate(a);
        dl_window.push_back(d);
        window_fill++;
        send(d,pout);
        window_sent++;
        send_count++;
        if(window_fill<window_size+start)
        {
            D_pdu *req= new D_pdu();
            req->setId(0);
            req->setType(0);
            req->setAlphabet('a');
            req->setMsg("request_letter");
            send(req,aout);
        }
        else
        {
            bubble("Window_full");
        }

    }
    else if(msg->getArrivalGate()==ain)
    {
        A_pdu *a=check_and_cast<A_pdu*>(msg);

        if(strcmp(a->getMsg(),"new_message"))
        {
            app_buf.push(msg);


            if (uniform(0, 1) < 0.3)
            {
                sender_delay=new cMessage();
                scheduleAt(simTime()+2,sender_delay);
                bubble("processing delay1 (30%)");
            }
            else
            {
                sender_delay=new cMessage("proc_delay");
                scheduleAt(simTime()+1,sender_delay);
                bubble("processing delay1 (70%)");

            }

        }

    }
    else if(msg->getArrivalGate()==pin)
    {
        D_pdu *p=check_and_cast<D_pdu*>(msg);
        if(p->getType()==0)
        {
            if(p->getId()==rec_expected%window_size)
            {
                D_pdu *d= new D_pdu();
                d->setId(p->getId());
                d->setAlphabet(p->getAlphabet());
                d->setType(0);
                d->setMsg("Data_received");
            //    send(d,aout);

                D_pdu *ack= new D_pdu();
                ack->setId(p->getId()+1);
                ack->setType(1);
                ack->setMsg("Positive_ack");
                send(ack,pout);
                rec_expected++;
            }
            else
            {
                bubble("Discard");
                D_pdu *gbn= new D_pdu();
                gbn->setId(1);
                gbn->setType(1);
                gbn->setMsg("go_back_n");
                send(gbn,pout);
            }
        }

        if(p->getType()==1)
        {
            if(p->getId()==start+1)
            {
                start++;
                end++;
            }
            else
            {
                //go back n
                bubble("GO BACK N");
                window_sent=start;
                for(int j=start;j<window_fill;j++)
                {
                    D_pdu *d_new= new D_pdu();
                    d_new=dl_window[j];
                    send(d_new,pout);
                }
            }




        }
    }








}


