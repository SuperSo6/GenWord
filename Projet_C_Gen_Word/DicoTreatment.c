//
// Created by Romai on 18/10/2022.
//

#include "DicoTreatment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeWords.h"

#define MAX_LENGTH 256



void LireFichier(){
    arbre Abr_nom,Abr_Adj,Abr_Verbes,Abr_Adv; // initialiser les 4 arbres
    Abr_nom = creerArbre(); // Arbre nom
    Abr_Adj = creerArbre(); // Arbre Adjectif
    Abr_Verbes = creerArbre();  // Arbre Verbes
    Abr_Adv = creerArbre(); // Arbre Adverbes


    FILE *fp = fopen("../dico.txt", "r");   // Creer un pointeur pour ouvrir le fichier

    char buffer[MAX_LENGTH];
    char str0[MAX_LENGTH],str1[MAX_LENGTH],str2[MAX_LENGTH];
    int i,j;

    if (fp == NULL)             // Test si le fichier est ouvrable
    {
        printf("Le fichier texte.txt n'a pas pu être ouvert\n");
        return;
    }

    while (fgets(buffer, MAX_LENGTH, fp)){ // On recupere ligne par ligne
        j=0;
        i=0;

        while(buffer[i]!='\t') {            // On separe dans 3 strings differents les 3 mots de la lignes
            str0[j]=buffer[i];
            i++;
            j++;
        }
        str0[j]='\0';       // On definit la fin de la chaine de caractere
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



       SortCategory(str0,str1,str2,Abr_nom,Abr_Adv,Abr_Verbes,Abr_Adj);  // on appelle la fonction qui va permettre de trier en fonction de Nom / Verbes / Adjectifs / Adverbes
        /*
        printf("String 1 : %s \n",str0);
        printf("String 2 : %s \n",str1);
        printf("String 3 : %s \n",str2);
        printf("------------- \n");
         */


}

    fclose(fp);  // fermer le fichier

    return;

}

void SortCategory(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH],arbre Arbre_Nom,arbre Arbre_Adverbe,arbre Arbre_Verbe ,arbre Arbre_Adjectif){   // on recupere les 3 strings et les  4 abres

    // declaration variable
    char type[4];
    int z;

    for (z=0;z<3;z++){      // Boucle qui permets de recuperer les 3 premiers caracteres : exemple ( Nom:Mas+SG ) -> Nom
        type[z]=Category[z];
    }
    type[3]='\0';

    if(strcmp(type,"Ver") == 0){                      // Trie et appelle les fonctions définis pour les verbes / adjectifs / noms et adverbes
        Verbes(Mot, FormeBase,  Category);

    } else if(strcmp(type,"Adj") == 0){
        Adjectifs(Mot, FormeBase,  Category, Arbre_Adjectif);
    }else if(strcmp(type,"Nom") == 0){
        Noms(Mot, FormeBase,  Category, Arbre_Nom);

    }else if(strcmp(type,"Adv") == 0){
        Adverbes();
    }

/*
    printf("Mot :  : %s \n",Mot);
    printf("Forme Flechi : %s \n",FormeFlechi);
    printf("------------- \n");
*/


    return;
}

void Adverbes(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH]){  //A completer avec les arbres
    printf("FormeBase\n");
    return;
}

void Verbes(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH]){  // Permets de triers les element associe a la forme flechie
    char temps[15],personne[15]="NULL",quantite[15]="NULL";
    int cpt=1,i=0;
    char *Verbe_Temp,*V_String;

    Verbe_Temp= strtok(Category, ":");      // permets de split la chaine de caractere exemple : "Ver:IPSim+SG+P1" devient "Ver" et "IPSim+SG+P1"

    while(Verbe_Temp != NULL)
    {



        if (strcmp(Verbe_Temp,"Ver")!=0){               // split le deuxieme element de Verbe_temp exemple : "IPSim+SG+P1" -> "IPSim", "SG", "P1"
            temps[0]='1';

            V_String = strtok(Verbe_Temp,"+");
            while(V_String !=NULL) {


                if (temps[0] == '1') {
                    strcpy(temps,V_String);     // strcpy permets de copier un string dans un autre

                } else if(strcmp(temps,"Inf")!=0){



                    if (quantite[0] == 'N') {
                        strcpy(quantite,V_String);
                    } else {
                        strcpy(personne,V_String);


                    }



                }

                V_String = strtok(NULL, "+");
            }

            printf("Verbes(Forme Flechi) : %s Verbes(Base) : %s temps : %s, personne : %s, quantite : %s\n",Mot,FormeBase,temps, personne, quantite);

            Verbe_Temp = strtok(NULL, ":");
        }
        else{
            Verbe_Temp = strtok(NULL,":");
        }



    }

    printf("\n");



    return;
}
void Adjectifs(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH],arbre Arbre_Adjectif){  //  Permets de trier les elements associes à la forme flechie
    char Genre[15],Quantite[15];
    int cpt,i=0;
    char *TriCategory = strtok(Category,":"),*QG;
    Genre[0]='1';


    while (TriCategory !=NULL){     // "Adj:Mas+SG" -> "Adj" et "Mas+SG"



        if(strcmp(TriCategory,"Adj")!=0){               // "Mas+SG" -> "Mas" et "SG"
            QG = strtok(TriCategory,"+");
            while (QG != NULL){

                if(Genre[0]=='1'){
                    strcpy(Genre,QG);
                } else{
                    strcpy(Quantite,QG);
                }
                QG = strtok(NULL,"+");
            }

        }

        TriCategory= strtok(NULL,":");

    }



    printf("Adjectif(Forme Flechi) : %s Adjectif(Base) : %s quantite : %s genre : %s\n",Mot,FormeBase,Quantite,Genre);
    printf("\n");

    return;
}
void Noms(char Mot[MAX_LENGTH],char FormeBase[MAX_LENGTH],char Category[MAX_LENGTH], arbre Arbre_Nom){
   char Genre[15],Quantite[15];
    int cpt,i=0;
    char *TriCategory = strtok(Category,":"),*QG;
    Genre[0]='1';


    while (TriCategory !=NULL){



        if(strcmp(TriCategory,"Nom")!=0){
        QG = strtok(TriCategory,"+");
            while (QG != NULL){

                if(Genre[0]=='1'){
                    strcpy(Genre,QG);
                } else{
                    strcpy(Quantite,QG);
                }
                QG = strtok(NULL,"+");
            }

        }

        TriCategory= strtok(NULL,":");

    }
    printf("Nom(FormeFlechi) : %s Nom(Base) %s quantie %s genre %s\n",Mot,FormeBase,Quantite,Genre);
    printf("\n");



    /*

    p_noeud_lettre temp;
    p_noeud_lettre nouveauNoeud;
    size_t taille_base = strlen(FormeBase);
    int compteur=0;

    temp = Arbre_Nom.racine;
    while (compteur<taille_base){

        p_cellule pointeur_cellule = temp->enfants->head;
        int trouve = 0;

        while (pointeur_cellule!= NULL && trouve !=1){

            if(pointeur_cellule->enfant->lettre==FormeBase[compteur]){
                temp = pointeur_cellule->enfant ;
                trouve=1;

            } else{
                pointeur_cellule = pointeur_cellule->suivant;
            }

        }
        if(trouve==0){
            p_cellule nouvelleCellule = creerCellule(FormeBase[compteur]);
            if(temp->enfants->head== NULL){
                temp->enfants->head = nouvelleCellule;
            } else{
            p_cellule cellule_temp = temp->enfants->head;
                while (cellule_temp->suivant!=NULL){
                    cellule_temp = cellule_temp->suivant;
                }
                cellule_temp->suivant = nouvelleCellule;
            }
            temp = nouvelleCellule->enfant;

        }
        compteur++;


    }
    p_noeud_lettre temp2 = Arbre_Nom.racine;
    while (temp2!= NULL){
        printf("%c",temp2->lettre);
        temp2 = temp2->enfants->head->enfant;
    }

        */







    return;
}



