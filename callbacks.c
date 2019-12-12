#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamag.h"



void
on_actualiserll_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
	GtkWidget *reclamagent;
	GtkWidget *treeview1mm;
reclamagent=lookup_widget(objet_graphique,"reclamagent");
treeview1mm=lookup_widget(reclamagent,"treeview1mm");
afficherreclamag(treeview1mm);
}

void on_Actualiserreclag_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
	GtkWidget *reclamagent;
  	GtkWidget *treeviewrecagmm;
  reclamagent=lookup_widget(objet_graphique,"reclamagent");
  treeviewrecagmm=lookup_widget(reclamagent,"treeviewrecagmm");
  afficherepagmm(treeviewrecagmm);
}


void
on_ajouterrecag_clicked (GtkWidget *objet_graphique,gpointer user_data)
{
	reponsm repm;  
  GtkWidget *input12;  
  GtkWidget *input13; 
  GtkWidget *output1;

input12=lookup_widget(objet_graphique,"spinbuttonrecag"); 		       			   input13=lookup_widget(objet_graphique,"entryreclag"); 
output1=lookup_widget(objet_graphique,"label2133");
  strcpy(repm.numm,gtk_entry_get_text(GTK_ENTRY(input12)));
  strcpy(repm.reponsem,gtk_entry_get_text(GTK_ENTRY(input13)));
if (verifierreclammm(repm.numm)!=0){
gtk_label_set_text(GTK_LABEL(output1),"Veuillez verifier le numéro");}
else 
{
ajouterrepagmm(repm);
gtk_label_set_text(GTK_LABEL(output1),"la reponse est envoyée avec succés");
}
}



