#pragma once

#include "Chess.hpp"

class Joueur {
public:
	Joueur(QString couleur = "blanc", int valeurJoueur = -1)
	{
		couleur_ = couleur;
		valeurJoueur_ = valeurJoueur;
	}
	int getValeurJoueur()
	{
		return valeurJoueur_;
	}
	QString getCouleur() { return couleur_; }
private:
	QString couleur_;
	int valeurJoueur_;
};