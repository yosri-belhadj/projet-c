#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

enum
{
  ID_RES,
	NOM,
	ADRESSE,
	PRENOM,
	SEXE,
	PAYS,
	TELEPHONE,
	EMAIL,
	HOTEL,
	ADULTE,
	ENFANT,
	DEPART,
	RETOUR,
	COLUMNS
};

void inscription_client(int num_res,char nom[],char adresse [],char prenom[],char pays[],char telephone[],char email[],char hotel[],int nbr_adulte,int nbr_enfant,char dateDepart[], char dateRetour[], char sexe[])
{
FILE *f;
f=fopen("texte.txt","a+");
if(f!=NULL)
{
fprintf(f,"%d %s %s %s %s %s %s %s %s %d %d %s %s \n",num_res,nom,prenom,sexe,adresse,
pays,telephone,email,hotel,nbr_adulte,nbr_enfant,dateDepart,dateRetour);
fclose(f);
}
}
void afficher_reservation(GtkTreeView *treeview1)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

char num_res[20];
char nom[20];
char prenom[20];
char sexe[2];
char adresse [20];
char email[20];
char telephone[20];
char pays[20];
char hotel[20];
char nbr_adulte[2];
char nbr_enfant[2];
char dateDepart[30];
char dateRetour[30];

FILE *f ;
store =NULL;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{
//1
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("num_res",renderer,"text",ID_RES,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//2
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//2

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prenom",renderer,"text",PRENOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//3

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("sexe",renderer,"text",SEXE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//4

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("adresse",renderer,"text",ADRESSE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//5
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("email",renderer,"text",EMAIL,NULL);
	    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//6
             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("telephone",renderer,"text",TELEPHONE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//7
	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("hotel",renderer,"text",HOTEL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
       
//8
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbr_adulte",renderer,"text",ADULTE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//9  
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbr_enfant",renderer,"text",ENFANT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

  
//10
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("dateDepart",renderer,"text",DEPART,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
     
//11
            
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("dateRetour",renderer,"text",RETOUR,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
//12

  }          
           

            store =gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("texte.txt","r");
  if (f!=NULL){
  while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s ",num_res,nom,prenom,sexe,adresse,
pays,telephone,email,hotel,nbr_adulte,nbr_enfant,dateDepart,dateRetour)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,ID_RES,num_res,NOM,nom,PRENOM,prenom,SEXE,sexe,ADRESSE,adresse,PAYS,pays,TELEPHONE,telephone,EMAIL,email,HOTEL,hotel,ADULTE,nbr_adulte,ENFANT,nbr_enfant,DEPART,dateDepart,RETOUR,dateRetour,-1);
}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
            g_object_unref(store);
}



  void supprimerReservation(char num_res[]){
FILE *f;
FILE *f1 ;
char num_resc[20];
char nom[20];
char prenom[20];
char sexe[2];
char adresse [20];
char email[20];
char telephone[20];
char pays[20];
char hotel[20];
char nbr_adulte[2];
char nbr_enfant[2];
char dateDepart[30];
char dateRetour[30];
f1 =NULL;
f=fopen("texte.txt","r") ;
if (f!= NULL)
{

while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s ",num_resc,nom,prenom,sexe,adresse,
pays,telephone,email,hotel,nbr_adulte,nbr_enfant,dateDepart,dateRetour)!=EOF) {
if (strcmp(num_res,num_resc))
{
f1=fopen("a.txt","a");

fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",num_resc,nom,prenom,sexe,adresse,
pays,telephone,email,hotel,nbr_adulte,nbr_enfant,dateDepart,dateRetour) ;
fclose(f1);
}
}
}
fclose(f);
remove("texte.txt");
rename("a.txt","texte.txt");

}
  





int get_last_id(){
    FILE *f;
    char ch;
    //2
    int i=0;
    f = fopen("texte.txt", "r");
    while(!feof(f))
    {
      ch = fgetc(f);
      if(ch == '\n')
      {
        i++;
      }
    }
    g_print("%d",i);
    return i;
}



void modifierReservation(char num_res[],char nom1[],char prenom1[],char sexe1[],char adresse1[],char email1[],char telephone1[],char pays1[],
  char hotel1[],char nbr_adulte1[],char nbr_enfant1[],char dateDepart1[],char dateRetour1[] )
{
  char num_resb[20];
  char nomb[20];
	char adresseb[20];
	char prenomb[20];
	char paysb[20];
	char telephoneb[20];
	char emailb[20];
  char hotelb[20];
	char nbr_adulteb[2];
	char nbr_enfantb[2];
	char dateDepartb[20];
	char dateRetourb[20];
	char sexeb[2];
  
FILE *f;
FILE *f1;
f1=NULL ;
f=fopen("texte.txt","r+");
f1=fopen("text.txt","w");
if (f!= NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",num_resb,nomb,prenomb,sexeb,adresseb,paysb,telephoneb,emailb,hotelb,nbr_adulteb,nbr_enfantb,dateDepartb,dateRetourb)!=EOF) {
if ((strcmp(num_res,num_resb))==0)
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",num_resb,nom1,prenom1,sexe1,adresse1,
pays1,telephone1,email1,hotel1,nbr_adulte1,nbr_enfant1,dateDepart1,dateRetour1) ;

}
else
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",num_resb,nomb,prenomb,sexeb,adresseb,
paysb,telephoneb,emailb,hotelb,nbr_adulteb,nbr_enfantb,dateDepartb,dateRetourb) ;

}
fclose(f1);
fclose(f);
remove("texte.txt");
rename ("text.txt","texte.txt");
}
}











