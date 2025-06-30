#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/word.h"

char nom_fichier[256];
char line[256];
int choix, ind;

int main() {
    printf("\033[35m******** Mini gestionnaire de texte ******** \n\033[0m");

    //Entrée du chemin d'accès du fichier
    printf("Entrez le chemin d'accès du fichier : \n");
    fgets(nom_fichier, sizeof(nom_fichier), stdin);
    nom_fichier[strcspn(nom_fichier, "\n")] = 0;

    //Chargemnt du fichier
    loadFile(nom_fichier);

    while (1) {
        //Menu
        printf("\nMenu :\n");
        printf(" 1 - Afficher les lignes du texte\n");
        printf(" 2 - Ajouter une ligne\n");
        printf(" 3 - Modifier une ligne\n");
        printf(" 4 - Supprimer une ligne\n");
        printf(" 5 - Quitter\n");
        printf("Votre choix -> ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\n\033[32m1 - Afficher les lignes \n\n\033[0m");
                showLines();
                break;

            case 2:
                printf("\n\033[32m2 - Ajouter une ligne \n\n\033[0m");
                
                //Entrée de la ligne
                getchar();
                printf("Entrez la ligne à ajouter : ");
                fgets(line, 256, stdin);

                addLine(line);
                saveData(nom_fichier);

                break;

            case 3:
                printf("\n\033[32m3 - Modifier une ligne \n\n\033[0m");

                //Entrée de l'index de la ligne 
                while(1){
                    printf("Entrez le numéro de la ligne à modifier : ");
                    scanf("%d", &ind);
                    if (ind < 1 || ind > nb_lines) {
                        printf("Numéro invalide, réessayez\n");
                    }else{
                        break;
                    }
                }

                //Entrée de la ligne
                getchar();
                printf("Entrez la ligne à modifier : ");
                fgets(line, 256, stdin);

                editLine(ind, line);
                saveData(nom_fichier);
                break;
                
            case 4:
                printf("\n\033[32m3 - Supprimer une ligne \n\n\033[0m");

                //Entrée de l'index de la ligne 
                while(1){
                    printf("Entrez le numéro de la ligne à supprimer : ");
                    scanf("%d", &ind);
                    if (ind < 1 || ind > nb_lines) {
                        printf("Numéro invalide, réessayez\n");
                    }else{
                        break;
                    }
                }

                deleteLine(ind);
                saveData(nom_fichier);
                break;

            case 5:
                printf("Au revoir!\n");
                freeMemory();
                exit(0);

            default:
                printf("Option invalide. Veuillez réessayer.\n");
                break;
        }
    }

    return 0;
}