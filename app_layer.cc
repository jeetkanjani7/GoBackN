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

#include "app_layer.h"

Define_Module(App_layer);

void App_layer::initialize()
{


    id = par("nid");
    din = gate("din");
    dout = gate("dout");



    if(id == 11)
    {

        for(char i='a';i<='z';i++)
            app_buffer.push(i);


        scheduleAt(0,self_message);
    }
}

void App_layer::handleMessage(cMessage *msg)
{


    if(msg==self_message)
    {

        A_pdu *a=new A_pdu();
        a->setAlphabet(char(app_buffer.front()));
        a->setType(0);
        a->setMsg("new_Letter");
        a->setId(0);
        EV << "Letter sent " << app_buffer.front();
        app_buffer.pop();
        send(a,dout);
        letter_count++;
    }

    if(msg->getArrivalGate()==din)
    {
      //  D_pdu *ap=check_and_cast<D_pdu*>(msg);
        //bubble(ap->getMsg());
        //A_pdu *ass=new A_pdu();
       // ass=check_and_cast<A_pdu*>(ap->decapsulate());


            if(letter_count>=26)
            {
                bubble("STOP");
                A_pdu *st=new A_pdu();
                st->setType(0);
                st->setMsg("STOP");
                send(st,dout);
            }
            bubble("request_letter");
            A_pdu *a=new A_pdu();
            a->setType(0);
            a->setMsg("new_letter");
            a->setAlphabet(char(app_buffer.front()));
            a->setId(letter_count);
            send(a,dout);
            letter_count++;
            EV<<"Request received for letter"<<letter_count<<", sent succesfully";




    }
}
