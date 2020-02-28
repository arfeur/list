/**
  * Author: Arthur Dherbomez;
  * FileName: main.c;
  * Description: Permet d'utiliser les fonctions du ListManager;
  * Date: 28/02/2020;
  */
#include <stdlib.h>
#include <stdio.h>
#include "ListManager.h"
#include "ListManager.c"


int main()
{   
    /* Exercice 1 */
    list * myList = createNew(3);
    addLast(myList,2);
    addLast(myList,2);
    addLast(myList,4);
    addLast(myList,5);
    addLast(myList,6);

    /* Exercice 2 */
    printf("Exercice 2: ");
    displayInt(myList);
    printf("\n");

    /* Exercice 3 */
    printf("Exercice 3: ");
    searchOccurence(myList,4);
    printf("%d\n",searchOccurence(myList,4));

    /* Exercice 4 */
    printf("Exercice 4: ");
    myList = searchEntier(myList, 4, 1);
    displayInt(myList);
    printf("\n");
    
    /* Exercice 5 */
    list * listB = createNew(4);
    addLast(listB,2);
    addLast(listB,2);
    addLast(listB,4);

    myList = fusionList(myList,listB);

    /* Exercice 6 */
    printf("Exercice 6: ");
    int count = countElement(myList);
    printf("Count :%d\n",count);

    return 0;

}
