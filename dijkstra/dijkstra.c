#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "initialisation.h"

void update_nodes(int, Rue (*)[], Noeud[]);
void init_anode(int, Noeud[]);
int find_curnode(Noeud[]);
Etape *talloc(); //Léry's combo

void find_path(int anode, int bnode, Rue graph[][get_nb_noeuds()], Noeud sheet[])
{
    int tmp=INFINI;

    //init point de depart
    init_anode(anode, sheet);

    while (tmp!=bnode)
    {
        //printf("\n%d", shortest);
        tmp = find_curnode(sheet);
        update_nodes(tmp, graph, sheet); //parcoure les fils et actualise la feuille de calcul
    }
    //store_shorter_path(len, anode, bnode, first, last, nstep, graph, sheet);
}

void init_anode(int anode, Noeud sheet[])
{
    sheet[anode].poids=0;
}

int find_curnode(Noeud sheet[])
{

    int i, j=0, min=0;

    for (i=0;i<get_nb_noeuds();i++) //on parcoure toute la feuille de calcul
    {
        if (!sheet[i].parcouru && sheet[i].poids!=INFINI) //si le noeud n'a pas déjà été parcouru mais poids qd mm different de l'init
        {
            if (j == 0 || (sheet[i].poids)<(sheet[min].poids)) //si c'est le premier tour ou bien que le poids est plus petit on le garde
            {
                min = i;
            }
            j++;
        }
    }
    return min; //après avoir parcouru tous les noeuds on revoie le pluts léger
}

void update_nodes(int curnode, Rue graph[][get_nb_noeuds()], Noeud sheet[])
{

    int curweight, i, isshorter;

    for (i=0; i<get_nb_noeuds(); i++) //on parcoure la feuille
    {
        curweight = sheet[curnode].poids+graph[curnode][i].distance;
        isshorter = (curweight<sheet[i].poids);
        //est plus petit si poids du noeud pere + poids du chemin jusqu'au noued fils < poids du noueud fils

        //on actualise la feuille de calcul si le noeud est bien un fils
        //si le neoud n'a pas déjà été parcouru et que le chemin scanné est plus petit (ou bien non initialisé = 999)
        if (graph[curnode][i].distance!=INFINI && !sheet[i].parcouru && isshorter)
        {
            //si on trouve un plus court chemin valide : on met le nouveau poids et on actualise le père dans le noeud fils
            sheet[i].poids=curweight;
            sheet[i].pere=curnode;
            //printf("\n%d - %d", curpath, curnode);
        }
    }
    sheet[curnode].parcouru=1;
}

//!!!! dat's one way LIFO linked list..
void store_path(int anode, int bnode, Etape** first, Rue graph[][get_nb_noeuds()], Noeud sheet[])
{
    int i = bnode;
    Etape *tmp;
    //printf("%d", (*bnode));

    while(i!=anode)
    {
        tmp = talloc(); //typed alloc => special Léry combo

        tmp->prochaine=NULL;
        tmp->noeud_A=sheet[i].pere;
        tmp->noeud_B=i;
        tmp->distance=graph[sheet[i].pere][i].distance;
        tmp->id_rue=graph[sheet[i].pere][i].id_rue;

        //printf("%d", first);
        if ((*first)==NULL)
        {
            //printf("\n%s", tmp->street);
            (*first)=tmp;
        }

        else
        {
            tmp->prochaine = (*first); //le next de l'actuel devient le premier
            (*first)=tmp; //le premier devient l'actuel
            //printf("\n%d", (**last).dist);
        }
        i = (sheet[i].pere);
    }
}

Etape *talloc()
{
    return (Etape*) malloc(sizeof(Etape));
}

//TODO traduire en français...
