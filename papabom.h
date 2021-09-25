#ifndef PAPABOM_H
#define PAPABOM_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <vector>

#define Ruta_imagen "../Papabom/imagenes/gris.jpg"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class Papabom; }
QT_END_NAMESPACE

class Papabom : public QMainWindow
{
    Q_OBJECT

public:
    Papabom(QWidget *parent = nullptr);
    ~Papabom();

private:
    Ui::Papabom *ui;
    QGraphicsScene *scene;
    vector <QGraphicsRectItem *> bloques;

};
#endif // PAPABOM_H
