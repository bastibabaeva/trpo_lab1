#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include <QString>
#include <QObject>

class ConsoleLogger: public QObject
{
    Q_OBJECT
public:
    ConsoleLogger(){} //класс ConsoleLogger для вывода изменений в файле в консоль
public slots:
    void printFileExistenceChange(QString path, bool state, int size); //метод для печати изменения статуса файла
    void printFileSizeChange(QString path, bool state, int size); //метод для печати изменения размера файла

};
#endif // CONSOLELOGGER_H
