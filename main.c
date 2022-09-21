#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
//declare global variables :
int i,a,j=0,q,pos,c=0,found=0;
int intro=0;
//----------------------------------------------------------------------------------------------------------------
//produit struct :
struct produit  {
int code;
char nom[20];
int quantite;
float prix;
};
typedef struct produit;
struct produit pstock[100];
//-----------------------------------------------------------------------------------------------------------------
//date struct  :
typedef struct Date{int day;
int month;
int year;};
struct Date date;
//--------------------------------------------------------------------------------------------------------------------
//sales struct :
typedef struct Ventes{int code; char nom[30];int quantite;float prix;float prixTTC;struct Date date;};
typedef struct Ventes;
struct Ventes vstock[100];
//---------------------------------------------------------------------------------------------
//funcion for add new products
void remplissage_plus_prod(){
struct produit p;
printf("\nhow many product you want to enter :");
scanf("%d",&q);
for(i=0;i<q;i++){
printf("\n---------------------------------------------------------------------------");
printf("\nsaisir le code de produit :");
scanf("%d",&p.code);
printf("\nsaisir le nom de produit :");
scanf("%s",&p.nom);
printf("\nsaisir la quantite de produit :");
scanf("%d",&p.quantite);
printf("\nsaisir le prix de produit :");
scanf("%f",&p.prix);
c++;
pstock[i] = p;
}
}
//---------------------------------------------------------------------------------------------
//funcion  for add only one product :
void remplissage_seul_prod(){
struct produit p;
printf("\n---------------------------------------------------------------------------");
printf("\nsaisir le code de produit :");
scanf("%d",&p.code);
printf("\nsaisir le nom de produit :");
scanf("%s",&p.nom);
printf("\nsaisir la quantite de produit :");
scanf("%d",&p.quantite);
printf("\nsaisir le prix de produit :");
scanf("%f",&p.prix);
c++;
pstock[i] = p;
}
//-------------------------------------------------------------------------------------------------------------------
//function for search by code :
void recherche_code(){
 int code,rc=1;
 printf("donner le code :");
 scanf("%d",&code);
 for(i=0;i<c;i++){
  if(code==pstock[i].code){
   found=1;
   //rc = 1;
   pos = i;
   break;
  }
 else
    found=0;
 }
if(found==0)
    printf("\nn'exist pas");
else
    printf("Exist");
}
//----------------------------------------------------------------------------------------------------------
//function for search by quantity :
void recherche_quantite(){
 int quantite,rc=1;
 printf("donner la quanite :");
 scanf("%d",&quantite);
 for(i=0;i<c;i++){
  if(quantite==pstock[i].quantite){
   found=1;
   //rc = 1;
   pos = i;
   break;
  }
 else
    found=0;
 }
if(found==0)
    printf("out of stock");
else
    printf("Exist");
}
//----------------------------------------------------------------------------------------------------------
//function for delete a product :
void suppression(){
 int code;
 //printf("entrer le code produit q supprimer: ");
 //scanf("%d",&code);
 recherche_code();
 if(found==0)
  printf(" : impossible ");
 else
  for(i=pos;i<c;i++){
   pstock[i] = pstock[i+1];
  }
  printf("\n==>suppression avec succes");
 c--;
}
//-----------------------------------------------------------------------------------------------------------
//function to display all the products :
void affichage(){
for(i=0;i<c;i++){
float prixTTC = pstock[i].prix + pstock[i].prix*0.15 ;
printf("\n-----------------------------------------------------------------------------------\n");
printf("\nle produit n %d :\n ",i+1);
printf("le code est: %d\nle nom est: %s\nla quanitite est:%d\nle prix est :%.2f \nle prix TTC est :%.2f",
                pstock[i].code,pstock[i].nom,pstock[i].quantite,pstock[i].prix,prixTTC);
}
}
//-----------------------------------------------------------------------------------------------------------
// function for sort by price :
void lister_prix(){
struct produit cpt;
for(i=0;i<c;i++){
    for(j=0;j<c-1;j++){
        if(pstock[j].prix<pstock[j+1].prix){
            cpt = pstock[j] ;
            pstock[j] = pstock[j+1];
            pstock[j+1] = cpt;}}
}
}
//---------------------------------------------------------------------------------------------------------
//function to display products with quantity under 3 :
void etat_stock(){
for(i=0;i<c;i++){
    if(pstock[i].quantite <=3){
        float prixTTC = pstock[i].prix + pstock[i].prix*0.15 ;
        printf("le code est: %d\nle nom est: %s\nla quanitite est:%d\nle prix est :%.2f \nle prix TTC est :%.2f",
                pstock[i].code,pstock[i].nom,pstock[i].quantite,pstock[i].prix,prixTTC);
    }
    else
        printf("tous les produits a superieur de 3 en quantite");
}
}
//--------------------------------------------------------------------------------------------------------------
//function for sort by name :
void lister_nom(){
    struct produit temp;
    for(int i=0;i<c- 1;i++){
        for(int j =i+1;j<c;j++){
            if(strcmp(pstock[i].nom,pstock[j].nom)>0){
                temp = pstock[i];
                pstock[i] = pstock[j];
                pstock[j] = temp;
            }
        }
    }
}
//------------------------------------------------------------------------------------------------------
// function to declare products that get bought:
void achete(){
int v;
recherche_code();
if(found==1){
    printf("\n combien de produit a ete vendu ?");
    scanf("%d",&v);
    if(pstock[pos].quantite>0 && pstock[pos].quantite>=v ){
        printf("\nle produit %s a vendu avec succes",pstock[pos].nom);
        pstock[pos].quantite = pstock[pos].quantite - v;
        printf("\n*entrer la date de vente(dd/mm/yyyy) :");
        scanf("%d",&date.day);
        scanf("%d",&date.month);
        scanf("%d",&date.year);
        //printf("\n%d / %d / %d",d.day,d.month,d.year);
        vstock[j].code = pstock[pos].code;
        strcpy(vstock[j].nom,pstock[pos].nom);
        vstock[j].quantite = v;
        vstock[j].prix = pstock[pos].prix;
        vstock[j].prixTTC=pstock[pos].prix+pstock[pos].prix*0.15;
        vstock[j].date = date;
        j++;
        a=j+1;
    }
    else
        printf("out of stock");
}
}
//-------------------------------------------------------------------------------------------------------------------
//function for daily statistics :
void ventes_statistic(){
float max = vstock[0].prix ;
float min = vstock[0].prix ;
float sum=0;
int choix,ve=1;
printf("entrer une date pour afficher les statistique de ce jour :");
scanf("%d %d %d",&date.day,&date.month,&date.year);
for(i=0;i<a;i++){
if(vstock[i].date.day == date.day && vstock[i].date.month == date.month && vstock[i].date.year == date.year){
printf("\n1- afiicher tout les ventes de ce jour.\n");
printf("2- afficher la vente de maximum prix ce jour.\n");
printf("3- afficher la vente de minimum prix ce jour.\n");
printf("4- afficher la somme des ventes ce jour.\n");
printf("5- afficher la moyenne des ventes ce jour.\n");
printf("0- sortir\n");
printf("\nchoisissez l'un de ces choix :");
scanf("%d",&choix);
//system("cls");
}
else
    ve=0;
}
if(ve=0)
    printf("\n!!! pas de vente ce jour !!!!");
float moyenne;
switch (choix){
case 1 :
    printf("les ventes de ce jour est :\n");
    for(j=0;j<a;j++){
    printf("le produit n %d :\n ",j+1);
    printf("le code est: %d\nle nom est: %s\nla quanitite est:%d\nle prix est :%.2f \nle prix TTC est :%.2f",
            vstock[j].code,vstock[j].nom,vstock[j].quantite,vstock[j].prix,vstock[j].prixTTC);
    }
    break;
case 2 :
    max = vstock[0].prix ;
    for(j=1;j<a;j++){
        if(vstock[j].prix >= max){
            max = vstock[j].prix;
            i = j;
            printf("test");}
    }
    printf("le produit avec le max prix est :\n");
    printf("le code est: %d\nle nom est: %s\nla quanitite est:%d\nle prix est :%.2f \nle prix TTC est :%.2f",
            vstock[i].code,vstock[i].nom,vstock[i].quantite,vstock[i].prix,vstock[i].prixTTC);
    break;
case 3:
    for(j=0;j<a;j++){
        if(vstock[j].prix < min){
            max = vstock[j].prix;
            i = j;}
    }
    printf("le produit avec le max prix est :");
    printf("le code est: %d\nle nom est: %s\nla quanitite est:%d\nle prix est :%.2f \nle prix TTC est :%.2f",
            vstock[i].code,vstock[i].nom,vstock[i].quantite,vstock[i].prix,vstock[i].prixTTC);
    break;
case 4 :
    for(j=0;j<a;j++){
        sum = sum+(vstock[j].prix*vstock[j].quantite);
    }
    printf("\nTotal des prix ce jour est :%.2f",sum);
    break;
case 5 :
    for(j=0;j<a;j++){
        sum = sum+(vstock[j].prix*vstock[j].quantite);
    }
    moyenne = sum/a ;
    printf("\nla moyenne des prix ce jour est :%.2f",moyenne);
    break;
case 0 :
    break;
default:
    printf("\n!!!! votre choix est indisponible !!!");
    break;
}
}
//------------------------------------------------------------------------------------------------------
//function for add quantity to products:
void alimenter(){
int v;
printf("pour alimenter le stock ");
recherche_code();
if(found==1){
    printf("\n combien de produit vous voulez ajoutez ?");
    scanf("%d",&v);
    if(pstock[pos].quantite>0 && pstock[pos].quantite>v ){
        printf("\nle produit %s a alimenté avec succes",pstock[pos].nom);
        pstock[pos].quantite = pstock[pos].quantite + v;
}
}
}
//------------------------------------------------------------------------------------------------------------
int main()
{
int c;
char c1,c2;
if(intro==0){
printf("===============================================================================================================\n");
printf("===============================================================================================================\n");
printf("\t\t\t==============\t GESTION DE PHARMACIE \t==============\n");
printf("\t\t\t******************************************************\n");
intro=1;
}
Sleep(150);
printf("\t\t\t  *******************    MENU    *******************\n");
Sleep(150);
printf("\t\t1 - AJOUTER UN NOUVEAU PRODUIT.\n");
Sleep(150);
printf("\t\t2 - AJOUTER PLUSIEUR NOUVEAUX PRODUITS.\n");
Sleep(150);
printf("\t\t3 - AFFICHER TOUT LES PRODUITS.\n");
Sleep(150);
printf("\t\t4 - LISTER LES PRODUITS.\n");
Sleep(150);
printf("\t\t5 - ACHETER UN PRODUIT. \n");
Sleep(150);
printf("\t\t6 - RECHERCHER un produit.\n");
Sleep(150);
printf("\t\t7 - ETAT DE STOCK.\n");
Sleep(150);
printf("\t\t8 - ALIMENTER LE STOCK.\n");
Sleep(150);
printf("\t\t9 - STATISTIQUE DE VENTE.\n");
Sleep(150);
printf("\t\t10 - SUPPRIMER UN PRODUIT.\n");
Sleep(150);
printf("\t\t0 - SORTIR.\n");
Sleep(400);
printf("choisir un choix ==>");
scanf("%d",&c);
switch(c)
{
case 1:
    remplissage_seul_prod();
    printf("clique sur un button si tu veux revenir au menu\n");

    main();
    break;
case 2:
    remplissage_plus_prod();

    main();
    break;
case 3:
    affichage();

    main();
    break;
case 4:
    printf("A - lister par prix.\n");
    Sleep(200);
    printf("B - lister par nom.\n");
    Sleep(200);
    printf("choisir aun choix :");
    scanf(" %c",&c2);
    switch(c2){
    case 'A':
        lister_prix();
        affichage();
        break;
    case 'a':
        lister_prix();
        affichage();
        break;
    case 'B':
        lister_nom();
        affichage();
        break;
    case 'b':
        lister_nom();
        affichage();
        break;
    }
    main();
    break;
case 5:
    achete();
    //system("cls");
    main();
    break;
case 6:
    printf("A - recherche par code.\n");
    Sleep(200);
    printf("B - recherche par quantite.\n");
    Sleep(200);
    printf("choisir un choix :");
    scanf(" %c",&c1);
    switch(c1){
    case 'A':
        recherche_code();
        break;
    case 'a':
        recherche_code();
        break;
    case 'B':
        recherche_quantite();
        break;
    case 'b':
        recherche_quantite();
        break;
    default:
        printf("votre choix est indisponible !!");
    }
    main();
    break;
case 7:
    etat_stock();
    main();
    break;
case 8:
    alimenter();
    main();
    break;
case 9:
    ventes_statistic();
    main();
    break;
case 10:
    suppression();
    main();
    break;
case 0:
    exit(0);
    break;
default:
    printf("votre choix pas disponible !!");
}
//remplissage_plus_prod();
//remplissage_seul_prod();
//recherche_code();
//recherche_quantite();
//suppression();
//lister_prix();
//achete();
//affichage();
//etat_stock();
//ventes_statistic();
//alimenter();


}
