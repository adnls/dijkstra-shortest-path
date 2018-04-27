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
    Rue graph_voiture[NB_NOEUDS][NB_NOEUDS];
    Rue graph_apieds[NB_NOEUDS][NB_NOEUDS];
    Noeud feuille_de_calcul[get_nb_noeuds()];
    Etape *point_depart = NULL;

    initialiser_liste_rues(liste_rues);

    initialiser_graph(graph_apieds, "graph_20noeuds_apieds.txt");
    initialiser_graph(graph_voiture, "graph_20noeuds_voiture.txt");

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

            mode = choisir_mode();

            if (mode == 1)
            {
                choisir_chemin(&noeud_A, &noeud_B, graph_apieds, liste_rues);
                find_path(noeud_A, noeud_B, graph_apieds, feuille_de_calcul);
                store_path(noeud_A, noeud_B, &point_depart, graph_apieds, feuille_de_calcul);
                afficher_chemin(point_depart, liste_rues, noeud_A, noeud_B, graph_apieds, mode);
            }
            else
            {
                //gros trap...
                choisir_chemin(&noeud_A, &noeud_B, graph_apieds, liste_rues);
                find_path(noeud_A, noeud_B, graph_voiture, feuille_de_calcul);
                store_path(noeud_A, noeud_B, &point_depart, graph_voiture, feuille_de_calcul);
                afficher_chemin(point_depart, liste_rues, noeud_A, noeud_B, graph_apieds, mode);
            }
            break;

        case 2:

            if (noeud_A!=-1)
            {
                mode == 1 ?
                afficher_chemin(point_depart, liste_rues, noeud_A, noeud_B, graph_apieds, mode)
                :
                afficher_chemin(point_depart, liste_rues, noeud_A, noeud_B, graph_apieds, mode);
            }
            break;

        case 3: dire_au_revoir();
            break;

        default: break;
        }
    }
    return 0;
}
