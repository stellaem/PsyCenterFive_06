#ifndef PLACE_H
#define PLACE_H

#include <QObject>

class Place : public QObject
{
    Q_OBJECT
public:
    Place(int id, QObject *parent = nullptr);
    Place(QObject *parent = nullptr) : QObject(parent){};

    int getId() const;
    void setId(int newId);
    const QString &getName() const;
    void setName(const QString &newName);

signals:
    void idChanged();
    void nameChanged();

private:
    int id;
    QString name;
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
};


#endif // PLACE_H
