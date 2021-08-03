#ifndef CELLCLASS_H
#define CELLCLASS_H

#include <QObject>
#include <QDateTime>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

#include "objects/place.h"
#include "persons/specialist.h"
#include "persons/client.h"
#include "objects/place.h"


class CellClass : public QObject
{
    Q_OBJECT
public:
    CellClass(int id, QObject *parent = nullptr);
    CellClass(QObject *parent = nullptr) : QObject(parent) {};
    ~CellClass(){};
    int getId() const;
    void setId(int newId);
    const QDateTime &getDateAndTimeStart() const;
    void setDateAndTimeStart(const QDateTime &newDateAndTimeStart);
    const QTime &getTimeStart() const;
    void setTimeStart(const QTime &newTimeStart);
    int getDuration() const;
    void setDuration(int newDuration);
    Place *getPlace() const;
    void setPlace(Place *newPlace);
    Specialist *getSpecialist() const;
    void setSpecialist(Specialist *newSpecialist);
    const QList<QVariant> &getListVClient() const;
    void setListVClient(const QList<QVariant> &newListVClient);
    Q_INVOKABLE void recordCell();

signals:
    void idChanged();
    void dateAndTimeStartChanged();
    void timeStartChanged();
    void durationChanged();
    void placeChanged();
    void specialistChanged();
    void listVClientChanged();

private:
    int id;
    QDateTime dateAndTimeStart;
    QTime timeStart;
    int duration;

    Place *place;
    Specialist *specialist;
    QList<QVariant> listVClient;

    void searchFromClassClient();
    void addToListVClient(int id_client);

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QDateTime dateAndTimeStart READ getDateAndTimeStart WRITE setDateAndTimeStart NOTIFY dateAndTimeStartChanged)
    Q_PROPERTY(QTime timeStart READ getTimeStart WRITE setTimeStart NOTIFY timeStartChanged)
    Q_PROPERTY(int duration READ getDuration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(Place * place READ getPlace WRITE setPlace NOTIFY placeChanged)
    Q_PROPERTY(Specialist * specialist READ getSpecialist WRITE setSpecialist NOTIFY specialistChanged)
    Q_PROPERTY(QList<QVariant> listVClient READ getListVClient WRITE setListVClient NOTIFY listVClientChanged)
};

#endif // CELLCLASS_H
