#pragma once

#include <QtWidgets/QWidget>
#include "ui_Chess.h"
#include <QPushButton>
#include <QPainter>
#include <QLabel>
#include <vector>
#include <qvector2d.h>
#include <string>
#include "Tuile.hpp"
#include <QGraphicsView>

using namespace std;

class Piece;

class Chess : public QGraphicsView
{
    Q_OBJECT
public:
    Chess(QWidget* parent = Q_NULLPTR);
    int getTailleTuiles()
    {
        return tailleTuiles;
    }
    Tuile* getTuile(int caseX, int caseY)
    {
        if (caseX < 0 || caseY < 0 || caseX > 7 || caseY > 7)
            return nullptr;
        return tuiles[caseX][caseY];
    }
    Piece* getPieceActive();
    void changerPieceActive(Piece* p);
private:
    Ui::ChessClass ui;
    int tailleTuiles = 75;
    vector<vector<Tuile*>> tuiles;
    QGraphicsScene scene = QGraphicsScene();
    Piece* pieceSelectionnee;
};
