#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extension.h"
#include <time.h> 





int main(){
int i;
int k;
int m;
//----------------------------------nombre de ligne-----------------------------------------------------------------------------------------------------------------------------------------------
	srand(time(NULL));
	int nbligne=0;//le nombre de lignes de données
	FILE * fichier=fopen("airbnb_donnees_propre.csv","r");  
	char texte[256];
	fgets(texte,255,fichier); 
	while(fgets(texte,255,fichier)!=NULL)
	{
		nbligne++;//on incrémente dès qu'on sait le nombre de ligne
	}
	fclose(fichier);
	printf("%d lignes\n",nbligne);
//-----------------------------------donnée de l'appartement----------------------------------------------------------------------------------------------------------------------------------

    	struct logement{
    	int accommodates;
    	int bedrooms;
    	int bathrooms;
    	int beds;
    	int prix;
    	int minimum_nights;
    	int maximum_nights;
    	int number_of_reviews;
    	};
    	struct logement x1;	
    	
        		printf("accommodates:");
        		scanf("\n%d",&x1.accommodates);
        	
        		printf("bedrooms:");
        		scanf("\n%d",&x1.bedrooms);
		
			printf("bathrooms:");
			scanf("\n%d",&x1.bathrooms);
			
			printf("beds:");
			scanf("\n%d",&x1.beds);
			
			printf("prix:");
			scanf("\n%d",&x1.prix);
			
			printf("minimum_nights:");
			scanf("\n%d",&x1.minimum_nights);
			
			printf("maximum_nights:");
			scanf("\n%d",&x1.maximum_nights);
				
			printf("number_of_reviews:");
			scanf("\n%d",&x1.number_of_reviews);
			      			
        			 
        		 
//----------------------------------------------------------------ouverture de ficher et séparation de colonne-------------------------------------------------------------------------------   	
 	 	
	int j=0; //c'est pour le while au moment de saisir de 1 à 8
	FILE * fichier2=fopen("airbnb_donnees_propre.csv","r");
	char texte2[256]; //enregistrer le texte
	fgets(texte2,255,fichier2); //enregistrement des nom de colonne
	char * colonne = strtok (texte2, "," );//decouper la colonne
	double distance[nbligne];//on va ranger les distances 
	int dist[nbligne];//on va ranger les distances en enlevant le négatif
	int ordre[nbligne];// ranger les numéros de series issue de la première colonne
	int prix[nbligne];//on va ranger les prix
//------------------------------------------------------------------choix de calcul et le nombre k premier à utiliser-------------------------------------------------------------------------	
	while(j==0 || j>8){
		printf("vous voulez calculer quoi?\n");
		printf("1-accommodates\n2-bedrooms\n3-bathrooms\n4-beds\n5-prix\n6-minimum_nights\n7-maximum_nights\n8-number_of_reviews\n");
	scanf("%d",&j);
	}
	
//-------------------------------------------------------------calcul de distance avec les autres appartement----------------------------------------------------------------------------------- 	
	for(i=0;i<nbligne;i++)
	{
		fgets(texte2,255,fichier2);	//enregistrement des premieres données chiffrés
		colonne = strtok (texte2, "," );//les données à couper
		ordre[i]=atoi(colonne);//convertir le numéro de serie char en int
		
	
		for(k=1;k<j+1;k++){       
        	colonne = strtok (NULL, ",");
        	if (k==5){
        		prix[i]=atoi(colonne);//enregistrer le prix
        	}
        	} //séparation des données selon une virgule qui sépare	
        	
        	switch(j)
        	{
        		case 1:
        		distance[i]=(x1.accommodates-atoi(colonne));//distance de accommodates
        		for(k=1;k<5;k++){       
        		colonne = strtok (NULL, ",");
        		if (k==4){//enregistrer le prix
        		prix[i]=atoi(colonne);
        		}}
        		if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
        		break;
        		case 2:
        		distance[i]=(x1.bedrooms-atoi(colonne));//distance de bedroom
        		for(k=2;k<5;k++){       
        		colonne = strtok (NULL, ",");
        		if (k==4){//enregistrer le prix
        		prix[i]=atoi(colonne);
        		}}
        		if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 3:
			distance[i]=(x1.bathrooms-atoi(colonne));//distance de bathroom
			for(k=3;k<5;k++){       
        		colonne = strtok (NULL, ",");
        		if (k==4){//enregistrer le prix
        		prix[i]=atoi(colonne);
        		}}
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 4:
			distance[i]=(x1.beds-atoi(colonne));//distance de beds
			for(k=4;k<5;k++){       
        		colonne = strtok (NULL, ",");
        		if (k==4){//enregistrer le prix
        		prix[i]=atoi(colonne);
        		}}
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 5:
			distance[i]=(x1.prix-atoi(colonne));//distance de prix
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 6:
			distance[i]=(x1.minimum_nights-atoi(colonne));//distance de minimum_nights
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 7:
			distance[i]=(x1.maximum_nights-atoi(colonne));if(distance[i]<0)//distance de maximum_nights
        		{dist[i]=distance[i]*(-1);}//enlever le négatif
        		else{dist[i]=distance[i];}
			
			break;
			case 8:
			distance[i]=(x1.number_of_reviews-atoi(colonne));//distance de number of review
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;         					 
        	
        	}
        	
        }	       		
    	
	fclose(fichier2);
	
  	
//--------------------------------------------------------------------choix du k premier d'appartement et tri dans l'ordre décroissant-----------------------------------------------------------------
	triRapid(dist,ordre,prix,0,nbligne-1); //tri des distance avec le prix et le numero de série dans l'ordre croissant
	int l;//c'est le k nombre 
	int moyenne=0;
	int moyenneprix=0;
	printf("votre k nombre à afficher\n");
	scanf("%d",&l);//remplir le k nombre
	for(i = 0; i < l; i++)  {
	moyenne=moyenne+dist[i];//calcul de moyenne en faisant d'abord une somme
	moyenneprix=moyenneprix+prix[i];
	printf("%d:la distance est de %d\n",ordre[i],dist[i]);}//afficher les k premiers distances avec leurs numéros de séries
	moyenne=moyenne/l;//calcul de moyenne
	moyenneprix=moyenneprix/l;//calcul de moyenne
	printf("\nla moyenne de distance est de %d\n",moyenne);//afficher la moyenne des k premiers données  
	printf("la moyenne de prix est de %d\n",moyenneprix);//afficher la moyenne des k premiers données  
//---------------------------de manière k aléatoire--------------------------------------------------------------------------------------------------------------------------------------------	
	
	moyenne=0;
	moyenneprix=0;
	int aleatoire[l];//ranger les nombre aléatoire
	int z=0;//pour le enième nombre aléatoire	
	FILE * fichier3=fopen("airbnb_donnees_propre.csv","r");
	char texte3[256]; 
	fgets(texte3,255,fichier3); //enregistrement des nom de colonne
	char * colonne1 = strtok (texte3, "," );
	double distancedesordre[l];//on va ranger les distances aléatoirement
	int distdesordre[l]; //on va ranger les distances aléatoirement en enlevant le négatif
	int desordre[l];// ranger les numéros de series issue de la première colonne dans le désordre
	int prixale[l];// ranger les prix aléatoirement en entier
	for(m=0;m<l;m++)
	{
	aleatoire[m]=rand()%(nbligne+1);//générer le nombre aléatoire entre 0 et le nombre de données
	}
	triRapid1(aleatoire,0,l-1);//mettre les numéro aléatoire dans l'ordre croissant
	
	for(i=0;i<nbligne;i++)
	{
		
		fgets(texte3,255,fichier3);	//enregistrement des premieres données chiffrés
		colonne1 = strtok (texte3, "," );//les données à couper
	    	if(i==aleatoire[z]) //nième ligne
		{ 	desordre[z]=atoi(colonne1);//enregistrer le premier colonne qui contient les numéros de séries dans le désordre en convertissant en entier
				        	
			for(k=1;k<j+1;k++){       
        			colonne1 = strtok (NULL, ",");
        			if (k==5){
        			prixale[z]=atoi(colonne);//enregistrer le prix
        			}} //séparation des données selon une virgule qui sépare	
        		switch(j){
        		case 1:
        		distancedesordre[z]=(x1.accommodates-atoi(colonne1));//distance de accommodates
        		for(k=1;k<5;k++){       
        			colonne = strtok (NULL, ",");
        			if (k==4){
        			prixale[z]=atoi(colonne);//enregistrer le prix
        		}}
        		if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
        		break;
        		case 2:
        		distancedesordre[z]=(x1.bedrooms-atoi(colonne1));//distance de bedroom
        		for(k=2;k<5;k++){       
        			colonne = strtok (NULL, ",");
        			if (k==4){
        				prixale[z]=atoi(colonne);//enregistrer le prix
        		}}
        		if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
			break;
			case 3:
			distancedesordre[z]=(x1.bathrooms-atoi(colonne1));//distance de bathroom
			for(k=3;k<5;k++){       
        			colonne = strtok (NULL, ",");
        			if (k==4){
        				prixale[z]=atoi(colonne);//enregistrer le prix
        		}}
			if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
			break;
			case 4:
			distancedesordre[z]=(x1.beds-atoi(colonne1));//distance de beds
			for(k=4;k<5;k++){       
        			colonne = strtok (NULL, ",");
        			if (k==4){
        				prixale[z]=atoi(colonne);//enregistrer le prix
        		}}
			if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
			break;
			case 5:
			distancedesordre[z]=(x1.prix-atoi(colonne1));//distance de prix
			if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
			break;
			case 6:
			distancedesordre[z]=(x1.minimum_nights-atoi(colonne1));//distance de minimum_nights
			if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
			break;
			case 7:
			distancedesordre[z]=(x1.maximum_nights-atoi(colonne1));//distance de maximum_nights
			if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
			break;
			case 8:
			distancedesordre[z]=(x1.number_of_reviews-atoi(colonne1));//number of reviews
			if(distancedesordre[z]<0)//enlever le négatif
        			{distdesordre[z]=distancedesordre[z]*(-1);}
        		else{distdesordre[z]=distancedesordre[z];}
			break;
			default:
			break;         			
      			}
        		z=z+1;//on incrémente pour le prochain rang aléatoire à trouver parmi la liste de logement 
        	}
        }                                              
        			 
        	       		   	
	fclose(fichier3);
	triRapid(distdesordre,desordre,prixale,0,l-1); //tri des distance aleatoirement dans l'ordre croissant
	printf("\naléatoirement\n");
	for(i = 0; i < l; i++)  {
		moyenne=moyenne+distdesordre[i];//calcul de moyenne en faisant d'abord une somme
		moyenneprix=moyenneprix+prixale[i];
		printf("%d:la distance est de %d\n",desordre[i],distdesordre[i]);}//afficher les k premiers distances avec leurs numéros de séries
	
	moyenne=moyenne/l;//calcul de moyenne
	moyenneprix=moyenneprix/l;//calcul de moyenne
	printf("\nla moyenne de distance est de %d\n",moyenne);//afficher la moyenne des k premiers données aléatoire
	printf("la moyenne de prix est de %d\n",moyenneprix);//afficher la moyenne des k premiers données aléatoire


	
    return 0;


}



	
	
	
	


