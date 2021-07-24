#ifndef ADMPROPERTY_H
#define ADMPROPERTY_H

#include <QObject>
#include <QSqlQueryModel>
#include <QVariant>
#include <QDate>
#include <QSqlQuery>
#include <QSqlTableModel>

#include "models/modeltasks.h"


class AdmProperty : public QObject
{
    Q_OBJECT
public:
    explicit AdmProperty(QObject *parent = nullptr);;

    Q_INVOKABLE QList<QVariant> getListVCellClass();
    void setListVCellClass(QDate date);

    Q_INVOKABLE QSqlQueryModel *getQueryModelPlace();
    void setQueryModelPlace();

    Q_INVOKABLE QVariant getModelTask();
    Q_INVOKABLE void setModelTask(QDate date);


    Q_INVOKABLE QDate &getDate();
    Q_INVOKABLE void setDate(QDate newDate);

    Q_INVOKABLE QString getStrDate();

signals:

    void dateChanged();

private:
    QList<QVariant> listVCellClass;
    QSqlQueryModel *queryModelPlace;
    ModelTasks *modelTask;
    QDate date;
};

#endif // ADMPROPERTY_H
