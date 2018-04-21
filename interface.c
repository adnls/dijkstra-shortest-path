#include "structures.h"
#include "csv.h"
#include "initialisation.h"
//#include "strplus.h"
//#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void afficher_rues(char(*)[]);
int choisir_noeud(int, Rue(*)[], char(*)[]);
void nettoyer_ecran();
void entree_pour_continuer();

void choisir_chemin(int* noeud_A, int* noeud_B, Rue graph[][get_nb_noeuds()], char liste_rues[][LONGUEUR_CHAMP])
{
    int id_rue;
    nettoyer_ecran();
    printf("\n> Trouvez votre point de depart\n");
    afficher_rues(liste_rues);
    printf("\n\n> Entrez un chiffre :\n\n> ");
    scanf("%d", &id_rue);
    fflush(stdin);
    id_rue--;

    printf("\n%s\n", liste_rues[id_rue]);
    (*noeud_A) = choisir_noeud(id_rue, graph, liste_rues);
    //printf("zzzzzzzzzzzzzzzzzz %d", (*noeud_A));

    nettoyer_ecran();
    printf("\n> Trouvez votre point d'arrivee!\n");
    afficher_rues(liste_rues);
    printf("\n\n> Entrez un chiffre :\n\n> ");
    scanf("%d", &id_rue);
    fflush(stdin);
    id_rue--;

    printf("\n%s\n", liste_rues[id_rue]);
    (*noeud_B) = choisir_noeud(id_rue, graph, liste_rues);

}

void afficher_rues(char liste_rues[][LONGUEUR_CHAMP])
{
    int nb_rues = get_nb_rues();

    for(int i = 0; i<nb_rues; i++)
    {
        printf("\n%d - %s", (i+1), liste_rues[i]);
    }
}

int choisir_noeud(int id_rue, Rue graph[][get_nb_noeuds()], char liste_rues[][LONGUEUR_CHAMP])
{
    int choix = 0;
    int nb_noeuds = get_nb_noeuds();
    int propositions[nb_noeuds];
    int l = 0;
    int compteur;

    while (choix < 1 || choix > l){

        l = 0;
        nettoyer_ecran();

        printf("> Choisissez une intersection\n");

        for (int i = 0; i<nb_noeuds; i++)
        {
            compteur = 0;

            for (int j = 0; j < nb_noeuds; j++)
            {
                //printf("\n%d %d", i, j);

                if (graph[i][j].id_rue == id_rue && compteur == 0)
                {
                    printf("\n%d - Intersection de : " , l+1);

                    for (int k = 0; k <nb_noeuds; k++)
                    {
                        if (graph[i][k].distance != INFINI)
                        {
                            printf("\n - %s", liste_rues[graph[i][k].id_rue]);
                        }
                    }
                    propositions[l] = i;
                    l++;
                    compteur++;
                }
            }
        }

        printf("\n\n> Entrez un  chiffre :\n\n> ");
        scanf("%d", &choix);
        fflush(stdin);
    }
    //printf("\nvous avez choisi le noeud numero : %d", propositions[choix-1]);
    return propositions[choix-1];
}


void afficher_chemin(Etape* point_depart, char liste_rues[][LONGUEUR_CHAMP], int noeud_A, int noeud_B)
{
    int i=0, distance_totale = 0;
    Etape *tmp=point_depart;

    nettoyer_ecran();

    while (tmp!=NULL)
    {
        printf("\nEtape %d - %s : %d metres", i+1, liste_rues[tmp->id_rue], tmp->distance);
        distance_totale += tmp->distance;
        i++;

        tmp = tmp->prochaine;
    }

    printf("\n\nDistance totale : %d metres", distance_totale);
    entree_pour_continuer();
}

int choisir_mode()
{
    int reponse = 0;

    while (reponse != 1 && reponse != 2)
    {
        printf("\n> Choisissez un mode: \n");
        printf("\n1 - A pieds");
        printf("\n2 - En voiture\n\n> ");
        scanf("%d", &reponse);
        fflush(stdin);
    };

    return reponse;
}

void afficher_menu()
{
        nettoyer_ecran();
        printf("> Menu\n\n");
        printf("1 - Trouver un plus court chemin\n");
        printf("2 - Revoir le chemin\n");
        printf("3 - Quitter\n");
        printf("\n> Entrez un chiffre :\n\n> ");
}

void nettoyer_ecran()
{
    for (int i = 0; i < 20; i++) printf("\n");
}

void entree_pour_continuer()
{
    printf("\n\n> Appuyez sur entree pour coninuer\n\n> ");
    getchar();
    fflush(stdin);
}


int est_dans_la_liste(int valeur, int liste[get_nb_rues()])
{
    int drapeau = 0, i = 0;

    while (!drapeau)
    {
        if (liste[i++]==valeur) drapeau = 1;
    }
    return drapeau;
}
