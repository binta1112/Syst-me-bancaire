#pragma once
#include"Compte.h"
#include"Compte_epargne.h"

class Client
{
private:
	static int cpt_clt;
	int id_client; //Identifiant du client
	string name;   //nom du client
	Compte* comptes[5];//les comptes simples du clients
	Compte_epargne* comptes_epargnes[5];//les comptes epargnes du clients
	int nb_comptes[3];     //les nombres des comptes
public:
	/*****************************************************/
	Client() = delete;
	Client(const Client& clt) = delete;
	Client operator = (const Client& clt) = delete;
	/*****************************************************/
	
	Client(string name, int num_compte, int compte_echeance, Devise d,double *taux);//avec creation d'un compte epagne ou simple

	Client(string name,Devise *d);//pour la creation d'un compte multi-devise

	void Creer_compte(int num_compte, int compte_echeance, Devise d, double* taux);

	void Creer_compte(int num_compte, int compte_echeance,Devise *d);//pour ajouter un compte muti-devise

	void Afficher_client() const;
	void Consulter_solde(int num_compte) const;
	void Recharger_compte(int num_compte,double montant);
	void Retirer_argent(int num_compte,double montant);
	void Effectuer_Transfet(int num_compte,int num_compte_recever,const Client& recever,double montant);

	int Rechercher_compte(int* type, int num_compte) const;

	~Client();
};

