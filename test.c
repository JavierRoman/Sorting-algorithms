#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"
#include "utils.h"

#define ALGCOUNT 5
#define ALGNAMELEN 50

int main(int argc, char const *argv[])
{
    void (*sortingAlgorithms[])(int *, int) = {selection, insertion, bubble, quicksort, mergesort};
    char algorithmNames[ALGCOUNT][ALGNAMELEN] = {"selectSort", "insertSort", "bubbleSort", "quickSort", "mergeSort"};
    int len = 0, *list = NULL, *copiedList = NULL;    
    
    list = introduceList(&len);
    if (NULL == list) return 1;
    printf("Your list is: ");
    printList(list, len);

    for (int i = 0; i < ALGCOUNT; i++)
    {
        copiedList = copyList(list, len);
        if (NULL == copiedList) return 1;
        sortingAlgorithms[i](copiedList, len);
        fprintf(stdout, "After %s: ", algorithmNames[i]);
        printList(copiedList, len);
        free(copiedList);
    }

    free(list);    
    return 0;
}
