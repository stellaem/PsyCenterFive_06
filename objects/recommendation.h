#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include <QDate>
#include <QObject>

class Recommendation : public QObject
{
    Q_OBJECT
public:
    explicit Recommendation(QObject *parent = nullptr);

    int getId() const;
    void setId(int newId);
    int getIdClient() const;
    void setIdClient(int newIdClient);
    int getType() const;
    void setType(int newType);
    const QString &getText() const;
    void setText(const QString &newText);
    const QDate &getDate() const;
    void setDate(const QDate &newDate);
    bool getIsActual() const;
    void setIsActual(bool newIsActual);

signals:
    void idChanged();
    void idClientChanged();
    void typeChanged();
    void textChanged();
    void dateChanged();
    void isActualChanged();

private:
    int id;
    int idClient;
    int type;
    QString text;
    QDate date;
    bool isActual;

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int idClient READ getIdClient WRITE setIdClient NOTIFY idClientChanged)
    Q_PROPERTY(int type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QDate date READ getDate WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(bool isActual READ getIsActual WRITE setIsActual NOTIFY isActualChanged)
};

#endif // RECOMMENDATION_H
