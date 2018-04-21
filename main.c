#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "initialisation.h"
#include "interface.h"
#include "dijkstra.h"

int main()
{
    configurer_programme();

    int noeud_A = -1, noeud_B = -1, mode = -1, choix_menu = -1;
    int NB_NOEUDS = get_nb_noeuds();
    char liste_rues[get_nb_rues()][LONGUEUR_CHAMP];
    Rue graph[NB_NOEUDS][NB_NOEUDS];
    Noeud feuille_de_calcul[get_nb_noeuds()];
    Etape *point_depart = NULL;

    initialiser_liste_rues(liste_rues);
    initialiser_graph(graph);

    while (choix_menu != 3)
    {
        afficher_menu();
        scanf("%d", &choix_menu);
        fflush(stdin);

        switch(choix_menu)
        {
        case 1:

            point_depart = NULL;
            initialiser_feuille_de_calcul(feuille_de_calcul);
            //mode = choisir_mode();
            choisir_chemin(&noeud_A, &noeud_B, graph, liste_rues);
            find_path(noeud_A, noeud_B, graph, feuille_de_calcul);
            store_path(noeud_A, noeud_B, &point_depart, graph, feuille_de_calcul);
            afficher_chemin(point_depart, liste_rues, noeud_A, noeud_B);
            break;

        case 2:

            if (noeud_A!=-1) afficher_chemin(point_depart, liste_rues, noeud_A, noeud_B);
            break;

        case 3: default:
            break;
        }
    }
    return 0;
}
