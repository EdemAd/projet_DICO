#include <stdio.h>
#include <stdlib.h>
#include "word.h"
#include "list_cell.h"


int main() {

    word_categorie cat_adj;
    cat_adj.nb_ff = 0;
    cat_adj.liste_ff = IsEmpty();

    word_categorie cat_ver;
    cat_ver.nb_ff = 0;
    cat_ver.liste_ff = IsEmpty();

    word_categorie cat_nom;
    cat_nom.nb_ff = 0;
    cat_nom.liste_ff = IsEmpty();

    read_word("test.txt",&cat_adj,&cat_nom,&cat_ver);

    read_categorie(cat_nom);

    printf("%s",cat_nom.liste_ff.head->ws->mot);

    return 0;
}
