#include <stdlib.h>

#ifndef INFINI
#define INFINI 9999
#endif

#ifndef LONGUEUR_CHAMP
#define LONGUEUR_CHAMP 100
#endif

#ifndef STRUCTURES
#define STRUCTURES

typedef struct Rue Rue;
struct Rue          {
                        int id_rue;
                        int distance;
                     };

typedef struct Noeud Noeud;
struct Noeud          {
                        int poids;
                        int pere;
                        int parcouru;
                     };

typedef struct Etape Etape;
struct Etape         {
                        int noeud_A;
                        int noeud_B;
                        int distance;
                        int id_rue;
                        Etape* prochaine;
                     };

#endif


