#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scenario.hpp"
#include "maze.hpp"

using namespace std;

int main(){
    FILE *mainFile = fopen("main.gm","r");
    if(mainFile==NULL){
        printf("Não foi possivel executar o game\n");
        exit(1);
    }

    char word[50];

    while(fscanf(mainFile, " %s",word)!=EOF){
        if(strcmp(word, "C:")==0)break;
        if(strcmp(word, "R:")==0)continue;
        printf("%s ",word);
    }puts("");

    fscanf(mainFile, " %s",word);

    Scenario scenario = Scenario(word);
    scenario.describe(); 
    
    // Maze maze = Maze(word);
    // maze.describe();

    return 0;
}