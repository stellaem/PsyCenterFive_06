#ifndef MODELTASKS_H
#define MODELTASKS_H

#include <QAbstractListModel>
#include <QSqlQuery>

class ModelTasks : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ModelTasks(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void findTaskInBase(QDate date);

private:

    QList<QString> listTask;

};

#endif // MODELTASKS_H
