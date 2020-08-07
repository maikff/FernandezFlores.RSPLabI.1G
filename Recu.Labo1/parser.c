#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Objeto.h"

int parser_ObjectFromText(FILE *pFile, LinkedList *this) {
	ePost *pObjeto;
	char auxID[128];
	char user[128];
	char dislikes[128];
	char likes[128];
	char followers[128];

	int todoOk = 0;
	int primerLinea = 1;

	if (pFile != NULL) {
		while (!feof(pFile))
        {
			if (primerLinea)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, user, likes, dislikes, followers);
				primerLinea = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, user, likes, dislikes, followers);
			pObjeto = Objeto_newParam(auxID, user,likes, dislikes,followers);

			if (pObjeto != NULL)
            {
				ll_add(this, pObjeto);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}
