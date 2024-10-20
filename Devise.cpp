#include "Devise.h"

/*
* Nom_methode:Devise
* Parametres: -devise de type string ,represente le nom de la devise (exemple Euro)
*             - symbole de type string ,represente le symbole de la devise (exemple pour l'euro )
*             -taux typpe double represente le taux d'echange par rapport a l'euro 
* Description:Constructeur de la classe, si il est invoqué sans les parametre ,
*            initialise les attribut par les valeurs par defauts prealablement definis
*/
Devise::Devise(string devise, string symbole , double taux):devise_name(devise),symbole(symbole),taux_echange(taux)
{}

/*
* Nom_methode:Affiche_devise
* Parametre:Aucun
* Description:methode responsable d'afficher a l'ecran les information d'une devise
*/
void Devise::Affiche_devise() const
{
	cout << "Devise_name: " << this->devise_name << endl;
	cout << "symbole: " << this->symbole<< endl;
	cout << "Devise_taux_echange: " << this->taux_echange<< endl;

}
/*
* Nom_methode:Exchange
* Parametre:-montant de type double le montant d'echange
*           -devise la devise d'echange
* Description:methode pour convertire un somme de la devise courante en une autre
*            puisqu'on a le taux de chaque monaie par rapport a l'euro alors
*            on convertit le montant d'abord en euro puis de l'euron a la devise finale
*/
double Devise::Exchange(double montant, const Devise& devise) const
{
	double final;
	final = (montant * this->taux_echange) / devise.taux_echange;
	return final;
}
