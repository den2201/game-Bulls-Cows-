#include "password_window.h"
#include <QSplashScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Pass_Window* win=new Pass_Window;
    QSplashScreen* splash=new QSplashScreen;

   splash->setPixmap(QPixmap("cow.png"));


    splash->show();






   win->show();




    return app.exec();
}
