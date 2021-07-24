#ifndef SETTINGS_H
#define SETTINGS_H
#include <QTime>
#include <QObject>
#include <QString>
#include <QVariant>

class Settings: public QObject
{
    Q_OBJECT
public:
    Settings( QObject *parent = nullptr );

    Q_INVOKABLE QTime getStartCenter() const { return startCenter; }
    Q_INVOKABLE QTime getEndCenter() const { return endCenter; }
    Q_INVOKABLE int minInSegment()const { return 60 / cellPerHour; } // количество минут в сегменте
    Q_INVOKABLE int secInSegment()const { return (60 / cellPerHour) * 60; } // количество секунд в сегменте
    Q_INVOKABLE QList<QVariant> getListTime() const { return listTime; }
    Q_INVOKABLE int countCellPerHour() const { return cellPerHour; }
    Q_INVOKABLE int countSegments() { return (endCenter.hour() - startCenter.hour()) * cellPerHour; } // количество ячеек в дне
    Q_INVOKABLE int countHours() {return endCenter.hour() - startCenter.hour(); }
    Q_INVOKABLE  QList<QString> &getListHours();
    Q_INVOKABLE  QList<QString> &getListMinuts();

    void setListMinuts();
    void setListHours();

    virtual ~Settings(){};







private:
    QTime startCenter = QTime(8, 00);
    QTime endCenter = QTime(20, 00);
    int cellPerHour = 12; // количество ячеек в часе
    QList<QVariant> listTime;
    QList<QString> listHours;
    QList<QString> listMinuts;

};


#endif // SETTINGS_H
