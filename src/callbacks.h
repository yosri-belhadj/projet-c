#include <gtk/gtk.h>


void
on_ajouter_clicked  (GtkWidget *objet_graphique,gpointer user_data);

void
on_afficher_clicked(GtkWidget     *objet_graphique,gpointer user_data);

void
on_supprimer_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkButton       *objet_graphiques,
                                        gpointer         user_data);


gboolean
on_treeview1_select_cursor_row         (GtkTreeView     *treeview,
                                        gboolean         start_editing,
                                        gpointer         user_data);
