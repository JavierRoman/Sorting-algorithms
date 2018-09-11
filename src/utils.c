#include <stdio.h>
#include <stdlib.h>

void printList(int *list, int len)
{
    printf("[%d", list[0]);
    for (int i = 1; i < len; i++) printf(", %d", list[i]);
    printf("]\n");
}

int *copyList(int *list, int len)
{
    int *copiedList = (int *) malloc(sizeof(int)*len);
    if (NULL == copiedList) return NULL;

    for (int i = 0; i < len; i++) copiedList[i] = list[i];

    return copiedList;
}

int *introduceList(int *len) 
{
    int *list = NULL;
    printf("Tell me the length of the list: ");
    scanf("%d", len);

    list = (int *) malloc(*len * sizeof(int));
    if (NULL == list) 
    {
        printf("Could not allocate memory\n");
        return NULL;
    }

    printf("Introduce the list of numbers: \n");
    for (int i = 0; i < *len; i++) scanf("%d", &list[i]);

    return list;
}

int *getSubList(int ini, int len, int *list)
{
    int *subList = NULL;
    int i = 0;

    subList = (int *) malloc(sizeof(int)*len);
    if (NULL == subList) return NULL;

    for (i = ini; i < ini + len; i++) subList[i-ini] = list[i];

    return subList;
}

void copyListContent(int *dst, int *src, int len)
{
    for (int i = 0; i < len; i++) dst[i] = src[i];
}