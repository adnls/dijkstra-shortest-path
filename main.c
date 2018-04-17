#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "initialisation.h"
#include "interface.h"

int main()
{
    configurer();

    int noeud_A, noeud_B;
    int NB_NOEUDS = get_nb_noeuds();
    //int NB_RUES = get_nb_rues();
    char liste_rues[get_nb_rues()][LONGUEUR_CHAMP];
    Rue graph[NB_NOEUDS][NB_NOEUDS];
    Noeud feuille_de_calcul[get_nb_noeuds()];

    initialiser_liste_rues(liste_rues);
    initialiser_graph(graph);
    initialiser_feuille_de_calcul(feuille_de_calcul);

    choisir_chemin(&noeud_A, &noeud_B, graph, liste_rues);

    printf("\n%d", noeud_A);
    printf("\n%d", noeud_B);

    //TODO implement dijkstra algorithm we've done => easiest part
    //Design menus and use r interactions better => output formating
    //implement search feature ? if we've the time..
    //find a way to configure with external data.. !! we have to
    //a pieds en voiture ... required
    //faire le makeFile ... required ++111111111111111
    //handle error cases
    //write the docs for teacher!!

    return 0;
}
