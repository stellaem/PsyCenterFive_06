#include "settings.h"
#include <QDebug>


Settings::Settings(QObject *parent)
{
    for( QTime i = startCenter; i < endCenter; i = i.addSecs(secInSegment()))
    {
        QVariant qvar = QVariant::fromValue(i);
        listTime.append(qvar);
    }

    refreshListHours();
    refreshListMinuts();
 }

QStringList Settings::getListHours()
{
    return listHours;
}

QStringList Settings::getListMinuts()
{

    return listMinuts;
}

void Settings::refreshListMinuts()
{
    listMinuts.clear();
    int start = 0;

    while (start < 60)
    {
        listMinuts.append(QString::number(start));
        start = start+minInSegment();
    }

}

void Settings::refreshListHours()
{
    listHours.clear();
    QTime start = startCenter;
    QTime end = endCenter;

    while (start < end) {
        listHours.append(start.toString("hh"));
        start = start.addSecs(60*60);
    }
}


