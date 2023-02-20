#include <cstdio>
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <string>

#include "scenario.hpp"

Scenario::Scenario(std::string scenFile) {
  std::ifstream scen(scenFile);

  scen >> this->exits >> this->npc;
  this->description = "";

  std::string aux;

  //printf("oloko\n");
  fillExits(scen);
  fillNPCs(scen);
  fillDescription(scen);

  scen.close();
}

void Scenario::descrever() {
  printf("Saidas: %d\n", this->exits);
  printf("Npcs: %d\n", this->exits);

  std::cout << description << std::endl;

  printf("Lista de saidas: \n");
  for (auto i : listExits) {
    std::cout << i.first << " " << i.second << std::endl;
  }

  printf("Lista de NPCs: \n");
  for (auto i : listNPCs) {
    std::cout << i.first << " " << i.second << std::endl;
  }
}

void Scenario::fillExits(std::ifstream &scen){
  fillMap(scen, this->exits, this->listExits);
}

void Scenario::fillNPCs(std::ifstream &scen){ 
    fillMap(scen, this->npc, this->listNPCs);
}

void Scenario::fillDescription(std::ifstream &scen){
  std::string aux;
  while (scen >> aux) {
    this->description += aux + " ";
  }
  this->description.pop_back();
}

void Scenario::fillMap(std::ifstream &scen, int n,
             std::map<std::string, std::string> &M){
  std::string name;
  std::string file;
  for (int i = 0; i < n; i++) {
    name = "";
    file = "";
    while(name.size()==0)
      std::getline(scen,name);
    while (name.back() != ' ') {
      file = name.back() + file;
      name.pop_back();
    }
    name.pop_back();

    M[name] = file;
  }
}