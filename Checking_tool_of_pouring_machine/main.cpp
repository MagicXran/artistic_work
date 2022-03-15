#define CONSOLE 1
#define DEBUG 0

#include "mainwindow.h"
#include <QApplication>
#include <cmath>
#include "HellQt_Clion.h"

int main(int argc , char *argv[]) {

#if (CONSOLE == 1)
    setbuf(stdout , nullptr);
#endif

#if DEBUG == 0
    QApplication a(argc , argv);
    MainWindow w;
    w.show();
    return QApplication::exec();

#else
    test();

#endif
}
