#include "client.h"
#include <QDebug>
#include <QSqlQuery>

Client::Client(int id, QObject *parent): QObject(parent),
    id(id)
{
    QSqlQuery q = QSqlQuery();
    q.prepare("select * from client where id = :id");
    q.bindValue(":id", id);
    q.exec();
    q.next();

    numCard = q.value("num_card").toInt();
    name = q.value("name").toString();
    patronymic = q.value("patronymic").toString();
    surname = q.value("surname").toString();
    birthday = q.value("birthday").toDate();
    firstConsult =  q.value("first_consult").toDate();
}

int Client::getId() const
{
    return id;
}

void Client::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

int Client::getNumCard() const
{
    return numCard;
}

void Client::setNumCard(int newNumCard)
{
    if (numCard == newNumCard)
        return;
    numCard = newNumCard;
    emit numCardChanged();
}

const QString &Client::getName() const
{
    return name;
}

void Client::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}

const QString &Client::getPatronymic() const
{
    return patronymic;
}

void Client::setPatronymic(const QString &newPatronymic)
{
    if (patronymic == newPatronymic)
        return;
    patronymic = newPatronymic;
    emit patronymicChanged();
}

const QString &Client::getSurname() const
{
    return surname;
}

void Client::setSurname(const QString &newSurname)
{
    if (surname == newSurname)
        return;
    surname = newSurname;
    emit surnameChanged();
}

const QDate &Client::getBirthday() const
{
    return birthday;
}

void Client::setBirthday(const QDate &newBirthday)
{
    if (birthday == newBirthday)
        return;
    birthday = newBirthday;
    emit birthdayChanged();
}

const QPixmap &Client::getPhoto() const
{
    return photo;
}

void Client::setPhoto(const QPixmap &newPhoto)
{
    if (&photo == &newPhoto)
        return;
    photo = newPhoto;
    emit photoChanged();
}

const QDate &Client::getFirstConsult() const
{
    return firstConsult;
}

void Client::setFirstConsult(const QDate &newFirstConsult)
{
    if (firstConsult == newFirstConsult)
        return;
    firstConsult = newFirstConsult;
    emit firstConsultChanged();
}

const QPixmap &Client::getQuestionnaire() const
{
    return questionnaire;
}

void Client::setQuestionnaire(const QPixmap &newQuestionnaire)
{
    if (&questionnaire == &newQuestionnaire)
        return;
    questionnaire = newQuestionnaire;
    emit questionnaireChanged();
}

const QPixmap &Client::getContract() const
{
    return contract;
}

void Client::setContract(const QPixmap &newContract)
{
    if (&contract == &newContract)
        return;
    contract = newContract;
    emit contractChanged();
}

const QList<QPixmap> &Client::getListSurvey() const
{
    return listSurvey;
}

void Client::setListSurvey(const QList<QPixmap> &newListSurvey)
{
    // TODO придумать как наиболее эфективно менять лист с пиксмэпом
    listSurvey = newListSurvey;
    emit listSurveyChanged();
}
