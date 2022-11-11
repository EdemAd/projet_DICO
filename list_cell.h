//
// Created by edema on 09/11/2022.
//

#ifndef PROJET_DICO_LIST_CELL_H
#define PROJET_DICO_LIST_CELL_H

#define MAX_SIZE_WORD 30

typedef struct stockage
{
    char mot[MAX_SIZE_WORD];
    char base[MAX_SIZE_WORD];
    char explain[MAX_SIZE_WORD];

} word_stock, * p_word_stock;


struct s_cell
{
    p_word_stock ws;
    struct s_cell * next;
};
typedef struct s_cell t_cell, *p_cell;

struct s_ht_list
{
    p_cell head;
    p_cell tail;
};
typedef struct s_ht_list t_ht_list;




//------------------------------------------------------------------------------------------------------------------------------------------------

typedef struct adj
{
    char mot[MAX_SIZE_WORD];
    char genre[MAX_SIZE_WORD];
    char accord[MAX_SIZE_WORD];
    int nb_adj;
    t_ht_list list_adj;

}t_adjectifs, * p_adjectifs;

typedef struct ver
{
    int nb_ver;
    t_ht_list list_ver;

}t_verbes, * p_verbes;

typedef struct nom
{
    int nb_nom;
    t_ht_list list_nom;

}t_noms, *p_noms;



//------------------------------------------------------------------------------------------------------------------------------------------------------



typedef struct s_node_nom
{
    p_noms noms;
    struct s_node_nom * tab[26];

} t_node_nom, * p_node_nom;

typedef struct s_node_ver
{
    p_verbes verbes;
    struct s_node_ver * tab[26];

} t_node_ver, * p_node_ver;

typedef struct s_node_adj
{
    p_adjectifs adjectifs;
    struct s_node_adj* tab[26];

} t_node_adj, * p_node_adj;


//------------------------------------------------------------------------------------------------------------------------------------------------------

p_cell createCell(p_word_stock ws);
t_ht_list createList();
void addTail(t_ht_list * list, p_word_stock ws);
#endif //PROJET_DICO_LIST_CELL_H
