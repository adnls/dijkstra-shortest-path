#include "structures.h"
#include "initialisation.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void afficher_rues(char(*)[]);
int choisir_noeud(int, Rue(*)[], char(*)[]);
void nettoyer_ecran();
void entree_pour_continuer();
int est_dans_la_liste(int, int[], int);
void afficher_noeud(int, Rue(*)[], char(*)[]);
void afficher_noeud_2(int, Rue(*)[], char(*)[]);
void vider_buffer();

void choisir_chemin(int* noeud_A, int* noeud_B, Rue graph[][get_nb_noeuds()], char liste_rues[][LONGUEUR_CHAMP])
{
    int id_rue;
    nettoyer_ecran();
    printf("Trouvez votre point de depart : \n\n");
    afficher_rues(liste_rues);
    printf("\nEntrez le numero correspondant : ");
    scanf("%d", &id_rue);
    id_rue--;
    (*noeud_A) = choisir_noeud(id_rue, graph, liste_rues);

    nettoyer_ecran();
    printf("Trouvez votre point d'arrivee : \n\n");
    afficher_rues(liste_rues);
    printf("\nEntrez le numero correspondant : ");
    scanf("%d", &id_rue);
    id_rue--;
    (*noeud_B) = choisir_noeud(id_rue, graph, liste_rues);

}

void afficher_rues(char liste_rues[][LONGUEUR_CHAMP])
{
    int nb_rues = get_nb_rues(), i;

    for(i = 0; i<nb_rues; i++)
    {
        printf("%d - %s\n", (i+1), liste_rues[i]);
    }
}

int choisir_noeud(int id_rue, Rue graph[][get_nb_noeuds()], char liste_rues[][LONGUEUR_CHAMP])
{
    int choix = 0, i, k, l;
    int nb_noeuds = get_nb_noeuds();
    int nb_rues = get_nb_rues();
    int intersections[nb_rues];
    int propositions[nb_noeuds];
    int drapeau, j, compteur;
    int pos = 1;

    nettoyer_ecran();

    printf("Propositions pour : %s\n", liste_rues[id_rue]);

    for (i = 0; i < nb_noeuds; i++)
    {
        drapeau = 0;
        j = 0;
        compteur = 0;

        while (!drapeau && j < nb_noeuds)
        {
            //printf("sfvsfv");
            if (graph[i][j].id_rue == id_rue)
            {
                for (k = 0; k<nb_noeuds; k++)
                {
                    if (graph[i][k].id_rue != INFINI && !est_dans_la_liste(graph[i][k].id_rue, intersections, compteur))
                    {
                            intersections[compteur] = graph[i][k].id_rue;
                            compteur++;
                    }
                }

                printf("\n%d - Intersection de : \n\n", pos);
                propositions[pos-1] = i;
                pos++;

                for (l = 0; l<compteur; l++)
                {
                    printf("  + %s\n", liste_rues[intersections[l]]);
                }

                drapeau = 1;
            }
            j++;
        }
    }

    printf("\nEntrez un numero: ");
    scanf("%d", &choix);
    
    return propositions[choix-1];
}

void afficher_chemin(Etape* point_depart, int arrivee, char liste_rues[][LONGUEUR_CHAMP], int noeud_A, int noeud_B, Rue graph[][get_nb_noeuds()], int mode)
{
    int i=0, distance_totale = 0;
    Etape *tmp=point_depart;

    nettoyer_ecran();

    printf("Pour aller de l'intersection de :\n\n");
    afficher_noeud(noeud_A, graph, liste_rues);
    printf("\na l'intersection de :\n\n");
    afficher_noeud(noeud_B, graph, liste_rues);

    if (mode == 1)
    {
        printf("\nA pied,\n\nprenez :\n\n");
    }
    else
    {
        printf("\nEn voiture,\n\nprenez :\n\n");
    }

    while (tmp!=NULL)
    {
        printf("%s\npendant %d metres jusqu'a l'intersection de :\n\n", liste_rues[tmp->id_rue], tmp->distance);	
	
	afficher_noeud(tmp->noeud_B, graph, liste_rues);
	if (tmp->noeud_B != arrivee) printf("\nPuis prenez :\n\n");
	
        distance_totale += tmp->distance;
        tmp = tmp->prochaine;
        i++;
    }

    printf("\nVous etes arrives!\n");
    printf("\nDistance totale : %d metres\n\n", distance_totale);
    entree_pour_continuer();
}

int choisir_mode()
{
    int reponse = 0;

    while (reponse != 1 && reponse != 2)
    {
        nettoyer_ecran();
        printf("Vous voulez y aller :\n\n");
        printf("1 - A pied\n");
        printf("2 - En voiture\n");
        printf("\nEntrez le numero associe a votre choix : ");
        scanf("%d", &reponse);
    };

    return reponse;
}

void afficher_menu()
{
        nettoyer_ecran();
        int i = 92;
        printf("================================================================\n");
        printf("******************** SOUS LE CIEL DE PARIS *********************\n");
        printf("================================================================\n");
        printf("Copyright David&Kien Company, avril 2014. Tous droits reserves\n\n");
        printf("        _____\n");
        printf("    ,-:` %c;',`'-, \n",i);
        printf("  .'-;_,;  ':-;_,'.\n");
        printf(" /;   '/    ,  _`.-%c\n",i);
        printf("| '`. (`     /` ` %c`|\n",i);
        printf("|:.  `%c`-.   %c_   / |\n",i,i);
        printf("|     (   `,  .`%c ;'|\n",i);
        printf(" %c     | .'     `-'/\n",i);
        printf("  `.   ;/        .'\n");
        printf("    `'-._____.\n");
        printf("\n\nVous etes dans le deuxieme arrondissement a Paris et vous avez du mal à trouver votre destination?\n");
        printf("Ce programme facilite les deplacements en ville en vous proposant la meilleure route!!");
        printf("\n\n ## MENU PRINCIPAL ##\n\n");
        printf("1 - Trouver mon itineraire\n");
        printf("2 - Revoir le resultat\n");
        printf("3 - Quitter\n");
        printf("\nVeuillez entrer le numero de votre choix : ");
}

void nettoyer_ecran()
{
	int i;
    for (i = 0; i < 100; i++) printf("\n");
}

void entree_pour_continuer()
{
    printf("Appuyez sur entree pour continuer\n");
	vider_buffer();    
	getchar();
    
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

void afficher_noeud(int noeud, Rue graph[][get_nb_noeuds()], char liste_rues[][LONGUEUR_CHAMP])
{
    int NB_NOEUDS = get_nb_noeuds(), i, j;
    int rues[get_nb_rues()];
    int compteur = 0;

    for (i = 0; i<NB_NOEUDS; i++)
    {
        if (graph[noeud][i].id_rue != INFINI && !est_dans_la_liste(graph[noeud][i].id_rue, rues, compteur))
        {
            rues[compteur++] = graph[noeud][i].id_rue;
        }
    }

    for (j = 0; j<compteur; j++)
    {
        printf("  + %s\n", liste_rues[rues[j]]);
    }
}


void dire_au_revoir()
{
    int i;
    nettoyer_ecran();
    printf("Bon voyage !   <(^_^)>   <(^_^)>\n\n\n\n\n");
}

void vider_buffer()
  {
    int tmp = 0;
    while (tmp != '\n' && tmp != EOF) 
    {
      tmp = getchar();
    }
  }
