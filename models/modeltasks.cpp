#include "modeltasks.h"
#include <QString>
#include <QSqlQuery>

ModelTasks::ModelTasks(QObject *parent)
    : QSqlQueryModel(parent)
{
    refresh(QDate().currentDate());
}

QVariant ModelTasks::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if(role < Qt::UserRole)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

QHash<int, QByteArray> ModelTasks::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[TextRole] = "txt";
    return roles;
}

void ModelTasks::refresh(QDate date)
{
    this->setQuery(QString("select id, text from adm_task where DATE(datetime_plan) = '%1'").arg(date.toString("yyyy-MM-dd")));
//    endResetModel(); // WARNING: ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ! ЗАПОМНИТЬ!
}
