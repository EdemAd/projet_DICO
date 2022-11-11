//
// Created by edema on 09/11/2022.
//

#include "list_cell.h"
#include <stdio.h>
#include <stdlib.h>



p_cell createCell(p_word_stock ws)
{
    p_cell new = malloc(sizeof(t_cell));
    new->next = NULL;
    new->ws = ws;

    return new;
}

t_ht_list createList()
{
    t_ht_list L;
    L.head = NULL;
    L.tail = NULL;
    return L;
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
    }
}
