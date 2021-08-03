#include "modelspecialist.h"

ModelSpecialist::ModelSpecialist(QObject *parent)
    : QSqlQueryModel(parent)
{
    refresh();
}

QVariant ModelSpecialist::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> ModelSpecialist::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    return roles;
}
void ModelSpecialist::refresh()
{
    this->setQuery(QString("select id, name from staff where isSpec = true"));
}
