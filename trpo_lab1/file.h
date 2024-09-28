#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QFileINfo>

class File: public QFileInfo //класс File наследуется от класса QFileInfo, чтобы получать информацию о файле
{
    QString path; //путь файла
    int size;     // размер файла
    bool status; //существование файла
public:
    File(const QString& pathOfFile);//конструктор с параметром по умолчанию
    void Update();//обновление данных о файле

    bool isExist(); //проверка на существование файла
    bool isEmpty();//проверка на пустоту файла

    bool isChangedSize(); //проверка на изменение рамера файла
    bool isChangedStatus();//проверка на изменение существование файла
#endif // FILE_H
