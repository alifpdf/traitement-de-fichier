#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extension.h"
#include <time.h> 
int i;
int k;




int main(){
//----------------------------------nombre de ligne-----------------------------------------------------------------------------------------------------------------------------------------------
	srand(time(NULL));
	int nbligne=0;
	FILE * fichier=fopen("airbnb_donnees_propre.csv","r");  
	char texte[256];
	fgets(texte,255,fichier); 
	while(fgets(texte,255,fichier)!=NULL)
	{
		nbligne++;
	}
	fclose(fichier);
	printf("%d\n",nbligne);
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
 	 	
	int j=0;
	FILE * fichier2=fopen("airbnb_donnees_propre.csv","r");
	char texte2[256]; 
	fgets(texte2,255,fichier2); //enregistrement des nom de colonne
	char * colonne = strtok (texte2, "," );
	double distance[nbligne];//on va ranger les distances 
	int dist[nbligne];//on va ranger les distances en enlevant le négatif
	int ordre[nbligne];// ranger les numéros de series issue de la première colonne
//------------------------------------------------------------------choix de calcul et le nombre k premier à utiliser-------------------------------------------------------------------------	
	while(j==0 || j>8){
		printf("vous voulez calculer quoi?\n");
		printf("1-accommodates\n2-bedrooms\n3-bathrooms\n4-beds\n5-prix\n6-minimum_nights\n7-maximum_nights\n8-number_of_reviews\n");
	scanf("%d",&j);}
	
//-------------------------------------------------------------calcul de distance avec les autres appartement----------------------------------------------------------------------------------- 	
	for(i=0;i<nbligne;i++)
	{
		fgets(texte2,255,fichier2);	//enregistrement des premieres données chiffrés
		colonne = strtok (texte2, "," );//les données à couper
		ordre[i]=atoi(colonne);
		
	
		for(k=1;k<j+1;k++){       
        	colonne = strtok (NULL, ",");} //séparation des données selon une virgule qui sépare	
        	
        	switch(j)
        	{
        		case 1:
        		distance[i]=(x1.accommodates-atoi(colonne));
        		if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
        		break;
        		case 2:
        		distance[i]=(x1.bedrooms-atoi(colonne));
        		if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 3:
			distance[i]=(x1.bathrooms-atoi(colonne));
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 4:
			distance[i]=(x1.beds-atoi(colonne));
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 5:
			distance[i]=(x1.prix-atoi(colonne));
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 6:
			distance[i]=(x1.minimum_nights-atoi(colonne));
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;
			case 7:
			distance[i]=(x1.maximum_nights-atoi(colonne));if(distance[i]<0)//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			
			break;
			case 8:
			distance[i]=(x1.number_of_reviews-atoi(colonne));
			if(distance[i]<0)		//enlever le négatif
        		{dist[i]=distance[i]*(-1);}
        		else{dist[i]=distance[i];}
			break;         			
		 
        	}
        }	       		
    	
	fclose(fichier2);
	
  	
//--------------------------------------------------------------------choix du k premier d'appartement et tri dans l'ordre décroissant-----------------------------------------------------------------
	triRapid(dist,ordre,0,nbligne-1); //tri des distance dans l'ordre décroissant
	int l;
	int moyenne=0;
	printf("votre k nombre à afficher\n");
	scanf("%d",&l);
	for(i = 0; i < l; i++)  {
	moyenne=moyenne+dist[i];//calcul de moyenne en faisant d'abord une somme
	printf("%d:la distance est de %d\n",ordre[i],dist[i]);}//afficher les k premiers distances avec leurs numéros de séries
	moyenne=moyenne/l;//calcul de moyenne
	printf("la moyenne de distance est de %d\n",moyenne);//afficher la moyenne des k premiers données  
//---------------------------de manière k aléatoire--------------------------------------------------------------------------------------------------------------------------------------------	
	
	int aleatoire;	
	FILE * fichier3=fopen("airbnb_donnees_propre.csv","r");
	char texte3[256]; 
	fgets(texte3,255,fichier3); //enregistrement des nom de colonne
	char * colonne1 = strtok (texte3, "," );
	double distancedesordre[nbligne];//on va ranger les distances aléatoirement
	int distdesordre[nbligne]; //on va ranger les distances aléatoirement en enlevant le négatif
	int desordre[nbligne];// ranger les numéros de series issue de la première colonne dans le désordre
	for(i=0;i<nbligne;i++)
	{
		fgets(texte3,255,fichier3);	//enregistrement des premieres données chiffrés
		colonne1 = strtok (texte3, "," );//les données à couper
		aleatoire=rand()%(nbligne);//générer le nombre aléatoire 0 et le nombre de données
		desordre[aleatoire]=atoi(colonne1);//enregistrer le premier colonne qui contient les numéros de séries dans le désordre en convertissant en entier
		
		
        	
		for(k=1;k<j+1;k++){       
        	colonne1 = strtok (NULL, ",");} //séparation des données selon une virgule qui sépare	
        	switch(j){
        		case 1:
        		distancedesordre[aleatoire]=(x1.accommodates-atoi(colonne1));
        		if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
        		break;
        		case 2:
        		distancedesordre[aleatoire]=(x1.bedrooms-atoi(colonne1));
        		if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
			break;
			case 3:
			distancedesordre[aleatoire]=(x1.bathrooms-atoi(colonne1));
			if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
			break;
			case 4:
			distancedesordre[aleatoire]=(x1.beds-atoi(colonne1));
			if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
			break;
			case 5:
			distancedesordre[aleatoire]=(x1.prix-atoi(colonne1));
			if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
			break;
			case 6:
			distancedesordre[aleatoire]=(x1.minimum_nights-atoi(colonne1));
			if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
			break;
			case 7:
			distancedesordre[aleatoire]=(x1.maximum_nights-atoi(colonne1));
			if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
			break;
			case 8:
			distancedesordre[aleatoire]=(x1.number_of_reviews-atoi(colonne1));
			if(distancedesordre[aleatoire]<0)
        		{distdesordre[aleatoire]=distancedesordre[aleatoire]*(-1);}
        		else{distdesordre[aleatoire]=distancedesordre[aleatoire];}
			break;
			default:
			break;         			
      
        	
        	}                                              
        			 
        }	       		
    	
	fclose(fichier3);

//------------------------tri aleatoire--------------------------------------------------------------------------------------------------------------------------------------------------------	
	
	
	
	int selection[l];//donnee en aléatoire
	int selectionordre[l];//numéro de série
	moyenne=0;
	for(i=0;i<l;i++){		
		selection[i]=distdesordre[i];//enregistrer les k premiers distances 
		selectionordre[i]=desordre[i];//enregistrer les k premiers numéros de séries
		moyenne=moyenne+selection[i];//calcul de moyenne en faisant d'abord une somme
		}
	moyenne=moyenne/l;//calcul de moyenne
	triRapid(selection,selectionordre,0,l-1);//tri des k logements aléatoirement
	printf("\naléatoire\n");
        for(i = 0; i < l; i++)  {
	printf("%d:la distance est de %d\n",selectionordre[i],selection[i]);//afficher les k premiers distances qui avait été rangé aléatoirement avec leurs numéros de séries
	
	}	

	printf("la moyenne de distance aléatoirement est de %d\n",moyenne);//afficher la moyenne des k premiers données pris aléatoirement 
    return 0;


}



	
	
	
	



