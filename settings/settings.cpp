#include "settings.h"
#include <QDebug>


Settings::Settings(QObject *parent)
{
    for( QTime i = startCenter; i < endCenter; i = i.addSecs(secInSegment()))
    {
        QVariant qvar = QVariant::fromValue(i);
        listTime.append(qvar);
    }

    setListHours();
 }

QList<QString> &Settings::getListHours()
{
    return listHours;
}

QList<QString> &Settings::getListMinuts()
{

    return listMinuts;
}

void Settings::setListMinuts()
{

}

void Settings::setListHours()
{
    listHours.clear();
    QTime start = startCenter;
    QTime end = endCenter;

    while (start < end) {
        listHours.append(start.toString("hh"));
        start = start.addSecs(60*60);
    }
    qDebug() << listHours;
}


