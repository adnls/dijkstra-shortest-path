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
        printf("> Menu\n");
        printf("1 - Trouver un plus court chemin\n");
        printf("2 - Revoir le chemin\n");
        printf("3 - Quitter\n");
        printf("\n> Entrez un chiffre :\n\n> ");
        scanf("%d", &choix_menu);
        fflush(stdin);

        switch(choix_menu)
        {
        case 1:

            initialiser_feuille_de_calcul(feuille_de_calcul);
            //mode = choisir_mode();
            choisir_chemin(&noeud_A, &noeud_B, graph, liste_rues);
            point_depart = NULL;
            find_path(noeud_A, noeud_B, graph, feuille_de_calcul);
            store_path(noeud_A, noeud_B, &point_depart, graph, feuille_de_calcul);
            afficher_chemin(point_depart, liste_rues);
            break;

        case 2:

            if (noeud_A!=-1) afficher_chemin(point_depart, liste_rues);
            break;

        case 3: default:
            break;
        }
    }
    //travailler presentation
    //features => menu loop
    //search street3
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
