#include "lecture_med.h"


void lecture_hotel(FILE *f,hotel T[])
{
		char filename[sz]="hotel.txt";
		char ide[sz]; char name[sz]; char famname[sz]; char use[sz]; char pwd[sz];
		char mail[50];
		int i=0;
		f=fopen(filename,"r");

			while (fscanf(f, "%s %s %s %s %s %s\n",ide,name,famname,use,pwd,mail) != EOF )
				 {
					 

				   strcpy(T[i].id, ide);
				   strcpy(T[i].nom, name);
			           strcpy(T[i].classement, famname);
				   strcpy(T[i].nombrech, use);
			           strcpy(T[i].adresse, pwd);
					
				   strcpy(T[i].email,mail);

				   i++;
				 }
			fclose(f);
	}



void lecture_vol(FILE *f,vol T[])
{
	char filename[sz]="vol.txt";
	char ide[sz]; char name[sz]; char famname[sz]; char use[sz]; 
	int i=0,j,m,a;
	f=fopen(filename,"r");

		while (fscanf(f, "%s %s %s %s %d %d %d\n",ide,name,famname,use,&j,&m,&a) != EOF )
			 {
				 strcpy(T[i].id, ide);
				 strcpy(T[i].nom, name);
				 strcpy(T[i].destination, famname);
				 strcpy(T[i].lieude,use);
				 T[i].datedepart.jour=j;
                                 T[i].datedepart.mois=m;
                                 T[i].datedepart.annee,a;

				 i++;
			 }
		fclose(f);

}

/*typedef struct 
 {
    char id[sz];
    char nom[sz];
    char destination[sz];
    char lieude[sz];
   // char datedepart[sz];
    Date datedepart;
    
 }vol;*/

