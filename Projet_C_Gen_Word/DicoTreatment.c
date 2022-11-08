//
// Created by Romai on 18/10/2022.
//

#include "DicoTreatment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 256

void LireFichier(){
    FILE *fp = fopen("../dico.txt", "r");

    char buffer[MAX_LENGTH];
    char str0[MAX_LENGTH],str1[MAX_LENGTH],str2[MAX_LENGTH];
    int i,j;

    if (fp == NULL)
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
        return;
    }

    while (fgets(buffer, MAX_LENGTH, fp)){
        j=0;
        i=0;

        while(buffer[i]!='\t') {
            str0[j]=buffer[i];
            i++;
            j++;
        }
        str0[j]='\0';
        i++;
        j=0;
            while(buffer[i]!='\t') {
                str1[j]=buffer[i];
                i++;
                j++;
            }
        str1[j]='\0';
        i++;
        j=0;
        while (buffer[i]!='\n'){
            str2[j]=buffer[i];
            i++;
            j++;
        }
        str2[j]='\0';

        SortCategory(str0,str1,str2);
        /*
        printf("String 1 : %s \n",str0);
        printf("String 2 : %s \n",str1);
        printf("String 3 : %s \n",str2);
        printf("------------- \n");
        */

}

    fclose(fp);

    return;

}

void SortCategory(char Mot[MAX_LENGTH],char FormeFlechi[MAX_LENGTH],char Category[MAX_LENGTH]){

    char type[4];
    int i;

    for (i=0;i<3;i++){
        type[i]=Category[i];
    }
    type[3]='\0';

    if(strcmp(type,"Ver") == 0){
        Verbes();

    } else if(strcmp(type,"Adj") == 0){
        Adjectifs();
    }else if(strcmp(type,"Nom") == 0){
        Noms(Mot, FormeFlechi,  Category);

    }else if(strcmp(type,"Adv") == 0){
        Adverbes();
    }

    /*
    printf("Mot :  : %s \n",Mot);
    printf("Forme Flechi : %s \n",FormeFlechi);
    printf("------------- \n");
    */


    return;
}

void Adverbes(){
    printf("Adverbes\n");
    return;
}

void Verbes(){
    printf("Verbes\n");
    return;
}
void Adjectifs(){
    printf("Adjectifs\n");
    return;
}
void Noms(char Mot[MAX_LENGTH],char FormeFlechi[MAX_LENGTH],char Category[MAX_LENGTH]){
    char Genre[4],Quantite[3];
    int cpt,i=0;

    for(cpt=4;cpt<7;cpt++){
        Genre[i]=Category[cpt];
        i++;
    }Genre[3]='\0';
    i=0;
    for(cpt=8;cpt<=9;cpt++){
        Quantite[i]=Category[cpt];
        i++;
    }Quantite[2]='\0';


    printf("Noms : %s et %s\n",Quantite,Genre);

    return;
}