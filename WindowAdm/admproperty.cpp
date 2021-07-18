#include "admproperty.h"
#include "objects/cellclass.h"

#include <QSqlQuery>
#include <QDebug>

AdmProperty::AdmProperty(QObject *parent) : QObject(parent),
    queryModelPlace(new QSqlQueryModel),
    modelTask(new ModelTasks),
    date (QDate().currentDate())
{
    setQueryModelPlace();
    setListVCellClass(date);
    setModelTask(date);
}

QList<QVariant> AdmProperty::getListVCellClass()
{
    return listVCellClass;
}

QSqlQueryModel *AdmProperty::getQueryModelPlace()
{
    return queryModelPlace;
}

void AdmProperty::setListVCellClass(QDate date)
{
    listVCellClass.clear();
    QSqlQuery *q = new QSqlQuery();
    q->prepare("select id from class where DATE(date_and_time) = :date");
    q->bindValue(":date", date.toString("yyyy-MM-dd"));
    q->exec();
    if(q->next())
    {
        CellClass *c = new CellClass(q->value("id").toInt());
        QVariant var = QVariant::fromValue(c);
        listVCellClass.append(var);
    }
}

void AdmProperty::setQueryModelPlace()
{
    queryModelPlace->setQuery("select id, name from place");
}

QVariant AdmProperty::getModelTask()
{
    QVariant var = QVariant::fromValue(modelTask);
    return var;
}

void AdmProperty::setModelTask(QDate date)
{
    modelTask->findTaskInBase(date);
}

QDate &AdmProperty::getDate()
{
    return date;
}

void AdmProperty::setDate(QDate newDate)
{
    if (date == newDate)
        return;
    date = newDate;
    setListVCellClass(date);
    setModelTask(date);
    emit dateChanged();
}
