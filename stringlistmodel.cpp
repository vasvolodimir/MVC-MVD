#include "stringlistmodel.h"


int StringListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_strings.count();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() >= m_strings.size())
        return QVariant();

    // for read-only model check only DisplayRole
    if(role == Qt::DisplayRole || role == Qt::EditRole)
        return m_strings.at(index.row());
    else
        return QVariant();
}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        m_strings.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

bool StringListModel::insertRow(int row, const QModelIndex &parent)
{
    if(row < 0 || row > m_strings.size()) return false;

    beginInsertRows(QModelIndex(), row, row);

    m_strings.insert(row, "");

    endInsertRows();

    return true;
}

bool StringListModel::removeRow(int row, const QModelIndex &parent)
{
    if(row < 0 || row > m_strings.size()) return false;

    beginRemoveRows(QModelIndex(), row, row);
    m_strings.removeAt(row);
    endRemoveRows();

    return true;
}


