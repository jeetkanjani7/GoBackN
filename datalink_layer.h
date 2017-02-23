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

#ifndef __GOBACKN_DATALINK_LAYER_H_
#define __GOBACKN_DATALINK_LAYER_H_

#include <omnetpp.h>
#include<vector>
#include<queue>
#include<string>
#include<d_pdu_m.h>
#include<a_pdu_m.h>
#include<p_pdu_m.h>
using namespace std;
using namespace omnetpp;


class Datalink_layer : public cSimpleModule
{
  private:
    std::vector<D_pdu *> dl_window;
    int window_size;
    queue<cMessage *> app_buf;
    queue<cMessage *> phy_buf;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    int id;
    int window_fill;
    int window_sent;
    int start;
    int end;
    int rec_expected;
    int send_expected;
    int send_count;
    cGate *aout;
    cGate *ain;
    cGate *pout;
    cGate *pin;
    cMessage *sender_delay;
    cMessage *rec_delay;
};

#endif
