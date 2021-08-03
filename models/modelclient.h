#ifndef MODELCLIENT_H
#define MODELCLIENT_H

#include <QSqlQueryModel>
#include <QObject>

class ModelClient : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit ModelClient(QObject *parent = nullptr);
    enum SpecialistRoles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void refresh();
};

#endif // MODELCLIENT_H
