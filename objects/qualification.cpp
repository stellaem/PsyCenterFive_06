#include "qualification.h"

Qualification::Qualification(QObject *parent) : QObject(parent)
{

}

int Qualification::getId() const
{
    return id;
}

void Qualification::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

const QString &Qualification::getName() const
{
    return name;
}

void Qualification::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}

const QPixmap &Qualification::getDocument() const
{
    return document;
}

void Qualification::setDocument(const QPixmap &newDocument)
{
    if (&document == &newDocument)
        return;
    document = newDocument;
    emit documentChanged();
}

const QDate &Qualification::getConfirm() const
{
    return confirm;
}

void Qualification::setConfirm(const QDate &newConfirm)
{
    if (confirm == newConfirm)
        return;
    confirm = newConfirm;
    emit confirmChanged();
}
