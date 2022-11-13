//
// Created by edema on 09/11/2022.
//

#ifndef PROJET_DICO_LIST_CELL_H
#define PROJET_DICO_LIST_CELL_H

#define MAX_SIZE_WORD 30

typedef struct node_verbe
{
    char val;
    struct cell_verbe* liste_fils;
    struct liste_fleche_verbe* f_fleche;
}node_verbe;

typedef struct cell_verbe
{
    struct node_verbe* val;
    struct cell_verbe* next;
}cell_verbe;

typedef struct liste_fleche_verbe
{
    struct forme_fleche_verbe *val;
    struct liste_fleche_verbe* next;

}liste_fleche_verbe;

typedef struct forme_fleche_verbe
{
    char *forme;
    int nb;
    int personne;
    char* forme_flechie;

}forme_fleche_verbe;

typedef struct tree_verbe
{
    node_verbe root;

}tree_verbe;

///--------------------------------------------------nom----------------------------------------------------------------

typedef struct node_nom
{
    char val;
    struct cell_nom* liste_fils;
    struct liste_fleche_nom* f_fleche;
}node_nom;

typedef struct cell_nom
{
    struct node_nom* val;
    struct cell_nom* next;
}cell_nom;

typedef struct liste_fleche_nom
{
    struct forme_fleche_nom *val;
    struct liste_fleche_nom* next;

}liste_fleche_nom;

typedef struct forme_fleche_nom
{
    int nb;
    int personne;
    char* forme_flechie;

}forme_fleche_nom;


typedef struct tree_nom
{
    node_nom root;

}tree_nom;

///-----------------------------------------------------------------------Adverbe------------------------------------

typedef struct node_adv
{
    char val;
    struct cell_adv* liste_fils;
    int fin_mot;
}node_adv;

typedef struct cell_adv
{
    struct node_adv* val;
    struct cell_adv* next;
}cell_adv;

typedef struct tree_adv
{
    node_adv root;

}tree_adv;

///--------------------------------------------------------------------------adjectif-------------------------------

typedef struct node_adj
{
    char val;
    struct cell_adj* liste_fils;
    struct liste_fleche_adj* f_fleche;
}node_adj;

typedef struct cell_adj
{
    struct node_adj* val;
    struct cell_adj* next;
}cell_adj;

typedef struct liste_fleche_adj
{
    struct forme_fleche_adj *val;
    struct liste_fleche_adj* next;

}liste_fleche_adj;

typedef struct forme_fleche_adj
{
    int nb;
    int personne;
    char* forme_flechie;
}forme_fleche_adj;

typedef struct tree_adj
{
    node_adj root;

}tree_adj;


#endif //PROJET_DICO_LIST_CELL_H
