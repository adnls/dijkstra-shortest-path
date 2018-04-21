#include <string.h>
#include <ctype.h>
#include "structures.h"
#include "csv.h"

//local requirements
void creer_rue(FILE*, Rue*);

//variables statiques
static int nb_rues;
static int nb_noeuds;

int get_nb_rues(){
    return nb_rues;
}

int get_nb_noeuds(){
    return nb_noeuds;
}
//TODO recuperer le nb noeuds de l'exterieur
void configurer_programme()
{
    nb_rues = 11;
    nb_noeuds = 20;
}

void initialiser_liste_rues(char noms[][LONGUEUR_CHAMP])
{
    int i;
    char chemin[]="names.txt", tmp[LONGUEUR_CHAMP];
    FILE* csv;
    csv=fopen(chemin, "r");

    for (i=0;i<nb_rues; i++)
    {
        csvscanf(csv, tmp);
        strcpy(noms[i], tmp);
        /*test*/
        //printf("\n%s", noms[i]);
    }
    fclose(csv);
}

void initialiser_graph(Rue graph[][nb_noeuds])
{
    FILE* csv;
    char chemin[] = "graph.txt";
    int i, ligne=0, colonne;
    csv = fopen(chemin, "r");
    Rue tmp;

    for(i=0; i<nb_noeuds*nb_noeuds;i++)

    {
        creer_rue(csv, &tmp);
        colonne = i%nb_noeuds;

        graph[ligne][colonne]=tmp;

        /*test*/
        /*printf("\n%d - %d : %d - %d",
               graph[ligne][colonne].id_rue, graph[ligne][colonne].distance, ligne, colonne);*/

        if (colonne==nb_noeuds-1)
            ligne++;
    }
    fclose(csv);
}

void initialiser_feuille_de_calcul(Noeud feuille_de_calcul[])
{
    int i;
    Noeud defaut = {INFINI, INFINI, 0};

    for (i=0;i<nb_noeuds;i++)
    {
        feuille_de_calcul[i]=defaut;
        /*test*/
        //printf("\n%d", feuille_de_calcul[i].poids);
    }
}

void creer_rue(FILE* csv, Rue* tmp)
{
    int i=0, variable=0, nb_variables=2, fini = 0;
    char champ[LONGUEUR_CHAMP];

    while(variable != nb_variables-1 && !fini)
    {
        fini = csvscanf(csv, champ) == EOF;

        variable = i%nb_variables;

        switch(variable)
        {
            case 0:
                tmp->id_rue = atoi(champ);
                break;
            case 1:
                tmp->distance = atoi(champ);
                break;
        }
        i++;
    }
}

