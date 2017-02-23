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

package gobackn;

module Super_node
{
    parameters:
    	int super_id;
    
     gates:
        input in;
        output out;    
            
   	submodules:
       	a_l:App_layer;
        d_l:Datalink_layer;
        p_l:Physical_layer;
    connections:
       	a_l.din <-- d_l.aout;
		a_l.dout --> d_l.ain;
		p_l.din <-- d_l.pout;
		p_l.dout --> d_l.pin;
		p_l.nin <-- in;
		p_l.nout --> out;
         
         
}
