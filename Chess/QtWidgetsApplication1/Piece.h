#pragma once

#include <QtWidgets/QApplication>
#include "Joueur.hpp"
#include <QGraphicsSceneMouseEvent>

class Piece : public QWidget {
public:
	Piece(Chess* parent, Tuile* tuile, Joueur joueur = Joueur(), bool active = true)
	{
		parent_ = parent;
		tuile_ = tuile;
		joueur_ = joueur;
		active_ = active;
	}

protected:
	Joueur joueur_;
	bool active_;
	Tuile* tuile_;
	Chess* parent_;
private:
	void mousePressEvent(QMouseEvent* event)
	{
		if (parent_->getPieceActive() == this)
		{
			tuile_->retournerCouleurOriginal();
			parent_->changerPieceActive(nullptr);
		}
		else
		{
			parent_->changerPieceActive(this);
			tuile_->changerCouleur(Qt::darkRed);
		}
		tuile_->changerCouleur(Qt::black);
	}
};
class Pion : public Piece {
public:
	Pion(Chess* parent, QLabel* l, Tuile* tuile) : Piece(parent, tuile)
	{
		image.load("pion_" + joueur_.getCouleur() + ".png");
		l->setPixmap(QPixmap::fromImage(image.scaled(parent->getTailleTuiles(), parent->getTailleTuiles())));
	}
private:
	QImage image;
	//std::vector<QVector2D> ensembleDeplacement_ = {QVector2D(1,1),QVector2D(-1,1),QVector2D(0,1), QVector2D(0,2) };
};