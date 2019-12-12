#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
//#include "treevieww.h"
#include "lecture_med.h"


void on_Agent_window_show (GtkWidget *objet_graphique,  gpointer user_data)

{
  GtkWidget *Agent_window;
  GtkWidget *treeview_hotel;
  Agent_window=lookup_widget(objet_graphique,"Agent_window");
  treeview_hotel=lookup_widget(Agent_window,"treeview_hotel");
  afficher(treeview_hotel);

  GtkWidget *Agent_windoww;
  GtkWidget *treeview_vol;
  Agent_windoww=lookup_widget(objet_graphique,"Agent_window");
  treeview_vol=lookup_widget(Agent_window,"treeview_vol");
  afficherr(treeview_vol);


}

void on_quit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  /*GtkWidget *login_window; /*nchouf el jme3a chmseminha*/
  GtkWidget *Agent_window;

 /* login_window = create_login_window ();*/
 /* gtk_widget_show (login_window);*/
  Agent_window=lookup_widget(objet_graphique,"Agent_window");
  gtk_widget_hide(Agent_window);
}

void on_ajouter_nouveau_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_hotel;
  GtkWidget *Agent_window;

  ajouter_nouveau_hotel = create_ajouter_hotel_window ();
  gtk_widget_show (ajouter_nouveau_hotel);
  Agent_window=lookup_widget(objet_graphique,"Agent_window");
  gtk_widget_hide(Agent_window);
}

void on_search_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *edit_hotel;
  edit_hotel=create_edit_hotel();
  gtk_widget_show (edit_hotel);
}


void on_refresh_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
    GtkWidget *Agent_window;
    Agent_window=lookup_widget(objet_graphique,"Agent_window");
    gtk_widget_hide(Agent_window);

    Agent_window = create_Agent_window ();
    gtk_widget_show (Agent_window);
}


void on_refresh_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
    GtkWidget *Agent_window;
    Agent_window=lookup_widget(objet_graphique,"Agent_window");
    gtk_widget_hide(Agent_window);

    Agent_window = create_Agent_window ();
    gtk_widget_show (Agent_window);
}


void on_ajouter_nouveau_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_vol;
  GtkWidget *Agent_window;

  ajouter_nouveau_vol = create_ajouter_vol_window ();
  gtk_widget_show (ajouter_nouveau_vol);
  Agent_window=lookup_widget(objet_graphique,"Agent_window");
  gtk_widget_hide(Agent_window);
}


void on_search_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *edit_hotel;
  edit_hotel=create_edit_vol_window();
  gtk_widget_show (edit_hotel);
}


void on_ajouter_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *output;

  char name1[20];char jour1[10];
  char annee1[50];
  char email_nom_domaine[30]; char email_ent[30];
  char email1[30];
  char adress1[300];
  char numero1[20];
  hotel ho;
  input1 = lookup_widget(objet_graphique, "nom_hotel");
  input2 = lookup_widget(objet_graphique, "classement_hotel"); //Combobox
  input3 = lookup_widget(objet_graphique, "nombre_chambre"); //entry
  input4 = lookup_widget(objet_graphique, "email_hotel"); //entry
  input5 = lookup_widget(objet_graphique, "mail_hotel_combobox");//combobox
  input6 = lookup_widget(objet_graphique, "numero_hotel");
  input7 = lookup_widget(objet_graphique, "adresse_hotel");

  output= lookup_widget(objet_graphique, "label_verif_hotel_info");

  strcpy(name1, gtk_entry_get_text(GTK_ENTRY(input1)));
  int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(input2)) + 1;
  sprintf(jour1,"%.2d",active_jour);
  strcpy(annee1, gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(email_ent, gtk_entry_get_text(GTK_ENTRY(input4)));
  int nom_domaine =gtk_combo_box_get_active(GTK_COMBO_BOX(input5));
  //strcpy(email_nom_domaine, gtk_combo_box_get_active(GTK_COMBO_BOX(input7)));
  switch (nom_domaine)
  {
  case 0: strcpy(email_nom_domaine,"@gmail.com");
  break;
  case 1: strcpy(email_nom_domaine,"@yahoo.com");
  break;
  case 2: strcpy(email_nom_domaine,"@icloud.com");
  break;
  case 3: strcpy(email_nom_domaine,"@outlook.com");
  break;
  case 4: strcpy(email_nom_domaine,"@hotmail.com");
  break;
  case 5: strcpy(email_nom_domaine,"@esprit.tn");
  break;
  default : strcpy(email_nom_domaine,"@esprit.tn");
  }



  /*
  0-gmail.Com
  1-yahoo.Com
  2-icloud.Com
  3-outlook.Com
  4-hotmail.Com
  5-esprit.tn

  */
  /***Récupération de l'adresse mail***/
  strcpy(email1,email_ent);
  strcat(email1,email_nom_domaine);

  strcpy(numero1,  gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(adress1,  gtk_entry_get_text(GTK_ENTRY(input7)));


    int nouveau_id = auto_incre_id_ho();
    char n_id[sz];
    sprintf(n_id,"%d",nouveau_id);
    gtk_label_set_text(GTK_LABEL(output), n_id);
    //strcpy(n_id,inf.id);*/
    strcpy(ho.id,n_id);
    strcpy(ho.nom,name1);
    strcpy(ho.classement,jour1);
    strcpy(ho.nombrech,annee1);
    strcpy(ho.email,email1);
    strcpy(ho.num,numero1);
    strcpy(ho.adresse,adress1);
    ajouter_h(ho);
    gtk_label_set_text(GTK_LABEL(output),"hotel ajouté avec succès");
    GtkWidget *ajouter_nouveau_hotel;
    GtkWidget *Agent_window;

    GtkWidget *conf_window;
    //mailtonew(email1);
    /*conf_window = create_ajout_succes_window ();*/
    gtk_widget_show (conf_window);
    ajouter_nouveau_hotel=lookup_widget(objet_graphique,"ajouter_hotel_window");
    gtk_widget_hide(ajouter_nouveau_hotel);
    //gtk_label_set_text(GTK_LABEL(output), "hotel ajouté avec succés");
  
}


void on_annuler_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_hotel;
  GtkWidget *Agent_window;

  Agent_window = create_Agent_window ();
  gtk_widget_show (Agent_window);
  ajouter_nouveau_hotel=lookup_widget(objet_graphique,"ajouter_hotel_window");
  gtk_widget_hide(ajouter_nouveau_hotel);
}


void on_ajouter_vol_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *output;
  vol v;
  char name1[20]; char last1[20];
  char jour1[10]; char mois1[30]; char annee1[5];
  char adress1[300];char name2[20]; 
  input1 = lookup_widget(objet_graphique, "nom_vol");
  input2 = lookup_widget(objet_graphique, "destination_vol");
  input3 = lookup_widget(objet_graphique, "jour_vol"); //Combobox
  input4 = lookup_widget(objet_graphique, "mois_vol"); // combobox
  input5 = lookup_widget(objet_graphique, "annee_vol"); //entry
  input6 = lookup_widget(objet_graphique, "ville_depart");

  output= lookup_widget(objet_graphique, "label_verif_vol");

  strcpy(name1, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(last1, gtk_entry_get_text(GTK_ENTRY(input2)));

 /* int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(jour1,"%.2d",active_jour);
  int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(mois1, "%.2d", active_mois);*/

  //strcpy(annee1, gtk_entry_get_text(GTK_ENTRY(input5)));

 v.datedepart.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
 v.datedepart.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
 v.datedepart.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
  strcpy(name2, gtk_entry_get_text(GTK_ENTRY(input6)));

    int nouveau_id = auto_incre_id_v();
    char n_id[sz];
    sprintf(n_id,"%d",nouveau_id);
    gtk_label_set_text(GTK_LABEL(output), n_id);
    //strcpy(n_id,vol.id);*/
    strcpy(v.id,n_id);
    strcpy(v.nom,name1);
    strcpy(v.destination,last1);
    strcpy(v.lieude,name2);
  /*  strcpy(v.datedepart.jour,jour1);
    strcpy(v.datedepart.mois,mois1);
    strcpy(v.datedepart.annee,annee1);*/
    ajouter_vol(v);
    gtk_label_set_text(GTK_LABEL(output),"vol ajouté avec succès");
    GtkWidget *ajouter_nouveau_vol;
    GtkWidget *Agent_window;

    GtkWidget *conf_window;
    /*conf_window = create_ajout_succes_window ();*/
    gtk_widget_show (conf_window);
    ajouter_nouveau_vol=lookup_widget(objet_graphique,"ajouter_vol_window");
    gtk_widget_hide(ajouter_nouveau_vol);
    //gtk_label_set_text(GTK_LABEL(output), "vol ajouté avec succés");
  }


void on_annuler_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_vol;
  GtkWidget *Agent_window;

  Agent_window = create_Agent_window ();
  gtk_widget_show (Agent_window);
  ajouter_nouveau_vol=lookup_widget(objet_graphique,"ajouter_vol_window");
  gtk_widget_hide(ajouter_nouveau_vol);
}


void on_button_trouver_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
    GtkWidget *input;
    GtkWidget *output;
    GtkWidget *nom_entry;
    GtkWidget *ville_entry;
    GtkWidget *adresse_rue;
    GtkWidget *jour_combo;
    GtkWidget *annee_entry;

     hotel h;
    input = lookup_widget(objet_graphique, "id_search");
    output= lookup_widget(objet_graphique, "label_not_found");

    nom_entry = lookup_widget(objet_graphique,"nom_input");
    annee_entry=lookup_widget(objet_graphique,"edit_nombre_entry");
    ville_entry = lookup_widget(objet_graphique,"numero_input");
    adresse_rue = lookup_widget(objet_graphique,"adresse_rue");
    jour_combo = lookup_widget(objet_graphique, "edit_classement_combobox");

    char id[10];

    strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
    h = chercher_h(id);
    if (strcmp(h.id , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "Aucun hotel n'est trouvé avec cet identifiant, veuillez réessayer");
    }
    else {
        gtk_label_set_text(GTK_LABEL(output), "Id existant");


        gtk_entry_set_text(GTK_ENTRY(nom_entry), h.nom);
        gtk_entry_set_text(GTK_ENTRY(annee_entry), h.nombrech);
        gtk_entry_set_text(GTK_ENTRY(ville_entry), h.num);
        gtk_entry_set_text(GTK_ENTRY(adresse_rue), h.adresse);
        gtk_combo_box_set_active(GTK_COMBO_BOX(jour_combo),(atoi(h.classement)-1));
    }

}

void on_supprimer_id_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output2;
    GtkWidget *nom_entry;
    GtkWidget *ville_entry;
    GtkWidget *adresse_rue;
    GtkWidget *jour_combo;
    GtkWidget *annee_entry;


    hotel h;
    input = lookup_widget(objet_graphique, "id_search");
    output2= lookup_widget(objet_graphique, "label_not_found");

    nom_entry = lookup_widget(objet_graphique,"nom_input");
    annee_entry=lookup_widget(objet_graphique,"edit_nombre_entry");
    ville_entry = lookup_widget(objet_graphique,"numero_input");
    adresse_rue = lookup_widget(objet_graphique,"adresse_rue");
    jour_combo = lookup_widget(objet_graphique, "edit_classement_combobox");


  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  h = chercher_h(id);
  if (strcmp(h.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output2), "Nothing to be deleted");
  }
  else
  {
    strcpy(h.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(h.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(h.adresse, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);

    strcpy(h.classement,jour1);

    gtk_label_set_text(GTK_LABEL(output2), "Champs supprimer avec succès");
    supprimer_h(h.id);

    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(ville_entry), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");
    gtk_entry_set_text(GTK_ENTRY(annee_entry), "");

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Agent_window;
    Agent_window = create_Agent_window ();
    gtk_widget_show (Agent_window);
    */
  }
}


void on_edit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
   GtkWidget *input;
  GtkWidget *output2;
    GtkWidget *nom_entry;
    GtkWidget *ville_entry;
    GtkWidget *adresse_rue;
    GtkWidget *jour_combo;
    GtkWidget *annee_entry;

  hotel hot;
  input = lookup_widget(objet_graphique, "id_search");
  output2= lookup_widget(objet_graphique, "label164");

   nom_entry = lookup_widget(objet_graphique,"nom_input");
    annee_entry=lookup_widget(objet_graphique,"edit_nombre_entry");
    ville_entry = lookup_widget(objet_graphique,"numero_input");
    adresse_rue = lookup_widget(objet_graphique,"adresse_rue");
    jour_combo = lookup_widget(objet_graphique, "edit_classement_combobox");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  hot = chercher_h(id);
  if (strcmp(hot.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output2), "Nothing to be updated");
  }
  else
  {
    strcpy(hot.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(hot.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(hot.adresse, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);

    strcpy(hot.classement,jour1);

    gtk_label_set_text(GTK_LABEL(output2), "Champs modifier avec succès");
    modifier_h(hot);

   /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Agent_window;
    Agent_window = create_Agent_window ();
    gtk_widget_show (Agent_window);
    */

  }

}


void on_button_trouver_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  vol v;
  input = lookup_widget(objet_graphique, "id_inf_search");
  output= lookup_widget(objet_graphique, "label276");

  nom_entry = lookup_widget(objet_graphique,"nom_inf");
  prenom_entry = lookup_widget(objet_graphique,"destination_inf");
  username_entry = lookup_widget(objet_graphique,"ville_depart_inf");
  annee_entry=lookup_widget(objet_graphique,"annee_inf");
  jour_combo = lookup_widget(objet_graphique, "jour_inf");
  mois_combo = lookup_widget(objet_graphique, "mois_inf");


  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  v= chercher_vol(id);
  if (strcmp(v.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Aucun vol n'est trouvé avec cet identifiant, veuillez réessayer");
  }
  else {
      gtk_label_set_text(GTK_LABEL(output), "Id existant");

      gtk_entry_set_text(GTK_ENTRY(nom_entry), v.nom);
      gtk_entry_set_text(GTK_ENTRY(prenom_entry), v.destination);
      gtk_entry_set_text(GTK_ENTRY(username_entry), v.lieude);

      //gtk_entry_set_text(GTK_ENTRY(annee_entry), v.Date.anne);
      //gtk_combo_box_set_active(GTK_COMBO_BOX(jour_combo),(atoi(v.Date.jour)-1));
      //gtk_combo_box_set_active(GTK_COMBO_BOX(mois_combo),(atoi(v.Date.mois)-1));
  }


    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Agent_window;
    Agent_window = create_Agent_window ();
    gtk_widget_show (Agent_window);
    */

}


void on_supprimer_id_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  vol v;
  input = lookup_widget(objet_graphique, "id_inf_search");
  output= lookup_widget(objet_graphique, "label276");

nom_entry = lookup_widget(objet_graphique,"nom_inf");
  prenom_entry = lookup_widget(objet_graphique,"destination_inf");
  username_entry = lookup_widget(objet_graphique,"ville_depart_inf");
  annee_entry=lookup_widget(objet_graphique,"annee_inf");
  jour_combo = lookup_widget(objet_graphique, "jour_inf");
  mois_combo = lookup_widget(objet_graphique, "mois_inf");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  v= chercher_vol(id);
  if (strcmp(v.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be deleted");
  }
  else
  {
    strcpy(v.lieude, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(v.destination, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(v.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    /*char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);*/

 

    gtk_label_set_text(GTK_LABEL(output), "Champs supprimer avec succès");
    supprimer_vol(v.id);

    gtk_entry_set_text(GTK_ENTRY(username_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");


    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Agent_window;
    Agent_window = create_Agent_window ();
    gtk_widget_show (Agent_window);
    */
  }


}


void on_edit_inf_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{

  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

   vol v;
  input = lookup_widget(objet_graphique, "id_inf_search");
  output= lookup_widget(objet_graphique, "label276");

nom_entry = lookup_widget(objet_graphique,"nom_inf");
  prenom_entry = lookup_widget(objet_graphique,"destination_inf");
  username_entry = lookup_widget(objet_graphique,"ville_depart_inf");
  annee_entry=lookup_widget(objet_graphique,"annee_inf");
  jour_combo = lookup_widget(objet_graphique, "jour_inf");
  mois_combo = lookup_widget(objet_graphique, "mois_inf");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  v= chercher_vol(id);
  if (strcmp(v.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be updated");
  }
  
    else
  {
    strcpy(v.lieude, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(v.destination, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(v.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));

    /*char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(v.Date.jour,jour1);
    strcpy(v.Date.mois,mois1);*/

    gtk_label_set_text(GTK_LABEL(output), "Champs modifier avec succès");
    modifier_vol(v);

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Agent_window;
    Agent_window = create_Agent_window ();
    gtk_widget_show (Agent_window);
    */
  }


}

