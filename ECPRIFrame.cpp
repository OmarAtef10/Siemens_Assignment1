//
// Created by Omar on 2/6/2023.
//

#include "ECPRIFrame.h"

const string &ECPRIFrame::getRevisionReservedC() const {
    return revisionReservedC;
}

void ECPRIFrame::setRevisionReservedC(const string &revisionReservedC) {
    ECPRIFrame::revisionReservedC = revisionReservedC;
}

const string &ECPRIFrame::getMessageType() const {
    return messageType;
}

void ECPRIFrame::setMessageType(const string &messageType) {
    ECPRIFrame::messageType = messageType;
}

const string &ECPRIFrame::getPayloadSize() const {
    return payloadSize;
}

void ECPRIFrame::setPayloadSize(const string &payloadSize) {
    ECPRIFrame::payloadSize = payloadSize;
}

const string &ECPRIFrame::getRtcId() const {
    return rtcId;
}

void ECPRIFrame::setRtcId(const string &rtcId) {
    ECPRIFrame::rtcId = rtcId;
}

const string &ECPRIFrame::getSeqId() const {
    return seqId;
}

void ECPRIFrame::setSeqId(const string &seqId) {
    ECPRIFrame::seqId = seqId;
}

const int ECPRIFrame::getRevisionReservedCLength() {
    return REVISION_RESERVED_C_LENGTH;
}

const int ECPRIFrame::getMessageTypeLength() {
    return MESSAGE_TYPE_LENGTH;
}

const int ECPRIFrame::getPayloadSizeLength() {
    return PAYLOAD_SIZE_LENGTH;
}

const int ECPRIFrame::getRtcIdLength() {
    return RTC_ID_LENGTH;
}

const int ECPRIFrame::getSeqIdLength() {
    return SEQ_ID_LENGTH;
}

ECPRIFrame::ECPRIFrame() = default;
