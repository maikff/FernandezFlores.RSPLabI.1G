
#ifndef Objeto_H_INCLUDED
#define Objeto_H_INCLUDED

typedef struct {
    int id;
	char user[128];
	int likes;
	int dislikes;
	int followers;
}ePost;

//getters

/** \brief obtiene la cantidad de followers del user
 *
 * \param this es la lista de users
 * \param followers es el valor de followers que tendra
 * \return 1 si pudo, 0 si error.
 *
 */

int Objeto_getFollowers(ePost *this, int *followers);

/** \brief  obtiene la cantidad de likes de los users
 *
 * \param   this es la lista de users
 * \param   likes es el valor de likes que tendra
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getLikes(ePost *this, int *Likes);

/** \brief obtiene la cantidad de dislikes.
 *
 * \param   this es la lista de dislikes
 * \param   dislikes es el valor de dislikes que habra
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getDislikes(ePost *this, int *dislikes);

/** \brief obtiene la cantidad de users que hay.
 *
 * \param   this es la lista de users
 * \param   user es el valor de users
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getUser(ePost *this, char *user);

/** \brief  le otroga el ID al user
 *
 * \param   this es la lista de id
 * \param   id es el valor que le da al user
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getID(ePost *this, int *id);

//setters

/** \brief Coloca la cantidad de dislikes
 *
 * \param this es el valor en la lista
 * \param   dislikes es el valor que hay.
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setDislikes(ePost *this, int dislikes);

/** \brief coloca la cantidad de likes
 *
 * \param this es el valor en la lista
 * \param likes es el valor en la misma
 * \return 1 si se pudo, 0 el error
 *
 */


int Objeto_setLikes(ePost *this, int Likes);

/** \brief coloca la cantidad de followers
 *
 * \param   this puntero LinckedList
 * \param   followers es el valor en la lista
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setFollowers(ePost *this, int followers);

/** \brief permite colocar datos en la funcion
 *
 * \param   Thhis es puntero a la linkedList
 * \param   user es el valor en la lista
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setUser(ePost *this, char *user);

/** \brief coloca ID
 *
 * \param   This es puntero a la linkedList
 * \param  id es el valir en la lista
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setID(ePost *this, int *id);


//constructores
ePost* Objeto_new();
ePost* Objeto_newParam(char *id, char *user, char *dislikes,	char *likes, char* followers);

/** \brief Nuevo parametro
 *
 * \param   id a evaluar
 * \param   user a evaluar
 * \param   dislikes  a evaluar
 * \param   likes a evaluar
 * \param   followers a evaluar
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_sortFollowers(void *hater1, void *hater2);

/** \brief ordena el array con el campo dislikes
 *
 * \param hater1: primer numero a evaluar
 * \param hater2: segundo numero a evaluar
 * \return retorna 0 si son iguales, 1 si el segundo es menor y sino -1 si es mayor.
 *
 */


#endif // Objeto_H_INCLUDED
