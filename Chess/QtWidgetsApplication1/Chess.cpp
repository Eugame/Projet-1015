#include "Chess.hpp"

Chess::Chess(QWidget *parent)
    : QGraphicsView(parent)
{
    setFixedSize(8 * tailleTuiles, 8 * tailleTuiles);
    scene.setSceneRect(0, 0, 8 * tailleTuiles, 8 * tailleTuiles);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(&scene);
    QColor couleur;
    for (int i = 0; i < 8; i++)
    {
        tuiles.push_back(vector<Tuile*>());
        for (int j = 0; j < 8; j++)
        {
            Tuile* t = new Tuile();
            tuiles[i].push_back(t);
            t->setPosition(QVector2D(i, j));
            t->setPos(i * tailleTuiles, j * tailleTuiles);

            if ((i + j) % 2 == 0)
                couleur = Qt::lightGray;
            else
                couleur = Qt::darkCyan;
            t->setCouleur(couleur);
            t->changerCouleur(couleur);
            scene.addItem(t);
        }
    }
    ui.setupUi(this);
}
void Chess::changerPieceActive(Piece* p)
{
    pieceSelectionnee = p;
}
Piece* Chess::getPieceActive()
{
    return pieceSelectionnee;
}
