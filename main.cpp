#include "password_window.h"
#include <QSplashScreen>
#include <QApplication>
#include <QPixmap>
#include <QHBoxLayout>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Pass_Window* win=new Pass_Window;
    QFont font("Times", 20, QFont::Bold);

    QSplashScreen* splash=new QSplashScreen;

    QLabel* lab1=new QLabel;
    lab1->setFont(font);
    lab1->setText("The First program of Nikiforov Denis");

QTimer* time=new QTimer;

    QHBoxLayout* h_lay=new QHBoxLayout;
    h_lay->addWidget(lab1);
    splash->setLayout(h_lay);
   splash->setPixmap(QPixmap("1.png"));
   splash->resize(400,300);

splash->show();
time->start(1000);
QTimer::singleShot(5000,splash,SLOT(close()));
QTimer::singleShot(5000,win,SLOT(show()));


   return app.exec();
}
