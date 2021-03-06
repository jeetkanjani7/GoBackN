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

#ifndef __GOBACKN_APP_LAYER_H_
#define __GOBACKN_APP_LAYER_H_

#include<d_pdu_m.h>
#include<a_pdu_m.h>
#include <vector>
#include <queue>
#include <string>
#include <omnetpp.h>

using namespace omnetpp;
using namespace std;

class App_layer : public cSimpleModule
{
  private:
    queue<char> app_buffer;

    int id;
    cGate *din;
    cGate *dout;
    cMessage *self_message=new cMessage();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

  public:
    int letter_count;
};

#endif
