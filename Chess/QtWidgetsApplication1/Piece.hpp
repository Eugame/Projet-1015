#pragma once

#include <QtWidgets/QApplication>
#include "Joueur.hpp"
#include <QGraphicsSceneMouseEvent>

class Chess;

class Piece : public QWidget {
public:
	Piece(Chess* parent, Tuile* tuile, Joueur joueur = Joueur(), bool active = true) : QWidget(parent)
	{
		setFixedSize(parent->getTailleTuiles(), parent->getTailleTuiles());
		parent_ = parent;
		tuile_ = tuile;
		joueur_ = joueur;
		active_ = active;
		tuile_->setOccupee(true);
		tuile_->setPiece(this);
		move(tuile_->getPosition().x() * parent->getTailleTuiles(), tuile_->getPosition().y() * parent->getTailleTuiles());
	}
	Joueur* getJoueur() { return &joueur_; }
	virtual vector<QVector2D> getMouvements() { return vector<QVector2D>(); }
protected:
	Joueur joueur_;
	bool active_;
	Tuile* tuile_;
	Chess* parent_;
private:
	void mousePressEvent(QMouseEvent* event) override
	{
		vector<QVector2D> mouvements = getMouvements();
		if (parent_->getPieceActive() == this)
		{
			tuile_->retournerCouleurOriginal();
			parent_->changerPieceActive(nullptr);
			for (int i = 0; i < mouvements.size(); i++)
			{
				parent_->getTuile(mouvements[i].x(), mouvements[i].y())->retournerCouleurOriginal();
			}
		}
		else
		{
			parent_->changerPieceActive(this);
			tuile_->changerCouleur(Qt::darkRed);
			for (int i = 0; i < mouvements.size(); i++)
			{
				parent_->getTuile(mouvements[i].x(), mouvements[i].y())->changerCouleur(Qt::darkRed);
			}
		}
	}
};