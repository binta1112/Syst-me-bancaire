#pragma once
#include "Date.h"
#include "Devise.h"
#include "Transaction.h"
#include "Transfert.h"
/*
* Classe pour les comptes
*/
class Compte
{
	
protected:
	static int cpt_compte;
	int compte_id;        //identifiant du compte
	int num_compte;      //numéro du compte
	double solde;        //solde du compte
	Date creation_date;  //date de creation du compte
	Date expiration_date;//date d'expiration du compte
	
	shared_ptr <Transaction> intern_Transaction[10];// les transaction associées au uniquement compte (depot,retrait,..)
	                                               //avec un nombre maximal 10
	shared_ptr <Transfert> extern_Transaction[10];// les transaction associées au compte et un autre (virement,payement par carte,abonnement..)
	                                             // avec nombre maximal 10
	int nb_trans[2];                            //nombre de transaction 
	bool etat;									//precise l'etat du compte (actif ou non )

	Devise devise;       //la devise du compte
public:
	Compte() = delete;
	Compte(const Compte& c)=delete;
	Compte(int num ,Devise devise,int echeance);
	Compte operator = (const Compte& c) = delete;
	void consulter_solde() const;
	void Infos_sur_compte() const;
	void Historique_trans()const;
	void Retrait_sur_compte(double montant);
	void Depot_sur_compte(double montant);
	void Transfert_sur_compte(double montant, Compte& recever);

	void Reactiver_compte();
	bool is_equal(int num_compte) const;
	bool Etat_du_compte() const;




};

