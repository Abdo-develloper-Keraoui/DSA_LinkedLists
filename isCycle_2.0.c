#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Liste{
                int val;
                struct Liste *suiv;
};
typedef struct Liste Liste;


int isCycle(Liste *tete)
{

                if (tete == NULL)
                                return 0;
                int i = 0, j;
                Liste **Maillon_Visite;
                Maillon_Visite = (Liste**)malloc(sizeof(Liste*));
                Maillon_Visite[i] = tete;
                Liste *courant = tete->suiv;
                while(courant != NULL)
                {
                                                for(j = 0; j <= i; j++)
                                                {
                                                                if (courant == Maillon_Visite[j])
                                                                                return 1;
                                                }
                                                i++;
                                                Maillon_Visite = (Liste**)realloc(Maillon_Visite,i*sizeof(Liste*));
                                                Maillon_Visite[i] = courant;
                                                courant = courant->suiv;
                }
                return 0;
}

int main()
{
                Liste *maillon1 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon2 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon3 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon4 = (Liste*)malloc(sizeof(Liste));
                Liste *tete = maillon1;
                maillon1->val = 1;
                maillon2->val = 2;
                maillon3->val = 3;
                maillon4->val = 4;
                maillon1->suiv = maillon2;
                maillon2->suiv = maillon3;
                maillon3->suiv = maillon4;
                //maillon4->suiv = NULL;
                maillon4->suiv = maillon3;
                 int X = isCycle(tete);
                 if(X == 1)
                                printf("There is a cycle!\n");
                if(X == 0)
                                printf("There is no cycle!\n");
}
