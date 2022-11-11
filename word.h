//
// Created by edema on 09/11/2022.
//

#ifndef PROJET_DICO_WORD_H
#define PROJET_DICO_WORD_H


#include "list_cell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_SIZE 150

void read_line(char *,p_noms, p_verbes, p_adjectifs);
void read_nom(p_noms,p_word_stock);
void read_adj(p_adjectifs, p_word_stock );
void read_ver(p_verbes, p_word_stock);



#endif //PROJET_DICO_WORD_H
