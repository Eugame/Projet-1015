#include "Tuile.hpp"

Tuile::Tuile(QGraphicsItem* parent, int tailleTuile) : QGraphicsRectItem(parent) {
	setRect(0, 0, tailleTuile, tailleTuile);
	occupee_ = false;
}
QVector2D Tuile::getPosition() { return position_; }
void Tuile::setPosition(QVector2D pos) { position_ = pos; }

bool Tuile::getOccupee() { return occupee_; }
void Tuile::setOccupee(bool o) { occupee_ = o; }

void Tuile::setCouleur(QColor couleur) { couleur_ = couleur; }
void Tuile::changerCouleur(QColor couleur) { setBrush(couleur); }
void Tuile::retournerCouleurOriginal() { changerCouleur(couleur_); }

void Tuile::setPiece(Piece* p) { piece = p; }
Piece* Tuile::getPiece() { return piece; }
