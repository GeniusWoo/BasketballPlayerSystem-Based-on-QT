#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignupDialog(QWidget *parent = nullptr);
    ~SignupDialog();

    QString Name(); //返回球员姓名
    QString TName(); //返回球队名
    QDate CompeteDate();//返回比赛日期
    int ThreepointNum(); //返回三分球数
    int ReboundNum(); //返回篮板数
    int DunkNum(); //返回扣篮数
    int StealNum();//返回抢断数
    int Score();//返回得分
    QString tname; //球队名

private slots:
    void on_comboTeamname_currentIndexChanged(const QString &arg1);

private:
    Ui::SignupDialog *ui;
};

#endif // SIGNUPDIALOG_H
