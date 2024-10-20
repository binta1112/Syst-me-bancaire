#pragma once

class Date
{
private:
	int jour;
	int mois;
	int annee;
public:
	Date();
	Date(int jour, int mois, int annee);
	Date& Date_final( int nb_j,int nb_m,int nb_an) const;

	void Afficher_date() const;
	
};

bool  Deep_year(int anne);