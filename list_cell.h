//
// Created by edema on 09/11/2022.
//

#ifndef PROJET_DICO_LIST_CELL_H
#define PROJET_DICO_LIST_CELL_H

typedef struct stockage
{
    char * mot;
    char * base;
    char * explain;

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



typedef struct nom
{
    int nb_f;
    t_ht_list liste_f;

}t_nom;


typedef struct adjectif
{
    int nb_f;
    t_ht_list liste_f;

}t_adj;

typedef struct verbe
{
    int nb_f;
    t_ht_list liste_f;
}t_ver;


struct categorie
{
    int nb_ff;
    t_ht_list liste_ff;

};

typedef struct categorie word_categorie;






t_ht_list IsEmpty();
p_cell createCell(p_word_stock);
void addHead(t_ht_list *, p_word_stock);
void addTail(t_ht_list * , p_word_stock);


#endif //PROJET_DICO_LIST_CELL_H
