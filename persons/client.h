#ifndef CLIENT_H
#define CLIENT_H

#include <QDate>
#include <QObject>
#include <QPixmap>

#include "objects/recommendation.h"
#include "objects/request.h"
#include "objects/note.h"

class Client: public QObject
{
    Q_OBJECT
public:
    Client(int id, QObject *parent = nullptr);
    int getId() const;
    void setId(int newId);
    int getNumCard() const;
    void setNumCard(int newNumCard);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QDate &getBirthday() const;
    void setBirthday(const QDate &newBirthday);
    const QPixmap &getPhoto() const;
    void setPhoto(const QPixmap &newPhoto);
    const QDate &getFirstConsult() const;
    void setFirstConsult(const QDate &newFirstConsult);
    const QPixmap &getQuestionnaire() const;
    void setQuestionnaire(const QPixmap &newQuestionnaire);
    const QPixmap &getContract() const;
    void setContract(const QPixmap &newContract);
    const QList<QPixmap> &getListSurvey() const;
    void setListSurvey(const QList<QPixmap> &newListSurvey);

signals:
    void idChanged();
    void numCardChanged();
    void nameChanged();
    void patronymicChanged();
    void surnameChanged();
    void birthdayChanged();
    void photoChanged();
    void firstConsultChanged();
    void questionnaireChanged();
    void contractChanged();
    void listSurveyChanged();

private:
    int id;
    int numCard;

    QString name;
    QString patronymic;
    QString surname;
    QDate birthday;
    QPixmap photo;

    QDate firstConsult;
    Note note;

    QPixmap questionnaire;
    QPixmap contract;

    QList <QPixmap> listSurvey;
    QList <Request> listRequest;
    QList <Recommendation> listRecommendation;
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int numCard READ getNumCard WRITE setNumCard NOTIFY numCardChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString patronymic READ getPatronymic WRITE setPatronymic NOTIFY patronymicChanged)
    Q_PROPERTY(QString surname READ getSurname WRITE setSurname NOTIFY surnameChanged)
    Q_PROPERTY(QDate birthday READ getBirthday WRITE setBirthday NOTIFY birthdayChanged)
    Q_PROPERTY(QPixmap photo READ getPhoto WRITE setPhoto NOTIFY photoChanged)
    Q_PROPERTY(QDate firstConsult READ getFirstConsult WRITE setFirstConsult NOTIFY firstConsultChanged)
    Q_PROPERTY(QPixmap questionnaire READ getQuestionnaire WRITE setQuestionnaire NOTIFY questionnaireChanged)
    Q_PROPERTY(QPixmap contract READ getContract WRITE setContract NOTIFY contractChanged)
    Q_PROPERTY(QList<QPixmap> listSurvey READ getListSurvey WRITE setListSurvey NOTIFY listSurveyChanged)
};

#endif // CLIENT_H
