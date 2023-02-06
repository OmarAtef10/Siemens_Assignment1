//
// Created by Omar on 2/6/2023.
//

#ifndef ASSIGNMENT1_ECPRIFRAME_H
#define ASSIGNMENT1_ECPRIFRAME_H

#include "Frame.h"

class ECPRIFrame : public Frame {
private:

    static const int REVISION_RESERVED_C_LENGTH = 1;
    static const int MESSAGE_TYPE_LENGTH = 1;
    static const int PAYLOAD_SIZE_LENGTH = 2;
    static const int RTC_ID_LENGTH = 2;
    static const int SEQ_ID_LENGTH = 2;

    string revisionReservedC;
    string messageType;
    string payloadSize;
    string rtcId;
    string seqId;

public:
    ECPRIFrame();

    static const int getRevisionReservedCLength();

    static const int getMessageTypeLength();

    static const int getPayloadSizeLength();

    static const int getRtcIdLength();

    static const int getSeqIdLength();

    const string &getRevisionReservedC() const;

    void setRevisionReservedC(const string &revisionReservedC);

    const string &getMessageType() const;

    void setMessageType(const string &messageType);

    const string &getPayloadSize() const;

    void setPayloadSize(const string &payloadSize);

    const string &getRtcId() const;

    void setRtcId(const string &rtcId);

    const string &getSeqId() const;

    void setSeqId(const string &seqId);
};


#endif //ASSIGNMENT1_ECPRIFRAME_H
