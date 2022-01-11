#ifndef SELECTITEM_H
#define SELECTITEM_H

#include <QDialog>

namespace Ui {
class SelectItem;
}

class SelectItem : public QDialog
{
    Q_OBJECT

public:
    explicit SelectItem(QWidget *parent = nullptr);
    ~SelectItem();
    int m_iSelectIndex; //当前选项

private slots:
    void on_comboSelectItem_currentIndexChanged(const QString &arg1);

private:
    Ui::SelectItem *ui;
};

#endif // SELECTITEM_H
