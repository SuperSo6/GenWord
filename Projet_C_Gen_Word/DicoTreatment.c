//
// Created by Romain on 18/10/2022.
// Romain / Rayan / Floren / Jean

#include "DicoTreatment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "TreeWords.h"

#define MAX_LENGTH 256          // Taille MAX
#define MAX_Length_Tab 10000


void LireFichier(int option){
    char Noms[MAX_Length_Tab],Adjectif[MAX_Length_Tab],Verbes[MAX_Length_Tab],Adverbes[MAX_Length_Tab];
    arbre Abr_nom,Abr_Adj,Abr_Verbes,Abr_Adv; // initialiser les 4 arbres
    Abr_nom = creerArbre(); // Arbre nom
    Abr_Adj = creerArbre(); // Arbre Adjectif
    Abr_Verbes = creerArbre();  // Arbre Verbes
    Abr_Adv = creerArbre(); // Arbre Adverbes
    time_t t1;

    Noms[0]='1';
    Adjectif[0]='1';
    Adverbes[0]='1';
    Verbes[0]='1';

    srand((unsigned) time (&t1)); // Permets de creer de l'aleatoire


    FILE *fp = fopen("../dicodetest.txt", "r");   // Creer un pointeur pour ouvrir le fichier

    char buffer[MAX_LENGTH];
    char str0[MAX_LENGTH],str1[MAX_LENGTH],str2[MAX_LENGTH];
    int i,j,x;

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

        char type[4];
        int z;

        for (z=0;z<3;z++){      // Boucle qui permets de recuperer les 3 premiers caracteres : exemple ( Nom:Mas+SG ) -> Nom
            type[z]=str2[z];
        }
        type[3]='\0';

        if(strcmp(type,"Ver") == 0){                      // Trie et appelle les fonctions définis pour les verbes / adjectifs / noms et adverbes


            x = rand() % 100 + 1;

            if(x % 13 == 0){
                fill_abr(Verbes,str0);

            }



        } else if(strcmp(type,"Adj") == 0){


            x = rand() % 100 + 1;

            if(x % 13 == 0){
                fill_abr(Adjectif,str0);

            }


        }else if(strcmp(type,"Nom") == 0){


            x = rand() % 100 + 1;

            if(x % 13 == 0){
                fill_abr(Noms,str0);

            }


        }else if(strcmp(type,"Adv") == 0){


            x = rand() % 100 + 1;

            if(x % 13 == 0){
                fill_abr(Adverbes,str0);

            }


        }



     //  SortCategory(str0,str1,str2,Abr_nom,Abr_Adv,Abr_Verbes,Abr_Adj);  // on appelle la fonction qui va permettre de trier en fonction de Nom / Verbes / Adjectifs / Adverbes
        /*
        printf("String 1 : %s \n",str0);
        printf("String 2 : %s \n",str1);
        printf("String 3 : %s \n",str2);
        printf("------------- \n");
         */




}
/*
    printf("Adjectif : %s\n",Adjectif);
    printf("Nom : %s\n",Noms);
    printf("Adv : %s\n",Adverbes);
    printf("Verbes : %s\n",Verbes);
*/
    result(Noms,Adverbes,Verbes,Adjectif,option);




    fclose(fp);  // fermer le fichier



    return;

}

void result(char Noms[MAX_Length_Tab],char Adverbes[MAX_Length_Tab],char Verbes[MAX_Length_Tab],char Adjectif[MAX_Length_Tab],int option){  // Fonction qui permets de generer les 3 types de phrases
    time_t t1;
    srand((unsigned) time (&t1));
    switch (option) {
        case 1:{
            // Generation de la phrase numero 1
            // ' nom - adjectif - verbe -nom '
             char *V_split,*N1_split,*N2_split,*A_split;
             V_split = strtok(Verbes,"/");
             N1_split = strtok(Noms,"/");
             N2_split = strtok(Noms,"/");
             A_split = strtok(Adjectif,"/");
             int x;
             x= rand()%  40 + 1;

             while (x>0 ){
                V_split = strtok(NULL,"/");
                x--;
             }


            x= rand()% 30 + 1;
            while (x>0){
                N1_split = strtok(NULL,"/");
                x--;
            }


            x= rand()% 30 + 1;
            while (x>0 ){
                N2_split = strtok(NULL,"/");
                x--;
            }

            x= rand()% 5 + 1;
            while (x>0){
                A_split = strtok(NULL,"/");
                x--;
            }
            if(V_split==NULL || N1_split==NULL || N2_split==NULL || A_split==NULL){
                printf("Veuillez relancer le programme !");
                break;
            }

            printf("Votre phrase g%cn%cr%c : La %s %s %s une %s",130,130,130,N1_split,A_split,V_split,N2_split);
             break;
        }
        case 2:{
            //Generation de la phrase numero 2

            // ' nom - qui - verbe - verbe - nom - adjectif '
            char *V1_split,*N1_split,*N2_split,*A_split,*V2_split;
            V1_split = strtok(Verbes,"/");
            V2_split = strtok(Verbes,"/");
            N1_split = strtok(Noms,"/");
            N2_split = strtok(Noms,"/");
            A_split = strtok(Adjectif,"/");
            int x;
            x= rand()%  40 + 1;

            while (x>0 ){
                V1_split = strtok(NULL,"/");
                x--;
            }

            x= rand()%  40 + 1;

            while (x>0 ){
                V2_split = strtok(NULL,"/");
                x--;
            }


            x= rand()% 30 + 1;
            while (x>0){
                N1_split = strtok(NULL,"/");
                x--;
            }


            x= rand()% 30 + 1;
            while (x>0 ){
                N2_split = strtok(NULL,"/");
                x--;
            }

            x= rand()% 5 + 1;
            while (x>0){
                A_split = strtok(NULL,"/");
                x--;
            }
            if(V1_split==NULL || N1_split==NULL || N2_split==NULL || A_split==NULL || V2_split==NULL){
                printf("Veuillez relancer le programme !");
                break;
            }

            printf("Votre phrase g%cn%cr%c : Le %s qui %s %s un %s %s",130,130,130,N1_split,V1_split,V2_split,N2_split,A_split);
            break;
        }
        case 3:{
            //Generation de la phrase numero 3
            // 'nom - adjectif - qui - verbe - adverbe '
            char *V_split,*N1_split,*Adv_split,*A_split;
            V_split = strtok(Verbes,"/");
            N1_split = strtok(Noms,"/");
            Adv_split = strtok(Noms,"/");
            A_split = strtok(Adjectif,"/");
            int x;
            x= rand()%  40 + 1;

            while (x>0 ){
                V_split = strtok(NULL,"/");
                x--;
            }


            x= rand()% 30 + 1;
            while (x>0){
                N1_split = strtok(NULL,"/");
                x--;
            }


            x= rand()% 4 + 1;
            while (x>0 ){
                Adv_split = strtok(NULL,"/");
                x--;
            }

            x= rand()% 5 + 1;
            while (x>0){
                A_split = strtok(NULL,"/");
                x--;
            }
            if(V_split==NULL || N1_split==NULL || Adv_split==NULL || A_split==NULL){
                printf("Veuillez relancer le programme !");
                break;
            }
            printf("Votre phrase g%cn%cr%c : Le %s %s qui %s %s",130,130,130,N1_split,A_split,V_split,Adv_split);
            break;
        }
        default:{
            printf("Cette option n'existe pas\n");
            break;
        }
    }
}

void fill_abr(char tab[MAX_Length_Tab],char Str[MAX_LENGTH]){  // permets de remplir un tableau a l'aide partir d'une chaine de caracteres.
    char c;
    size_t taille = strlen(Str);
    int i,z=0;
    i=0;

    c = tab[i];
    if(tab[0]=='1'){
        for (z=0;z<taille;z++){
            tab[z]=Str[z];
        }
        tab[z]='\0';

    }
    while (c!='\0'){
        i++;
        c=tab[i];
    }
    tab[i]='/';
    i++;
    for (z=0;z<taille;z++) {
        tab[i]=Str[z];
        i++;
    }
    tab[i]='\0';



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


    }/*
    p_noeud_lettre temp2 = Arbre_Nom.racine;
    while (temp2!= NULL){
        printf("%c",temp2->lettre);
        temp2 = temp2->enfants->head->enfant;
    }*/









    return;
}



