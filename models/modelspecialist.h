#ifndef MODELSPECIALIST_H
#define MODELSPECIALIST_H

#include <QSqlQueryModel>
#include <QObject>

class ModelSpecialist : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit ModelSpecialist(QObject *parent = nullptr);
    enum SpecialistRoles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void refresh();
};

#endif // MODELSPECIALIST_H
