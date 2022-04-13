#pragma once

#include "Piece.hpp"

class Fou : public Piece {
public:
	Fou(Chess* parent, QLabel* l, Tuile* tuile, Joueur joueur) : Piece(parent, tuile, joueur)
	{
		image.load("pion_" + joueur_.getCouleur() + ".png");
		l->setPixmap(QPixmap::fromImage(image.scaled(parent->getTailleTuiles(), parent->getTailleTuiles())));
		l->move(pos().x(), pos().y());
	}
	vector<QVector2D> getMouvements() override
	{
		vector<QVector2D> mouvements;
		for (int i = 1; i < 8; i++)
		{
			if (parent_->getTuile(tuile_->getPosition().x() + i,
				tuile_->getPosition().y() + i) == nullptr)
				break;
			Tuile* position = parent_->getTuile(tuile_->getPosition().x() + i,
				tuile_->getPosition().y() + i);
			if (position->getOccupee())
				if (joueur_.getValeurJoueur() == position->getPiece()->getJoueur()
					->getValeurJoueur())
					break;
			mouvements.push_back(position->getPosition());
		}
		for (int i = 1; i < 8; i++)
		{
			if (parent_->getTuile(tuile_->getPosition().x() - i,
				tuile_->getPosition().y() + i) == nullptr)
				break;
			Tuile* position = parent_->getTuile(tuile_->getPosition().x() - i,
				tuile_->getPosition().y() + i);
			if (position->getOccupee())
				if (joueur_.getValeurJoueur() == position->getPiece()->getJoueur()
					->getValeurJoueur())
					break;
			mouvements.push_back(position->getPosition());
		}
		for (int i = 1; i < 8; i++)
		{
			if (parent_->getTuile(tuile_->getPosition().x() + i,
				tuile_->getPosition().y() - i) == nullptr)
				break;
			Tuile* position = parent_->getTuile(tuile_->getPosition().x() + i,
				tuile_->getPosition().y() - i);
			if (position->getOccupee())
				if (joueur_.getValeurJoueur() == position->getPiece()->getJoueur()
					->getValeurJoueur())
					break;
			mouvements.push_back(position->getPosition());
		}
		for (int i = 1; i < 8; i++)
		{
			if (parent_->getTuile(tuile_->getPosition().x() - i,
				tuile_->getPosition().y() - i) == nullptr)
				break;
			Tuile* position = parent_->getTuile(tuile_->getPosition().x() - i,
				tuile_->getPosition().y() - i);
			if (position->getOccupee())
				if (joueur_.getValeurJoueur() == position->getPiece()->getJoueur()
					->getValeurJoueur())
					break;
			mouvements.push_back(position->getPosition());
		}
		return mouvements;
	}
private:
	QImage image;
};