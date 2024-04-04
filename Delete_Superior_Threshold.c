#include <stdio.h>
#include <stdlib.h>


struct Liste
{
                int val;
                struct Liste *suiv;
};
typedef struct Liste Liste;

/*what does the code do ? Explain it to the folks at home Mister:
it takes in head (tete) to a linked list and deletes all elements above a certain threshold:
                1) if it is null -> it returns null
                2) if it has one element -> it checks if that one element is above the threshold
                                it returns NULL if it is, and head if it isn't
                3) if none of the above then:
                it declares a precedent(previous) = tete and courant(current) = tete->suiv and a temporary temp
                                it enters a while loop with the end of the linked list as its exit condition
                                if value at the courant is superior than the threshold we delete it by :
                                                a) temp takes courant
                                                b)the precedent->suiv aka the courant in another words but that is connected to the linked list takes the courant->suiv
                                                c)then the courant takes the value of the courant -> suiv pointing to the next element of the linked list
                                                d) we finish by deleting the temp pointer aka the value we want to delete.
                                if else:
                                                we proceed to the next elements by simply
                                                                precedent  = courant;
                                                                and courant = courant->suiv;
                4) finaly we give the head back return tete

*/

Liste *Supprimer_Sup_Seuil_BETA(Liste *tete, int seuil)
{
                if(tete == NULL)
                {
                                printf("La liste est vide!");
                                return NULL;
                }
                if(tete->suiv == NULL)
                {
                                if(tete->val > seuil)
                                {
                                                free(tete);
                                                return NULL;
                                }
                                else
                                                return tete;
                }
                Liste *precedent = tete;
                Liste *courant = tete->suiv;
                Liste *temp = NULL;
                while (courant != NULL)
                {
                                if(courant->val > seuil)
                                {
                                                temp = courant;
                                                precedent->suiv = courant->suiv;
                                                courant = courant->suiv;
                                                free(temp);
                                }
                                else
                                {
                                                precedent = courant;
                                                courant = courant->suiv;
                                }
                }
                return (tete);
}

void afficher_liste(Liste *tete)
{
                Liste *courant = tete->suiv;
                while(courant != NULL){
                                printf("%d \t", courant->val);
                                courant = courant->suiv;
                }
                printf("\n");
}

int main()
{
                Liste *maillon1 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon2 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon3 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon4 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon5 = (Liste*)malloc(sizeof(Liste));
                Liste *maillon6 = (Liste*)malloc(sizeof(Liste));
                Liste *tete = (Liste*)malloc(sizeof(Liste));
                tete->suiv = maillon1;
                maillon1->val = 3;
                maillon2->val = 2;
                maillon3->val = 10;
                maillon4->val = 17;
                maillon5->val = 3;
                maillon6->val = 8;
                maillon1->suiv = maillon2;
                maillon2->suiv = maillon3;
                maillon3->suiv = maillon4;
                maillon4->suiv = maillon5;
                maillon5->suiv = maillon6;
                maillon6->suiv = NULL;
                tete = Supprimer_Sup_Seuil(tete,8);
                afficher_liste(tete);
}
