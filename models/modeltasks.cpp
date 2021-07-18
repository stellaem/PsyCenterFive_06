#include "modeltasks.h"

#include <QDate>
#include <QDebug>

ModelTasks::ModelTasks(QObject *parent)
    : QAbstractListModel(parent)
{
    findTaskInBase(QDate().currentDate());
}


int ModelTasks::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return listTask.size();

}

QVariant ModelTasks::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case Qt::DisplayRole: return listTask[index.row()];
    default: return QVariant();
    }

}

void ModelTasks::findTaskInBase(QDate date)
{
    listTask.clear();
    QSqlQuery query;
    query.prepare("select id, text from adm_task where DATE(datetime_plan) = :date");
    query.bindValue(":date", date);
    if (query.exec())
    {

        while (query.next())
        {

            listTask.append(query.value("text").toString());
        }
    }
    endResetModel(); // WARNING: ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ!
}
