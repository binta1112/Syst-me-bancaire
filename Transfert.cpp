#include "Transfert.h"

/*
* Nom_methode:Transfert
* Parametres: - date de type shared_ptr<Date> ,un pointer sur un element date qui peut etre partage
*            - sender numeo du compte emmeteut
*            - recever numeo du comptereceveur
* Description:Constructeur de la classe,ne peut pas etre appelé sans prametre car cette possibilité est desactivée
*/
Transfert::Transfert( double montant,int sender, int recever) :Transaction("Transfert", montant), sender(sender), recever(recever)
{}

/*
* Nom_methode:Afficher
* Parametre:Aucun
* Description:methode responsable d'afficher a l'ecran les information d'un Transfert
*/
void Transfert::Afficher() const
{
	Transaction::Afficher();
	cout << "Compte emmeteur: " << this->sender << endl;
	cout << "Compte receveur: " << this->recever << endl;

}
