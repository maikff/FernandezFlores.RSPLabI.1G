#ifndef INFORMES_INFORMES_H_
#define INFORMES_INFORMES_H_

void* setearFollowers(void*followers);

void* setearDislikes(void*haters);

void* setearLikes(void*likes);

int filtrarExitoso(void*cantidad);

int filtrarHaters(void*cantidad);

LinkedList* listaUserMasPopular(LinkedList* this);

#endif /* INFORMES_INFORMES_H_ */
