#include "Client.h"
int Client::cpt_clt = 0;

/*
* Nom_methode:Client
* Parametres:-name :Nom du client
*            -num_compte numero du compte
*            -compte_echeance :duree de validite du compte en nombre d'annees
*            - d : la devise du compte
*            -taux: le taux d'interet pour le compte d'epargne (est a null pour un compte ordinaire)
* Description:Constructeur a utiliser l'hors de la creation d'client avec un compte epargne ou ordinaire
*/
Client::Client(string name, int num_compte, int compte_echeance, Devise d, double *taux):id_client(cpt_clt++), name(name)
{
	this->nb_comptes[0] = this->nb_comptes[1] = this->nb_comptes[2] = 0;
	//si le taux est un pointeur null alors il s'agit d'un compte ordinaire
	if(!taux)
		this->comptes[this->nb_comptes[0]++] = new Compte(num_compte, d, compte_echeance);
	else//sinon il s'agit d'un compte d'epargne
		this->comptes_epargnes[this->nb_comptes[1]++] = new Compte_epargne(num_compte, d, *taux, compte_echeance);

}



/**************************************************************************************************/

/*
* Nom_methode:Client
* Parametres:-name :Nom du client
*            -num_compte numero du compte
*            -compte_echeance :duree de validite du compte en nombre d'annees
*            - d : la devise du compte
* Description:Constructeur a utiliser l'hors de la creation d'client avec un compte simple
*/
Client::Client(string name, Devise* d) 
{

}
/**************************************************************************************************/
/*
* Nom_methode:Creer_compte
* Parametres:
*            -num_compte numero du compte
*            -compte_echeance :duree de validite du compte en nombre d'annees
*            - d : la devise du compte
* Description:La methode permet l'ouverture d'un nouveau compte pour un client existant
*/
void Client::Creer_compte(int num_compte, int compte_echeance, Devise d, double* taux)
{
	//si le taux est un pointeur null alors il s'agit d'un compte ordinaire
	if (!taux)
		this->comptes[this->nb_comptes[0]++] = new Compte(num_compte, d, compte_echeance);
	else//sinon il s'agit d'un compte d'epargne
		this->comptes_epargnes[this->nb_comptes[1]++] = new Compte_epargne(num_compte, d, *taux, compte_echeance);
}

/*
* Nom_methode:Creer_compte
* Parametres:
*            -num_compte numero du compte
*            -compte_echeance :duree de validite du compte en nombre d'annees
*            - d : la devise du compte
* Description:La methode permet l'ouverture d'un nouveau compte multi-devise pour un client existant
*/
void Client::Creer_compte(int num_compte, int compte_echeance, Devise* d)
{
}
/**************************************************************************************************/

void Client::Afficher_client() const
{
	cout << "*****************Information sur le client***************" << endl;
	cout << "Identifiant_client: "<<this->id_client << endl;
	cout << "Nom_client: " << this->name << endl;
	cout << "********************Les comptes du clients "<< endl;

	if (this->nb_comptes[0] > 0)
	{
		cout << "Comptes ordinaires:"<<endl;
		for (int i = 0; i < this->nb_comptes[0]; i++)
		{
			this->comptes[i]->Infos_sur_compte();
			cout << "****************************** " << endl;

		}

	}
	if (this->nb_comptes[1] > 0)
	{
		cout << "Comptes epargnes:" << endl;
		for (int i = 0; i < this->nb_comptes[0]; i++)
		{
			this->comptes_epargnes[i]->Infos_sur_compte();
			cout << "****************************** " << endl;

		}

	}



}
/**************************************************************************************************/

void Client::Consulter_solde(int num_compte) const
{
	int indice, type ;
	/*On recherche le compte*/
	indice = this->Rechercher_compte(&type, num_compte);
	/*puis on effectue l'operation selon le compte*/
	switch (type)
	{
	case 0:
		this->comptes[indice]->consulter_solde();
		break;
	case 1:
		this->comptes_epargnes[indice]->consulter_solde();
		break;
	default:
		break;
	}
}

void Client::Recharger_compte(int num_compte, double montant)
{
	int indice,  type ;
	/*On recherche le compte*/
	indice = this->Rechercher_compte(&type, num_compte);
	/*puis on effectue l'operation selon le compte*/
	switch (type)
	{
	case 0:
		this->comptes[indice]->Depot_sur_compte(montant);
		break;
	case 1:
		this->comptes_epargnes[indice]->Depot_sur_compte(montant);
		break;
	default:
		break;
	}
}

void Client::Retirer_argent(int num_compte, double montant)
{
	int indice, *type=nullptr;
	/*On recherche le compte*/
	indice = this->Rechercher_compte(type, num_compte);
	/*puis on effectue l'operation selon le compte*/
	switch (*type)
	{
	case 0:
		this->comptes[indice]->Retrait_sur_compte(montant);
		break;
	case 1:
		this->comptes_epargnes[indice]->Retrait_sur_compte(montant);
		break;
	 default:
		break;
	}
}

void Client::Effectuer_Transfet(int num_compte, int num_compte_recever, const Client& recever, double montant)
{
	int indice1,indice2, type1,type2;
	/*On recherche les deux  comptes*/
	indice1 = this->Rechercher_compte(&type1, num_compte);
	indice2 = recever.Rechercher_compte(&type2, num_compte_recever);

	/*puis on effectue l'operation selon le compte*/
	switch (type1)
	{
	case 0:
		if (type2 == 0) this->comptes[indice1]->Transfert_sur_compte(montant, *recever.comptes[indice2]);
		else
			if(type2==1)this->comptes[indice1]->Transfert_sur_compte(montant, *recever.comptes_epargnes[indice2]);
		  
		break;
	case 1:
		if (type2 == 0) this->comptes_epargnes[indice1]->Transfert_sur_compte(montant, *recever.comptes[indice2]);
		else
			if (type2 == 1)this->comptes_epargnes[indice1]->Transfert_sur_compte(montant, *recever.comptes_epargnes[indice2]);
		break;
	default:
		break;
	}
}
Client::~Client()
{
	for (int i = 0; i < this->nb_comptes[0]; i++) delete this->comptes[i];
	for (int i = 0; i < this->nb_comptes[1]; i++) delete this->comptes_epargnes[i];

}
int Client::Rechercher_compte(int* type,int num_compte)const
{
	/*si le num_compte est un compte ordinaire*/
	if (num_compte < 100)
		for (int j = 0; j < this->nb_comptes[0]; j++)
		{
			if (this->comptes[j]->is_equal(num_compte))
			{
				*type = 0;
				return j;
			}
		}
	/*si le num_compte est un compte epargne*/
	if (num_compte < 1000)
		for (int j = 0; j < this->nb_comptes[1]; j++)
		{
			if (this->comptes_epargnes[j]->is_equal(num_compte))
			{
				*type = 1;
				return j;
			}
		}
	/*Sinon un compte multi-devise*/
}

