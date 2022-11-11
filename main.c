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


    printf("NOM (%d):\n",nom.nb_nom);
    p_cell temp = nom.list_nom.head;
    while(temp != NULL)
    {
        read_nom(&nom,temp->ws);
        printf("%s:\n",nom.mot);
        printf("\t-%s\n",nom.genre);
        printf("\t-%s\n",nom.accord);
        printf("\n");

        temp =temp->next;
    }

    printf("ADJECTIFS (%d):\n",adj.nb_adj);


    p_cell temp2 = adj.list_adj.head;
    while(temp2 != NULL)
    {
        read_adj(&adj,temp2->ws);
        printf("%s:\n",adj.mot);
        printf("\t-%s\n",adj.genre);
        printf("\t-%s\n",adj.accord);
        printf("\n");
        temp2 = temp2->next;
    }

    printf("VERBES (%d):\n",ver.nb_ver);
    p_cell temp3 = ver.list_ver.head;
    while(temp3 != NULL)
    {
        printf("%s\n",temp3->ws->mot);
        temp3 = temp3->next;
    }

}
