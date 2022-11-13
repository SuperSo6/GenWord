//
// Created by Romain on 13/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "TreeWords.h"

p_cellule creerCellule(char lettre){

    p_cellule NouvelleCellule = (p_cellule)malloc(sizeof (cellule));
    NouvelleCellule->enfant = creerNoeud(lettre);
    NouvelleCellule->suivant = NULL;
    return NouvelleCellule;
}

p_std_liste creerListvide(){
    p_std_liste Liste = (p_std_liste) malloc(sizeof (t_std_liste));
    Liste->head = NULL;
    return Liste;
}

p_f_cellule creerFcellule(){
    p_f_cellule NouvelleFcellule = (p_f_cellule) malloc(sizeof (f_cellule));
    NouvelleFcellule->Flechi = NULL;
    NouvelleFcellule->caracteristiques = NULL;
    return  NouvelleFcellule;
}

p_f_std_liste creerFlisteVide(){
    p_f_std_liste F_liste = (p_f_std_liste) malloc(sizeof (f_std_liste));
    F_liste->suivant = NULL;
    return F_liste;
}

p_noeud_lettre creerNoeud(char lettre){
    p_noeud_lettre Noeud = (p_noeud_lettre)malloc(sizeof (noeud_lettre));
    Noeud->lettre = lettre;
    Noeud->enfants = creerListvide();
    Noeud->FormeFlechie = creerFlisteVide();
    return Noeud;
}

arbre creerArbre(){
    arbre NouvelArbre;
    NouvelArbre.racine = creerNoeud(':');
    return NouvelArbre;
}


