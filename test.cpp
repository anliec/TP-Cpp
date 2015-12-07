//
// Created by nicolas on 07/12/15.
//

#include "test.h"

void testAdd(DataManager & dataManager)
{
    tm tm1;
    LogOtherInfos otherInfos("192.169.0.0",tm1,1,2,"Firefox","moi","pseudo","GET");
    dataManager.add("s1","google",12,100,otherInfos);
    dataManager.add("s1","google",13,100,otherInfos);
    dataManager.add("s1","google",14,100,otherInfos);

    dataManager.Request();
}