#pragma once
#include <iostream>
#include "Compte.h"
#include "Transfert.h"
#include <memory>
#include "Date.h"
#include "Client.h"
int main()
{
	
    double t = 0.5;
	Client c("Binta", 10, 4, Devise(), nullptr);
	c.Creer_compte(1001,4,Devise(),&t);
	c.Recharger_compte(10, 1000);
	c.Afficher_client();
}

