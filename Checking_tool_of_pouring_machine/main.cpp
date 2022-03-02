#define CONSOLE 1
#define DEBUG 0

#include "mainwindow.h"
#include <QApplication>
#include "HellQt_Clion.h"

#if DEBUG == 1


void test() {
    using namespace std;
    std::cout << "test" << std::endl;


    std::shared_ptr<common_tools::ParseJson> parser_ = std::make_shared<common_tools::ParseJson>();
    if (parser_->Open(JSON_PATH)) {
        for (const auto &var : parser_->getJsonValuesFromArray("pressure")) {
//            std::cout << var << std::endl;
        }

        std::cout << parser_->getRoot(0)["pressure"];

        common_tools::ParseJson par;
        if (par.Open(JSON_PATH)) {
//            std::cout <<  << std::endl;;
//            std::cout << par.getModel()[0]["name"];
//            std::cout << par[0]["pressure"];
        }
    }


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
