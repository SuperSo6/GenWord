//
// Created by Romain on 12/11/2022.
//

#ifndef PROJET_C_GEN_WORD_ABRNOMS_H
#define PROJET_C_GEN_WORD_ABRNOMS_H
#define ALPHABET_SIZE 26
#define MAX_LENGTH 256
typedef struct s_lettre_node
{
    char lettre;
    struct lettre_node * enfants [ALPHABET_SIZE] ;

} t_lettre_node,*p_letter_node;

typedef struct s_tree
{
    t_lettre_node root ;
} t_tree ;

void AbrNoms(char [MAX_LENGTH]);


#endif //PROJET_C_GEN_WORD_ABRNOMS_H
