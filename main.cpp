#include "mainwindow.hpp"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    srand( (unsigned) time( NULL) );
    QApplication a(argc, argv);
	std::cout << "Running ..." << std::endl;
    MainWindow w;
    w.show();

    return a.exec();
}
