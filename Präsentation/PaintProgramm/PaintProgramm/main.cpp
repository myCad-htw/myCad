#include "PaintProgramm.h"
#include <QtWidgets/QApplication>
#include "mMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mMainWindow Window;
    Window.setWindowTitle("myCad");
    Window.show();
    return a.exec();
}
