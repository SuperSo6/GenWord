//
// Created by Romain on 13/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "TreeWords.h"

p_cellule creerCellule(char lettre){

    p_cellule NouvelleCellule = (p_cellule)malloc(sizeof (cellule));
    //NouvelleCellule->enfant = QQch;
    NouvelleCellule->suivant = NULL;
    return NouvelleCellule;
}

