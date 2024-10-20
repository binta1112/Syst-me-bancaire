#pragma once
#include <iostream>
using namespace std;

class Devise
{
private:
	string devise_name;//nom de la devise
	string symbole;     //le symbole de la devise
	double taux_echange; //taux d'echange par rapport a l'euro que je considere comme monaie de reference
	
public:
	Devise(string devise = "Euro",string symbole ="$", double taux = 1.0);
	void Affiche_devise() const;
	double Exchange(double montant, const Devise& devise) const;
};

