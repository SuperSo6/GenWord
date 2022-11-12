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
        Verbes(Mot, FormeFlechi,  Category);

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

void Verbes(char Mot[MAX_LENGTH],char FormeFlechi[MAX_LENGTH],char Category[MAX_LENGTH]){
    char temps[6],personne[3],quantite[3],tab1[MAX_LENGTH],tab2[MAX_LENGTH],tab3[MAX_LENGTH],tab4[MAX_LENGTH],tab5[MAX_LENGTH],tab6[MAX_LENGTH];
    int cpt=1,i=0;
    char *Verbe_Temp,*V_String ;

    Verbe_Temp= strtok(Category, ":");

    while(Verbe_Temp != NULL)
    {



        if (strcmp(Verbe_Temp,"Ver")!=0){
           /* printf("'%s'\n",Verbe_Temp);*/

            switch (cpt) {
                case 1:{

                    for(i=0;i<=sizeof(Verbe_Temp)+2;i++){
                        tab1[i]=Verbe_Temp[i];
                    }
                    tab1[i]='\0';
                    printf("case 1 : %s\n",tab1);
                    cpt++;
                    break;
                }
                case 2:{
                    for(i=0;i<=sizeof(Verbe_Temp)+2;i++){
                        tab2[i]=Verbe_Temp[i];
                    }
                    tab2[i]='\0';
                    printf("case 2 : %s\n",tab2);
                    cpt++;
                    break;
                }
                case 3:{
                    for(i=0;i<=sizeof(Verbe_Temp)+2;i++){
                        tab3[i]=Verbe_Temp[i];
                    }
                    tab3[i]='\0';
                    cpt++;
                    printf("case 3 : %s\n",tab3);
                    break;
                }
                case 4:{
                    for(i=0;i<=sizeof(Verbe_Temp)+2;i++){
                        tab4[i]=Verbe_Temp[i];
                    }
                    tab4[i]='\0';
                    cpt++;
                    printf("case 4 : %s\n",tab4);
                    break;
                }case 5:{
                    for(i=0;i<=sizeof(Verbe_Temp)+2;i++){
                        tab5[i]=Verbe_Temp[i];
                    }
                    tab5[i]='\0';
                    printf("case 5 : %s\n",tab5);
                    cpt++;
                    break;
                }case 6:{
                    for(i=0;i<=sizeof(Verbe_Temp)+2;i++){
                        tab6[i]=Verbe_Temp[i];
                    }
                    tab6[i]='\0';
                    cpt++;
                    printf("case 6 : %s\n",tab6);
                    break;
                }
                default:{
                    printf("existe pas");
                }

                cpt = 1;
            }


            Verbe_Temp = strtok(NULL, ":");
        } else{
            Verbe_Temp = strtok(NULL,":");
        }



    }

    printf("\n");



    return;
}
void Adjectifs(){
    printf("Adjectifs\n");
    return;
}
void Noms(char Mot[MAX_LENGTH],char FormeFlechi[MAX_LENGTH],char Category[MAX_LENGTH]){
   char Genre[4],Quantite[3];
    int cpt,i=0;
    char *TriCategory = strtok(Category,":"),*QG;

    while (TriCategory !=NULL){

        if(strcmp(TriCategory,"Nom")!=0){
            printf("T");
        }

        TriCategory= strtok(NULL,":");

    }



    printf("Noms : %s et %s\n",Quantite,Genre);

    return;
}

