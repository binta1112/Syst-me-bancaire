#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;
Date::Date()
{
	time_t T = time(nullptr);
	tm sysT;
	localtime_s(&sysT,&T);
	this->jour = sysT.tm_mday;
	this->mois = sysT.tm_mon + 1;
	this->annee = sysT.tm_year + 1900;
}
Date::Date(int jour, int mois, int annee):jour(jour),mois(mois),annee(annee)
{}

Date& Date::Date_final(int nb_j, int nb_m, int nb_an)const
{
	int tab_mois[12] = {31,28,31,30,31,30,31,31,30,31,30,31},
		jour, mois, annee;
	
	jour = this->jour + nb_j;
	mois = (this->mois + nb_m)%12;
	if (mois == 0) mois = 12;
	annee = this->annee + nb_an+ (this->mois + nb_m) / 13;
	if (jour > tab_mois[mois-1])
	{
		if (mois == 2 && Deep_year(annee))
			jour = 29;
		else
		{
			jour = jour % tab_mois[mois-1];
			annee += (mois + 1) / 13;
			mois = (mois+1)%12;
			if (mois == 0) mois=12;
		}
	}
	Date d(jour, mois, annee);
	return d;
}

bool Deep_year(int anne)
{
	return false;
}



void Date::Afficher_date() const
{
	cout << this->jour <<"-" <<this->mois<<"-"<<this->annee << endl;
	
}


