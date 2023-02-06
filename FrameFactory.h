//
// Created by Omar on 2/6/2023.
//

#ifndef ASSIGNMENT1_FRAMEFACTORY_H
#define ASSIGNMENT1_FRAMEFACTORY_H
#include "ECPRIFrame.h"
#include "EthernetFrame.h"

class FrameFactory {

public:
    static Frame *createFrameObject(string frameTypeCode);

};


#endif //ASSIGNMENT1_FRAMEFACTORY_H
