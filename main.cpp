#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DataManager.h"

using namespace std;

int main(int argc, char * argv[])
{
    DataManager manager;

    bool optionE = false;
    bool optionT = false;
    bool optionG = false;
    int tHour = 0;
    string gFilePath = "";
    string logFilePath = "";
    int currantArg = 1; //pass the first arg which is the programe name (+ path)

    //read the input arguments:

    while (currantArg < argc-1)
    {
        if(argv[currantArg][0] == '-')
        {
           switch (argv[currantArg][1])
           {
               case 'e':
                   optionE = true;
                   break;
               case 't':
                   optionT = true;
                   currantArg++; //if the argument is "-t" then the next must be the hour
                   tHour = atoi(argv[currantArg]);
                   break;
               case 'g':
                   optionG = true;
                   currantArg++; //if the argument is "-g" then the next must be the file path
                   gFilePath = argv[currantArg];
                   break;
           }
        }
        currantArg++;
    }
    if(currantArg >= argc)
    {
        cout << "wrong number of arguments" << endl;
        return 1;
    }
    logFilePath = argv[argc-1];

    manager.LoadLogFile(logFilePath);



    return 0;
}

