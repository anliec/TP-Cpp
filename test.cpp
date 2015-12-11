//
// Created by nicolas on 07/12/15.
//

#include "test.h"

void testAdd(DataManager & dataManager)
{
    tm tm1;
    LogOtherInfos otherInfos("192.169.0.0",tm1,1,2,"Firefox","moi","pseudo","GET", 200);
    for (int i = 0; i < 10; ++i)
    {
        dataManager.add("s1","google",i,100,otherInfos);
        //dataManager.add("s2","google.png",i,100,otherInfos);
    }

    dataManager.Request(false,0,true,true,"out.test");
}