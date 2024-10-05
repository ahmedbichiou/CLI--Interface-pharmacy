struct date
{
    int jour;
    int mois;
    int annee;

};
typedef struct date DATE;
struct Temp
{
    int heure;
    int minute;
    int seconde;
};
typedef struct Temp TEMP;



struct client
{
    int id_client;
    char nom[20];
    char prenom[20];
    int CIN;
};
typedef struct client CLIENT;



struct produit
{
    int id_med;
    char nom[20];
    char entreprise[20];
    int quantite;
    float prix_med;
    DATE validite;
};
typedef struct produit PRODUIT;

struct Employe
{
    int id_employe;
    char nom[20];
    char prenom[20];
    DATE date_debut;
    float salaire;
    char role[50];
};
typedef struct Employe EMPLOYE;


struct Facture
{
 EMPLOYE employe_caisse;
 CLIENT client;
 int nbr_produits_dans_facture;
 PRODUIT *les_produit;
 TEMP temp_achat;
 float prixTotal;
 PRODUIT prod_pop;
};
typedef struct Facture FACTURE;

struct Recette
{
 DATE date_jour;
 int nbr_factures_dans_recette;
 FACTURE *tous_factures;

};
typedef struct Recette RECETTE;


struct pharmacie
{
    int nbr_produit;
    int nbr_clients;
    int nbr_employes;
    int nbr_recettes;
    CLIENT tab_client[50];
    PRODUIT *tab_produits;
    EMPLOYE *tab_employes;
    RECETTE *tab_recette;

};

typedef struct pharmacie PHARMACIE;




struct plusvendu
{
  PRODUIT produit_jour;
  DATE date_jour;
};

typedef struct plusvendu PLVENDU;


int valide(int,int,int);
float calcul_total(int,int);
char menu();
char menu_produits();
char menu_factures();
char menu_Employes();
char menu_traitements();
void Ajout_produit(PRODUIT*,int);
void Ajout_employe(EMPLOYE*,int);
void setup(int*,int*,int*);
void affichage_produit(PRODUIT*,int);
void affichage_employe(EMPLOYE*,int);
void allocation_recettes(RECETTE**,int*);
void allocation_recettes(RECETTE** ,int*);
void valide_temp(int*,int*,int*);
void allocation_produits(PRODUIT**,int);
void allocation_employes(EMPLOYE**,int);
void allocation_tableau_dyn_adr_strc(PLVENDU***,int);
void produit_plus_populaire_par_jour(RECETTE*,PRODUIT*,int*);
void produit_plus_populaire_par_facture(FACTURE*);
float calcul_total(int,int);
void nom_client_plus_frequent(RECETTE*);

