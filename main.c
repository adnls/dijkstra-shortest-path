#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "initialisation.h"
#include "interface.h"
#include "dijkstra.h"

int main()
{
    //obtenir valeur des variables statiques
    //nb_noeuds, nb rues

    configurer_programme();

    int noeud_A, noeud_B;
    int NB_NOEUDS = get_nb_noeuds();
    char liste_rues[get_nb_rues()][LONGUEUR_CHAMP];
    Rue graph[NB_NOEUDS][NB_NOEUDS];
    Noeud feuille_de_calcul[get_nb_noeuds()];
    Etape *point_depart;

    initialiser_liste_rues(liste_rues);
    initialiser_graph(graph);

    choisir_chemin(&noeud_A, &noeud_B, graph, liste_rues);

    printf("\n- Noeud A => %d", noeud_A);
    printf("\n- Noeud B => %d", noeud_B);

    initialiser_feuille_de_calcul(feuille_de_calcul);

    point_depart = NULL;

    find_path(noeud_A, noeud_B, graph, feuille_de_calcul);
    store_path(noeud_A, noeud_B, &point_depart, graph, feuille_de_calcul);
    afficher_chemin(point_depart, liste_rues);

    //features => menu loop
    //search street
    //enable recursive version
    //pieds-voiture

    //Design menus and use r interactions better => output formating
    //implement search feature ? if we've the time..
    //find a way to configure with external data.. !! we have to
    //a pieds en voiture ... required
    //faire le makeFile ... oblige
    //handle error cases
    //write the docs for the teacher!!

    return 0;
}
