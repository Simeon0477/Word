#ifndef _WORD_H
#define _WORD_H

extern char** lines;
extern int nb_lines;
extern int capacity;

void growth();
void loadFile(const char* nom_fichier);
void showLines();
void addLine(const char* line);
void editLine(int index, const char* line);
void deleteLine(int index);
void saveData(const char* nom_fichier);
void freeMemory();

#endif