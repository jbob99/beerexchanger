#include "mainwindow.hpp"
#include <QApplication>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    srand( (unsigned) time( NULL) );
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	cout << "Closing up..." << endl;

    return a.exec();
}
