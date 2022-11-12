//
// Created by Romai on 18/10/2022.
//

#ifndef PROJET_C_GEN_WORD_DICOTREATMENT_H
#define PROJET_C_GEN_WORD_DICOTREATMENT_H
#define MAX_LENGTH 256


void LireFichier();



void SortCategory(char[MAX_LENGTH],char[MAX_LENGTH],char[MAX_LENGTH]);

void Adverbes();
void Verbes(char [MAX_LENGTH],char [MAX_LENGTH],char [MAX_LENGTH]);
void Adjectifs();
void Noms(char[MAX_LENGTH],char[MAX_LENGTH],char[MAX_LENGTH]);


#endif //PROJET_C_GEN_WORD_DICOTREATMENT_H
