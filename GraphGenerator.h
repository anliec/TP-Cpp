/*************************************************************************
                     GraphGenerator  -  description
                             -------------------
    debut                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

#ifndef TP_CPP_GRAPHGENERATOR_H
#define TP_CPP_GRAPHGENERATOR_H

//--------------------------------------------------------------- Includes
#include <iostream>
#include <fstream>

//-------------------------------------------------------------- Constants
const int FILE_ERROR = 80;

//------------------------------------------------------------------------
// The class GraphGenerator handle all that is related to the creation of
// the graph file
//------------------------------------------------------------------------
class GraphGenerator
{
//----------------------------------------------------------------- PUBLIC
public:
//--------------------------------------------------------- Public methods
    int addNodeToGraph(const std::string &nodeName);
    // adds a node to the graph. Label given in parameter
    int addLinkToGraph(const std::string &nodeNameFrom, const std::string &nodeNameTo, const std::string &linkLabel);
    //adds a link between two nodes given in parameters. Label given in parameter
//--------------------------------------------- Constructors - destructors
    GraphGenerator(const std::string &filePath);
    virtual ~GraphGenerator();

//---------------------------------------------------------------- PRIVATE
private:
//-------------------------------------------------------- Private methods
    std::string transformToNodeName(const std::string &nonUsableName) const;

private:
    std::ofstream graphFileStream;
};


#endif //TP_CPP_GRAPHGENERATOR_H
