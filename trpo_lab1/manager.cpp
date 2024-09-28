#include "manager.h"
#include <chrono>
#include <thread>
using namespace std;

void Manager::Monitoring(int i) //метод, реализующий за характеристиками файлов(размер и существование)
{
    while(true) //бесконечный цикл для обновления состояния объекта
    {
        File file=files.at(i);// метод at() дял доступа к файлам (элементам вектора files)
        if(file.isChangedStatus()) //если в файле был изменен статус, то
        {
            file.Update(); //обновляем информацию о файле
            emit existOfFileChanged(); //генерируем сигнал об изменении
        }
        else if(file.isChangedSize()) //если в файле был изменен размер, то
        {
            file.Update(); //обновляем информацию о файле
            emit sizeOfFileChanged(); //генерируем сигнал об изменении
        }
        this_thread::sleep_for(chrono::milliseconds(100)); //функция, которая приостанавливает выполнение цикла на 100 миллисекунд
    }
}

void Manager::AddFiles(QString path) //метод добавления файлов для слежения за ними в основной программе
{
    File file(path); //создаем объект file, которому передаем путь текущего файла
    files.push_back(file); //добавляем его в вектор file, с помощью метода push_back
}
