#include "place.h"

#include <QVariant>
#include <QSqlQuery>

Place::Place(int id, QObject *parent) : QObject(parent),
    id(id)
{
    QSqlQuery q = QSqlQuery();
    q.prepare("select name from place where id = :id");
    q.bindValue(":id", id);
    q.exec();
    q.first();
    name = q.value("name").toString();
}

int Place::getId() const
{
    return id;
}

void Place::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

const QString &Place::getName() const
{
    return name;
}

void Place::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}

