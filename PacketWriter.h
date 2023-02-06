//
// Created by Omar on 2/6/2023.
//

#ifndef ASSIGNMENT1_PACKETWRITER_H
#define ASSIGNMENT1_PACKETWRITER_H

#include "ECPRIFrame.h"
#include "EthernetFrame.h"

class PacketWriter {
    static int packetCounter;
public:
    static void writeECIPRIFrame(string filename, ECPRIFrame frame, string packet);

    static void writeEthernetFrame(string filename, EthernetFrame frame, string packet);


};


#endif //ASSIGNMENT1_PACKETWRITER_H
