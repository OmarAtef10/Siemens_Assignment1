//
// Created by Omar on 2/6/2023.
//

#include "PacketReader.h"
#include "iostream"
#include "fstream"

PacketReader::PacketReader(string file_name) {
    this->file_name = file_name;
    read_packets();
}

void PacketReader::read_packets() {
    try {
        ifstream ReadFile(file_name);
        string line;
        //read first line and add to vector
        while (getline(ReadFile, line)) {
            this->packets.push_back(line);
        }

    } catch (exception e) {
        cout << "File not found" << endl;
    }
}

void PacketReader::print_packets() {
    for (const string &packet : packets) {
        cout << packet << endl;
    }
    cout << packets.size();

}

const vector<string> &PacketReader::getPackets() const {
    return packets;
}
