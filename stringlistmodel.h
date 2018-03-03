#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT

public:
        StringListModel(QStringList &lst, QObject *parent = 0)
            : m_strings(lst), QAbstractListModel(parent) {}

        // for read-only model
        int rowCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;

        // for read-write model
        Qt::ItemFlags flags(const QModelIndex &index) const;
        bool setData(const QModelIndex &index, const QVariant &value, int role);

        bool insertRow(int row, const QModelIndex &parent);
        bool removeRow(int row, const QModelIndex &parent);

private:
        QStringList m_strings;
};

#endif // STRINGLISTMODEL_H
