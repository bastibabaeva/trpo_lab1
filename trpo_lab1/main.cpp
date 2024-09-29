#include <QCoreApplication>
#include "manager.h"
#include <QTimer>
#include <QObject>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    Manager manager;

    manager.AddFiles("C:\\lab1.txt");
    manager.AddFiles("C:\\lab2.txt");

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, manager, &Manager::Monitoring);
    timer.start(100);
    return a.exec();
}
