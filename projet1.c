#include <stdio.h>
#include "structs.h"
#include <string.h>
#include <stdlib.h>
int valide(int jour,int mois,int annee)
{
    if(annee>=1990 && annee<=3000)
    {
        if(mois>=1 && mois<=12)
        {
            if((jour>=1 && jour<=31) && (mois==1 || mois==3 || mois==5 || mois==7 || mois==8 || mois==10 || mois==12))
                return 1;
            else if((jour>=1 && jour<=30) && (mois==4 || mois==6 || mois==9 || mois==11))
                return 1;
            else if((jour>=1 && jour<=28) && (mois==2))
                return 1;
            else if(jour==29 && mois==2 && (annee%400==0 ||(annee%4==0 && annee%100!=0)))
                return 1;
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

char menu()
{
 char choix;
 printf("\n");
  printf("_________Pharmacie_________\n\n");
  printf(" |    1: Gerer factures    |\n");
  printf(" |    2: Gerer produits    |\n");
  printf(" |    3: Gerer employes    |\n");
  printf(" |    4: Traitements       |\n");
  printf("___________________________\n");
  while((choix != '1')&&(choix != '2')&&(choix != '3')&&(choix != '4'))
  {
    printf("choisir fonction : ");
    scanf("%c",&choix) ;
      fflush(stdin);
  };
  fflush(stdin);
  return choix;
}

char menu_produits()
{
 char choix;
 printf("\n");
  printf("_________Pharmacie_Produits______________________\n\n");
  printf(" |        1: Ajouter Produit                     |\n");
  printf(" |        2: Afficher tous les produits          |\n");
  printf(" |        3: Retourner                           |\n");
  printf("_________________________________________________\n");
  while((choix != '1')&&(choix != '2')&&(choix != '3'))
  {
    printf("choisir fonction : ");
    scanf("%c",&choix) ;
      fflush(stdin);
  };
  fflush(stdin);
  return choix;
}

char menu_factures()
{
 char choix;
 printf("\n");
  printf("_______________Pharmacie_Recettes________________\n\n");
  printf(" |        1: Ajouter Recette                     |\n");
  printf(" |        2: Afficher tous Recettes              |\n");
  printf(" |        3: Retourner                           |\n");
  printf("_________________________________________________\n");
  while((choix != '1')&&(choix != '2')&&(choix != '3'))
  {
    printf("choisir fonction : ");
    scanf("%c",&choix) ;
      fflush(stdin);
  };
  fflush(stdin);
  return choix;
}

char menu_Employes()
{
 char choix;
 printf("\n");
  printf("_________Pharmacie_Employes______________________\n\n");
  printf(" |        1: Ajouter Employes                    |\n");
  printf(" |        2: Afficher tous les Employes          |\n");
  printf(" |        3: Retourner                           |\n");
  printf("_________________________________________________\n");
  while((choix != '1')&&(choix != '2')&&(choix != '3'))
  {
    printf("choisir fonction : ");
    scanf("%c",&choix) ;
      fflush(stdin);
  };
  fflush(stdin);
  return choix;
}

void Ajout_produit(PRODUIT* med,int i)
{
    med->id_med=i;
    printf("| donner nom medicament %d : ",i);
    scanf("%s",&med->nom);
    printf("| donner nom entreprise du medicament %d : ",i);
    scanf("%s",&med->entreprise);
    printf("| donner quantite du medicament  %d : ",i);
    scanf("%d",&med->quantite);
    printf("| donner prix du  medicament %d : ",i);
    scanf("%f",&med->prix_med);
        //init
        int valid=0;

        while(valid == 0)
            {
                fflush(stdin);
    printf("| donner la date de validite du medicament : \n");
    printf("| annee : ");
                scanf("%d",&med->validite.annee);
    printf("| mois : ");
                scanf("%d",&med->validite.mois);
    printf("| jour : ");
                scanf("%d",&med->validite.jour);
                valid=valide(med->validite.jour,med->validite.mois,med->validite.annee);
                fflush(stdin);
            };
}

 void Ajout_employe(EMPLOYE* empl,int i)
 {
    empl->id_employe=i;
    printf("| Donner nom employe %d : ",i);
    scanf("%s",&empl->nom);
    printf("| Donner prenom employe %d : ",i);
    scanf("%s",&empl->prenom);
    printf("| Donner salaire de l'employe %d : ",i);
    scanf("%f",&empl->salaire);
    printf("| Role de l'employe %d : ",i);
    scanf("%s",&empl->role);

        //init
        int valid=0;

        while(valid == 0)
            {
                fflush(stdin);
    printf("| donner la date debut de l'employe : \n");
    printf("| annee : ");
                scanf("%d",&empl->date_debut.annee);
    printf("| mois : ");
                scanf("%d",&empl->date_debut.mois);
    printf("| jour : ");
                scanf("%d",&empl->date_debut.jour);
                valid=valide(empl->date_debut.jour,empl->date_debut.mois,empl->date_debut.annee);
                fflush(stdin);
            };


 }


void setup(int* nbr_produit,int* nbr_employes,int* nbr_clients)
{
printf("-->donner nombre des produits total : ");
scanf("%d",nbr_produit);
printf("-->donner nombre des employes total : ");
scanf("%d",nbr_employes);
printf("-->donner nombre des clients total : ");
scanf("%d",nbr_clients);
}

void affichage_produit(PRODUIT* med,int i)
{
  printf(" __________>>>> Produit %d <<<<_____________\n",med->id_med);
  printf("| Nom medicament : %s                       \n",med->nom);
  printf("| Entreprise : %s                           \n",med->entreprise);
  printf("| Quantite : %d                             \n",med->quantite);
  printf("| Prix : %f                                 \n",med->prix_med);
  printf("| Date validite : %d/%d/%d                 \n",med->validite.jour,med->validite.mois,med->validite.annee);
  printf(" ___________________________________________\n",i);
}
void affichage_employe(EMPLOYE* empl,int i)
{
  printf(" __________>>>> Employe %d <<<<_____________\n",empl->id_employe);
  printf("| Nom employe : %s                       \n",empl->nom);
  printf("| Prenom employe : %s                       \n",empl->prenom);
  printf("| Salaire : %f                           \n",empl->salaire);
  printf("| Role : %s                             \n",empl->role);
  printf("| Date Debut : %d/%d/%d                 \n",empl->date_debut.jour,empl->date_debut.mois,empl->date_debut.annee);
  printf(" ___________________________________________\n",i);
}
void allocation_recettes(RECETTE** rec,int* nbr_recettes)
{
    printf("-->donner le nombre des recettes: ");
    scanf("%d",nbr_recettes);
   *rec = (RECETTE**)malloc (*nbr_recettes * sizeof(RECETTE));
    if(!*rec) exit(-1);

}
void allocation_factures(RECETTE* rec,int nbr)
{
    printf("| Donner le nombre des factures dans la recette %d : ",nbr);
    scanf("%d",&rec->nbr_factures_dans_recette);

    for(int i=0;i<rec->nbr_factures_dans_recette;i++)
    {
    rec->tous_factures = (FACTURE*) malloc(rec->nbr_factures_dans_recette * sizeof(FACTURE));
    }
}

void valide_temp(int *heure,int*minute,int*seconde)
{
    int heure_val = 0;
    int minute_val = 0;
    int seconde_val = 0;
    while((heure_val == 0)&&(minute_val == 0)&&(seconde_val == 0))
    {
    printf(" | Temp Facture :\n");
    printf(" |   donner Heures :\n ");
    scanf("%d",heure);
    printf(" |   donner Minutes :\n ");
    scanf("%d",minute);
    printf(" |   donner secondes :\n ");
    scanf("%d",seconde);
    if((*heure < 12)&&(*heure>0))
    {
        heure_val =1;
    }
      if((*minute < 60)&&(*minute>0))
    {
        minute_val =1;
    }
      if((*seconde < 60)&&(*seconde>0))
    {
        seconde_val =1;
    }
    }

}





void Ajout_facture(FACTURE* fac,PHARMACIE* phar,int nbr)
{
    printf(" | ______________Facture %d________________\n",nbr);
    printf(" | donner le nom du client : ");
    scanf("%s",&fac->client.nom);
    printf(" | donner le prenom du client : ",nbr);
    scanf("%s",&fac->client.prenom);
    printf(" | donner CIN du client : ");
    scanf("%d",&fac->client.CIN);
    valide_temp(&fac->temp_achat.heure,&fac->temp_achat.minute,&fac->temp_achat.seconde);
    printf(" | donner le nombre des produit dans la facture : ");
    scanf("%d",&fac->nbr_produits_dans_facture);
    fac->les_produit= (PRODUIT*) malloc (fac->nbr_produits_dans_facture * sizeof(PRODUIT));
    printf(" | __________Choisir Produit : _____________ \n");
     for(int i=0;i<phar->nbr_produit;i++)
  {
    affichage_produit(&phar->tab_produits[i],i);
  }
    int num_prod;
    int valid_prod = 0;
    for(int k=0;k<fac->nbr_produits_dans_facture;k++)
    {
    while(valid_prod == 0)
    {
        printf(" >>> Choisir le numero du produit %d : ",k);
        scanf("%d",&num_prod);
        if((num_prod >= 0 )&&(num_prod < phar->nbr_produit))
        {
            valid_prod = 1;
        }
    }
    fac->les_produit[k] = phar->tab_produits[num_prod];
    phar->tab_produits[num_prod].quantite--;
    valid_prod = 0;
    num_prod = -1;
    }
printf(" | __________Choisir Employe : _____________ \n");
 int num_employe;
 int valid_employe = 0;
for(int k2=0;k2<phar->nbr_employes;k2++)
{
affichage_employe(&phar->tab_employes[k2],k2);
}

 while(valid_employe == 0)
 {
    printf(" >>> Choisir le numero de l'employe a la caisse : ");
    scanf("%d",&num_employe);
    if((num_employe>=0)&&(num_employe < phar->nbr_employes))
    {
        valid_employe = 1;
    }
 }
 fac->employe_caisse = phar->tab_employes[num_employe];
 valid_employe = 0;
 num_employe = -1;
fflush(stdin);
 for(int i=0;i<fac->nbr_produits_dans_facture;i++)
 {
      fac->prixTotal+=(float)fac->les_produit[i].prix_med;
      fflush(stdin);
 }
 printf("prix total = %f \n",fac->prixTotal);
}


void Affiche_client(CLIENT* cl)
{
  printf(" _____________>>>> Client <<<<______________\n");
  printf("| Nom client : %s                       \n",cl->nom);
  printf("| Prenom client : %s                       \n",cl->prenom);
  printf("| CIN : %d                             \n",cl->CIN);
  printf(" ___________________________________________\n");
}


void Ajout_recette_date(DATE* date)
{
    int valid=0;

        while(valid == 0)
            {
                fflush(stdin);
    printf("| donner la date du recette du medicament : \n");
    printf("| annee : ");
                scanf("%d",&date->annee);
    printf("| mois : ");
                scanf("%d",&date->mois);
    printf("| jour : ");
                scanf("%d",&date->jour);
                valid=valide(date->jour,date->mois,date->annee);
                fflush(stdin);
            };
}
void Affichage_recette(RECETTE* rec,int nbr)
{
FACTURE* fact;
fact = rec->tous_factures;
for(int i=0;i<rec->nbr_factures_dans_recette;i++)
{
    printf(" \n| ____________Facture %d_________ |\n\n",i);
    printf(" | Temp Achat : %d:%d:%d\n",fact[i].temp_achat.heure,fact[i].temp_achat.minute,fact[i].temp_achat.seconde);
    printf(" | Les produits sont :             \n");
    for(int j=0;j<fact[i].nbr_produits_dans_facture;j++)
        affichage_produit(&(fact[i].les_produit[j]),j);
    printf(" | Employe a la caisse             |\n");
    affichage_employe(&(fact[i].employe_caisse),0);
    Affiche_client(&(fact[i].client));
    printf(" | Prix total : %f ",fact[i].prixTotal);

}
}
void allocation_produits(PRODUIT** prd,int nbr)
{
    *prd = (PRODUIT*)malloc (nbr * sizeof(PRODUIT));
}
void allocation_employes(EMPLOYE** prd,int nbr)
{
    *prd = (EMPLOYE*)malloc (nbr * sizeof(EMPLOYE));
}


float pertes_pharmacie(int nombre,PHARMACIE* ph)
{
    float pertes;
    for(int i=0;i<nombre;i++)
    {
        pertes=ph->tab_employes[i].salaire+pertes;

    }
    return pertes;
}

char menu_traitements()
{
 char choix;
 printf("\n");
  printf("_________Pharmacie_Produits______________________\n\n");
  printf(" |        1: Gain et Pertes                      |\n");
  printf(" |        2: Nom client le plus frequent         |\n");
  printf(" |        3: Produit plus populaire par facture  |\n");
  printf(" |        4: Produit plus populaire par jour     |\n");
  printf(" |        5: Retourner                           |\n");
  printf("_________________________________________________\n");
  while((choix != '1')&&(choix != '2')&&(choix != '3')&&(choix != '4')&&(choix != '5'))
  {
    printf("choisir fonction : ");
    scanf("%c",&choix) ;
      fflush(stdin);
  };
  fflush(stdin);
  return choix;
}



void nom_client_plus_frequent(RECETTE *rec)
{
      int max = 0;
       char max_nom[20];
       int max_eff = 0;
       char max_eff_nom[20];
         for(int j=0;j<rec->nbr_factures_dans_recette;j++)
      {
       strcpy(max_eff_nom,rec->tous_factures[j].client.nom);
        max_eff = 0;
         for(int j2=j;j2<rec->nbr_factures_dans_recette;j2++)
      {
         if(0 == strcmp (max_eff_nom,rec->tous_factures[j2].client.nom))
         {
             max_eff++;
         }
         if(max_eff > max)
         {
             max = max_eff;
             strcpy(max_nom,max_eff_nom);
         }
      }
      }printf("le client max est %s\n",max_nom);
}



float calcul_total(int gain,int pertes)
{
int marge = gain*0.3;
return marge - pertes;
}


void produit_plus_populaire_par_facture(FACTURE* fac)
{fflush(stdin);
      int max = 0;
       char max_nom[20];
       int max_eff = 0;
       char max_eff_nom[20];
         for(int j=0;j<fac->nbr_produits_dans_facture;j++)
          {
           strcpy(max_eff_nom,fac->les_produit[j].nom);
           max_eff = 0;

                      for(int j3=0;j3<fac->nbr_produits_dans_facture;j3++)
                      {
                          if(0 == strcmp (max_eff_nom,fac->les_produit[j3].nom))
                             {
                                 max_eff++;
                             }
                          if(max_eff > max)
                             {
                                 max = max_eff;
                                 strcpy(max_nom,max_eff_nom);
                                fac->prod_pop = fac->les_produit[j3];
                             }
                      }
          }
fflush(stdin);
}

void produit_plus_populaire_par_jour(RECETTE* rec,PRODUIT* produit_pop,int* USED)
{
fflush(stdin);
      int max = 0;
       char max_nom[20];
       int max_eff = 0;
       char max_eff_nom[20];
                    fflush(stdin);
                    if(*USED == 0)
                        for(int j3=0;j3<rec->nbr_factures_dans_recette;j3++)
                      {
                          printf("remplis pop par jour \n");
                        produit_plus_populaire_par_facture(&(rec->tous_factures[j3]));
                        *USED = 1;
                      }
                      fflush(stdin);
         for(int j=0;j<rec->nbr_factures_dans_recette;j++)
          {
           strcpy(max_eff_nom,rec->tous_factures[j].prod_pop.nom);
           max_eff = 0;

                      for(int j3=0;j3<rec->nbr_factures_dans_recette;j3++)
                      {
                        produit_plus_populaire_par_facture(&(rec->tous_factures[j]));
                          if(0 == strcmp (max_eff_nom,rec->tous_factures[j3].prod_pop.nom))
                             {
                                 max_eff++;
                             }
                          if(max_eff > max)
                             {
                                 max = max_eff;
                                 strcpy(max_nom,max_eff_nom);
                                 *produit_pop = rec->tous_factures[j3].prod_pop;
                             }
                      }
          }
          PRODUIT WTF;
          WTF = *produit_pop;
          affichage_produit(&WTF,WTF.id_med);
       // printf("affichage %d",WTF.id_med);
}



void allocation_tableau_dyn_adr_strc(PLVENDU*** pl,int size)
{
    *pl = (PLVENDU**)malloc(size*sizeof(PLVENDU*));
    for(int i=0;i<size;i++)
    {
        *(*pl+i)= (PLVENDU*)malloc(sizeof(PLVENDU));
    }
}

int main()
 {

  char choix_menu;
  char choix_produits;
  char choix_employes;
  char choix_traitements;
  char choix_factures;
  int USED = 0;
  PHARMACIE *phar;

  phar = (PHARMACIE*)malloc(sizeof(PHARMACIE));
  phar->nbr_produit=0;
  phar->nbr_employes=0;
  phar->nbr_clients=0;
  PLVENDU** pl;
  allocation_tableau_dyn_adr_strc(&(pl),phar->nbr_recettes);




  allocation_produits(&(phar->tab_produits),phar->nbr_produit);
  allocation_employes(&(phar->tab_employes),phar->nbr_employes);
  allocation_recettes(&phar->tab_recette,&phar->nbr_recettes);
  fflush(stdin);
while(1==1)
{
    fflush(stdin);
  choix_menu = menu();
    fflush(stdin);
if(choix_menu == '2' )
{
  choix_menu = '0';
  choix_produits = menu_produits();
}
if(choix_menu == '1' )
{
  choix_menu = '0';
  choix_factures = menu_factures();
}
fflush(stdin);
if(choix_menu == '3')
{
    choix_menu = '0';
    choix_employes = menu_Employes();
}
if(choix_menu == '4')
{
    choix_menu = '0';
    choix_traitements = menu_traitements();
}


if(choix_traitements=='1')
{
    printf("_________________Gain et Pertes__________\n\n");
            int valid=0;
            int annee,mois,jour;
        while(valid == 0)
            {
                fflush(stdin);
    printf("| donner le journee a calculer : \n");
    printf("| annee : ");
                scanf("%d",&annee);
    printf("| mois : ");
                scanf("%d",&mois);
    printf("| jour : ");
                scanf("%d",&jour);
                valid=valide(jour,mois,annee);
                fflush(stdin);
            };
    float gain;
     for(int i=0;i<phar->nbr_recettes;i++)
    {
        if((phar->tab_recette[i].date_jour.annee == annee)&&(phar->tab_recette[i].date_jour.mois == mois)&&(phar->tab_recette[i].date_jour.jour == jour))

     {
         for(int j=0;j<phar->tab_recette[i].nbr_factures_dans_recette;j++)
      {
          for(int k=0;k<phar->tab_recette[i].tous_factures[j].nbr_produits_dans_facture;k++)
          {
              gain = phar->tab_recette[i].tous_factures[j].les_produit[k].prix_med +gain;
          }

      }
     }
     else {
        gain =0;
     }
    }
    float pertes ;
    float total;
    pertes=  pertes_pharmacie(phar->nbr_employes,phar) / 30;
    total = calcul_total(gain,pertes);
    printf("| Gain : %f\n",gain);
    printf("| Pertes : %f\n",pertes);

    printf("| Totat avec marge de 30% : %f\n",total);
    printf("__________________________________________\n\n");

}

if(choix_traitements == '2')
{
    for(int i=0;i<phar->nbr_recettes;i++)
    {
        printf("Jour %d/%d/%d\n",phar->tab_recette[i].date_jour.jour,phar->tab_recette[i].date_jour.mois,phar->tab_recette[i].date_jour.annee);
        nom_client_plus_frequent(&(phar->tab_recette[i]));
    }

}
if(choix_traitements == '3')
{
    for(int i=0;i<phar->nbr_recettes;i++)
    {
        printf(">>> Jour %d/%d/%d\n",phar->tab_recette[i].date_jour.jour,phar->tab_recette[i].date_jour.mois,phar->tab_recette[i].date_jour.annee);
        for(int j=0;j<phar->tab_recette[i].nbr_factures_dans_recette;j++)
            {
                printf("\n---------->>> Facture %d<<<<-------------\n",j);
                if(USED == 0)
                {
                      printf("remplis pop par facture \n");
                    produit_plus_populaire_par_facture(&(phar->tab_recette[i].tous_factures[j]));
                    USED = 1;
                }

                affichage_produit(&(phar->tab_recette[i].tous_factures[j].prod_pop),i);
            }
    }

}
if(choix_traitements == '4')
{

       fflush(stdin);
    for(int i=0;i<phar->nbr_recettes;i++)
    {
 fflush(stdin);
        produit_plus_populaire_par_jour(&(phar->tab_recette[i]),&((*(pl+i))->produit_jour),&(USED));
        (*(pl+i))->date_jour = phar->tab_recette[i].date_jour;
        printf(">>> Jour %d/%d/%d\n",(*(pl+i))->date_jour.jour,(*(pl+i))->date_jour.mois,(*(pl+i))->date_jour.annee);
       // affichage_produit(&((*(pl+i))->produit_jour),i);
    }

     fflush(stdin);

}

if(choix_factures =='1')
{
printf("___________________Ajout Recettes_________________ \n\n");
for(int i=0;i<phar->nbr_recettes;i++)
    {
Ajout_recette_date(&(phar->tab_recette[i].date_jour));
printf("_________>>> Recette Date : %d/%d/%d <<<__________ \n\n",phar->tab_recette->date_jour.jour,phar->tab_recette->date_jour.mois,phar->tab_recette->date_jour.annee);
      allocation_factures(&(phar->tab_recette[i]),i);
      for(int j=0;j<phar->tab_recette[i].nbr_factures_dans_recette;j++)
      {
        Ajout_facture(&(phar->tab_recette[i].tous_factures[j]),phar,j);
      }
    }
}

if(choix_factures=='2')
{
printf("_______________Affichage tous les recettes______________\n\n");
for(int i=0;i<phar->nbr_recettes;i++)
{
printf("___________Affichage Recette Date : %d/%d/%d____________\n\n",phar->tab_recette->date_jour.jour,phar->tab_recette->date_jour.mois,phar->tab_recette->date_jour.annee);
    Affichage_recette(&(phar->tab_recette[i]),i);
}
}
if(choix_factures=='3')
{

}
fflush(stdin);


//-management produit
if(choix_produits == '1')
{
  //---------------> Ajout produit
    printf(" _____________ajouter produit_______________\n");

    phar->nbr_produit++;
       phar->tab_produits = (PRODUIT*)realloc (phar->tab_produits,phar->nbr_produit * sizeof(PRODUIT));
       Ajout_produit(&(phar->tab_produits[(phar->nbr_produit)-1]),phar->nbr_produit-1);

    printf(">>  Medicaments Ajouter  <<");
    }
if(choix_produits == '2')
{
  //---------------> Afficher produit
  printf(" ____________Affichage produit______________\n\n");
  for(int i=0;i<phar->nbr_produit;i++)
  {
    affichage_produit(&phar->tab_produits[i],i);
  }

}
if(choix_produits == '3')
{
    //menu principal
}
   fflush(stdin);




//-management employés
if(choix_employes == '1')
{
  //---------------> Ajout produit
    printf(" _____________ajouter employes_______________\n");


        phar->nbr_employes++;
         phar->tab_employes = (EMPLOYE*)realloc (phar->tab_employes,phar->nbr_employes * sizeof(EMPLOYE));
       Ajout_employe(&(phar->tab_employes[(phar->nbr_employes)-1]),(phar->nbr_employes)-1);

     printf(">>  Employe Ajouter  <<");
    }
if(choix_employes == '2')
{
  //---------------> Afficher Employes
  printf(" ______________Affichage Employes________________\n\n");
  for(int i=0;i<phar->nbr_employes;i++)
  {
  affichage_employe(&phar->tab_employes[i],i);
  }

}
if(choix_employes == '3')
{
    //menu principal
}



choix_employes = '0';
choix_produits = '0';
choix_factures = '0';
choix_traitements = '0';

//tri(&(phar->nbr_produit),phar->nbr_produit);

PRODUIT aux;


   for(int j=0;j<phar->nbr_produit;j++)
   {
      for(int k=j;k<phar->nbr_produit;k++)
      {
        if(phar->tab_produits[j].quantite < phar->tab_produits[k].quantite)
       {
            aux = phar->tab_produits[j];
       phar->tab_produits[j]= phar->tab_produits[k];
       phar->tab_produits[k]=aux;

       int id;
       id = phar->tab_produits[j].id_med;
       phar->tab_produits[j].id_med = phar->tab_produits[k].id_med;
       phar->tab_produits[k].id_med= id;
       }
      }
}





}
 }


