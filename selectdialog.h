#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(QWidget *parent = nullptr);
    ~SelectDialog();

    QString m_teamname;  //当前选中球队名
    int m_iSelectIndex; //当前选中选项


private slots:
    void on_comboSpecialItem_currentIndexChanged(const QString &arg1);


private:
    Ui::SelectDialog *ui;

};

#endif // SELECTDIALOG_H
