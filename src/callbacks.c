#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#define _OPEN_SYS_ITOA_EXT
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <glib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h" 								
#include "fonctions.h"
#include "fonctions.c"

void on_ajouter_clicked(GtkWidget     *objet_graphique, gpointer   user_data)
{
  int num_res = get_last_id()+1;
	char nom[20];
	char adresse [20];
	char prenom[20];
	char pays[20];
	char nom_dutilisateur[20];
	char mot_de_passe[20];
	char telephone[20];
	char email[20];
  char hotel[20];
	int nbr_adulte;
	int nbr_enfant;
	char dateDepart[20];
	char dateRetour[20];
	char sexe[2];

    GtkWidget *entry1;
  	GtkWidget *entry2;
	  GtkWidget *entry3;
    GtkWidget *entry4;
    GtkWidget *entry5;
    GtkWidget *entry6;
	  GtkComboBox *hotel_combobox;
	  GtkWidget *fenetre_inscription;
	  GtkWidget *nbr_enfant_spinbutton;
	  GtkWidget *nbr_adulte_spinbutton;
	  GtkCalendar *calDepart;
  	GtkCalendar *calRetour;	
  	GtkWidget *hommeR;
    GtkWidget *femmeR;

	fenetre_inscription=lookup_widget(objet_graphique,"fenetre_inscription");
	  entry1=lookup_widget(objet_graphique,"nom");
	  entry2=lookup_widget(objet_graphique,"prenom");
    entry3=lookup_widget(objet_graphique,"adresse");
    entry4=lookup_widget(objet_graphique,"telephone");
    entry5=lookup_widget(objet_graphique,"email");
    entry6=lookup_widget(objet_graphique,"pays");
	  hotel_combobox=lookup_widget(objet_graphique,"hotel");
    nbr_adulte_spinbutton= lookup_widget(objet_graphique,"nbr_adulte");
	  nbr_enfant_spinbutton= lookup_widget(objet_graphique,"nbr_enfant");
	  calDepart=lookup_widget(objet_graphique,"date_depart");
	  calRetour=lookup_widget(objet_graphique,"date_retour");
	  hommeR=lookup_widget(objet_graphique,"h"); 		
	  femmeR=lookup_widget(objet_graphique,"f"); 

	if (gtk_entry_get_text_length(entry1)==0){
		 GtkDialog *dialog = gtk_message_dialog_new (user_data,
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_INFO,
                                  GTK_BUTTONS_CLOSE,
                                  "Veuillez saisir un nom valide !",
                                  "", g_strerror (objet_graphique));
		gtk_dialog_run (GTK_DIALOG (dialog));
 		gtk_widget_destroy (dialog);
		return -1;
	}else 
		strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry1)));
	
  if (gtk_entry_get_text_length(entry2)==0){
		 GtkDialog *dialog = gtk_message_dialog_new (user_data,
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_INFO,
                                  GTK_BUTTONS_CLOSE,
                                  "Veuillez saisir un prenom valide !",
                                  "", g_strerror (objet_graphique));
		gtk_dialog_run (GTK_DIALOG (dialog));
 		gtk_widget_destroy (dialog);
		return -1;
	}else 
     strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(entry2)));



	nbr_adulte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbr_adulte_spinbutton));
	nbr_enfant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbr_enfant_spinbutton));


	strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(entry3)));	
	strcpy(telephone,gtk_entry_get_text(GTK_ENTRY(entry4)));
	strcpy(email,gtk_entry_get_text(GTK_ENTRY(entry5)));
    strcpy(pays,gtk_entry_get_text(GTK_ENTRY(entry6)));
   	strcpy(hotel,gtk_combo_box_get_active_text(GTK_COMBO_BOX(hotel_combobox)));
	g_snprintf(dateDepart,30,"%d:%d:%d",calDepart->day,calDepart->month+1,calDepart->year);	
	g_snprintf(dateRetour,30,"%d:%d:%d",calRetour->day,calRetour->month+1,calRetour->year);	
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hommeR))==TRUE)
		{strcpy(sexe,"H");;}
	else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femmeR))==TRUE)
		{strcpy(sexe,"F");;}


	inscription_client (num_res,nom,adresse,prenom,pays,telephone,email,hotel,nbr_adulte,nbr_enfant,dateDepart,dateRetour,sexe);
  	GtkWidget *treeview1;
  	fenetre_inscription=lookup_widget(objet_graphique,"fixed8");
  	treeview1=lookup_widget( fenetre_inscription,"treeview1");
  	afficher_reservation(treeview1);
}



void
on_afficher_clicked(GtkWidget *objet_graphique,gpointer user_data)

{

  GtkWidget *fenetre_inscription;
  GtkWidget *treeview1;

  fenetre_inscription=lookup_widget(objet_graphique,"fenetre_inscription");
  
  treeview1=lookup_widget( fenetre_inscription,"treeview1");
  afficher_reservation(treeview1);

}



void
on_supprimer_clicked (GtkButton  *objet_graphique,gpointer user_data)
{
  GtkWidget *input1;  
  gchar  *num_res;

  input1=lookup_widget(objet_graphique,"num_res"); 
  strcpy(&num_res,gtk_entry_get_text(GTK_ENTRY(input1)));
  g_print("%s",&num_res);

  supprimerReservation(&num_res);




}


void
on_treeview1_row_activated(GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{ 
gchar *num_res;
gchar *nom;
gchar *prenom;
gchar *sexe;
gchar *adresse;
gchar *email;
gchar *telephone;
gchar *pays;
gchar *hotel;
gchar *nbr_adulte;
gchar *nbr_enfant;
gchar *dateDepart;
gchar *dateRetour;

   GtkTreeModel *model = gtk_tree_view_get_model(treeview);
   gchar *string;
   GtkTreeIter iter;

   gtk_tree_model_get_iter(model, &iter, path); 
   gtk_tree_model_get (model, &iter, ID_RES ,&num_res ,NOM, &nom,PRENOM 
   ,&prenom,SEXE,&sexe,ADRESSE,&adresse,PAYS,&pays
   ,TELEPHONE,&telephone,EMAIL,&email,HOTEL
   ,&hotel,ADULTE,&nbr_adulte,ENFANT,&nbr_enfant
   ,DEPART,&dateDepart,RETOUR,&dateRetour,-1);
	

    GtkEntry *id_entry;
  id_entry = lookup_widget(treeview,"num_res");
  gtk_entry_set_text(id_entry,num_res);


  GtkEntry *entry1;
  entry1 = lookup_widget(treeview,"entry1");
  gtk_entry_set_text(entry1,nom);
 	
    
    GtkEntry *entry2;
	  GtkEntry *entry3;
    GtkEntry *entry4;
    GtkEntry *entry5;
    GtkEntry *entry6;
	  GtkEntry *entry7;
 	  GtkEntry *entry8;
	  GtkEntry *entry9;
    GtkEntry *entry10;
    GtkEntry *entry11;
    GtkEntry *entry12;

	
	  entry2=lookup_widget(treeview,"entry2");
    entry3=lookup_widget(treeview,"entry3");
    entry4=lookup_widget(treeview,"entry4");
    entry5=lookup_widget(treeview,"entry5");
    entry6=lookup_widget(treeview,"entry6");
	  entry7=lookup_widget(treeview,"entry7");
	  entry8=lookup_widget(treeview,"entry8");
    entry9=lookup_widget(treeview,"entry9");
    entry10=lookup_widget(treeview,"entry10");
    entry11=lookup_widget(treeview,"entry11");
    entry12=lookup_widget(treeview,"entry12");
	
gtk_entry_set_text(entry1,nom);
gtk_entry_set_text(entry2,prenom);
gtk_entry_set_text(entry3,sexe);
gtk_entry_set_text(entry4,adresse);
gtk_entry_set_text(entry5,pays);
gtk_entry_set_text(entry6,telephone);
gtk_entry_set_text(entry7,email);
gtk_entry_set_text(entry8,hotel);
gtk_entry_set_text(entry9,nbr_adulte);
gtk_entry_set_text(entry10,nbr_enfant);
gtk_entry_set_text(entry11,dateDepart);
gtk_entry_set_text(entry12,dateRetour);




  //afficher_reservation(treeview);
  
}


void
on_modifier_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input1;  
  GtkWidget *input2; 
  GtkWidget *input3;  
  GtkWidget *input4;  
  GtkWidget *input5;  
  GtkWidget *input6;  
  GtkWidget *input7;  
  GtkWidget *input8; 
  GtkWidget *input9;
  GtkWidget *input10;  
  GtkWidget *input11; 
  GtkWidget *input12;
  GtkWidget *id_wid;
  
char  nom1[20];
char  prenom1[20];
char  sexe1[20];
char  adresse1[20];
char  email1[20];
char  telephone1[20];
char  pays1[20];
char  hotel1[20];
char  nbr_adulte1[20];
char  nbr_enfant1[20];
char dateDepart1[20];
char dateRetour1[20];
char num_res[20];

  id_wid=lookup_widget(objet_graphique,"num_res"); 
  input1=lookup_widget(objet_graphique,"entry1"); 
  input2=lookup_widget(objet_graphique,"entry2"); 
  input3=lookup_widget(objet_graphique,"entry3"); 
  input4=lookup_widget(objet_graphique,"entry4"); 
  input5=lookup_widget(objet_graphique,"entry5"); 
  input6=lookup_widget(objet_graphique,"entry6");
  input7=lookup_widget(objet_graphique,"entry7"); 
  input8=lookup_widget(objet_graphique,"entry8"); 
  input9=lookup_widget(objet_graphique,"entry9"); 
  input10=lookup_widget(objet_graphique,"entry10"); 
  input11=lookup_widget(objet_graphique,"entry11");
  input12=lookup_widget(objet_graphique,"entry12"); 

  strcpy(num_res,gtk_entry_get_text(GTK_ENTRY(id_wid)));
  strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(prenom1,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(sexe1,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(adresse1,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(email1,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(telephone1,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(pays1,gtk_entry_get_text(GTK_ENTRY(input7)));
  strcpy(hotel1,gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(nbr_adulte1,gtk_entry_get_text(GTK_ENTRY(input9)));
  strcpy(nbr_enfant1,gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(dateDepart1,gtk_entry_get_text(GTK_ENTRY(input11)));
  strcpy(dateRetour1,gtk_entry_get_text(GTK_ENTRY(input12)));

  modifierReservation(num_res,nom1,prenom1,sexe1,adresse1,email1,telephone1,pays1,
  hotel1,nbr_adulte1,nbr_enfant1,dateDepart1,dateRetour1 );
}




gboolean
on_treeview1_select_cursor_row         (GtkTreeView     *treeview,
                                        gboolean         start_editing,
                                        gpointer         user_data)
{
g_print("Row selected ");
  return FALSE;
}

