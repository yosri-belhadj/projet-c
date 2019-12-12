#include "treeView.h"


static GtkTreeModel * create_and_fill_model_hotel (GtkWidget *treeview_hotel,hotel T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="hotel.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}


  store = gtk_list_store_new (COLUMNS_HOTEL, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_ID , T[i].id, COL_NOM, T[i].nom, COL_CLASSEMENT, T[i].classement, COL_NOMBRECH, T[i].nombrech, COL_ADRESSE, T[i].adresse,-1);

}

  return GTK_TREE_MODEL (store);
}


static GtkWidget * create_view_and_model_hotel (GtkWidget *treeview_hotel, hotel T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_hotel),
                                               -1,
                                               "Identifiant",
                                               renderer,
                                               "text", COL_ID,
                                               NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_hotel),
                                               -1,
                                               "Nom",
                                               renderer,
                                               "text", COL_NOM,
                                               NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_hotel),
                                               -1,
                                               "Classement",
                                               renderer,
                                               "text", COL_CLASSEMENT,
                                               NULL);

/* --- Colonne 4 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_hotel),
                                               -1,
                                               "Nombre de Chambre",
                                               renderer,
                                               "text", COL_NOMBRECH,
                                               NULL);

/* --- Colonne 5 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_hotel),
                                               -1,
                                               "Adresse",
                                               renderer,
                                               "text", COL_ADRESSE,
                                               NULL);

/* --- Colonne  6--- */

/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Date de naissance",
                                            renderer,
                                              "text", COL_DATE,
                                            NULL);

/* --- Colonne  7--- */

/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Email",
                                            renderer,
                                              "text", COL_MAIL,
                                            NULL);

/* --- Colonne  8--- */
/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Numéro",
                                            renderer,
                                              "text", COL_NUMERO,
                                            NULL);

/* --- Colonne  9--- */
/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Rue",
                                            renderer,
                                              "text", COL_RUE,
                                            NULL);

/* --- Colonne  10--- */
/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Ville",
                                            renderer,
                                              "text", COL_VILLE,
                                            NULL);
*/

  model = create_and_fill_model_hotel (treeview_hotel,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_hotel), model);

  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_hotel);
}

void affichagehotel (GtkWidget *treeview_hotel, hotel T[])
{
  treeview_hotel = create_view_and_model_hotel (treeview_hotel,T);
}


