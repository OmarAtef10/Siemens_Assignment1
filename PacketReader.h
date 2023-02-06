//
// Created by Omar on 2/6/2023.
//

#ifndef ASSIGNMENT1_PACKETREADER_H
#define ASSIGNMENT1_PACKETREADER_H

#include "iostream"
#include "vector"

using namespace std;

class PacketReader {
private:
    string file_name;
    vector<string> packets;
public:
    PacketReader(string file_name);

    void read_packets();

    void print_packets();

    const vector<string> &getPackets() const;
};


#endif //ASSIGNMENT1_PACKETREADER_H
