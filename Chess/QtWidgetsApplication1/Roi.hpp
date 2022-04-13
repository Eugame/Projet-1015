#pragma once

#include "Piece.hpp"

class Roi : public Piece {
public:
	Roi(Chess* parent, QLabel* l, Tuile* tuile, Joueur joueur) : Piece(parent, tuile, joueur)
	{
		image.load("pion_" + joueur_.getCouleur() + ".png");
		l->setPixmap(QPixmap::fromImage(image.scaled(parent->getTailleTuiles(), parent->getTailleTuiles())));
		l->move(pos().x(), pos().y());
	}
	vector<QVector2D> getMouvements() override
	{
		vector<QVector2D> mouvements;
        //haut-gauche
        if (parent_->getTuile(tuile_->getPosition().x() - 1,
            tuile_->getPosition().y() + 1) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x() - 1,
                tuile_->getPosition().y() + 1);
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }

        //haut
        if (parent_->getTuile(tuile_->getPosition().x(),
            tuile_->getPosition().y() + 1) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x(),
                tuile_->getPosition().y() + 1);
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }
        //haut-droite
        if (parent_->getTuile(tuile_->getPosition().x() + 1,
            tuile_->getPosition().y() + 1) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x() + 1,
                tuile_->getPosition().y() + 1);
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }
        //droite
        if (parent_->getTuile(tuile_->getPosition().x() + 1,
            tuile_->getPosition().y()) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x() + 1,
                tuile_->getPosition().y());
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }
        //bas-droite
        if (parent_->getTuile(tuile_->getPosition().x() + 1,
            tuile_->getPosition().y() - 1) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x() + 1,
                tuile_->getPosition().y() - 1);
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }
        //bas
        if (parent_->getTuile(tuile_->getPosition().x(),
            tuile_->getPosition().y() - 1) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x(),
                tuile_->getPosition().y() - 1);
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }
        //bas-gauche
        if (parent_->getTuile(tuile_->getPosition().x() - 1,
            tuile_->getPosition().y() - 1) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x() - 1,
                tuile_->getPosition().y() - 1);
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }
        //gauche
        if (parent_->getTuile(tuile_->getPosition().x() - 1,
            tuile_->getPosition().y()) != nullptr) {
            Tuile* position = parent_->getTuile(tuile_->getPosition().x() - 1,
                tuile_->getPosition().y());
            if (position->getOccupee()) {
                if (joueur_.getValeurJoueur() != position->getPiece()->getJoueur()->
                    getValeurJoueur()) {
                    mouvements.push_back(position->getPosition());
                }
            }
            else
                    mouvements.push_back(position->getPosition());
        }
		return mouvements;
	}
private:
	QImage image;
};