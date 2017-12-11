/*
 * Banque.h
 *
 *  Created on: 18 janv. 2017
 *      Author: joel
 */

#ifndef BANQUE_H_
#define BANQUE_H_
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <future>
#include <mutex>
#include "Titulaire.h"
#include "Compte.h"




class Banque {
	std::string nom;
	std::string code;

	std::map<int, Compte*> comptes;

	int rangerCompte(Compte * cpt) {
		comptes[cpt->getNumero()] = cpt;
			return cpt->getNumero();
	}
public:
	Banque(std::string const& nom, std::string const&  code) :
		nom(nom), code(code) {
	}
	~Banque() {
		std::cout << "Constructeur de Banque" << std::endl;
		for(auto& p : comptes)
			delete p.second;
	}

	int ouvrirCompte(float depotIntial, Titulaire * titulaire) {
		return rangerCompte(new Compte(depotIntial,titulaire));
	}


	Compte * getCompte(int numero) const {
		const auto& iter = comptes.find(numero);
		return iter != comptes.end() ? iter->second : nullptr;
	}

	float fermerCompte(int numero) {
		Compte * cpt = getCompte(numero);
		if(cpt != nullptr && cpt->getSolde() >= 0)	 {
			float relicat = cpt->getSolde();
			comptes.erase(numero);
			delete cpt;
			return relicat;
		}
		return 0;
	}

	void editerLesReleves() const {
		for(auto& p : comptes)
			p.second->editerReleve();
	}

};

#endif /* BANQUE_H_ */
