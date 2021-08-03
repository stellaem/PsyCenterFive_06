#ifndef NOTE_H
#define NOTE_H

#include <QObject>

class Note : public QObject
{
    Q_OBJECT
public:
    Note(QObject *parent = nullptr) : QObject(parent) {}
    Note(int id, QObject *parent = nullptr);

    int getId() const;
    void setId(int newId);
    const QString &getText() const;
    void setText(const QString &newText);

signals:
    void idChanged();
    void textChanged();

private:
    int id;
    QString text;

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
};
#endif // NOTE_H
