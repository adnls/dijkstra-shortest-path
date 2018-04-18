#include <stdio.h>
#include "structures.h"

#ifndef INITIALISATION
#define INITIALISATION

int get_nb_noeuds();
int get_nb_rues();
void configurer_programme(); //va chercher le nb rues et le nb noeuds tout simplement
//TODO recursive version, menu, implement search bar, complete UI
void initialiser_graph(Rue(*)[]);
void initialiser_feuille_de_calcul(Noeud[]);
void initialiser_liste_rues(char(*)[]);

#endif // INITIALISATION
