#define CONSOLE 1
#define DEBUG 0

#include "mainwindow.h"
#include <QApplication>
#include <cmath>
#include "HellQt_Clion.h"

#if DEBUG == 1

void test() {

}

#endif


int main(int argc , char *argv[]) {

#if (CONSOLE == 1)
    setbuf(stdout , nullptr);
#endif

#if DEBUG == 0
    QApplication a(argc , argv);
    MainWindow w;
    w.show();
    return a.exec();

#else
    test();
#endif
}
