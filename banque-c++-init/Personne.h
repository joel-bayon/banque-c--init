#ifndef PERSONNE_H_
#define PERSONNE_H_
#include <iostream>
#include <string>
#include  "Titulaire.h"



class Personne :  public Titulaire {
	std::string nom;
	std::string prenom;
	std::string adresse;

public:
	Personne(const std::string& nom, const std::string& prenom, const std::string& adresse)
	: nom(nom), prenom(prenom), adresse(adresse) { std::cout << "Instanciation de Personne" << std::endl;}
	~Personne(){std::cout << "Destruction de Personne" << std::endl;}

	std::string getIdentite() const override {
		return nom + " " + prenom;
	}
	std::string getAdressePostale() const override {
		return adresse;
	}

};


#endif /* PERSONNE_H_ */
