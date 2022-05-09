#include "createcanvasdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createCanvasDialog w;
    w.show();
    return a.exec();
}
