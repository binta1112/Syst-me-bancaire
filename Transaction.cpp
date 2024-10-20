#include "Transaction.h"
/*
* On initialise cette variable de classe qui nous permetra de creer d'attribuer
* differents identifients a chaque creation 
*/
int Transaction::compter_trs = 0;
/*
* Nom_methode:Transaction
* Parametres: -name de type string ,pour specifier la transaction (exemple un depot sur le compte)
*             - date de type shared_ptr<Date> ,un pointer sur un element date qui peut etre partage
*             
* Description:Constructeur de la classe,ne peut pas etre appelé sans prametre car cette possibilité est desactivée
*/
Transaction::Transaction(string name, double montant) :transaction_id(compter_trs++),montant(montant), transaction_name(name),transaction_date(Date())
{}

/*
* Nom_methode:Afficher
* Parametre:Aucun
* Description:methode responsable d'afficher a l'ecran les information d'une transaction
*/
void Transaction::Afficher() const
{
	cout << "Transaction_id " << this->transaction_id << endl;
	cout << "Transaction_name: " << this->transaction_name << endl;
	cout << "Transaction_date: " ;
	this->transaction_date.Afficher_date();
}
