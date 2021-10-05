#include "papabom.h"
#include "ui_papabom.h"



Papabom::Papabom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Papabom)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(); //Creo escena
    QPen pen(Qt::gray, 1, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    QPen pen2(Qt::darkGreen, 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);// Creo contorno para bloques fijos
    QPen pen3(Qt::black, 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin); //contorno negro
    QImage im(Ruta_imagenb); //Leo imagen de bloques en la direccion ruta_imagen
    QBrush brushbloques(im); // creo brocha con textura gris
    QImage caja(Ruta_caja); //Leo imagen de caja en la direccion ruta_caja
    QBrush brushcajas(caja); // creo brocha con textura de caja
    QImage enemigo(Ruta_enemigo); //Leo imagen de enemigo en la direccion ruta_caja
    QBrush brushenemigo(enemigo); // creo brocha con textura de enemigo
    QImage personaje(Ruta_personaje); //Leo imagen de personaje en la direccion ruta_caja
    QBrush brushpersonaje(personaje); // creo brocha con textura de personaje
    QBrush brushsalida(Qt::black);// creo brocha para salida

     //algoritmo para creacion de bloques en la plataforma
     int ancho=44, alto=44; // dimensiones bloques
     int posy=0;
     for (int i=0; i<13 ; i++ ) {
          int posx=0;

          for(int j=0; j<23;j++){
          if(mapabloques[i][j]==49){
              bloques.push_back(scene->addRect(posx,posy,ancho,alto,pen,brushbloques));
              posx+=44;
          }

          else posx+=44;
          }
           posy+=44;
      }

     //creación personaje
     PerSal.push_back(scene->addRect(45,45,ancho-2,alto-2,pen2,brushpersonaje));


     //Creación de la puerta

     unsigned int ram1,ram2,verificador=0;
     while(verificador==0){
     ram1= QRandomGenerator::global()->bounded(12);
     ram2= QRandomGenerator::global()->bounded(22);
     if (mapabloques[ram1][ram2]==50){
         PerSal.push_back(scene->addRect(ram2*44,ram1*44,ancho,alto,pen3,brushsalida));
         verificador=1;
     }}

     //algoritmo para la creación de las cajas
     posy=0;
     for (int i=0; i<13 ; i++ ) {
          int posx=0;

          for(int j=0; j<23;j++){
          if(mapabloques[i][j]==50){
              cajas.push_back(scene->addRect(posx,posy,ancho,alto,pen2,brushcajas));
              posx+=44;
          }
          else posx+=44;
          }
           posy+=44;
      }

    //Creación de enemigos
     posy=0;
     for (int i=0; i<13 ; i++ ) {
          int posx=0;

          for(int j=0; j<23;j++){
          if(mapabloques[i][j]==51){
              enemigos.push_back(scene->addRect(posx,posy,ancho,alto,pen2,brushenemigo));
              posx+=44;
          }
          else posx+=44;
          }
           posy+=44;
      }





     ui->graphicsView->setScene(scene);

}

Papabom::~Papabom()
{
    delete ui;
}


//--------------------------------------------------------
// Movimiento de personaje y colision con cajas y bloques|
//--------------------------------------------------------
bool colision=false; //Para verificar colission
void Papabom::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_A:
        PerSal.front()->setPos(PerSal.front()->x()-44,PerSal.front()->y());
        for(auto i :bloques){
            colision=PerSal.front()->collidesWithItem(i);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x()+44,PerSal.front()->y());
            colision=false;
        }}
        for(auto c :cajas){
            colision=PerSal.front()->collidesWithItem(c);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x()+44,PerSal.front()->y());
            colision=false;
        }}
        break;

    case Qt::Key_D:
        PerSal.front()->setPos(PerSal.front()->x()+44,PerSal.front()->y());
        for(auto i :bloques){
            colision=PerSal.front()->collidesWithItem(i);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x()-44,PerSal.front()->y());
            colision=false;
        }}
        for(auto c :cajas){
            colision=PerSal.front()->collidesWithItem(c);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x()-44,PerSal.front()->y());
            colision=false;
        }}
        break;


    case Qt::Key_W:
        PerSal.front()->setPos(PerSal.front()->x(),PerSal.front()->y()-44);
        for(auto i :bloques){
            colision=PerSal.front()->collidesWithItem(i);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x(),PerSal.front()->y()+44);
            colision=false;
        }}
        for(auto c :cajas){
            colision=PerSal.front()->collidesWithItem(c);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x(),PerSal.front()->y()+44);
            colision=false;
        }}
        break;

    case Qt::Key_S:
        PerSal.front()->setPos(PerSal.front()->x(),PerSal.front()->y()+44);
        for(auto i :bloques){
            colision=PerSal.front()->collidesWithItem(i);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x(),PerSal.front()->y()-44);
            colision=false;
        }}
        for(auto c :cajas){
            colision=PerSal.front()->collidesWithItem(c);
        if (colision==true){
            PerSal.front()->setPos(PerSal.front()->x(),PerSal.front()->y()-44);
            colision=false;
        }}
        break;

    case Qt::Key_Space:
        QPen pen3(Qt::black, 0, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
        QBrush brushsalida(Qt::black);
        if(VeriBom==0){
        bomba= scene->addEllipse(PerSal.front()->x()+47,PerSal.front()->y()+47,35,35,pen3,brushsalida);
        timer= new QTimer(this);
        connect(timer,SIGNAL(timeout()),this, SLOT(eliminarBomba()) );
        timer->start(2000);
        VeriBom=1;}
        break;
    }
    ui->graphicsView->setSceneRect(PerSal.front()->x(),PerSal.front()->y(),44,44);
}

void Papabom::eliminarBomba()
{
    scene->removeItem(bomba);
    timer->stop();
    VeriBom=0;
}
// funcion para eliminar items


