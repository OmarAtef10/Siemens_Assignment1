//
// Created by Omar on 2/6/2023.
//

#ifndef ASSIGNMENT1_PACKETANALYZER_H
#define ASSIGNMENT1_PACKETANALYZER_H

#include "iostream"
#include "vector"
#include "Frame.h"
#include "EthernetFrame.h"
#include "ECPRIFrame.h"

class PacketAnalyzer {
private:
    vector<Frame> frames;
public:
    int HEX_BYTE_SIZE = 2;

    PacketAnalyzer(vector<string> packets);

    Frame *analyze_packets(string packet);

    string getType(string packet, int &index, int length);

    string getPreamble(string packet, int &index, int length);

    string getDestinationAddress(string packet, int &index, int length);

    string getSourceAddress(string packet, int &index, int length);

    string getFCS(string packet, int &index, int length);

    string getPayload(string packet, int &index, int length);

    void analyzeECIPRI(ECPRIFrame &frame, string payloadData);

    const vector<Frame> &getFrames() const;

    void setFrames(const vector<Frame> &frames);
};


#endif //ASSIGNMENT1_PACKETANALYZER_H
