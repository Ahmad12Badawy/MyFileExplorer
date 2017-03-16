#include "dialog.h"
#include <QApplication>
#include <QtCore>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;
    d.setWindowTitle("MyFileExplorer");
    d.show();

    return a.exec();
}
