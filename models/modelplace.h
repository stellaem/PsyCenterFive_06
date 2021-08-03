#ifndef MODELPLACE_H
#define MODELPLACE_H

#include <QAbstractItemModel>
#include <QDebug>
#include <QSqlQueryModel>

class ModelPlace : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit ModelPlace(QObject *parent = nullptr);
    enum PlaceRoles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void refresh();
private:

};

#endif // MODELPLACE_H
