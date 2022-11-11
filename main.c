#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "word.h"

int main() {

    t_noms nom;
    t_adjectifs adj;
    t_verbes ver;

    nom.nb_nom = 0;
    ver.nb_ver = 0;
    adj.nb_adj = 0;

    nom.list_nom = createList();
    ver.list_ver = createList();
    adj.list_adj = createList();
    read_line("test.txt",&nom,&ver,&adj);


    printf("NOM:\n");
    p_cell temp = nom.list_nom.head;
    while(temp != NULL)
    {
        printf("%s\n",temp->ws->mot);
        temp =temp->next;
    }

    printf("\nADJECTIFS:\n");

    p_cell temp2 = adj.list_adj.head;
    while(temp2 != NULL)
    {
        printf("%s\n",temp2->ws->mot);
        temp2 = temp2->next;
    }

    printf("\nVERBES:\n");
    p_cell temp3 = ver.list_ver.head;
    while(temp3 != NULL)
    {
        printf("%s\n",temp3->ws->mot);
        temp3 = temp3->next;
    }

}
