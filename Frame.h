//
// Created by Omar on 2/6/2023.
//

#ifndef ASSIGNMENT1_FRAME_H
#define ASSIGNMENT1_FRAME_H

#include "iostream"

using namespace std;


enum FrameType {
    ECPRI,
    RAW,
};

class Frame {
private:
    static const int PREAMBLE_LENGTH = 8;
    static const int DESTINATION_ADDRESS_LENGTH = 6;
    static const int SOURCE_ADDRESS_LENGTH = 6;
    static const int TYPE_LENGTH = 2;
    static const int FCS_LENGTH = 4;


    string preamble;
    string destinationAddress;
    string sourceAddress;
    string type;
    string payload;
    string fcs;
    string packet;

public:
    static const int getFCSLength();

    static const int getTypeLength();

    static const int getDestinationAddressLength();

    static const int getSourceAddressLength();

    static const int getPreambleLength();

    const string &getPacket() const;

    void setPacket(const string &packet);

    const string &getPreamble() const;

    void setPreamble(const string &preamble);

    const string &getDestinationAddress() const;

    void setDestinationAddress(const string &destinationAddress);

    const string &getSourceAddress() const;

    void setSourceAddress(const string &sourceAddress);

    const string &getType() const;

    void setType(const string &type);

    const string &getPayload() const;

    void setPayload(const string &payload);

    const string &getFcs() const;

   virtual void setFcs(const string &fcs);

};


#endif //ASSIGNMENT1_FRAME_H
