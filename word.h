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


typedef struct word_stock
{
    char *mot;
    char *base;
    char *explain;
}word_stock,*p_word_stock;

///--------adv
node_adv create_node_adv(p_word_stockws,int cmpt);
void add_adv(p_word_stock ws,tree_adv *tree);
///--------adj
node_adj create_node_adj(p_word_stock ws,int cmpt);
void add_adj(p_word_stock ws,tree_adj *tree);
void add_forme_flechie_adj(node_adj *new,p_word_stock ws);
///------------nom
node_nom create_node_nom(p_word_stock ws,int cmpt);
void add_nom(p_word_stock ws,tree_nom *tree);
void add_forme_flechie_nom(node_nom *new,p_word_stock ws);
///---è------verbe
node_verbe create_node_verbe(p_word_stock ws,int cmpt);
void add_verbe(p_word_stock ws,tree_verbe *tree);
void add_forme_flechie_verbe(node_verbe *new,p_word_stock ws);
