#include "password_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Pass_Window* win=new Pass_Window;




    win->show();




    return app.exec();
}
