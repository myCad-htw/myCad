#include "PaintProgramm.h"
#include <QtWidgets/QApplication>
#include"FenPrincipale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenPrincipale mainWindow;
    mainWindow.setWindowTitle("myCad");
    mainWindow.show();
    return a.exec();
}
