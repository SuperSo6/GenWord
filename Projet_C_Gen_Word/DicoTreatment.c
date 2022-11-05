//
// Created by Romai on 18/10/2022.
//

#include "DicoTreatment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 256

void LireFichier(){
    FILE *fp = fopen("../dictionnaire_non_accentue.txt", "r");

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

        printf("String 1 : %s \n",str0);
        printf("String 2 : %s \n",str1);
        printf("String 3 : %s \n",str2);
        printf("------------- \n");


}

    fclose(fp);

    return;

}

void SortCategory(char Mot[MAX_LENGTH],char FormeFlechi[MAX_LENGTH],char Category[MAX_LENGTH]){
    pass;
}