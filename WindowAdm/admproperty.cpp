#include "admproperty.h"
#include "objects/cellclass.h"

#include <QSqlQuery>
#include <QDebug>

AdmProperty::AdmProperty(QObject *parent) : QObject(parent),
    modelPlace(new ModelPlace),
    modelTask(new ModelTasks),
    modelSpecialist(new ModelSpecialist),
    date (QDate().currentDate())
{
    reloadListVCellClass(date);
    setModelTask(date);
}

QList<QVariant> AdmProperty::getListVCellClass()
{
    return listVCellClass;
}


void AdmProperty::reloadListVCellClass(QDate date)
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

QVariant AdmProperty::getModelPlace()
{
    QVariant var = QVariant::fromValue(modelPlace);
    return var;
}

QVariant AdmProperty::getModelTask()
{
    QVariant var = QVariant::fromValue(modelTask);
    return var;
}

QVariant AdmProperty::getModelSpecialist()
{
    QVariant var = QVariant::fromValue(modelSpecialist);
    return var;
}

void AdmProperty::setModelTask(QDate date)
{
    modelTask->refresh(date);
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
    reloadListVCellClass(date);
    setModelTask(date);
    emit dateChanged();
}

QString AdmProperty::getStrDate()
{
    return date.toString("dddd dd.MM.yyyy");
}
