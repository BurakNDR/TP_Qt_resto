#include "resto.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    resto w;
    w.show();
    return a.exec();
}
