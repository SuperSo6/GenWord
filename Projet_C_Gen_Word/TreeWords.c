//
// Created by Romain on 13/11/2022.
//  Romain / Rayan / Floren / Jean
#include <stdio.h>
#include <stdlib.h>
#include "TreeWords.h"


p_f_std_liste creerFlisteVide() { // Creer une liste chaine pour les formes flechies
    p_f_std_liste F_liste = (p_f_std_liste) malloc(sizeof(f_std_liste));
    F_liste->suivant = NULL;
    return F_liste;
}

p_std_liste creerListvide(){ //Creer une liste chaine pour les enfants
    p_std_liste Liste = (p_std_liste) malloc(sizeof (t_std_liste));
    Liste->head = NULL;
    return Liste;
}

arbre creerArbre() {  // Initialiser l'arbre
    arbre NouvelArbre;
    NouvelArbre.racine = creerNoeud(':');
    return NouvelArbre;
}




p_noeud_lettre creerNoeud(char lettre){  // Creer un noeud pour l'arbre
    p_noeud_lettre Noeud = (p_noeud_lettre)malloc(sizeof (noeud_lettre));
    Noeud->lettre = lettre;
    Noeud->enfants = creerListvide();
    Noeud->FormeFlechie = creerFlisteVide();
    return Noeud;
}



p_cellule creerCellule(char lettre) { // creer une cellule pour la liste chaine des enfants

    p_cellule NouvelleCellule = (p_cellule) malloc(sizeof(cellule));
    NouvelleCellule->enfant = creerNoeud(lettre);
    NouvelleCellule->suivant = NULL;
    return NouvelleCellule;
}

p_f_cellule creerFcellule(){    // Creer une cellule pour la liste chaine des formes fléchies
    p_f_cellule NouvelleFcellule = (p_f_cellule) malloc(sizeof (f_cellule));
    NouvelleFcellule->Flechi = NULL;
    NouvelleFcellule->caracteristiques = NULL;
    return  NouvelleFcellule;
}

