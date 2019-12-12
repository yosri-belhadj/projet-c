#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "lecture_med.h"

enum
{
  COL_ID=0,
  COL_NOM,
  COL_CLASSEMENT,
  COL_NOMBRECH,
  COL_ADRESSE,
  COLUMNS_HOTEL
} ;
/*enum
{
  COL_IDI=0,
  COL_NOMI,
  COL_DESTINATION,
  COL_LIEUDE,
  COL_DATEDEPART,
  COLUMNS_VOL
} ;*/



static GtkTreeModel * create_and_fill_model_hotel (GtkWidget *treeview_hotel,hotel T[]);
static GtkWidget * create_view_and_model_hotel (GtkWidget *treeview_hotel, hotel T[]);
void affichagehotel (GtkWidget *treeview_hotel, hotel T[]);


/*static GtkTreeModel * create_and_fill_model_vol (GtkWidget *treeview_vol,vol T[]);
static GtkWidget * create_view_and_model_vol (GtkWidget *treeview_vol, vol T[]);
void affichagevol (GtkWidget *treeview_vol, vol T[]);*/

