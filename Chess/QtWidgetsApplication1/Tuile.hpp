#pragma once

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <qvector2d.h>
#include <QGraphicsRectItem>
//#include "Piece.hpp"

class Piece;

class Tuile : public QGraphicsRectItem {
public:
	Tuile(QGraphicsItem* parent = 0, int tailleTuile = 75);
	
	QVector2D getPosition();
	void setPosition(QVector2D pos);

	bool getOccupee();
	void setOccupee(bool o);

	void setCouleur(QColor couleur);
	void changerCouleur(QColor couleur);
	void retournerCouleurOriginal();

	void setPiece(Piece* p);
	Piece* getPiece();
private:
	QColor couleur_;
	bool occupee_;
	QVector2D position_;
	Piece* piece;
};