#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "maze.hpp"

Maze::Maze(std::string mazeFile){
    
    std::ifstream maze(mazeFile);

    maze >> this->rows >> this->cols;
    maze >> this->exits >> this->npc 
         >> this->itens >> this->dark;

    this->lab = std::vector<std::vector<char>>
                (this->rows,std::vector<char>(this->cols,'0'));

    fillExits(maze);
    fillNPCs(maze);
    fillItens(maze);
    fillMaze(maze);

    maze.close();
}

void Maze::descrever(){
    printf("Saidas: %d\n",this->exits);
    printf("NPCs: %d\n",this->npc);
    printf("Itens: %d\n",this->itens);
    printf("Escuro: %d\n",this->dark);

    printMaze();

    printf("Lista de Saidas:\n");
    for(auto i: this->listExits){
        printf("(%d,%d) - ",i.first.first,i.first.second);
        std::cout<<i.second<<std::endl;
    }

    printf("Lista de NPCs:\n");
    for(auto i: this->listNPCs){
        printf("(%d,%d) - ",i.first.first,i.first.second);
        std::cout<<i.second<<std::endl;
    }

    printf("Lista de Itens:\n");
    for(auto i: this->listItens){
        printf("(%d,%d) - ",i.first.first,i.first.second);
        std::cout<<i.second<<std::endl;
    }

}

void Maze::printMaze(){
    for(auto i:lab){
        for(auto j:i){
            printf("%c ",j);
        }puts("");
    }
}

void Maze::fillExits(std::ifstream &maze){
    fillMap(maze,this->exits,this->listExits);
}

void Maze::fillNPCs(std::ifstream &maze){
    fillMap(maze,this->npc,this->listNPCs);
}

void Maze::fillItens(std::ifstream &maze){
    fillMap(maze, this->itens, this->listItens);
}

void Maze::fillMaze(std::ifstream &maze){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            maze>>this->lab[i][j];
        }
    }
}

void Maze::fillMap(std::ifstream &maze, int n, std::map<ii,std::string> &M){
    int x;
    int y;
    std::string file;
    
    for(int i=0;i<n;i++){
        maze >> x >> y >> file;
        M[{x,y}] = file;
    }
}