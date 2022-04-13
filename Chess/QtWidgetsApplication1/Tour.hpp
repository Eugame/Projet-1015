#pragma once

#include "Piece.hpp"

class Tour : public Piece {
public:
	Tour(Chess* parent, QLabel* l, Tuile* tuile, Joueur joueur) : Piece(parent, tuile, joueur)
	{
		image.load("pion_" + joueur_.getCouleur() + ".png");
		l->setPixmap(QPixmap::fromImage(image.scaled(parent->getTailleTuiles(), parent->getTailleTuiles())));
		l->move(pos().x(), pos().y());
	}
	vector<QVector2D> getMouvements() override
	{
		vector<QVector2D> mouvements;
        for (int i = tuile_->getPosition().y() + 1; i < 8; ++i) {
            if (parent_->getTuile(tuile_->getPosition().x(), i)->getOccupee()) {
                if (parent_->getTuile(tuile_->getPosition().x(), i)->getPiece()->getJoueur()->
                    getValeurJoueur() == joueur_.getValeurJoueur())
                    break;
            }
            mouvements.push_back(QVector2D(tuile_->getPosition().x(), i));
        }

        //gauche
        for (int i = tuile_->getPosition().x() - 1; i >= 0; --i) {
            if (parent_->getTuile(i, tuile_->getPosition().y())->getOccupee()) {
                if (parent_->getTuile(i, tuile_->getPosition().y())->getPiece()->getJoueur()->
                    getValeurJoueur() == joueur_.getValeurJoueur())
                    break;
            }
            mouvements.push_back(QVector2D(i, tuile_->getPosition().y()));
        }
        //haut
        for (int i = tuile_->getPosition().y() - 1; i >= 0; --i) {
            if (parent_->getTuile(tuile_->getPosition().x(), i)->getOccupee()) {
                if (parent_->getTuile(tuile_->getPosition().x(), i)->getPiece()->getJoueur()->
                    getValeurJoueur() == joueur_.getValeurJoueur())
                    break;
            }
            mouvements.push_back(QVector2D(tuile_->getPosition().x(), i));
        }
        //droite
        for (int i = tuile_->getPosition().x() + 1; i < 8; ++i) {
            if (parent_->getTuile(i, tuile_->getPosition().y())->getOccupee()) {
                if (parent_->getTuile(i, tuile_->getPosition().y())->getPiece()->getJoueur()->
                    getValeurJoueur() == joueur_.getValeurJoueur())
                    break;
            }
            mouvements.push_back(QVector2D(i, tuile_->getPosition().y()));
        }
		return mouvements;
	}
private:
	QImage image;
};