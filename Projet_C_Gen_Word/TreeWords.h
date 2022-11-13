//
// Created by Romain on 13/11/2022.
//

#ifndef PROJET_C_GEN_WORD_TREEWORDS_H
#define PROJET_C_GEN_WORD_TREEWORDS_H

typedef  struct noeud_lettre *p_noeud_lettre;

typedef struct Flechi_cellule{
        char * Flechi;
        char * caracteristiques;
}f_cellule,*p_f_cellule;

typedef struct f_std_liste{
    struct Flechi_cellule enfant;
    struct f_std_liste * suivant;
}f_std_liste,*p_f_std_liste;


typedef struct cellule{

    p_noeud_lettre enfant;
    struct cellule * suivant;

}cellule, *p_cellule;


typedef struct s_std_liste{
    p_cellule head;
}t_std_liste, *p_std_liste;


typedef struct noeud_lettre{
    char lettre;
    t_std_liste * enfants;
    f_std_liste * FormeFlechie;

}noeud_lettre;

typedef struct arbre{
    p_noeud_lettre racine;
}arbre,*p_arbre;



arbre creerArbre();
p_cellule creerCellule(char);
p_f_std_liste creerFlisteVide();
p_f_cellule creerFcellule();
p_std_liste creerListvide();
p_noeud_lettre creerNoeud(char);


#endif //PROJET_C_GEN_WORD_TREEWORDS_H
