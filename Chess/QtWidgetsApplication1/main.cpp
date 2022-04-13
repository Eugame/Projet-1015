#include "Fou.hpp"
#include "Tour.hpp"
#include "Roi.hpp"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chess w;
    QLabel* label = new QLabel(&w);
    Joueur j = Joueur();
    Roi p = Roi(&w, label, w.getTuile(4, 4), j);
    w.show();
    return a.exec();
}
