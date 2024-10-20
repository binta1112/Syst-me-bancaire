#pragma once
#include "Compte.h"
class Compte_epargne : public Compte
{
private:
	double taux; //le taux d'interet
public:
	Compte_epargne() = delete;
	Compte_epargne(const Compte_epargne& c) = delete;
	Compte_epargne(int num, Devise devise ,double taux,int echeance);
	Compte_epargne operator = (const Compte_epargne& c) = delete;
};

