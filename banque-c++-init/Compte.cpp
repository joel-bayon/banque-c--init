
#include <iostream>
#include "Compte.h"

using namespace std;
static int cptNumero = 10000;

Compte::Compte(float depotInitial, Titulaire * titulaire)
: numero(cptNumero++), solde(0), decouvertAutorise(depotInitial), titulaire(titulaire) {
	crediter(depotInitial);
	cout << "Construction d'un Compte" << endl;
}

Compte::~Compte() {
	cout << "Destruction d'un Compte" << endl;
	for(int i = 0; i < operations.size(); i++)
			delete operations[i];
}

void Compte::crediter(float montant) {
	solde+=montant;
	operations.push_back(new Operation(montant, Operation::typeOperation::credit));

}
void Compte::debiter(float montant) {
	if(montant <= solde+decouvertAutorise) {
		solde-=montant;
		operations.push_back(new Operation(montant, Operation::typeOperation::debit));
		return;
	}
	cout << "Debit impossible ... !" << endl;
}

void Compte::editerReleve() const {

	cout << "**** releve de compte ****" << endl;
	cout << "Titulaire=" + titulaire->getIdentite() << " adresse postale=" << titulaire->getAdressePostale() << endl;
	cout << toString() << endl;
	for(    vector<Operation *>::const_iterator iter = operations.begin();
			iter != operations.end();
			iter++)
		cout << (*iter)->toString() << endl;
}

std::string Compte::toString() const {
	return "Compte[numero=" + to_string(numero) + " solde=" + to_string(solde) + " decouvertAutorise=" + to_string(decouvertAutorise) +"]";
}

