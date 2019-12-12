#include "lecture_med.h"

/*************************Hotel************************/
/*********************************************************/
/*********************************AJOUTER**************************************/



void ajouter_h(hotel hot)
{
FILE *f ;
f=fopen("hotel.txt","a+");
if (f!= NULL){

fprintf (f,"%s %s %s %s %s %s %s\n",hot.id,hot.nom,hot.classement,hot.email,hot.num,hot.adresse,hot.nombrech);
fclose(f);
}
}
/**************************supprimer******************************/



void supprimer_h(char cin[sz])
{
  hotel ho;
  FILE *f;
  FILE *f_tmp;

  f=fopen("hotel.txt","a+");
	f_tmp=fopen("hotel.tmp","w");

  while(fscanf(f,"%s %s %s %s %s %s %s\n",ho.id,ho.nom,ho.classement,ho.email,ho.num,ho.adresse,ho.nombrech)!=EOF)
        {
          if (strcmp(cin,ho.id)!=0)
          {
            fprintf(f_tmp,"%s %s %s %s %s %s %s\n",ho.id,ho.nom,ho.classement,ho.email,ho.num,ho.adresse,ho.nombrech);
          }
        }
        fclose(f);
      	fclose(f_tmp);

      	remove("hotel.txt");
      	rename("hotel.tmp","hotel.txt");
}

/******************Chercher hotel**************/

hotel chercher_h(char x[])
{
  hotel ho;
  FILE* f;
  f=fopen("hotel.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s\n",(ho.id),ho.nom,ho.classement,ho.email,ho.num,ho.adresse,ho.nombrech)!=EOF)
          {
            if (strcmp(x,ho.id)==0)
              {
                return ho;
              }
          }
          fclose(f);
  }

  strcpy(ho.id, "-1");
  return ho;
}
/**************************************modifier**********************************/

void modifier_h(hotel hot1)
{
  FILE* f;
  FILE* f_tmp;
  hotel hot;

  f=fopen("hotel.txt","r");
  f_tmp=fopen("hotel.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s\n",hot.id,hot.nom,hot.classement,hot.email,hot.num,hot.adresse,hot.nombrech)!=EOF)
          {
                if (strcmp(hot1.id,hot.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s\n",hot.id,hot.nom,hot.classement,hot.email,hot.num,hot.adresse,hot.nombrech);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s\n",hot1.id,hot1.nom,hot1.classement,hot1.email,hot1.num,hot1.adresse,hot1.nombrech);
                  }
          }
          fclose(f);
          fclose(f_tmp);

          remove("hotel.txt");
          rename("hotel.tmp","hotel.txt");
  }
}

int auto_incre_id_ho()
{
  hotel ho;
  FILE *f;
  int new_id=0;
  char new[10];
  f=fopen("hotel.txt","r+");

  while(fscanf(f,"%s %s %s %s %s %s %s\n",ho.id,ho.nom,ho.classement,ho.email,ho.num,ho.adresse,ho.nombrech)!=EOF)
        {
          strcpy(new,ho.id);
        }
    fclose(f);
    new_id = atoi(new);
    new_id = new_id +1;
return new_id;
}

/*******************************************vol**********************************/
/**************************************************************************************/

/*********************************ajouter**************************/


void ajouter_vol(vol v)
{
FILE *f ;
f=fopen("vol.txt","a+");
if (f!= NULL){

fprintf (f,"%s %s %s %d %d %d %s\n",v.id ,v.nom ,v.destination,v.datedepart.jour,v.datedepart.mois,v.datedepart.annee,v.lieude);
fclose(f);
}
}
/**************************supprimer******************************/


void supprimer_vol(char CIN[]){
FILE *f ;
FILE *f_tmp;
vol v;
f=fopen("vol.txt","a+");
f_tmp=fopen("vol.tmp","w");

while (fscanf(f,"%s %s %s %d %d %d %s\n",v.id ,v.nom ,v.destination,&v.datedepart.jour,&v.datedepart.mois,&v.datedepart.annee,v.lieude)!=EOF){

 if(strcmp(CIN,v.id)!=0){
fprintf(f_tmp,"%s %s %s %d %d %d %s\n",v.id ,v.nom ,v.destination,v.datedepart.jour,v.datedepart.mois,v.datedepart.annee,v.lieude);
}



}

fclose(f);
remove("vol.txt");
rename("vol.tmp","vol.txt");

}
/**************************************modifier**********************************/

/*ypedef struct 
 {
    char id[sz];
    char nom[sz];
    char destination[sz];
    char lieude[sz];
   // char datedepart[sz];
    Date datedepart;
    
 }vol;*/
void modifier_vol(vol v1)
{
  FILE* f;
  FILE* f_tmp;
  vol v;

  f=fopen("vol.txt","r");
  f_tmp=fopen("vol.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %d %d %d %s\n",v.id ,v.nom ,v.destination,&v.datedepart.jour,&v.datedepart.mois,&v.datedepart.annee,v.lieude)!=EOF)
          {
                if (strcmp(v1.id,v.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %d %d %d %s\n",v.id ,v.nom ,v.destination,v.datedepart.jour,v.datedepart.mois,v.datedepart.annee,v.lieude);

                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %d %d %d %s\n",v1.id ,v1.nom ,v1.destination,v1.datedepart.jour,v1.datedepart.mois,v1.datedepart.annee,v1.lieude);

                  }
          }
          fclose(f);
          fclose(f_tmp);

          remove("vol.txt");
          rename("vol.tmp","vol.txt");
  }
}
/*************Chercher vol*************/
vol chercher_vol(char x[])
{
  vol vo;
  FILE* f;
  f=fopen("vol.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %d %d %d %s\n",vo.id,vo.nom ,vo.destination,&vo.datedepart.jour,&vo.datedepart.mois,&vo.datedepart.annee,vo.lieude)!=EOF)
          {
            if (strcmp(x,vo.id)==0)
              {
                return vo;
              }
          }
          fclose(f);
  }

  strcpy(vo.id, "-1");
  return vo;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**********Auto_increment vol id******/
int auto_incre_id_v()
{
  vol v;
  FILE *f;
  int new_id=0;
  char new[10];
  f=fopen("vol.txt","r+");

  while(fscanf(f,"%s %s %s %d %d %d %s\n",v.id,v.nom ,v.destination,&v.datedepart.jour,&v.datedepart.mois,&v.datedepart.annee,v.lieude)!=EOF)
        {
          strcpy(new,v.id);
        }
    fclose(f);
    new_id = atoi(new);
    new_id = new_id +1;
return new_id;
}
////  while(fscanf(f,"%s %s %s %s %s %s %s %s\n",ho.id,ho.nom,ho.classement,ho.email,ho.num,ho.adresse,ho.nombrech)!=EOF)
/*enum
{ID=0,
NOM,
CLASSEMENT,
EMAIL,
NUM,
ADRESSE,
NOMBRECH,
COL
};*/

void afficher(GtkWidget *treeview_hotel){

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter   iter;
GtkListStore *store;
 

char id[100];
char nom[100];
char classement[100];
char email[50];
char num[50];
char adresse[100];
char nombrech[100];
//id,nom,classement,email,num,adresse,nombrech

FILE *f ;
store=NULL;

store=gtk_tree_view_get_model(treeview_hotel);

if (store==NULL)
{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_hotel),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_hotel),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Classement",renderer,"text",CLASSEMENT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_hotel),column);

	        renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("E-mail",renderer,"text",EMAIL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_hotel),column);

                  
	        renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",NUM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_hotel),column);
                
	        renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Adresse",renderer,"text",ADRESSE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_hotel),column);

		renderer=gtk_cell_renderer_text_new();
         	column=gtk_tree_view_column_new_with_attributes("Nombre de chambre",renderer,"text",NOMBRECH,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_hotel),column);

		


}
	store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("hotel.txt","r");
if(f==NULL) {
return;
}
else
{
//////  while(fscanf(f,"%s %s %s %s %s %s %s %s\n",ho.id,ho.nom,ho.classement,ho.email,ho.num,ho.adresse,ho.nombrech)!=EOF)
///while (fscanf(f," %s %s %s %s %s ",Id,Nom,Classement,Nombrech,Adresse)!=EOF) {
 while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,classement,email,num,adresse,nombrech)!=EOF){
	gtk_list_store_append (store, &iter);
        gtk_list_store_set (store, &iter, ID, id, NOM, nom,CLASSEMENT,classement, EMAIL,email,NUM,num, ADRESSE ,adresse ,NOMBRECH,nombrech,-1);
  
}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_hotel),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
//////////////////////////////////////////////////////////////////////
void afficherr(GtkWidget *treeview_vol){

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter   iter;
GtkListStore *store;
 

char id[100];
char nom[100];
char destination[100];
char jour[50];
char mois[50];
char annee[100];
char lieude[100];
//id,nom,classement,email,num,adresse,nombrech

FILE *f ;
store=NULL;

store=gtk_tree_view_get_model(treeview_vol);

if (store==NULL)
{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",IDI,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_vol),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOMI,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_vol),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Destination",renderer,"text",DESTINATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_vol),column);

	        renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_vol),column);

                  
	        renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_vol),column);
                
	        renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Année",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_vol),column);

		renderer=gtk_cell_renderer_text_new();
         	column=gtk_tree_view_column_new_with_attributes("Lieu de depart",renderer,"text",LIEUDE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_vol),column);

		


}
	store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("vol.txt","r");
if(f==NULL) {
return;
}
else
{
//(f,"%s %s %s %d %d %d %s\n",v.id ,v.nom ,v.destination,&v.datedepart.jour,&v.datedepart.mois,&v.datedepart.annee,v.lieude)
// while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,classement,email,num,adresse,nombrech)!=EOF){
while(fscanf(f,"%s %s %s %s %s %s %s\n",id ,nom ,destination,jour,mois,annee,lieude)!=EOF){
	gtk_list_store_append (store, &iter);
        gtk_list_store_set (store, &iter, ID, id, NOM, nom,DESTINATION,destination, JOUR,jour,MOIS,mois, ANNEE ,annee ,LIEUDE,lieude,-1);
  
}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview_vol),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
