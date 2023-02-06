#include <iostream>
#include "PacketReader.h"
#include "vector"
#include "PacketAnalyzer.h"
#include "PacketWriter.h"
#include "fstream"

using namespace std;

void resetOutFile(string filename) {
    try {
        ofstream file(filename);
        file.close();
    } catch (exception e) {
        cout << "File Not Found" << endl;
    }
}

int main() {
    resetOutFile("output_packets");
    PacketReader packetReader("input_packets");
    vector<string> packets = packetReader.getPackets();
    PacketAnalyzer packetAnalyzer(packets);
    return 0;
}
