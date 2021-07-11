#include "recommendation.h"

Recommendation::Recommendation(QObject *parent) : QObject(parent)
{

}

int Recommendation::getId() const
{
    return id;
}

void Recommendation::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

int Recommendation::getIdClient() const
{
    return idClient;
}

void Recommendation::setIdClient(int newIdClient)
{
    if (idClient == newIdClient)
        return;
    idClient = newIdClient;
    emit idClientChanged();
}

int Recommendation::getType() const
{
    return type;
}

void Recommendation::setType(int newType)
{
    if (type == newType)
        return;
    type = newType;
    emit typeChanged();
}

const QString &Recommendation::getText() const
{
    return text;
}

void Recommendation::setText(const QString &newText)
{
    if (text == newText)
        return;
    text = newText;
    emit textChanged();
}

const QDate &Recommendation::getDate() const
{
    return date;
}

void Recommendation::setDate(const QDate &newDate)
{
    if (date == newDate)
        return;
    date = newDate;
    emit dateChanged();
}

bool Recommendation::getIsActual() const
{
    return isActual;
}

void Recommendation::setIsActual(bool newIsActual)
{
    if (isActual == newIsActual)
        return;
    isActual = newIsActual;
    emit isActualChanged();
}
