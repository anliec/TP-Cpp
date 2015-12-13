//
// Created by nicolas on 13/12/15.
//

#ifndef TP_CPP_GRAPHGENERATOR_H
#define TP_CPP_GRAPHGENERATOR_H

#include <iostream>
#include <fstream>

const int FILE_ERROR = 80;

class GraphGenerator
{
public:
    GraphGenerator(const std::string &filePath);
    virtual ~GraphGenerator();

    int addNodeToGraph(const std::string &nodeName);
    int addLinkToGraph(const std::string &nodeNameFrom, const std::string &nodeNameTo, const std::string &linkLabel);

private:
    std::string transformToNodeName(const std::string &nonUsableName) const;

private:
    std::ofstream graphFileStream;
};


#endif //TP_CPP_GRAPHGENERATOR_H
