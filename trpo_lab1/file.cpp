#include "file.h"

File::File(const QString& name):nameOfFile(name)//определение конструктора
{
    QFileInfo fileInfo(name);//создание объекта типа QFile, в который передается его имя или значение по умолчанию
    size=fileInfo.size();//вызов метода size() для получения информации о размере файла
    status=fileInfo.exists();//вызов метода exists для получения информации о существовании файла
}
bool File::isExist()//проверка на существование файла
{
    QFileInfo file(nameOfFile);
    return file.exists(); //true - если файл существует
}
bool File::isEmpty() //проверка на пустоту файла
{
    QFileInfo file(nameOfFile);
    if(file.exists()==true && file.size()==0)
        return true;
    else return false;
}
bool File::isChangedStatus()//проверка на изменение существования
{
    QFile file(nameOfFile);
    if(file.exists()!=status)
        return true;
    else return false;
}
bool File::isChangedSize() //проверка на изменение размера файла
{
    QFile file(nameOfFile);
    if(file.size()!=size)
        return true;
    else return false;
}
bool File::isChanged() //проверка на изменение существования или размера файла
{
    QFile file(nameOfFile);
    if(file.exists()!=status || file.size()!=size)
        return true;
    else return false;
}
