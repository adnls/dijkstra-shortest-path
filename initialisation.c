#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "structures.h"

void creer_rue(FILE*, Rue*);
int csvscanf(FILE*, char[]);
static int nb_rues;
static int nb_noeuds;

int get_nb_rues(){
    return nb_rues;
}

int get_nb_noeuds(){
    return nb_noeuds;
}

void configurer_programme()
{
    char chemin[]="config.txt";
    FILE* fichier;
    fichier = fopen(chemin, "r");
    fscanf(fichier, "%d", &nb_rues);
    fscanf(fichier, "%d", &nb_noeuds);
    fclose(fichier);
}

void initialiser_liste_rues(char noms[][LONGUEUR_CHAMP], char *chemin)
{
    int i, NB_RUES;
    NB_RUES = get_nb_rues();
    char tmp[LONGUEUR_CHAMP];
    FILE* csv;
    csv=fopen(chemin, "r");

    for (i=0;i<NB_RUES; i++)
    {
        csvscanf(csv, tmp);
        strcpy(noms[i], tmp);
        /*test*/
        //printf("%s\n", noms[i]);
    }
    fclose(csv);
}

void initialiser_graph(Rue graph[][nb_noeuds], char *chemin)
{
    FILE* csv;
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

int csvscanf(FILE* csv, char champ[])
{
    char tmp='a', delimiteur=',';
    int i=0;

    while ((tmp!= '\n') && (tmp != delimiteur) && (tmp != EOF))
    {
        if (fscanf(csv, "%c", &tmp)!=EOF)
        {
            champ[i]=tmp;
        }
        else
        {
            tmp=EOF;
        }
        i ++;
    }

    champ[i-1]='\0';
	//printf("\n%s", champ);
    return tmp;
    
}

