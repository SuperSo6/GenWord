//
// Created by Romai on 18/10/2022.
//

#ifndef PROJET_C_GEN_WORD_DICOTREATMENT_H
#define PROJET_C_GEN_WORD_DICOTREATMENT_H
#define MAX_LENGTH 256
#include "TreeWords.h"

void LireFichier();





void SortCategory(char[MAX_LENGTH],char[MAX_LENGTH],char[MAX_LENGTH],arbre,arbre,arbre,arbre);

void Adverbes();
void Verbes(char [MAX_LENGTH],char [MAX_LENGTH],char [MAX_LENGTH]);
void Adjectifs(char [MAX_LENGTH],char [MAX_LENGTH],char [MAX_LENGTH],arbre);
void Noms(char[MAX_LENGTH],char[MAX_LENGTH],char[MAX_LENGTH],arbre);


#endif //PROJET_C_GEN_WORD_DICOTREATMENT_H
