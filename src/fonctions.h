#include <gtk/gtk.h>
#include <glib.h>

void inscription_client(int num_res,char nom[],char adresse [],char prenom[],char pays[],char telephone[],char email[],char hotel[],int nbr_adulte,int nbr_enfant,char dateDepart[], char dateRetour[],char sexe[]);

void afficher_reseration (GtkTreeView *treeview1);

void   supprimerReservation(char num_res[]);
	


void modifierReservation(char num_res[],char nom1[],char prenom1[],char sexe1[],char adresse1[],char email1[],char telephone1[],char pays1[],
  char hotel1[],char nbr_adulte1[],char nbr_enfant1[],char dateDepart1[],char dateRetour1[] );



