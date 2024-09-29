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

