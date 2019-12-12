#include <gtk/gtk.h>
#define CALLBACKS_H_INCLUDED

void on_Agent_window_show (GtkWidget *objet_graphique,  gpointer user_data);

void on_quit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_refresh_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data);


void on_refresh_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_annuler_hotel_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_vol_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_annuler_vol_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button_trouver_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_id_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_edit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button_trouver_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_id_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_edit_inf_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);
