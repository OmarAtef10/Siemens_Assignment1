//
// Created by Omar on 2/6/2023.
//

#include "PacketWriter.h"
#include "fstream"

int PacketWriter::packetCounter = 0;

void PacketWriter::writeECIPRIFrame(string filename, ECPRIFrame frame, string packet) {
    try {
        ofstream file(filename, ios::app);
        file << "Packet Number: " << packetCounter << "\n";
        file << packet << "\n";
        file << "CRC: " << frame.getFcs() << "\n";
        file << "Revision-Reserved-C: " << frame.getRevisionReservedC() << "\n";
        file << "Destination Address: " << frame.getDestinationAddress() << "\n";
        file << "Message Type: " << frame.getMessageType() << "\n";
        file << "Payload Size: " << frame.getPayloadSize() << "\n";
        file << "RTC ID: " << frame.getRtcId() << "\n";
        file << "Sequence ID: " << frame.getSeqId() << "\n";
        file << "Source Address: " << frame.getSourceAddress() << "\n";
        file << "TYPE: " << frame.getType() << "\n";
        file << "***********************************" << "\n";
        packetCounter++;

        file.close();
    }
    catch (exception e) {
        cout << "File not found" << endl;
    }


}

void PacketWriter::writeEthernetFrame(string filename, EthernetFrame frame, string packet) {
    try {
        ofstream file(filename, ios::app);
        file << "Packet Number: " << packetCounter << "\n";
        file << packet << "\n";
        file << "CRC: " << frame.getFcs() << "\n";
        file << "Destination Address: " << frame.getDestinationAddress() << "\n";
        file << "Source Address: " << frame.getSourceAddress() << "\n";
        file << "TYPE: " << frame.getType() << "\n";
        file << "***********************************" << "\n";
        packetCounter++;
        file.close();


    }
    catch (exception e) {
        cout << "File not found" << endl;
    }


}
