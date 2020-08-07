#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "utn.h"
#include "Objeto.h"
#include "Controller.h"
#include "Informes.h"

int menu()
{
    int opcion;
    printf(	"\n\t    M E N U\n\n");
    printf( "    1) Cargar archivo.\n");
    printf( "    2) Imprimir lista.\n");
    printf( "    3) Asignar estadisticas.\n");
    printf( "    4) Filtrar por mejores posteos.\n");
    printf( "    5) Filtrar por haters.\n");
    printf( "    6) Ordenar por cantidad de followers.\n");
    printf( "    7) Mostrar mas popular.\n");
    printf( "    8) Salir.\n");
    utn_getNumero(&opcion, "Elegir opcion 1-8:  ","Opcion incorrecta.\n", 1, 9, 5);

    return opcion;
}

int redSocial()
{

    char confirma;
    char respuesta = 's';
    int archivoAbierto = 0;
    char path[128];

    LinkedList* listaFiltrada= ll_newLinkedList();
    LinkedList* userMasPopular = ll_newLinkedList();
    LinkedList* listaUsers = ll_newLinkedList();

    do
    {
        switch (menu())
        {
        case 1: // Carga Archivo
            utn_getNombre(path, 128, "ingresar nombre de archivo sin extension (posts): \n", "    Nombre incorrecto.\n", 7);
            strcat(path,".csv");
            printf("El archivo sera: %s\n",path);
            if(archivoAbierto)
            {
                printf("Archivo abierto.\n");
            }
            else
            {
                if(!controller_loadFromText(path,listaUsers))
                {
                    printf("error al cargar csv.\n");
                }
                else
                {
                    printf("Datos cargados!.\n");
                    archivoAbierto = 1;
                }
            }
            break;

        case 2: // Listar users
            if(!archivoAbierto)
            {
                printf("Imposible listar users, archivo sin cargar.");
            }
            else if(controller_ListObject(listaUsers))
            {
                printf("Users listados!\n");
            }
            break;

        case 3: // Mapear datos
            if(!archivoAbierto)
            {
                printf("error archivo sin cargar.\n");
            }
            else
            {
                listaUsers = ll_map(listaUsers, setearDislikes);
                listaUsers = ll_map(listaUsers, setearFollowers);
                listaUsers = ll_map(listaUsers, setearLikes);
                if(controller_ListObject(listaUsers))
                {
                    printf("Estadisticas asignadas!.\n");
                }
            }
            break;

        case 4: // filtrar mejor posteo
            if(!archivoAbierto)
            {
                printf("no se puede filtrar, archivo sin abrir.\n");
            }
            else
            {
                listaFiltrada = ll_filter(listaUsers, filtrarExitoso);
                if(controller_ListObject(listaFiltrada))
                {
                    controller_saveAsText("mejoresPosteos.csv", listaFiltrada);
                    printf("Users con mas de 5000 likes \n"
                           "Lista guardada como mejoresPosteos.csv\n");
                }
            }
            break;

        case 5: // filtrar users que superen los likes con dislikes
            if(!archivoAbierto)
            {
                printf("Imposible filtrar usuarios, abra el archivo.\n");
            }
            else
            {
                listaFiltrada = ll_filter(listaUsers, filtrarHaters);
                if (controller_ListObject(listaFiltrada))
                {
                    controller_saveAsText("postsMasDislikes.csv", listaFiltrada);
                    printf("Posts con mas cantidad de dislikes.\n"
                           "Lista guardada como postsMasDislikes.csv\n");
                }
            }
            break;

        case 6: // ordenar por dislikes mayor a menor
            if(listaUsers==NULL || !archivoAbierto)
            {
                printf("lista vacia o archivo sin cargar.\n");
            }
            else if(!ll_sort(listaUsers, Objeto_sortFollowers, 0))
            {
                controller_ListObject(listaUsers);
                printf("Ordenado por Nivel de followers (mayor a menor).\n");
            }
            break;

        case 7: //users mas populares
            if(!archivoAbierto)
            {
                printf("Archivo sin cargar.\n");
            }
            else
            {
                userMasPopular = listaUserMasPopular(listaUsers);
                if(controller_ListObject(userMasPopular))
                {
                    printf("Users mas Con mas likes.\n");
                }
            }
            break;

        case 8: /* Salir */
            printf("desea salir? s/n: ");
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                respuesta='n';
                ll_deleteLinkedList(listaFiltrada);
                ll_deleteLinkedList(listaUsers);
                ll_deleteLinkedList(userMasPopular);
            }
            break;

        default:
            printf(	"Opcion incorrecta (hay que usar de 1 a 8).\n");
            break;

        }
        system("pause");
        system("cls");

    }
    while (respuesta == 's');

    return 0;
}
