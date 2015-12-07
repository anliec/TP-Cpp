#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "DataManager.h"

#include "test.h"

using namespace std;

int main(int argc, char * argv[])
{
    DataManager manager;

    //testAdd(manager);

    bool optionE = false;
    bool optionT = false;
    bool optionG = false;
    int tHour = 0;
    string gFilePath = "";
    string logFilePath = "";
    int currentArg = 1; //pass the first arg which is the program name (+ path)

    //read the input arguments:

    while (currentArg < argc-1)
    {
        if(argv[currentArg][0] == '-')
        {
           switch (argv[currentArg][1])
           {
               case 'e':
                   optionE = true;
                   break;
               case 't':
                   optionT = true;
                   currentArg++; //if the argument is "-t" then the next must be the hour
                   tHour = atoi(argv[currentArg]);
                   break;
               case 'g':
                   optionG = true;
                   currentArg++; //if the argument is "-g" then the next must be the file path
                   gFilePath = argv[currentArg];
                   break;
           }
        }
        currentArg++;
    }
    if(currentArg >= argc)
    {
        cout << "wrong number of arguments" << endl;
        return 1;
    }
    logFilePath = argv[argc-1];

    manager.LoadLogFile(logFilePath);
    manager.Request(optionT,tHour, optionE, optionG,gFilePath);

    return 0;
}

