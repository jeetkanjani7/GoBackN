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

#include "physical_layer.h"

Define_Module(Physical_layer);

void Physical_layer::initialize()
{
    id = par("nid");
    dout = gate("dout");
    din = gate("din");
    nout = gate("nout");
    nin = gate("nin");

}

void Physical_layer::handleMessage(cMessage *msg)
{
    if(msg->getArrivalGate()==din)
    {
        D_pdu *d = check_and_cast<D_pdu*> (msg);
        P_pdu *p = new P_pdu();

        p->encapsulate(d);

        if(p->getId()==0)
        {
            if (uniform(0, 1) < 0.15)
            {
                EV << "\"Losing send\" message\n";
                delete p;
            }
            else
            {
                send(p,nout);
            }
        }
        else
        {
            send(p,nout);
        }

    }
    else if(msg->getArrivalGate()==nin)
    {
        P_pdu *p = check_and_cast<P_pdu*> (msg);
        D_pdu *d = new D_pdu();

        d = check_and_cast<D_pdu*> (p->decapsulate());

        if (uniform(0, 1) < 0.15)
        {
            EV << "\"Losing rec\" message\n";
            delete d;
        }
        else
        {
            send(d,dout);
        }


    }
}
