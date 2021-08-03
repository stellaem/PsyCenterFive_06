#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDate>
#include <QObject>

#include "objects/note.h"

class Administrator : public QObject
{
    Q_OBJECT
public:
    Administrator(QObject *parent = nullptr) : QObject(parent){};
    Administrator(int id, QObject *parent = nullptr);

    int getId() const;
    void setId(int newId);
    const QString &getLogin() const;
    void setLogin(const QString &newLogin);
    const QString &getPassword() const;
    void setPassword(const QString &newPassword);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QDate &getBirthday() const;
    void setBirthday(const QDate &newBirthday);

signals:
    void idChanged();
    void loginChanged();
    void passwordChanged();
    void nameChanged();
    void patronymicChanged();
    void surnameChanged();
    void birthdayChanged();

private:
    int id;
    QString login;
    QString password;
    QString name;
    QString patronymic;
    QString surname;
    QDate birthday;
    Note note;

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString login READ getLogin WRITE setLogin NOTIFY loginChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString patronymic READ getPatronymic WRITE setPatronymic NOTIFY patronymicChanged)
    Q_PROPERTY(QString surname READ getSurname WRITE setSurname NOTIFY surnameChanged)
    Q_PROPERTY(QDate birthday READ getBirthday WRITE setBirthday NOTIFY birthdayChanged)
};

#endif // ADMINISTRATOR_H
