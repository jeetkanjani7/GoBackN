//
// Generated file, do not edit! Created by nedtool 5.0 from a_pdu.msg.
//

#ifndef __A_PDU_M_H
#define __A_PDU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>a_pdu.msg:15</tt> by nedtool.
 * <pre>
 * //
 * // This program is free software: you can redistribute it and/or modify
 * // it under the terms of the GNU Lesser General Public License as published by
 * // the Free Software Foundation, either version 3 of the License, or
 * // (at your option) any later version.
 * // 
 * // This program is distributed in the hope that it will be useful,
 * // but WITHOUT ANY WARRANTY; without even the implied warranty of
 * // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * // GNU Lesser General Public License for more details.
 * // 
 * // You should have received a copy of the GNU Lesser General Public License
 * // along with this program.  If not, see http://www.gnu.org/licenses/.
 * //
 * packet A_pdu
 * {
 *     int id;
 *     int type;		//0-->data and 1-->ack
 *     char alphabet;
 *     string msg;
 * }
 * </pre>
 */
class A_pdu : public ::omnetpp::cPacket
{
  protected:
    int id;
    int type;
    char alphabet;
    ::omnetpp::opp_string msg;

  private:
    void copy(const A_pdu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const A_pdu&);

  public:
    A_pdu(const char *name=nullptr, int kind=0);
    A_pdu(const A_pdu& other);
    virtual ~A_pdu();
    A_pdu& operator=(const A_pdu& other);
    virtual A_pdu *dup() const {return new A_pdu(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
    virtual int getType() const;
    virtual void setType(int type);
    virtual char getAlphabet() const;
    virtual void setAlphabet(char alphabet);
    virtual const char * getMsg() const;
    virtual void setMsg(const char * msg);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const A_pdu& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, A_pdu& obj) {obj.parsimUnpack(b);}


#endif // ifndef __A_PDU_M_H

