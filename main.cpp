#include <iostream>
#include <string>

#include "DataManager.h"

int main(int argc, char * argv[])
{
    DataManager manager;

    bool optionE = false;
    bool optionT = false;
    bool optionG = false;
    int tHour = 0;
    std::string gFilePath = "";
    std::string logFilePath = "";
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
                   tHour = std::atoi(argv[currantArg]);
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
        std::cout << "wrong number of arguments" << std::endl;
        return 1;
    }
    logFilePath = argv[argc-1];

    manager.LoadLogFile(logFilePath);



    return 0;
}

