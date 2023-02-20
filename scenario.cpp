#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <map>

class scenario{
    int exits;
    int npc;
    std::string description;
    std::map<std::string,std::string> listExits;
    std::map<std::string,std::string> listNPCs;

    public:
    
    scenario(std::string scenFile){
        std::ifstream scen(scenFile);
        
        scen>>this->exits>>this->npc;
        this->description = "";

        std::string aux;
        
        fillExits(scen);
        fillNPCs(scen);
        fillDescription(scen);

        scen.close();
    }

    void descrever(){
        printf("Saidas: %d\n",this->exits);
        printf("Npcs: %d\n",this->exits);

        std::cout<<description<<std::endl;

        printf("Lista de saidas: \n");
        for(auto i: listExits){
            std::cout<<i.first<<" "<<i.second<<std::endl;
        }

        printf("Lista de NPCs: \n");
        for(auto i: listNPCs){
            std::cout<<i.first<<" "<<i.second<<std::endl;
        }

    }

    private:

    void fillExits(std::ifstream &scen){
        fillMap(scen, this->listExits);
    }

    void fillNPCs(std::ifstream &scen){
        fillMap(scen, this->listNPCs);
    }

    void fillDescription(std::ifstream &scen){
        std::string aux;
        while(scen>>aux){
            this->description+=aux+" ";
        }
        this->description.pop_back();
    }

    void fillMap(std::ifstream &scen, std::map<std::string,std::string> &M){
        std::string name;
        std::string file="";
        for(int i=0;i<this->exits;i++){
            std::getline(scen,name);
            
            while(name.back()!=' '){
                file = name.back()+file;
                name.pop_back();
            }
            name.pop_back();

            M[name] = file;
        }
    }
    
};