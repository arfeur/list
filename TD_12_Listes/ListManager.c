/**
  * Author: Arthur Dherbomez;
  * FileName: ListManager.c;
  * Description: Permet de d'instancier les fonctions qui manipulent les listes chainées;
  * Date: 28/02/2020;
  */
#include "ListManager.h"

struct _list{
    /*
        Structure de liste chainées
    */
    int value;
    struct _list * next;
};

list * createNew(int value){
    /* 
        value: valeur(int) de l'élément, permet de l'identifier.
        next: renseigne l'élément suivant de la liste.

        Permet de creer une liste .
    */    
    list * myList = malloc(sizeof(struct _list));
    myList->value = value;
    myList->next = NULL;

    return myList;
}

list * delete(list * listDelete, int position){
    /*  
        position: position de la liste à supprimer.

        Permet de supprimer un élement d'une liste.
    */
    int i = 0;
    list * listReturn = listDelete;
    list * listPrev = listDelete;
    if(position == 1)
    {
        listDelete = (list*) listDelete->next;
        free(listPrev);
        return listDelete;
    }
    else
    {
        for ( i = 0; i < position; i++)
        {
            listDelete = (list*) listDelete->next;
        }
        listPrev->next = listDelete;   
        free(listDelete);
        return listReturn;
    }
    return 0;
}

int searchPosition(list * myList, int value){
    /*  
        value: valeur(int) d'un nouvel élément.

        Permet de chercher la position d'un élément d'une liste.
    */
    int position = 1;
    while (myList != NULL)
    {
        if(myList->value == value)
        {
            return position;
        }
        ++position;

        myList = (list*) myList->next;
    }
    return 0;
}

list * searchEntier(list * myList,int value, int verif){
    /* 
        value: valeur(int) de l'élément à chercher
        verif: 0 si faux et 1 si vrai

        Permet de supprimer toutes les occurences de l’entier dans une liste si
        verif est vrai = 1.
        Sinon, la fonction ne supprime que la premiere occurence.
    */
    int position = 0;
    if(verif == 1)
    {   int occurence = searchOccurence(myList,value);
        while (occurence > 0)
        {   
            position = searchPosition(myList,value);
            myList = delete(myList, occurence);
            myList = myList->next; 
            occurence--;
        }
        return myList;
    }
    else
    {
        position = searchPosition(myList,value);
        return delete(myList, position);
    }
    return 0;
}

list * addFirst(list * myList, int value){
    /*
        Value: valeur(int) du nouvel élément.
        Permet d'ajouter un élément au début d'une liste.
    */
    list * newList = createNew(value);
    newList->next =  myList;

    return newList;
}

list * addLast(list * myList, int value){
    /*  
        Value: valeur(int) du nouvel élément.
        Permet d'ajouter un élément à la fin d'une liste.
    */
    while(myList->next != NULL){
        myList = (list*) myList->next;
    }
    myList->next = (list*) createNew(value);
    return myList;
}

void displayInt(list * myList){
    /*
        Permet d'afficher chaque valeur d'une liste en la parcourant.
    */
    while(myList != NULL){
        printf("%d -> ",myList->value);
        myList = (list *) myList->next;
    }
}

int searchOccurence(list * myList, int nb){
    /*  
        nb : chiffre que l'on cherche.

        Permet de chercher une occurence dans une liste.
    */
    int occurence = 0;
    while(myList != NULL){
        if (myList->value == nb)
        {
            occurence ++;
        }
        myList = (list *) myList->next;
    }

    return occurence;
}

list * fusionList(list * listA, list * listB){
    /*
        Fusionne 2 listes en ajoutant la 2ème à la suite de la 1ère.
    */
    list * listTemp = listA;
    while (listA->next != NULL)
    {   
        listA = listA->next;
    }
    listA->next=listB;
    return listTemp;
}

int countElement(list * myList){
    /*
        Compte le nombre d'éléments dans une liste.
    */
    int count = 0;
    while (myList != NULL)
    {   
        count ++;
        myList = myList->next;
    }
    return count;
}
