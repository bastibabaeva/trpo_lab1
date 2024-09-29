#include "manager.h"

Manager::Manager()
{
    logger=new ConsoleLogger; // Создание экземпляра ConsoleLogger
    // Подключение сигналов к слотам
    connect(this, &Manager::existOfFileChanged, logger, &ConsoleLogger::printFileExistenceChange);
    connect(this, &Manager::sizeOfFileChanged, logger, &ConsoleLogger::printFileSizeChange);
}
Manager::~Manager()
{
    delete logger; // Освобождаем память после использования
}
void Manager::Monitoring() //метод, реализующий за характеристиками файлов(размер и существование)
{
    for(int i=0; i<file.size();i++) //бесконечный цикл для обновления состояния объекта
    {
        File file=files.at(i);// метод at() дял доступа к файлам (элементам вектора files)
        if(file.isChangedStatus()) //если в файле был изменен статус, то
        {
            file.Update(); //обновляем информацию о файле
            emit existOfFileChanged(file.path, file.status, file.size); //генерируем сигнал об изменении
        }
        else if(file.isChangedSize()) //если в файле был изменен размер, то
        {
            file.Update(); //обновляем информацию о файле
            emit sizeOfFileChanged(file.path, file.status, file.size); //генерируем сигнал об изменении
        }
    }
}

void Manager::AddFiles(QString path) //метод добавления файлов для слежения за ними в основной программе
{
    File file(path); //создаем объект file, которому передаем путь текущего файла
    files.push_back(file); //добавляем его в вектор file, с помощью метода push_back
}
