//
// Created by Omar on 2/6/2023.
//

#include "FrameFactory.h"




Frame *FrameFactory::createFrameObject(string frameTypeCode) {
    if (frameTypeCode == "AEFE"){
        return new ECPRIFrame();
    }else{
        return new EthernetFrame();
    }
}
