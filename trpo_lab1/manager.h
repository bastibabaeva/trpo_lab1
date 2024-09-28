#ifndef MANAGER_H
#define MANAGER_H
#include <QObject>
#include <QVector>
#include "file.h"

class Manager:public QObject //класс Manager, наследуемый от QОbject для реализации наблюдения за файлами
{
    Q_OBJECT//макрос обеспечивающий сигнально-слотную связь
public:
    static Manager& Instance()//статический метод для создания объекта-одиночки
    {
        static Manager s;
        return s;
    }
    void Monitoring(int i); //метод, реализующий слежение за характеристиками файла (его размер и существование)
    void AddFiles(QString&path);//метод для добавления файлов (так как вектор files приватный) для слежения за ними в основной программе
private:
    Manager() {}//приватный конструктор по умолчанию

    //необходимо также запретить копирование
    Manager(Manager const&);//реализация не нужна
    Manager& operator=(Manager const&);//и тут реализация не нужна

    QVector<File> files;//вектор files для хранения информации о файлах
signals:
    void sizeOfFileChanged(); //генерируется, когда происходит изменение размера в файле
    void existOfFileChanged(); //генерируется, когда происходит изменение о существовании в файле

}
#endif // MANAGER_H
