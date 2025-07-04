#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/word.h"

#define MAX_LINES 1000

char** lines = NULL;
int nb_lines = 0;
int capacity = 10;

//Agrandissement du tableau
void growth() {
    if (nb_lines >= capacity) {
        capacity += 10;
        char** temp = realloc(lines, capacity * sizeof(char*));
        lines = temp;
    }
}

//Charge du fichier
void loadFile(const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (!fichier) {
        printf("Fichier inexistant.\n");
        return;
    }

    char read_lines[MAX_LINES];
    lines = malloc(sizeof(char*) * capacity);
    while (fgets(read_lines, MAX_LINES, fichier)) {
        growth();
        lines[nb_lines] = malloc(strlen(read_lines) + 1);
        strcpy(lines[nb_lines], read_lines);
        nb_lines++;
    }
    fclose(fichier);
}

//Affichage des lignes 
void showLines() {
    printf("\n----------- Contenu du fichier -----------\n");
    for (int i = 0; i < nb_lines; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }
    printf("\n------------------------------------------\n");
}

//Ajout d'une ligne
void addLine(const char* line) {
    growth();
    lines[nb_lines] = malloc(strlen(line) + 1);
    strcpy(lines[nb_lines], line);
    nb_lines++;
}

//Edition d'une ligne
void editLine(int index, const char* line) {
    free(lines[index - 1]);
    lines[index - 1] = malloc(strlen(line) + 1);
    strcpy(lines[index - 1], line);
}

//Suppression d'une ligne
void deleteLine(int index) {
    free(lines[index - 1]);
    for (int i = index - 1; i < nb_lines - 1; i++) {
        lines[i] = lines[i + 1];
    }
    nb_lines--;
}

//Sauvegarde des modifications
void saveData(const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "w");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < nb_lines; i++) {
        fputs(lines[i], fichier);
    }
    fclose(fichier);
}

//Libération de la mémoire
void freeMemory() {
    for (int i = 0; i < nb_lines ; i++) {
        free(lines[i]);
    }
}