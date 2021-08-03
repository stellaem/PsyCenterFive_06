#include "specialist.h"

#include <QSqlQuery>
#include <QVariant>

Specialist::Specialist(int id, QObject *parent) : QObject(parent),
    id(id)
{
    QSqlQuery q = QSqlQuery();
    q.prepare("select * from specialist where id = :id");
    q.bindValue(":id", id);
    q.exec();
    q.next();

    login = q.value("login").toString();
    name = q.value("name").toString();
    patronymic = q.value("patronymic").toString();
    surname = q.value("surname").toString();
    birthday = q.value("birthday").toDate();
}

Specialist::Specialist(QString login, QObject *parent): QObject(parent),
    login(login)
{
    QSqlQuery q = QSqlQuery();
    q.prepare("select * from specialist where login = :login");
    q.bindValue(":login", login);
    q.exec();
    q.next();

    id = q.value("id").toInt();
    name = q.value("name").toString();
    patronymic = q.value("patronymic").toString();
    surname = q.value("surname").toString();
    birthday = q.value("birthday").toDate();

}

int Specialist::getId() const
{
    return id;
}

void Specialist::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

const QString &Specialist::getLogin() const
{
    return login;
}

void Specialist::setLogin(const QString &newLogin)
{
    if (login == newLogin)
        return;
    login = newLogin;
    emit loginChanged();
}

const QString &Specialist::getPassword() const
{
    return password;
}

void Specialist::setPassword(const QString &newPassword)
{
    if (password == newPassword)
        return;
    password = newPassword;
    emit passwordChanged();
}

const QString &Specialist::getName() const
{
    return name;
}

void Specialist::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}

const QString &Specialist::getPatronymic() const
{
    return patronymic;
}

void Specialist::setPatronymic(const QString &newPatronymic)
{
    if (patronymic == newPatronymic)
        return;
    patronymic = newPatronymic;
    emit patronymicChanged();
}

const QString &Specialist::getSurname() const
{
    return surname;
}

void Specialist::setSurname(const QString &newSurname)
{
    if (surname == newSurname)
        return;
    surname = newSurname;
    emit surnameChanged();
}

const QDate &Specialist::getBirthday() const
{
    return birthday;
}

void Specialist::setBirthday(const QDate &newBirthday)
{
    if (birthday == newBirthday)
        return;
    birthday = newBirthday;
    emit birthdayChanged();
}

const QPixmap &Specialist::getPhoto() const
{
    return photo;
}

void Specialist::setPhoto(const QPixmap &newPhoto)
{
    if (&photo == &newPhoto)
        return;
    photo = newPhoto;
    emit photoChanged();
}



