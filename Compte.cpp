#include "Compte.h"
/*
* On initialise cette variable de classe qui nous permetra de creer d'attribuer
* differents identifients a chaque creation
*/
int Compte::cpt_compte = 0;
/*
* Nom_methode:Compte
* Parametres: -num de type int ,pour specifier la transaction (exemple un depot sur le compte)
*             - date de type shared_ptr<Date> ,un pointer sur un element date qui peut etre partage
*             - echeance de type int la durée en année du compte fourni par la banque
* Description:Constructeur de la classe,ne peut pas etre appelé sans prametre car cette possibilité est desactivée
*/
Compte::Compte(int num, Devise devise, int echeance) :compte_id(cpt_compte++), num_compte(num), solde(0.0), creation_date(Date()), devise(devise), etat(1)
{
    this->nb_trans[0] = 0;
    this->nb_trans[1] = 0;
    this->expiration_date = this->creation_date.Date_final(0,0,echeance);
}

/*
* Nom_methode:consulter_solde
* Paramètres:Aucun
* Description:Cette methode affiche le solde du compte
*/
void Compte::consulter_solde() const
{
    cout << "Solde total du compte: " << this->solde << endl;
}

/*
* Nom_methode:Infos_sur_compte
* Paramètres:Aucun
* Description:Cette methode affiche toutes les informations du compte
*/
void Compte::Infos_sur_compte() const
{
    cout << "Identifiant du compte: " << this->compte_id << endl;
    cout << "Numero du compte: " << this->num_compte << endl;
    cout << "Solde du compte: " << this->solde << endl;
    cout << "Devise utilise: "<<endl;
    this->devise.Affiche_devise();
    cout << "Cree le:        " ;
    this->creation_date.Afficher_date();
    cout << "Valable jusqu'au: ";
   this->expiration_date.Afficher_date();
    this->Historique_trans();

}
/*
* Nom_methode:Historique_trans
* Paramètres:Aucun
* Description:Cette methode affiche toutes les informations sur les differentes 
              transaction du compte
*/
void Compte::Historique_trans() const
{
    cout << "Historique des Transactions du compte" << endl;
    for (int i =0; i < this->nb_trans[0];i++)
        this->intern_Transaction[i]->Afficher();
    
    for (int i = 0; i < this->nb_trans[1]; i++)
        this->extern_Transaction[i]->Afficher();
}
/*
* Nom_methode:Retrait_sur_compte
* Paramètres:montant de type double
* Description:methode responsable de retrait sur le compte
*/
void Compte::Retrait_sur_compte(double montant)
{
    //Test si le montant donnée est valide
    if ((montant < 0) || (montant > solde)) return;
    this->solde -= montant;
   //Enregistrement du retrait dans la table des transaction
    intern_Transaction[this->nb_trans[0]++] = make_shared<Transaction>("Retrait", montant);

}
/*
* Nom_methode:Depot_sur_compte
* Paramètres:montant de type double
* Description:methode responsable de Depot sur le compte
*/
void Compte::Depot_sur_compte(double montant)
{

    //Test si le montant donnée est valide
    if (montant < 0) return;
    this->solde += montant;
    //Enregistrement du retrait dans la table des transaction
    intern_Transaction[this->nb_trans[0]++] = make_shared<Transaction>("Depot", montant);

}
/*
* Nom_methode:Transfert_sur_compte
* Paramètres:-montant de type double:montant de transfer
*            -recever type compte: le compte receveur
* Description:methode responsable du transfer d'argent entre deux comptes
*/
void Compte::Transfert_sur_compte(double montant, Compte& recever)
{
    //test de la validite du montant
    if ((montant < 0) || (montant > this->solde)) return;
    this->solde -= montant;
    //on convertit le montant en devise du recever puis l'ajouter sur son compte    
    recever.solde += this->devise.Exchange(montant,recever.devise);
    //On enregistre l'operation au niveau des deux comptes
    this->extern_Transaction[this->nb_trans[1]++] =
        recever.extern_Transaction[recever.nb_trans[1]++] =
        make_shared<Transfert>( montant, this->num_compte, recever.num_compte);


}
/*
* Nom_methode:is_equal
* Paramètres:Aucun
* Description:Cette methode permet de savoir si le numero correspond au num du compte
*/
bool Compte::is_equal(int num_compte)const
{
    return this->num_compte==num_compte;
}

/*
void Compte::Reactiver_compte()
{
}



bool Compte::Etat_du_compte() const
{
    return false;
}
*/