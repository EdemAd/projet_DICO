//
// Created by edema on 09/11/2022.
//
#include "word.h"
#include "list_cell.h"





void read_line(char * filename, p_noms noms, p_verbes verbes, p_adjectifs adjectifs)
{
    FILE * dico = fopen(filename,"r");

    char line[MAX_LINE_SIZE];
    char delim[] ="\t \0\n";



    while(fgets(line,MAX_LINE_SIZE,dico) != NULL)
    {
        p_word_stock ws = malloc(sizeof(word_stock));

        strcpy(ws->mot, strtok(line, delim));
        strcpy(ws->base, strtok(NULL, delim));
        strcpy(ws->explain, strtok(NULL, "\n"));

        char categorie[4];

        for (int i = 0; i < 3; i++) {
            categorie[i] = ws->explain[i];
        }

        categorie[3] ='\0';


        if (strcmp(categorie, "Nom") == 0) {

            addTail(&noms->list_nom,ws);
            noms->nb_nom++;

        } else if (strcmp(categorie, "Ver") == 0) {

            addTail(&verbes->list_ver,ws);
            verbes->nb_ver++;

        } else if (strcmp(categorie, "Adj") == 0) {
            addTail(&adjectifs->list_adj,ws);
            adjectifs->nb_adj++;

        }
        

    }
    fclose(dico);

}

void read_nom(p_noms noms, p_word_stock ws)
{
    strcpy(noms->mot,ws->mot);

    char delim[] =":+\n\0\t";

    char explain1[MAX_SIZE_WORD];
    char explain2[MAX_SIZE_WORD];

    strtok(ws->explain,delim);
    strcpy(explain1,strtok(NULL,delim));
    strcpy(explain2,strtok(NULL,delim));


    if(strcmp(explain1,"Mas\0")==0)
    {

        strcpy(noms->genre,"Masculin");
    }
    else if(strcmp(explain1,"Fem\n")==0)
    {
        strcpy(noms->genre,"Feminin");
    }
    else if(strcmp(explain1,"InvGen\0")==0)
    {
        strcpy(noms->genre,"InvariableGenre");
    }

    if(strcmp(explain2,"SG\0")==0)
    {
        strcpy(noms->accord,"Singulier");
    }
    else if(strcmp(explain1,"PL\0")==0)
    {
        strcpy(noms->accord,"Pluriel");
    }

}


void read_adj(p_adjectifs adj, p_word_stock ws)
{
    strcpy(adj->mot,ws->mot);

    char delim[] =":+\n\0\t";

    char explain1[MAX_SIZE_WORD];
    char explain2[MAX_SIZE_WORD];

    strtok(ws->explain,delim);
    strcpy(explain1,strtok(NULL,delim));
    strcpy(explain2,strtok(NULL,delim));


    if(strcmp(explain1,"Mas\0")==0)
    {

        strcpy(adj->genre,"Masculin");
    }
    else if(strcmp(explain1,"Fem\n")==0)
    {
        strcpy(adj->genre,"Feminin");
    }
    else if(strcmp(explain1,"InvGen\0")==0)
    {
        strcpy(adj->genre,"InvariableGenre");
    }

    if(strcmp(explain2,"SG\0")==0)
    {
        strcpy(adj->accord,"Singulier");
    }
    else if(strcmp(explain1,"PL\0")==0)
    {
        strcpy(adj->accord,"Pluriel");
    }

}


