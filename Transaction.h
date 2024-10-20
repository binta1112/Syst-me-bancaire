#pragma once
#include <iostream>
#include "Date.h"
using namespace std;
class Transaction
{
private:
	static int compter_trs; //compter pour varier l'identifiant a chq creation
	int transaction_id;   //identifiant de la transaction
	double montant;        //montant de la trabsaction
	string transaction_name; //nom de la transaction
    Date transaction_date; //date de la transaction                                   
public:
	Transaction() = delete; //les informations consernant une transaction son necessaires
	Transaction(const Transaction& T) = delete;//si il y'a une transaction entre deux alors il s'agit de la meme ,pas de copie

	Transaction(string name,double montant);
	void Afficher() const;

};

