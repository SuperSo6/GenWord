#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "DicoTreatment.h"
#include "TreeWords.h"

int main(void) {
    // ** MENU ACCUEIL ** //

    int choix=1;
    /*
    printf("Bienvenu sur le G%cn%crateur de phrases : \n",130,130);
    printf("Vous avez les choix entre 3 mod%cles de phrases diff%crentes %c g%cn%crer\n",138,130,133,130,130);
    printf("Option 1 : le mod%cle ' nom %c adjectif %c verbe %c nom '\n",138,45,45,45);
    printf("Option 2 : le mod%cle ' nom %c qui %c verbe %c verbe %c nom %c adjectif '\n",138,45,45,45,45,45);
    printf("Enfin Option 3 : le mod%cle ''\n",138);
    printf("Que choisissez vous ? : ");
    scanf("%d",&choix);
    switch (choix) {
        case 1:{
            printf("Vous avez choisis le mod%cle ' nom %c adjectif %c verbe %c nom '\n",138,45,45,45);
            break;
        }
        case 2:{
            printf("Vous avez choisis le mod%cle ' nom %c qui %c verbe %c verbe %c nom %c adjectif '\n",138,45,45,45,45,45);
            break;
        }
        case 3:{
            printf("Vous avez choisis le mod%cle \n",138);
            break;
        }
        default:{
            printf("Cette option n'existe pas !\n");
            main();
        }
    }*/

    LireFichier(choix); // Lancer le programe
    return 0;
}