#include "file.h"

File::File(const QString& pathOfFile):path(pathOfFile)//определение конструктора
{
    QFileInfo file(pathOfFile);//создание объекта типа QFile, в который передается его имя или значение по умолчанию
    size=file.size();//вызов метода size() для получения информации о размере файла
    status=file.exists();//вызов метода exists для получения информации о существовании файла
}
void File::Update() //обновление данных о файле при изменении его характеристик
{
    QFileInfo file(path);//создаем объект file, которому указываем текущий путь
    status=file.exists();//устанавливаем текущий статус для этого объекта
    size=file.size();//устанавливаем текущий размер для этого объекта
}
bool File::isExist()//проверка на существование файла
{
    QFileInfo file(path);
    return file.exists(); //true - если файл существует
}
bool File::isEmpty() //проверка на пустоту файла
{
    QFileInfo file(path);
    if(file.exists()==true && file.size()==0)
        return true; //если файл существует и его размер = 0, то true
    else return false;
}
bool File::isChangedStatus()//проверка на изменение существования
{
    QFile file(path);
    if(file.exists()!=status)
        return true;
    else return false;
}
bool File::isChangedSize() //проверка на изменение размера файла
{
    QFile file(path);
    if(file.size()!=size)
        return true;
    else return false;
}

