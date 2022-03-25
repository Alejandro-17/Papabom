#ifndef PAPABOM_H
#define PAPABOM_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QImage>
#include <list>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QTimer>
#include <vector>
#include <QDebug>
#include<ctime>


#define Ruta_imagenb "../Papabom/imagenes/gris.jpg"
#define Ruta_caja "../Papabom/imagenes/caja.jpg"
#define Ruta_enemigo "../Papabom/imagenes/enemigo.png"
#define Ruta_personaje "../Papabom/imagenes/personaje.png"
#define Ruta_puerta "../Papabom/imagenes/puerta.png"


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



protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void eliminarBomba();
    void moverenemigo();



    void on_tiempo_overflow();



private:
    Ui::Papabom *ui;
    QGraphicsScene *scene;
    QGraphicsItem *bomba;
    list <QGraphicsRectItem *> bloques;
    list <QGraphicsRectItem *> cajas;
    list <QGraphicsRectItem *> explocion;
    vector <QGraphicsRectItem *> enemigos;
    list <QGraphicsRectItem *> PerSal;
    QTimer *timer,*tiempo;
    QTimer *timerenemy;
    int VeriBom=0,vidas=0;
    int contador=0;
    int puntos=0;





    ////// Mapa de escenario ///////
    char mapabloques[13][23]={
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','0','0','0','2','0','0','0','2','2','2','2','0','0','0','0','2','2','2','0','0','2','1'},
        {'1','0','1','0','1','0','1','0','1','2','1','2','1','2','1','0','1','0','1','0','1','0','1'},
        {'1','2','0','0','0','0','0','0','0','3','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','1','0','1','0','1','0','1','0','1','2','1','0','1','0','1','0','1','0','1','2','1'},
        {'1','0','0','2','0','0','3','0','2','2','0','0','2','0','0','0','0','0','2','0','0','0','1'},
        {'1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','2','1','2','1','2','1','0','1'},
        {'1','2','0','0','0','2','2','0','0','0','0','0','0','0','2','0','0','0','3','0','0','0','1'},
        {'1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','0','1','2','1'},
        {'1','0','0','0','0','2','0','2','0','0','0','2','2','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','1','2','1','0','1','2','1','0','1','0','1','2','1','0','1','0','1','0','1','0','1'},
        {'1','0','0','0','2','0','0','0','2','2','0','3','0','2','0','0','2','0','2','0','0','0','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
    };


};
#endif // PAPABOM_H
