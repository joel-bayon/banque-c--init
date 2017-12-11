
#ifndef COMPTE_H_
#define COMPTE_H_

#include  <string>
#include  <vector>
#include  <iostream>
#include  <stdexcept>
#include  "Operation.h"
#include  "Titulaire.h"

class Compte {
public:

protected:
	const int numero;
	float solde;
	const float decouvertAutorise;

	std::vector<Operation *> operations;
	Titulaire * titulaire;

public:
	Compte(float depotInitial, Titulaire * titulaire);
	~Compte();

	void crediter(float montant);
	void debiter(float montant);
	void editerReleve() const ;
	std::string toString() const;


	float getDecouvertAutorise() const {
		return decouvertAutorise;
	}

	int getNumero() const {
		return numero;
	}

	float getSolde() const {
		return solde;
	}

	Titulaire * getTitulaire() const {
		return titulaire;
	}


	std::vector<Operation *> const & getOperations() const  {
			return operations;
	}

};

#endif /* COMPTE_H_ */
