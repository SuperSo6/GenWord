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

void SortCategory(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH]){

    char type[4];
    int i;

    for (i=0;i<3;i++){
        type[i]=Category[i];
    }
    type[3]='\0';

    if(strcmp(type,"Ver") == 0){
        Verbes(Mot, FormeBase,  Category);

    } else if(strcmp(type,"Adj") == 0){
        Adjectifs();
    }else if(strcmp(type,"Nom") == 0){
        Noms(Mot, FormeBase,  Category);

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

void Adverbes(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH]){
    printf("FormeBase\n");
    return;
}

void Verbes(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH]){
    char temps[15],personne[15]="NULL",quantite[15]="NULL";
    int cpt=1,i=0;
    char *Verbe_Temp,*V_String;

    Verbe_Temp= strtok(Category, ":");

    while(Verbe_Temp != NULL)
    {



        if (strcmp(Verbe_Temp,"Ver")!=0){
            temps[0]='1';

            V_String = strtok(Verbe_Temp,"+");
            while(V_String !=NULL) {


                if (temps[0] == '1') {
                    strcpy(temps,V_String);

                } else if(strcmp(temps,"Inf")!=0){



                    if (quantite[0] == 'N') {
                        strcpy(quantite,V_String);
                    } else {
                        strcpy(personne,V_String);


                    }



                }

                V_String = strtok(NULL, "+");
            }

            printf("Conjugaison : %s Verbes : %s temps : %s, personne : %s, quantite : %s\n",Mot,FormeBase,temps, personne, quantite);

            Verbe_Temp = strtok(NULL, ":");
        }
        else{
            Verbe_Temp = strtok(NULL,":");
        }



    }

    printf("\n");



    return;
}
void Adjectifs(char Mot[MAX_LENGTH],char FormeFlechi[MAX_LENGTH],char Category[MAX_LENGTH]){
    char Genre[15],Quantite[15];
    int cpt,i=0;
    char *TriCategory = strtok(Category,":"),*QG;
    Genre[0]='1';


    while (TriCategory !=NULL){



        if(strcmp(TriCategory,"Adj")!=0){
            QG = strtok(TriCategory,"+");
            while (QG != NULL){

                if(Genre[0]=='1'){
                    strcpy(Genre,QG);
                } else{
                    strcpy(Quantite,QG);
                }
                QG = strtok(NULL,"+");
            }

        }

        TriCategory= strtok(NULL,":");

    }



    printf("Adj : %s et %s\n",Quantite,Genre);

    return;
}
void Noms(char Mot[MAX_LENGTH],char FormeFlechi[MAX_LENGTH],char Category[MAX_LENGTH]){
   char Genre[15],Quantite[15];
    int cpt,i=0;
    char *TriCategory = strtok(Category,":"),*QG;
    Genre[0]='1';


    while (TriCategory !=NULL){



        if(strcmp(TriCategory,"Nom")!=0){
        QG = strtok(TriCategory,"+");
            while (QG != NULL){

                if(Genre[0]=='1'){
                    strcpy(Genre,QG);
                } else{
                    strcpy(Quantite,QG);
                }
                QG = strtok(NULL,"+");
            }

        }

        TriCategory= strtok(NULL,":");

    }



    printf("Noms : %s et %s\n",Quantite,Genre);

    return;
}

