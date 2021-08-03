#ifndef MODELTASKS_H
#define MODELTASKS_H

#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>


class ModelTasks : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit ModelTasks(QObject *parent = nullptr);
    enum PlaceRoles {
        IdRole = Qt::UserRole + 1,
        TextRole
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void refresh(QDate date);
};

#endif // MODELTASKS_H
