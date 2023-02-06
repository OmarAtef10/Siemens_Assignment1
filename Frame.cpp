//
// Created by Omar on 2/6/2023.
//

#include "Frame.h"

const string &Frame::getPreamble() const {
    return preamble;
}

void Frame::setPreamble(const string &preamble) {
    Frame::preamble = preamble;
}

const string &Frame::getDestinationAddress() const {
    return destinationAddress;
}

void Frame::setDestinationAddress(const string &destinationAddress) {
    Frame::destinationAddress = destinationAddress;
}

const string &Frame::getSourceAddress() const {
    return sourceAddress;
}

void Frame::setSourceAddress(const string &sourceAddress) {
    Frame::sourceAddress = sourceAddress;
}

const string &Frame::getType() const {
    return type;
}

void Frame::setType(const string &type) {
    Frame::type = type;
}

const string &Frame::getFcs() const {
    return fcs;
}

void Frame::setFcs(const string &fcs) {
    Frame::fcs = fcs;
}

const int Frame::getFCSLength() {
    return FCS_LENGTH;
}

const int Frame::getTypeLength() {
    return TYPE_LENGTH;
}

const int Frame::getDestinationAddressLength() {
    return DESTINATION_ADDRESS_LENGTH;
}

const int Frame::getSourceAddressLength() {
    return SOURCE_ADDRESS_LENGTH;
}

const int Frame::getPreambleLength() {
    return PREAMBLE_LENGTH;
}

const string &Frame::getPayload() const {
    return payload;
}

void Frame::setPayload(const string &payload) {
    Frame::payload = payload;
}

const string &Frame::getPacket() const {
    return packet;
}

void Frame::setPacket(const string &packet) {
    Frame::packet = packet;
}

