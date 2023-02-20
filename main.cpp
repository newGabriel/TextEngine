#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    ///TODO: inserir funções para manipulação de cenario 
    
    return 0;
}