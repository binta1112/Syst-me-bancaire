#pragma once
#include "Transaction.h"
class Transfert : public Transaction
{
private:
	int sender; //le numero du compte emmeteur
	int recever; //le numero du compte receveur
public:
	Transfert() = delete;
	Transfert(const Transfert& T) = delete;
	Transfert( double montant, int sender, int recever);
	void Afficher() const;
};

