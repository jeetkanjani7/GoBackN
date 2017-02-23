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

network TwoNodes
{
    submodules:
		n1:Super_node{
			super_id=1;
			a_l.nid=11;
			d_l.nid=12;
			p_l.nid=13;
		}
		n2:Super_node{
			super_id=2;
			a_l.nid=21;
			d_l.nid=22;
			p_l.nid=23;
		}
	connections:
		n1.in <-- { delay=100ms; } <-- n2.out;
		n1.out -->{ delay=100ms; }--> n2.in;	
}
