#include "delegate.h"

Delegate::Delegate(QItemDelegate *parent) : QItemDelegate(parent)
{

}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *line = new QLineEdit(parent);
    line->setFont(QFont("Ubuntu", 10, QFont::Bold));
    line->setStyleSheet("background: rgb(30, 120, 60); color: white;");

    return line;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*> (editor);
    line->setText(index.model()->data(index, Qt::DisplayRole).toString());
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*> (editor);
    model->setData(index, line->text(), Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

