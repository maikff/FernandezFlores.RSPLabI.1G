#include <stdio.h>
#include <stdlib.h>

#include "Objeto.h"
#include "LinkedList.h"

int getFollowersAleatorio(void){
	int aleatorio;
	//1000 - 50000
	aleatorio = rand()% (10000 + 10001);

	return aleatorio;
}

int getDislikesAleatorios(void){
	int aleatorio;
	//40000 - 2000000
	aleatorio = rand()% (300 + 3201);

	return aleatorio;
}

int getLikesAleatorios(void){
	int aleatorio;
	//50000 - 1000000
	aleatorio = rand()% (500 + 9501);

	return aleatorio;
}

void* setearFollowers(void*followers){
	ePost* follower = NULL;

	if(followers!=NULL){
		follower = (ePost*)followers;
		Objeto_setFollowers(follower, getFollowersAleatorio());

	}
	return follower;
}

void* setearDislikes(void*hater){
	ePost* dislikes = NULL;

	if(hater!=NULL){
		dislikes = (ePost*)hater;
		Objeto_setDislikes(dislikes, getDislikesAleatorios());

	}
	return dislikes;
}

void* setearLikes(void*likes){
	ePost* like = NULL;

	if(likes!=NULL){
		like = (ePost*)likes;
		Objeto_setLikes(like, getLikesAleatorios());
	}
	return like;
}

int filtrarExitoso(void*cantidad){
	int todoOk = 0;

	ePost* exitoso;
	if(cantidad!=NULL){
		exitoso = (ePost*)cantidad;
		if(exitoso->likes>5000){
			todoOk = 1;
		}
	}

	return todoOk;
}

int filtrarHaters(void*cantidad){
	int todoOk = 0;
	int likes;
	int dislikes;

	ePost* hater;
	if(cantidad!=NULL){
		hater = (ePost*)cantidad;
		Objeto_getDislikes(hater, &dislikes);
		Objeto_getLikes(hater, &likes);
		if(dislikes >=likes*3){
			todoOk = 1;
		}
	}
	return todoOk;
}

LinkedList* listaUserMasPopular(LinkedList* this){
	LinkedList* listaMapeada = NULL;
	int likesActual;
	int likesMayorCant;
	int flag = 0;
	ePost* pElement = NULL;

	if(this!=NULL){
		listaMapeada = ll_newLinkedList();
		for(int i = 0;i<ll_len(this);i++){
			pElement = ll_get(this, i);
			Objeto_getLikes(pElement, &likesActual);
			if(!flag || likesActual > likesMayorCant){
				likesMayorCant = likesActual;
				flag = 1;
			}
		}
        for(int i = 0;i<ll_len(this);i++){
			pElement = ll_get(this, i);
			Objeto_getLikes(pElement, &likesActual);
			if(likesActual==likesMayorCant){
				ll_add(listaMapeada, pElement);
			}
		}
	}

	return listaMapeada;
}
