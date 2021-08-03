#include "administrator.h"

#include <QSqlQuery>
#include <QVariant>

Administrator::Administrator(int id, QObject *parent) : QObject(parent),
    id(id)
{
    QSqlQuery q = QSqlQuery();
    q.prepare("select * from administrator where id = :id");
    q.bindValue(":id", id);
    q.exec();
    q.next();

    name = q.value("name").toString();
    patronymic = q.value("patronymic").toString();
    surname = q.value("surname").toString();
    birthday = q.value("birthday").toDate();
}

int Administrator::getId() const
{
    return id;
}

void Administrator::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

const QString &Administrator::getLogin() const
{
    return login;
}

void Administrator::setLogin(const QString &newLogin)
{
    if (login == newLogin)
        return;
    login = newLogin;
    emit loginChanged();
}

const QString &Administrator::getPassword() const
{
    return password;
}

void Administrator::setPassword(const QString &newPassword)
{
    if (password == newPassword)
        return;
    password = newPassword;
    emit passwordChanged();
}

const QString &Administrator::getName() const
{
    return name;
}

void Administrator::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}

const QString &Administrator::getPatronymic() const
{
    return patronymic;
}

void Administrator::setPatronymic(const QString &newPatronymic)
{
    if (patronymic == newPatronymic)
        return;
    patronymic = newPatronymic;
    emit patronymicChanged();
}

const QString &Administrator::getSurname() const
{
    return surname;
}

void Administrator::setSurname(const QString &newSurname)
{
    if (surname == newSurname)
        return;
    surname = newSurname;
    emit surnameChanged();
}

const QDate &Administrator::getBirthday() const
{
    return birthday;
}

void Administrator::setBirthday(const QDate &newBirthday)
{
    if (birthday == newBirthday)
        return;
    birthday = newBirthday;
    emit birthdayChanged();
}
