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
    QSplashScreen* splash=new QSplashScreen;
    QLabel* lab1=new QLabel("FIRST POJECT OF NIKIFOROV DENIS");
QTimer* time=new QTimer;
    QHBoxLayout* h_lay=new QHBoxLayout;
    h_lay->addWidget(lab1);
    splash->setLayout(h_lay);
   splash->setPixmap(QPixmap("1.png"));
   splash->resize(400,300);

time->start(0);
    splash->show();


    if(time->)






   win->show();



    return app.exec();
}
