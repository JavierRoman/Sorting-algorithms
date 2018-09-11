#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"
#include "utils.h"

void swap(int i, int j, int *list)
{
    int tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
}

void selection(int *list, int len)
{
    int lessIndex = 0;
    for (int i = 0; i < len-1; i++)
    {
        lessIndex = i;
        for (int j = i+1; j < len; j++) 
            if (list[j] < list[lessIndex]) 
                lessIndex = j;

        swap(i, lessIndex, list);        
    }
}

void insertion(int *list, int len)
{
    for (int i = 1; i < len; i++) 
    {
        for (int j = i; j > 0; j--)
        {
            if (list[j] < list[j-1]) 
                swap(j, j-1, list);
            else break;
        }
    }
}

void bubble(int *list, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i-1; j++) 
        {
            if (list[j] > list[j+1])
                swap(j, j+1, list);
        }
    }
}

int partition(int l, int r, int pivot, int *list)
{
    while (l <= r)
    {
        while (list[l] < pivot) l++;
        while(list[r] > pivot) r--;
        if (l <= r)
        {
            swap(l, r, list); l++; r--;
        }
    }

    return l;
}

void quicksortRecursive(int ini, int end, int *list)
{
    int pivot = list[(ini+end)/2], m = 0;
    
    if (ini >= end) return;

    m = partition(ini, end, pivot, list);

    // QS left
    quicksortRecursive(ini, m-1, list);
    //QS right
    quicksortRecursive(m, end, list);
}

void quicksort(int *list, int len)
{
    quicksortRecursive(0, len-1, list);
}

int *merge(int *listA, int lenA, int *listB, int lenB)
{
    int a = 0, b = 0, l = 0;
    int *list = NULL;
    
    list =  (int *) malloc(sizeof(int) * (lenA+lenB));
    if (NULL == list) return NULL;

    for (l = 0; l < (lenA + lenB); l++)
    {
        if (a >= lenA && b < lenB) list[l] = listB[b++];
        else if (b >= lenB && a < lenA) list[l] = listA[a++];
        else if (a < lenA && b < lenB)
        {
            if (listA[a] < listB[b]) list[l] = listA[a++];
            else list[l] = listB[b++];
        }
        else break;
    }
    
    
    free(listA);
    free(listB);

    return list;
}

void mergesort(int *list, int len)
{
    // List variables
    int half = len/2, lenL = half+1, lenR = len-half-1;
    int *leftList = NULL, *rightList = NULL, *tmp = NULL;

    if (1 == len) return;
    else if (2 == len && list[0] > list[1]) 
    {
        swap(0, 1, list);
        return;
    }
    else if (2 == len && list[0] <= list[1]) return;

    //Left
    leftList = getSubList(0, lenL, list);
    mergesort(leftList, lenL);

    //Right
    rightList = getSubList(half+1, lenR, list);
    mergesort(rightList, lenR);

    tmp = merge(leftList, lenL, rightList, lenR);
    if (NULL == tmp) 
    {
        free(list);
        list = NULL;
        return;
    }
    copyListContent(list, tmp, len);
    free(tmp);
}




