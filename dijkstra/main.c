#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "initialisation.h"
#include "interface.h"
#include "dijkstra.h"

int main()
{
    configurer_programme();

    int noeud_A = INFINI, noeud_B = INFINI, mode = INFINI, choix_menu = INFINI;
    int NB_NOEUDS = get_nb_noeuds();
    int NB_RUES = get_nb_rues();
    char liste_rues[NB_RUES][LONGUEUR_CHAMP];
    Rue graph_voiture[NB_NOEUDS][NB_NOEUDS];
    Rue graph_apieds[NB_NOEUDS][NB_NOEUDS];
    Noeud feuille_de_calcul[NB_NOEUDS];
    Etape *point_depart = NULL;

    initialiser_liste_rues(liste_rues, "liste-rues.csv");
    initialiser_graph(graph_apieds, "graph-a-pieds.csv");
    initialiser_graph(graph_voiture, "graph-en-voiture.csv");

    while (choix_menu != 3)
    {
        afficher_menu();
        scanf("%d", &choix_menu);

        switch(choix_menu)
        {
        case 1:

            point_depart = NULL;
            initialiser_feuille_de_calcul(feuille_de_calcul);

            mode = choisir_mode();

	    choisir_chemin(&noeud_A, &noeud_B, graph_apieds, liste_rues);
               
            if (mode == 1)
            {
                trouver_chemin(noeud_A, noeud_B, graph_apieds, feuille_de_calcul);
                stocker_chemin(noeud_A, noeud_B, &point_depart, graph_apieds, feuille_de_calcul);
            }
            else
            {
                trouver_chemin(noeud_A, noeud_B, graph_voiture, feuille_de_calcul);
                stocker_chemin(noeud_A, noeud_B, &point_depart, graph_voiture, feuille_de_calcul);
            
            }
	    afficher_chemin(point_depart, noeud_B, liste_rues, noeud_A, noeud_B, graph_apieds, mode);
            break;

        case 2:

            if (noeud_A!=INFINI)
                afficher_chemin(point_depart, noeud_B, liste_rues, noeud_A, noeud_B, graph_apieds, mode);
            
            break;

        case 3: dire_au_revoir();
            break;

        default: break;
        }
    }
    return 0;
}
