//
// Created by Romain on 13/11/2022.
//

#ifndef PROJET_C_GEN_WORD_TREEWORDS_H
#define PROJET_C_GEN_WORD_TREEWORDS_H

typedef struct noeud_lettre *p_noeud_lettre;

struct Flechi_cellule{
    
};


typedef struct cellule{

    p_noeud_lettre enfant;
    struct cellule * suivant;

};


typedef struct s_std_liste{
    p_cell head;
}t_std_liste;


struct noeud_lettre{
    char lettre;
    t_std_liste * enfants;
    F_std_liste * FormeFlechie;

};



#endif //PROJET_C_GEN_WORD_TREEWORDS_H
