//
// Created by Omar on 2/6/2023.
//

#include "PacketAnalyzer.h"
#include "FrameFactory.h"
#include "PacketWriter.h"

PacketAnalyzer::PacketAnalyzer(vector<string> packets) {
    for (string packet : packets) {
        Frame *frame = this->analyze_packets(packet);
        this->frames.push_back(*frame);
    }
}

Frame *PacketAnalyzer::analyze_packets(string packet) {
    Frame *frame = nullptr;
    int index = 0;
    string preamble = this->getPreamble(packet, index, frame->getPreambleLength());
    string destinationAddress = this->getDestinationAddress(packet, index, frame->getDestinationAddressLength());
    string sourceAddress = this->getSourceAddress(packet, index, frame->getSourceAddressLength());
    string type = this->getType(packet, index, frame->getTypeLength());
    int dataLength = (packet.length() - (HEX_BYTE_SIZE * frame->getFCSLength() + index));
    string payload = this->getPayload(packet, index, dataLength);
    string fcs = this->getFCS(packet, index, frame->getFCSLength());

    frame = FrameFactory::createFrameObject(type);
    frame->setPreamble(preamble);
    frame->setDestinationAddress(destinationAddress);
    frame->setSourceAddress(sourceAddress);
    frame->setType(type);
    frame->setPayload(payload);
    frame->setFcs(fcs);
    frame->setPacket(packet);
    if (type == "AEFE") {
        analyzeECIPRI(*dynamic_cast<ECPRIFrame *>(frame), payload);
        PacketWriter::writeECIPRIFrame("output_packets", *dynamic_cast<ECPRIFrame *>(frame), packet);
    } else {
        PacketWriter::writeEthernetFrame("output_packets", *dynamic_cast<EthernetFrame *>(frame), packet);
    }
    return frame;
}


string PacketAnalyzer::getPreamble(string packet, int &index, int length) {
    string preamble = packet.substr(index, HEX_BYTE_SIZE * length);
    index += HEX_BYTE_SIZE * length;
    return preamble;
}

string PacketAnalyzer::getDestinationAddress(string packet, int &index, int length) {
    string destinationAddress = packet.substr(index, HEX_BYTE_SIZE * length);
    index += HEX_BYTE_SIZE * length;
    return destinationAddress;
}

string PacketAnalyzer::getSourceAddress(string packet, int &index, int length) {
    string sourceAddress = packet.substr(index, HEX_BYTE_SIZE * length);
    index += HEX_BYTE_SIZE * length;
    return sourceAddress;
}

string PacketAnalyzer::getType(string packet, int &index, int length) {
    string type = packet.substr(index, HEX_BYTE_SIZE * length);
    index += HEX_BYTE_SIZE * length;
    return type;
}

string PacketAnalyzer::getFCS(string packet, int &index, int length) {
    string fcs = packet.substr(index, HEX_BYTE_SIZE * length);
    index += HEX_BYTE_SIZE * length;
    return fcs;
}

string PacketAnalyzer::getPayload(string packet, int &index, int length) {
    string payload = packet.substr(index, length);
    index += payload.size();
    return payload;
}

const vector<Frame> &PacketAnalyzer::getFrames() const {
    return frames;
}

void PacketAnalyzer::setFrames(const vector<Frame> &frames) {
    PacketAnalyzer::frames = frames;
}

void PacketAnalyzer::analyzeECIPRI(ECPRIFrame &frame, string payloadData) {
    int index = 0;
    string revisionReservedC = payloadData.substr(index, (HEX_BYTE_SIZE * ECPRIFrame::getRevisionReservedCLength()));
    index += (HEX_BYTE_SIZE * ECPRIFrame::getRevisionReservedCLength());
    frame.setRevisionReservedC(revisionReservedC);

    string messageType = payloadData.substr(index, (HEX_BYTE_SIZE * ECPRIFrame::getMessageTypeLength()));
    index += (HEX_BYTE_SIZE * ECPRIFrame::getMessageTypeLength());
    frame.setMessageType(messageType);

    string payloadSize = payloadData.substr(index, (HEX_BYTE_SIZE * ECPRIFrame::getPayloadSizeLength()));
    index += (HEX_BYTE_SIZE * ECPRIFrame::getPayloadSizeLength());
    frame.setPayloadSize(payloadSize);

    string rtcId = payloadData.substr(index, (HEX_BYTE_SIZE * ECPRIFrame::getRtcIdLength()));
    index += (HEX_BYTE_SIZE * ECPRIFrame::getRtcIdLength());
    frame.setRtcId(rtcId);

    string seqId = payloadData.substr(index, (HEX_BYTE_SIZE * ECPRIFrame::getSeqIdLength()));
    index += (HEX_BYTE_SIZE * ECPRIFrame::getSeqIdLength());
    frame.setSeqId(seqId);
}


