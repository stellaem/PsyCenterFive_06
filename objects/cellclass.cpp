#include "cellclass.h"

#include <QSqlRecord>



CellClass::CellClass(int id, QObject *parent) : QObject(parent),
    id(id)
{
    QSqlQuery *q =  new QSqlQuery();
    q->prepare("select duration, type, date_and_time from class where id = :id");
    q->bindValue(":id", id);
    q->exec();
    q->first();

    duration = q->value("duration").toInt();
    dateAndTimeStart = q->value("date_and_time").toDateTime();
    timeStart = dateAndTimeStart.time();

    place = new Place(id);
    specialist = new Specialist(id);

    searchFromClassClient();
}

int CellClass::getId() const
{
    return id;
}

void CellClass::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

const QDateTime &CellClass::getDateAndTimeStart() const
{
    return dateAndTimeStart;
}

void CellClass::setDateAndTimeStart(const QDateTime &newDateAndTimeStart)
{
    if (dateAndTimeStart == newDateAndTimeStart)
        return;
    dateAndTimeStart = newDateAndTimeStart;
    emit dateAndTimeStartChanged();
}

const QTime &CellClass::getTimeStart() const
{
    return timeStart;
}

void CellClass::setTimeStart(const QTime &newTimeStart)
{
    if (timeStart == newTimeStart)
        return;
    timeStart = newTimeStart;
    emit timeStartChanged();
}

int CellClass::getDuration() const
{
    return duration;
}

void CellClass::setDuration(int newDuration)
{
    if (duration == newDuration)
        return;
    duration = newDuration;
    emit durationChanged();
}

Place *CellClass::getPlace() const
{
    return place;
}

void CellClass::setPlace(Place *newPlace)
{
    if (place == newPlace)
        return;
    place = newPlace;
    emit placeChanged();
}

Specialist *CellClass::getSpecialist() const
{
    return specialist;
}

void CellClass::setSpecialist(Specialist *newSpecialist)
{
    if (specialist == newSpecialist)
        return;
    specialist = newSpecialist;
    emit specialistChanged();
}

const QList<QVariant> &CellClass::getListVClient() const
{
    return listVClient;
}

void CellClass::setListVClient(const QList<QVariant> &newListVClient)
{
    if (listVClient == newListVClient)
        return;
    listVClient = newListVClient;
    emit listVClientChanged();
}

void CellClass::recordCell()
{
    QSqlQuery *q = new QSqlQuery();
    q->prepare("insert into class (duration)  values (60)");
    q->exec();

}

void CellClass::searchFromClassClient()
{
    QSqlQuery *q =  new QSqlQuery();
    q->prepare("select id_client from class_client where id_class = :id_class");
    q->bindValue(":id_class", id);
    q->exec();
    while(q->next())
    {
        addToListVClient(q->value("id_client").toInt());
    }
}

void CellClass::addToListVClient(int id_client)
{
    Client *c = new Client(id_client);
    QVariant var = QVariant::fromValue(c);
    listVClient.append(var);
}

