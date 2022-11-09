//
// Created by edema on 09/11/2022.
//

#include "word.h"
#define MAX_WORD_SIZE  100

p_word_stock create_ws()
{
    p_word_stock ws;

    ws = malloc(sizeof(word_stock));

    ws->mot = malloc(30*sizeof(char));
    ws->base = malloc(30*sizeof(char));
    ws->explain = malloc(30*sizeof(char));

    return  ws;
}


void read_word( char * file_name, word_categorie * c_adj, word_categorie * c_nom, word_categorie * c_ver )
{

    FILE * dico = fopen(file_name,"r");

    char line[MAX_WORD_SIZE];
    char delim[] = "\t \0\n";

    while (fgets(line,MAX_WORD_SIZE,dico) != NULL)
    {
        p_word_stock  ws = create_ws();

        ws->mot = strtok(line,delim);
        ws->base = strtok(NULL,delim);
        ws->explain = strtok(NULL,"\n");

        char  *categorie;

        for(int i = 0; i<3; i++)
        {
            categorie[i] = ws->explain[i];
        }

        printf("%s\n",ws->mot);
        printf("%s\n",ws->base);
        printf("%s\n",ws->explain);
        printf("%s\n\n",categorie);

        if(strcmp(categorie,"Nom")==0)
        {
            printf("2\n");
            addTail(&c_nom->liste_ff,ws);
            c_nom->nb_ff++;
        }
        else if(strcmp(categorie,"Ver")==0)
        {
            printf("3\n");
            addTail(&c_ver->liste_ff,ws);
            c_ver->nb_ff++;

        }
        else if(strcmp(categorie,"Adj")==0)
        {
            printf("4\n");
            addTail(&c_adj->liste_ff,ws);
            c_adj->nb_ff++;
        }
        else
        {
            printf("1\n");
        }

    }
    fclose(dico);

}



void read_categorie(word_categorie wc)
{

    printf("Il y a %d mots dans cette categorie\n",wc.nb_ff);

    if( wc.liste_ff.head == NULL)
    {
        printf("liste vide");
    }

    else if((wc.liste_ff.head != NULL)&&(wc.liste_ff.tail == wc.liste_ff.head))
    {
        p_cell temp = wc.liste_ff.head;
        char mot[30];
        int i = 0;

        while((temp->ws->mot[i]) != '\0')
        {
            mot[i] = temp->ws->mot[i];
            i++;
        }
        printf("%s \n",mot);

    }
    else
    {
        p_cell temp = wc.liste_ff.head;
        while(temp != NULL)
        {
            char mot[30];
            int i = 0;

            while((temp->ws->mot[i]) != '\0')
            {
                mot[i] = temp->ws->mot[i];
                i++;
            }
            printf("%s \n",mot);
            temp = temp->next;
        }
    }



}





/* while (fgets(line,MAX_WORD_SIZE,dico) != NULL)
 {
     p_word_stock ws = create_ws();
     int cpt = 0;


     char * mot = strtok(line,delim);
     cpt++;
     ws->mot = mot;

     while( mot != NULL)
     {
         mot = strtok(NULL,delim);
         cpt++;
         if(cpt == 2)
         {
             ws->base = mot;
         }
         else if(cpt == 3)
         {
             ws->explain = mot;
         }
     }

     for(int i = 0; i<3; i++)
     {
         char * mot = strtok(line,delim);
         ws->mot = mot;

     }



     printf("NEW LINE\n");
 }*/

