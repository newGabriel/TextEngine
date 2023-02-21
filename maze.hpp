#pragma once

#include <string>
#include <map>
#include <vector>

typedef std::pair<int,int> ii;

class Maze{

    int rows;
    int cols;
    std::vector<std::vector<char>> lab;

    int exits;
    int npc;
    int itens;
    bool dark;

    std::map<ii,std::string> listExits;
    std::map<ii,std::string> listNPCs;
    std::map<ii,std::string> listItens;


    public:

    Maze(std::string mazeFile);

    void descrever();
    void printMaze();

    private:

    void fillExits(std::ifstream &maze);
    void fillNPCs(std::ifstream &maze);
    void fillItens(std::ifstream &maze);
    void fillMaze(std::ifstream &maze);
    void fillMap(std::ifstream &maze, int n, std::map<ii,std::string> &M);

};