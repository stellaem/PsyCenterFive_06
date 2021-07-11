#ifndef REQUEST_H
#define REQUEST_H

#include <QDate>
#include <QObject>

class Request : public QObject
{
    Q_OBJECT
public:
    explicit Request(QObject *parent = nullptr);

    int getId() const;
    void setId(int newId);
    int getIdClient() const;
    void setIdClient(int newIdClient);
    const QString &getInternalCode() const;
    void setInternalCode(const QString &newInternalCode);
    const QString &getComplaint() const;
    void setComplaint(const QString &newComplaint);
    const QString &getGoal() const;
    void setGoal(const QString &newGoal);
    const QString &getNote() const;
    void setNote(const QString &newNote);
    bool getCompleted() const;
    void setCompleted(bool newCompleted);
    const QDate &getStart() const;
    void setStart(const QDate &newStart);
    const QDate &getEnd() const;
    void setEnd(const QDate &newEnd);

signals:
    void idChanged();
    void idClientChanged();
    void internalCodeChanged();
    void complaintChanged();
    void goalChanged();
    void noteChanged();
    void completedChanged();
    void startChanged();
    void endChanged();

private:
    int id;
    int idClient;
    QString internalCode;
    QString complaint;
    QString goal;
    QString note;
    bool completed;
    QDate start;
    QDate end;
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int idClient READ getIdClient WRITE setIdClient NOTIFY idClientChanged)
    Q_PROPERTY(QString internalCode READ getInternalCode WRITE setInternalCode NOTIFY internalCodeChanged)
    Q_PROPERTY(QString complaint READ getComplaint WRITE setComplaint NOTIFY complaintChanged)
    Q_PROPERTY(QString goal READ getGoal WRITE setGoal NOTIFY goalChanged)
    Q_PROPERTY(QString note READ getNote WRITE setNote NOTIFY noteChanged)
    Q_PROPERTY(bool completed READ getCompleted WRITE setCompleted NOTIFY completedChanged)
    Q_PROPERTY(QDate start READ getStart WRITE setStart NOTIFY startChanged)
    Q_PROPERTY(QDate end READ getEnd WRITE setEnd NOTIFY endChanged)
};

#endif // REQUEST_H
