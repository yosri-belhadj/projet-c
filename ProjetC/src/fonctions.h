#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define sz 20
#define szm 50
#define jm 3
#define aa 5

struct date{
  char jour[jm];
  char mois[jm];
  char anne[aa];
};

struct adress{
  char ville[sz];
  char rue[sz];
};
typedef struct adress adress;
/*
struct hotel{
  char id[sz];
  char classement[sz];
  char nom[sz];
  char nombrech[sz];
  char email[szm];
  char num[sz];
  adress adresse;
};*/
struct vol{
  char id[sz];
  char destination[sz];
  char lieude[sz];
   struct date Date;
};


typedef struct personel hotel;

void ajouter_h(hotel hot);
void supprimer_h(char cin[]);
hotel chercher_h(char x[]);
//void modifier_h(hotel);
int auto_incre_id_ho();
void modifier_h(hotel hot1);

typedef struct personel vol;

void ajouter_vol(vol v);
void supprimer_vol(char cin[]);
vol chercher_vol(char x[]);

void modifier_vol(vol v1);
int auto_incre_id_v();


