//
// Created by edema on 09/11/2022.
//
#include "word.h"
#include "list_cell.h"





void readline (char* filename)
{
    FILE * dico = fopen(filename,"r");

    char line[MAX_LINE_SIZE];
    char delim[] ="\t \0\n";

    tree_adv *treeAdv;
    tree_verbe *treeVerbe;
    tree_nom *treeNom;
    tree_adj *treeAdj;
    treeAdv->root.liste_fils=NULL;
    treeVerbe->root.liste_fils=NULL;
    treeNom->root.liste_fils=NULL;
    treeAdj->root.liste_fils=NULL;


    while(fgets(line,MAX_LINE_SIZE,dico) != NULL) {
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
            add_nom(ws,treeNom);



        } else if (strcmp(categorie, "Ver") == 0) {
            add_verbe(ws,treeVerbe);



        } else if (strcmp(categorie, "Adj") == 0) {
            add_adj(ws,treeAdj);


        }else if (strcmp(categorie, "Adv") == 0) {
            add_adv(ws,treeAdv);


        }


    }

}




///-----------------------------------adverbe -------------------------------------------------------------------

void add_adv(p_word_stock ws,tree_adv *tree){

    int cmpt=0,fin=0;
    node_adv node=create_node_adv(ws,cmpt);

    cell_adv *tmp;

    if (tree->root.liste_fils==NULL){
        tmp->val=&node;
        tree->root.liste_fils = tmp;
    }
    else
    {
        tmp = tree->root.liste_fils;
        while(fin==0) {
            if (tmp->val->val == node.val)
            {
                fin = 1;
            }
            else {
                if (tmp->next == NULL) {

                    tmp->next=(cell_adv*)malloc(sizeof(cell_adv));
                    tmp->next->val = &node;
                    fin=1;
                    tmp=tmp->next;
                }
            }
        }
    }
    cmpt++;
    while (ws->base[cmpt]!='\0')
    {
        tmp=tmp->val->liste_fils;
        fin=0;
        while (tmp->next!=NULL&&fin==0)
        {
            if (tmp->val->val==ws->base[cmpt])
            {
                fin=1;
            }
            else {
                tmp = tmp->next;
            }
        }
        if (fin==0&&tmp->val->val!=ws->base[cmpt])
        {
            node=create_node_adv(ws,cmpt);
            tmp->val= &node;
        }

        cmpt++;
    }
}

node_adv create_node_adv(p_word_stock ws,int cmpt)
{
    node_adv new;
    new.val=ws->base[cmpt];
    new.liste_fils=NULL;
    if (ws->base[cmpt+1]=='\0')
    {
        new.fin_mot=1;
    }
    return new;
}

////-----------------------------------------------------------------adj-------------------------------------------------
void add_adj(p_word_stock ws,tree_adj *tree){

    int cmpt=0,fin=0;
    node_adj node=create_node_adj(ws,cmpt);

    cell_adj *tmp;

    if (tree->root.liste_fils==NULL){
        tmp->val=&node;
        tree->root.liste_fils = tmp;
    }
    else
    {
        tmp = tree->root.liste_fils;
        while(fin==0) {
            if (tmp->val->val == node.val)
            {
                fin = 1;
            }
            else {
                if (tmp->next == NULL) {

                    tmp->next = (cell_adj*)malloc(sizeof(cell_adj));
                    tmp->next->val = &node;
                    fin=1;
                    tmp=tmp->next;
                }
            }
        }
    }
    cmpt++;
    while (ws->base[cmpt]!='\0')
    {
        tmp=tmp->val->liste_fils;
        fin=0;
        while (tmp->next!=NULL&&fin==0)
        {
            if (tmp->val->val==ws->base[cmpt])
            {
                fin=1;
                if (ws->base[cmpt+1]=='\0')
                {
                    add_forme_flechie_adj(tmp->val,ws);

                }


            }
            else {
                tmp = tmp->next;
            }
        }
        if (fin==0&&tmp->val->val!=ws->base[cmpt])
        {
            node=create_node_adj(ws,cmpt);
            tmp->val= &node;
        }
        cmpt++;
    }

}

node_adj create_node_adj(p_word_stock ws,int cmpt)
{
    node_adj new;
    new.val=ws->base[cmpt];
    new.liste_fils=NULL;
    if (ws->base[cmpt+1]=='\0')
    {
        add_forme_flechie_adj(&new,ws);
    }
    return new;
}

void add_forme_flechie_adj(node_adj *new,p_word_stock ws)
{
    liste_fleche_adj *nouv;
    nouv->next=NULL;
    int cmpt=0;

    liste_fleche_adj *tmp;
    nouv=(liste_fleche_adj*)malloc(sizeof(liste_fleche_adj));

    while (ws->mot[cmpt]!='\0')
    {
        nouv->val->forme_flechie[cmpt]=ws->mot[cmpt];
    }
    while (ws->explain[cmpt]!=':'){
        cmpt++;
    }
    cmpt++;
    switch (ws->explain[cmpt])
    {
        case 'M':
            nouv->val->personne=1;
            break;
        case 'F':
            nouv->val->personne=2;
            break;
        case 'I':
            nouv->val->personne=3;
            break;
    }
    while (ws->explain[cmpt]!='+'){
        cmpt++;
    }
    cmpt++;
    switch (ws->explain[cmpt])
    {
        case 'S':
            nouv->val->nb=4;
            break;
        case 'P' :
            nouv->val->nb=5;
            break;
        case 'I':
            nouv->val->nb=6;
            break;
    }



    if (new->f_fleche==NULL)
    {
        new->f_fleche=nouv;
    }
    else
    {
        tmp=new->f_fleche;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=nouv;
    }
}


///------------------------------------------------------nom-(-----------------------------------------------------
void add_nom(p_word_stock ws,tree_nom *tree){

    int cmpt=0,fin=0;
    node_nom node=create_node_nom(ws,cmpt);

    cell_nom *tmp;

    if (tree->root.liste_fils==NULL){
        tmp->val=&node;
        tree->root.liste_fils = tmp;
    }
    else
    {
        tmp = tree->root.liste_fils;
        while(fin==0) {
            if (tmp->val->val == node.val)
            {
                fin = 1;
            }
            else {
                if (tmp->next == NULL) {

                    tmp->next = (cell_nom*)malloc(sizeof(cell_nom));
                    tmp->next->val = &node;
                    fin=1;
                    tmp=tmp->next;
                }
            }
        }
    }
    cmpt++;
    while (ws->base[cmpt]!='\0')
    {
        tmp=tmp->val->liste_fils;
        fin=0;
        while (tmp->next!=NULL&&fin==0)
        {
            if (tmp->val->val==ws->base[cmpt])
            {
                fin=1;
                if (ws->base[cmpt+1]=='\0')
                {
                    add_forme_flechie_nom(tmp->val,ws);

                }


            }
            else {
                tmp = tmp->next;
            }
        }
        if (fin==0&&tmp->val->val!=ws->base[cmpt])
        {
            node=create_node_nom(ws,cmpt);
            tmp->val= &node;
        }
        cmpt++;
    }

}

node_nom create_node_nom(p_word_stock ws,int cmpt)
{
    node_nom new;
    new.val=ws->base[cmpt];
    new.liste_fils=NULL;
    if (ws->base[cmpt+1]=='\0')
    {
        add_forme_flechie_nom(&new,ws);
    }
    return new;
}

void add_forme_flechie_nom(node_nom *new,p_word_stock ws)
{
    liste_fleche_nom *nouv;
    nouv->next=NULL;
    int cmpt=0;

    liste_fleche_nom *tmp;
    nouv=(liste_fleche_nom*)malloc(sizeof(liste_fleche_nom));

    while (ws->mot[cmpt]!='\0')
    {
        nouv->val->forme_flechie[cmpt]=ws->mot[cmpt];
    }
    while (ws->explain[cmpt]!=':'){
        cmpt++;
    }
    cmpt++;
    switch (ws->explain[cmpt])
    {
        case 'M':
            nouv->val->personne=1;
            break;
        case 'F':
            nouv->val->personne=2;
            break;
        case 'I':
            nouv->val->personne=3;
            break;
    }
    while (ws->explain[cmpt]!='+'){
        cmpt++;
    }
    cmpt++;
    switch (ws->explain[cmpt])
    {
        case 'S':
            nouv->val->nb=4;
            break;
        case 'P' :
            nouv->val->nb=5;
            break;
        case 'I':
            nouv->val->nb=6;
            break;
    }



    if (new->f_fleche==NULL)
    {
        new->f_fleche=nouv;
    }
    else
    {
        tmp=new->f_fleche;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=nouv;
    }

}



///----------------------------------------------------------verbe----------------------------------------------------

void add_verbe(p_word_stock ws,tree_verbe *tree){

    int cmpt=0,fin=0;
    node_verbe node=create_node_verbe(ws,cmpt);

    cell_verbe *tmp;

    if (tree->root.liste_fils==NULL){
        tmp->val=&node;
        tree->root.liste_fils = tmp;
    }
    else
    {
        tmp = tree->root.liste_fils;
        while(fin==0) {
            if (tmp->val->val == node.val)
            {
                fin = 1;
            }
            else {
                if (tmp->next == NULL) {

                    tmp->next = (cell_verbe*)malloc(sizeof(cell_verbe));
                    tmp->next->val = &node;
                    fin=1;
                    tmp=tmp->next;
                }
            }
        }
    }
    cmpt++;
    while (ws->base[cmpt]!='\0')
    {
        tmp=tmp->val->liste_fils;
        fin=0;
        while (tmp->next!=NULL&&fin==0)
        {
            if (tmp->val->val==ws->base[cmpt])
            {
                fin=1;
                if (ws->base[cmpt+1]=='\0')
                {
                    add_forme_flechie_verbe(tmp->val,ws);

                }



            }
            else {
                tmp = tmp->next;
            }
        }
        if (fin==0&&tmp->val->val!=ws->base[cmpt])
        {
            node=create_node_verbe(ws,cmpt);
            tmp->val= &node;
        }
        cmpt++;
    }

}

node_verbe create_node_verbe(p_word_stock ws,int cmpt)
{
    node_verbe new;
    new.val=ws->base[cmpt];
    new.liste_fils=NULL;
    if (ws->base[cmpt+1]=='\0')
    {
        add_forme_flechie_verbe(&new,ws);
    }
    return new;
}

void add_forme_flechie_verbe(node_verbe *new,p_word_stock ws)
{
    liste_fleche_verbe *nouv;
    int cmpt=0;
    liste_fleche_verbe *tmp;
    while (ws->explain[cmpt]!=':'){
        cmpt++;
    }




        nouv=(liste_fleche_verbe*)malloc(sizeof(liste_fleche_verbe));
        while (ws->mot[cmpt]!='\0')
        {
            nouv->val->forme_flechie[cmpt]=ws->mot[cmpt];
        }
        cmpt++;
        switch (ws->explain[cmpt])
        {
            case 'M':
                nouv->val->personne=1;
                break;
            case 'F':
                nouv->val->personne=2;
                break;
            case 'I':
                nouv->val->personne=3;
                break;
        }
        while (ws->explain[cmpt]!='+'){
            cmpt++;
        }
        cmpt++;
        switch (ws->explain[cmpt])
        {
            case 'S':
                nouv->val->nb=4;
                break;
            case 'P' :
                nouv->val->nb=5;
                break;
            case 'I':
                nouv->val->nb=6;
                break;
        }



        if (new->f_fleche==NULL)
        {
            new->f_fleche=nouv;
        }
        else
        {
            tmp=new->f_fleche;
            while(tmp->next!=NULL)
            {
                tmp=tmp->next;
            }
            tmp->next=nouv;
        }

}



