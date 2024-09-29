#include "consoleLogger.h"
#include <QString>
#include <QDebug>

void ConsoleLogger::printFileExistenceChange(QString path, bool state, int size)
{
    if(state==true)
    {
        qDebug()<<"File "<<path<<"is exist and his size: "<<size<<"\n";
    }
    else
    {
        qDebug()<<"File "<<path<<"is not exist"<<"\n";
    }
}
void ConsoleLogger::printFileSizeChange(QString path, bool state, int size)
{
    qDebug()<<"File "<<path<<" has been changed and his size "<<size<<"\n";
}
