#ifndef QUALIFICATION_H
#define QUALIFICATION_H

#include <QDate>
#include <QObject>
#include <QPixmap>

class Qualification : public QObject
{
    Q_OBJECT
public:
    explicit Qualification(QObject *parent = nullptr);

    int getId() const;
    void setId(int newId);
    const QString &getName() const;
    void setName(const QString &newName);
    const QPixmap &getDocument() const;
    void setDocument(const QPixmap &newDocument);
    const QDate &getConfirm() const;
    void setConfirm(const QDate &newConfirm);

signals:
    void idChanged();
    void nameChanged();
    void documentChanged();
    void confirmChanged();

private:
    int id;
    QString name;
    QPixmap document;
    QDate confirm;
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QPixmap document READ getDocument WRITE setDocument NOTIFY documentChanged)
    Q_PROPERTY(QDate confirm READ getConfirm WRITE setConfirm NOTIFY confirmChanged)
};

#endif // QUALIFICATION_H
