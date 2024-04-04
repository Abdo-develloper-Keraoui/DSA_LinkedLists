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
