//
// Created by edema on 09/11/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "list_cell.h"
#include "word.h"



p_cell createCell(p_word_stock ws)
{
    p_cell p;
    p=(p_cell) malloc(sizeof(t_cell));
    p->next = NULL;
    p->ws = ws;
    return p;
}

t_ht_list IsEmpty()
{
    t_ht_list L;
    L.head=NULL;
    L.tail=NULL;
    return L;
}


void addHead(t_ht_list * list, p_word_stock ws)
{
    p_cell p = createCell(ws);
    if(list->head==NULL)
    {
        list->head=p;
        list->tail=p;
    }
    else
    {
        p->next=list->head;
        list->head=p;
        list->tail->next=p;
    }
}



void addTail(t_ht_list * list, p_word_stock ws)
{
    p_cell p = createCell(ws);
    if(list->head==NULL)
    {
        list->head=p;
        list->tail=p;
    }
    else
    {
        list->tail->next=p;
        list->tail=p;
        list->tail->next=list->head;
    }
}