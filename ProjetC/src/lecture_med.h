#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#define sz 20
#define jm 3
#define aa 5

typedef struct {
   int jour;
   int mois;
    int annee;
}Date;
/*
struct hotel1
 {
    char id[sz];
    char nom[sz];
    char classement[sz];
    char nombrech[sz];
    char adresse[sz];
    char email[sz];
    char num[sz];
 };
typedef struct hotel1 hot;
*/

typedef struct  
 {
    char id[sz];
    char nom[sz];
    char classement[sz];
    char nombrech[sz];
    char adresse[sz];
    char email[sz];
    char num[sz];

}hotel;


typedef struct 
 {
    char id[sz];
    char nom[sz];
    char destination[sz];
    char lieude[sz];
   // char datedepart[sz];
    Date datedepart;
    
 }vol;




void lecture_hotel(FILE *f,hotel T[]);
void lecture_vol(FILE *f,vol T[]);
void ajouter_h(hotel hot);
void supprimer_h(char cin[]);
hotel chercher_h(char x[]);
//void modifier_h(hotel);

int auto_incre_id_ho();
void modifier_h(hotel hot1);
void ajouter_vol(vol v);
void supprimer_vol(char cin[]);
vol chercher_vol(char x[]);

void modifier_vol(vol v1);
int auto_incre_id_v();
/*
enum
{ID=0,
NOM,
CLASSEMENT,
NOMBRECH,
ADRESSE,
COL
};*/
//ID, id, NOM, nom,DESTINATION,destination, JOUR,jour,MOIS,mois, ANNEE ,annee ,LIEUDE,lieude,-1);
enum
{ID=0,
NOM,
CLASSEMENT,
EMAIL,
NUM,
ADRESSE,
NOMBRECH,
COL
};

void afficher(GtkWidget *treeview_hotel);

enum
{IDI=0,
NOMI,
DESTINATION,
JOUR,
MOIS,
ANNEE,
LIEUDE,
COLUMNS
};

void afficherr(GtkWidget *treeview_vol);
