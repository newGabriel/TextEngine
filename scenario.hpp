#pragma once

#include <string>
#include <map>

class Scenario{
    int exits;
    int npc;
    std::string description;
    std::map<std::string,std::string> listExits;
    std::map<std::string,std::string> listNPCs;

    public:
    
    Scenario(std::string scenFile);

    void descrever();

    private:

    void fillExits(std::ifstream &scen);

    void fillNPCs(std::ifstream &scen);

    void fillDescription(std::ifstream &scen);

    void fillMap(std::ifstream &scen, int n, std::map<std::string,std::string> &M);
    
};