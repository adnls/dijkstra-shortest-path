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

void choisir_chemin(int* noeud_A, int* noeud_B, Rue graph[][get_nb_noeuds()], char liste_rues[][LONGUEUR_CHAMP])
{
    int id_rue;

    printf("\ncherchez un point de depart!");
    afficher_rues(liste_rues);
    printf("\nentrez un id_rue : ");
    scanf("%d", &id_rue);
    id_rue--;
    (*noeud_A) = choisir_noeud(id_rue, graph, liste_rues);
    //printf("zzzzzzzzzzzzzzzzzz %d", (*noeud_A));

    printf("\ncherchez un point d'arrivee!");
    afficher_rues(liste_rues);
    printf("\nentrez un id_rue : ");
    scanf("%d", &id_rue);
    id_rue--;
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
    int choix;
    int nb_noeuds = get_nb_noeuds();
    int propositions[nb_noeuds];
    int l = 0;

    for (int i = 0; i<nb_noeuds; i++)
    {
        for (int j = 0; j < nb_noeuds; j++)
        {
            if (graph[i][j].id_rue == id_rue)
            {
                printf("\n////////////////");
                printf("\n%d - Intersection de : " , l+1);

                for (int k = 0; k <nb_noeuds; k++)
                {
                    if (graph[i][k].distance != INFINI)
                    {
                        printf("\n- %s", liste_rues[graph[i][k].id_rue]);
                    }
                }
                propositions[l] = i;
                l++;
            }
        }
    }

    printf("\nchoisissez un noeud : ");
    scanf("%d", &choix);
    return propositions[choix-1];
}
/*void afficher_chemin(Step* first, char names[][100])
{
    int i=0;
    //printf("\nkjdfghkdjfghdfg");

    Step *tmp=first;

    while (tmp!=NULL)
    {
        //printf("%s", tmp->street);
        printf("\nstep %d : %s",i+1, names[tmp->street]);
        tmp = tmp->next;
        i++;
    }
}*/

/*int choisir_rue_par_recherche(char names[][100])
{
    FILE* txt;
    char path[]="names;.txt", field[100], research[100];
    txt = fopen(path, "r");
    int i, j=0;
    char research[100];
    Link *first=NULL, *tmp;

    while (!feof(txt))
    {
        //fscanf(txt, "%s", field);
        fgets(field, sizeof field, txt);
        printf("%s", field);
    }

    printf("\n\nrecherche : ");

    gets(research);
    fflush(stdin); //avoir toute la str
    strcmprss(research);
    tolowers(research);

    int nb_rues = get_nb_rues();

    for (i=0; i<nb_rues; i++)
    {
        if (strsearch(names[i], research)==1)
        {
            //printf("\n%s", names[i]);
            simple_fifoq_put(i, &first);
            j++;
        }
    }

    tmp = first;
    while (simple_fifoq_get(&tmp, &i))
            printf("%d", i);

    if (j==0)
        printf("\naucun resultat");
        //search_street(names);
    else
        printf("\n%d resultat(s)\n", j);

    return 0;
}*/

/*void choose_node()
{

}*/


