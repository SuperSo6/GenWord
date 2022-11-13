//
// Created by Romain on 13/11/2022.
//

#ifndef PROJET_C_GEN_WORD_TREEWORDS_H
#define PROJET_C_GEN_WORD_TREEWORDS_H

typedef struct noeud_lettre *p_noeud_lettre;
/*
struct Flechi_cellule{

};*/


typedef struct cellule{

    p_noeud_lettre enfant;
    struct cellule * suivant;

}cellule, *p_cellule;


typedef struct s_std_liste{
    p_cellule head;
}t_std_liste, *p_std_liste;


struct noeud_lettre{
    char lettre;
    t_std_liste * enfants;
  //  f_std_liste * FormeFlechie;

};

p_cellule creerCellule(char lettre);

#endif //PROJET_C_GEN_WORD_TREEWORDS_H
