#include <stdio.h>
#include "Objeto.h"

#include <stdlib.h>
#include <string.h>

//setters
int Objeto_setID(ePost *this, int *id)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (id >= 0)
        {
            this->id = *id;
            todoOk = 1;
        }
    }
    return todoOk;
}

int Objeto_setUser(ePost *this, char *user)
{
    int todoOk = 0;

    if (this != NULL && user != NULL)
    {
        strncpy(this->user, user, 10);
        todoOk = 1;
    }
    return todoOk;
}

int Objeto_setFollowers(ePost *this, int followers)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (followers >= 0)
        {
            this->followers = followers;
            todoOk = 1;
        }
    }
    return todoOk;
}

int Objeto_setLikes(ePost *this, int likes)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (likes >= 0)
        {
            this->likes = likes;
            todoOk = 1;
        }
    }
    return todoOk;
}

int Objeto_setDislikes(ePost *this, int dislikes)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (dislikes >= 0)
        {
            this->dislikes = dislikes;
            todoOk = 1;
        }
    }
    return todoOk;
}

//getters
int Objeto_getID(ePost *this, int *id)
{
    int todoOk = 0;

    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int Objeto_getUser(ePost *this, char *user)
{
    int todoOk = 0;

    if (this != NULL && user != NULL)
    {
        strcpy(user, this->user);
        todoOk = 1;
    }
    return todoOk;
}

int Objeto_getDislikes(ePost *this, int *dislikes)
{
    int todoOk = 0;

    if (this != NULL && dislikes != NULL)
    {
        *dislikes = this->dislikes;
        todoOk = 1;
    }
    return todoOk;
}

int Objeto_getLikes(ePost *this, int *Likes)
{
    int todoOk = 0;

    if (this != NULL && Likes != NULL)
    {
        *Likes = this->likes;
        todoOk = 1;
    }
    return todoOk;
}

int Objeto_getFollowers(ePost *this, int *followers)
{
    int todoOk = 0;

    if (this != NULL && followers != NULL)
    {
        *followers = this->followers;
        todoOk = 1;
    }
    return todoOk;
}

// Constructores
ePost* Objeto_new()
{
    ePost *nuevoObjeto;
    nuevoObjeto = (ePost*) calloc(sizeof(ePost), 1);

    return nuevoObjeto;
}

ePost* Objeto_newParam(char *id, char *user, char *dislikes,	char *likes, char* followers)
{
    ePost *nuevoObjeto;
    nuevoObjeto = Objeto_new();

    int auxId;
    int auxLikes;
    int auxFollowers;
    int auxDislikes;

    auxId = atoi(id);
    auxLikes = atoi(likes);
    auxFollowers = atoi(followers);
    auxDislikes = atoi(dislikes);

    if (nuevoObjeto != NULL && id != NULL && user != NULL && dislikes != NULL && likes != NULL && followers != NULL )
    {
        Objeto_setID(nuevoObjeto, &auxId);
        Objeto_setUser(nuevoObjeto, user);
        Objeto_setDislikes(nuevoObjeto, auxDislikes);
        Objeto_setLikes(nuevoObjeto, auxLikes);
        Objeto_setFollowers(nuevoObjeto, auxFollowers);
    }
    return nuevoObjeto;
}

int Objeto_sortFollowers(void *user1, void *user2)
{
    int user_1;
    int user_2;
    int todoOk = 0;

    Objeto_getFollowers(user1, &user_1);
    Objeto_getFollowers(user2, &user_2);

    if (user_1 > user_2)
    {
        todoOk = 1;
    }
    else if (user_1 < user_2)
    {
        todoOk = -1;
    }
    return todoOk;
}
