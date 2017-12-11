/*
 * main.cpp
 *
 *  Created on: 16 janv. 2017
 *      Author: joel
 */
#include <iostream>
#include "Operation.h"
#include "Compte.h"
#include "Personne.h"
#include "Societe.h"
#include "Banque.h"

using namespace std;

int main(int argc, char **argv) {

	Personne *  p= new Personne("Long","Philip", "Bouguenais");
	Societe * s = new Societe("IRT Jules Verne","23123123", "Nantes");

	Banque b("LCL", "123123");

	int nCpt1 = b.ouvrirCompte(100, p);
	int nCpt2 = b.ouvrirCompte(10, s);
	b.ouvrirCompte(50, p);
	b.ouvrirCompte(100, p);
	b.ouvrirCompte(200, p);
	b.ouvrirCompte(150, p);
	b.ouvrirCompte(2000, p);
	b.editerLesReleves();
	Compte * c1 = b.getCompte(nCpt1);
	Compte * c2 = b.getCompte(nCpt2);


	c1->crediter(100);
	c1->debiter(300);
	c1->debiter(1);				// --> débit impossible ....

	c2->crediter(100);
	c2->crediter(150);
	c2->debiter(260); 			// --> solde à 0 ....
	b.fermerCompte(nCpt1);		// --> fermeture impossible solde négatif ....
	b.fermerCompte(nCpt2);
	b.editerLesReleves();

	cout << "******** Fin ********"<< endl;
	return 0;

}



