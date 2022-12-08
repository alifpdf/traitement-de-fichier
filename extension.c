#include <stdio.h>
#include "math.h"
#include <string.h>
	

/*int nb_logement(int j) //connaitre le nombre de ligne
{	
	j=0;
	FILE * fichier=fopen("airbnb_donnees_propre.csv","r");  
	char texte[256];
	fgets(texte,255,fichier); //enregistrement des noms de colonnes
	while(fgets(texte,255,fichier)!=NULL)
	{
		j++;
	}
	
	fclose(fichier);
	return j;
	

}



int colonne(int j) //connaitre le nombre de colonne

{
	FILE * fichier=fopen("airbnb_donnees_propre.csv","r");
	char texte1[256]; 
	fgets(texte1,255,fichier); //enregistrement des nom de colonne
	fgets(texte1,255,fichier);	//enregistrement des premiers données
	char * Token = strtok (texte1, "," );
    
    	while (Token != NULL) //connaissance du nombre de colonnes
    	{
        	Token = strtok (NULL, ","); //séparation des données selon une virgule qui sépare
        	 j++; 
        	
    	}
    	fclose(fichier);
    	return j;
    	
	 

}*/

void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void triRapid(int tab[],int tab1[], int first, int last) {
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
            }
        }
        permuter(&tab[pivot], &tab[j]);
        permuter(&tab1[pivot], &tab1[j]);
        triRapid(tab,tab1, first, j - 1);
        triRapid(tab,tab1, j + 1, last);
    }
}




	
	
	
	



