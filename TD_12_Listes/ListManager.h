/**
  * Author: Arthur Dherbomez;
  * FileName: ListManager.h;
  * Description: Permet de declarer les fonctions qui manipulent les listes chainées;
  * Date: 28/02/2020;
  */
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _list list;

list * createNew(int value);
list * delete(list * listDelete, int position);
list * addFirst(list * myList, int value);
list * addLast(list * myList, int value);
void displayInt(list * myList);
int searchOccurence(list * myList, int nb);
int searchPosition(list * myList, int value);
list * searchEntier(list * myList,int value, int verif);
list * fusionList(list * listA, list * listB);
int countElement(list * myList);



#endif
