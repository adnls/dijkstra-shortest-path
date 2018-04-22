#include "structures.h"
#include "csv.h"
#include "initialisation.h"
//#include "strplus.h"oid
//#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void afficher_rues(char(*)[]);
int choisir_noeud(int, Rue(*)[], char(*)[]);
void nettoyer_ecran();
void entree_pour_continuer();
int est_dans_la_liste(int, int[], int);

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
    int nb_rues = get_nb_rues();
    int intersections[nb_rues];
    int propositions[nb_noeuds];
    int drapeau, j, compteur;
    int pos = 1;

    nettoyer_ecran();

    printf("> Choisissez une intersection\n");
    //printf("%d", nb_noeuds);

    for (int i = 0; i < nb_noeuds; i++)
    {
        drapeau = 0;
        j = 0;
        compteur = 0;

        while (!drapeau && j < nb_noeuds)
        {
            //printf("sfvsfv");
            if (graph[i][j].id_rue == id_rue)
            {
                printf("\nIntersection : ");

                for (int k = 0; k<nb_noeuds; k++)
                {
                    if (graph[i][k].id_rue != INFINI && !est_dans_la_liste(graph[i][k].id_rue, intersections, compteur))
                    {
                            intersections[compteur] = graph[i][k].id_rue;
                            compteur++;
                    }
                }

                printf("\n%d - noeud trouve : %d", pos, i);
                propositions[pos-1] = i;
                pos++;

                for (int l = 0; l<compteur; l++)
                {
                    printf("\n%s", liste_rues[intersections[l]]);
                }

                drapeau = 1;
            }
            j++;
        }
    }

    printf("\n\n> Entrez un  chiffre :\n\n> ");
    scanf("%d", &choix);
    fflush(stdin);

    //printf("\nvous avez choisi le noeud numero : %d", propositions[choix-1]);
    return propositions[choix-1];
}


void afficher_chemin(Etape* point_depart, char liste_rues[][LONGUEUR_CHAMP], int noeud_A, int noeud_B)
{
    int i=0, distance_totale = 0, distance_temporaire=0;
    Etape *tmp=point_depart;
    int liste_affichage[get_nb_rues()];
    int rue_en_attente = -1;

    nettoyer_ecran();

    while (tmp!=NULL)
    {
        if (!est_dans_la_liste(tmp->id_rue, liste_affichage, i+1) && tmp->id_rue != rue_en_attente)
        {
            if (rue_en_attente != -1) printf("\n%s : %d", liste_rues[rue_en_attente], distance_temporaire);
            distance_temporaire = 0;
            printf("\nEtape %d - %s : %d metres", i+1, liste_rues[tmp->id_rue], tmp->distance);
            liste_affichage[i] = tmp->id_rue;
            distance_temporaire += tmp->distance;
            i++;
        }

        else
        {
            distance_temporaire += tmp->distance;
            printf("\ndist_temp : %d", distance_temporaire);
            rue_en_attente = tmp->id_rue;
        }

        distance_totale += tmp->distance;
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


int est_dans_la_liste(int valeur, int liste[get_nb_rues()], int chercher_pendant)
{
    int drapeau = 0, i = 0;

    while (!drapeau && i < chercher_pendant)
    {
        if (liste[i++]==valeur) drapeau = 1;
    }
    return drapeau;
}
