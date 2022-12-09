#include <stdio.h>
#include "math.h"
#include <string.h>
#include <time.h> 
#include <stdlib.h>	



void permuter(int *a, int *b) { //permutation
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void triRapid(int tab[],int tab1[],int tab2[], int first, int last) { //trirapide
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
                permuter(&tab1[i], &tab1[j]);
                permuter(&tab2[i], &tab2[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        permuter(&tab1[pivot], &tab1[j]);
        triRapid(tab,tab1,tab2, first, j - 1);
        triRapid(tab,tab1,tab2, j + 1, last);
    }
}

void triRapid1(int tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
       
        triRapid1(tab, first, j - 1);
        triRapid1(tab, j + 1, last);
    }
}






	
	
	
	


