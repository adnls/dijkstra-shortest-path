#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "initialisation.h"

void actualiser_feuille(int, Rue (*)[], Noeud[]);
void initialiser_noued_A(int, Noeud[]);
int trouver_noeud(Noeud[]);
Etape *talloc(); //Léry's combo

void trouver_chemin(int noeud_A, int noeud_B, Rue graph[][get_nb_noeuds()], Noeud feuille_de_calcul[])
{
    int tmp=INFINI;

    //init point de depart
    initialiser_noued_A(noeud_A, feuille_de_calcul);

    while (tmp!=noeud_B)
    {
        //printf("\n%d", shortest);
        tmp = trouver_noeud(feuille_de_calcul);
        actualiser_feuille(tmp, graph, feuille_de_calcul); //parcoure les fils et actualise la feuille de calcul
    }
}

void initialiser_noued_A(int noeud_A, Noeud feuille_de_calcul[])
{
    feuille_de_calcul[noeud_A].poids=0;
}

int trouver_noeud(Noeud feuille_de_calcul[])
{

    int i, j=0, min=0;

    for (i=0;i<get_nb_noeuds();i++) //on parcoure toute la feuille de calcul
    {
        if (!feuille_de_calcul[i].parcouru && feuille_de_calcul[i].poids!=INFINI) //si le noeud n'a pas déjà été parcouru mais poids qd mm different de l'init
        {
            if (j == 0 || feuille_de_calcul[i].poids < feuille_de_calcul[min].poids) //si c'est le premier tour ou bien que le poids est plus petit on le garde
            {
                min = i;
            }
            j++;
        }
    }
    return min; //après avoir parcouru tous les noeuds on renvoie le pluts léger
}

void actualiser_feuille(int noeud, Rue graph[][get_nb_noeuds()], Noeud feuille_de_calcul[])
{

    int poids_actuel, est_plus_petit, i;

    for (i=0; i<get_nb_noeuds(); i++) //on parcoure la feuille
    {
        poids_actuel = feuille_de_calcul[noeud].poids+graph[noeud][i].distance;
        est_plus_petit = (poids_actuel<feuille_de_calcul[i].poids);
        //est plus petit si poids du noeud pere + poids du chemin jusqu'au noued fils < poids du noueud fils

        //on actualise la feuille de calcul si le noeud est bien un fils
        //si le neoud n'a pas déjà été parcouru et que le chemin scanné est plus petit (ou bien non initialisé = 999)
        if (graph[noeud][i].distance!=INFINI && !feuille_de_calcul[i].parcouru && est_plus_petit)
        {
            //si on trouve un plus court chemin valide : on met le nouveau poids et on actualise le père dans le noeud fils
            feuille_de_calcul[i].poids=poids_actuel;
            feuille_de_calcul[i].pere=noeud;
            
        }
    }
    feuille_de_calcul[noeud].parcouru=1;
    //une fois le noeud le plus petit parcouru on le marque comme parcouru..
}

void stocker_chemin(int noeud_A, int noeud_B, Etape** depart, Rue graph[][get_nb_noeuds()], Noeud feuille_de_calcul[])
{
    int i = noeud_B;
    Etape *tmp;
    
    while(i!=noeud_A) 
    {
        tmp = talloc(); //typed alloc

        tmp->prochaine=NULL;
        tmp->noeud_A=feuille_de_calcul[i].pere;
        tmp->noeud_B=i;
        tmp->distance=graph[feuille_de_calcul[i].pere][i].distance;
        tmp->id_rue=graph[feuille_de_calcul[i].pere][i].id_rue;

        if ((*depart)==NULL)
        {
            (*depart)=tmp;
        }

        else
        {
            tmp->prochaine = (*depart); //le next de l'actuel devient le premier
            (*depart)=tmp; //le premier devient l'actuel
        }
        i = (feuille_de_calcul[i].pere);
    }
}

Etape *talloc()
{
    return (Etape*) malloc(sizeof(Etape));
}
