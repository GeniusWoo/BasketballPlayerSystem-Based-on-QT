#include "signupdialog.h"
#include "ui_signupdialog.h"

SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

QString SignupDialog::Name()
{
    return ui->textEditName->toPlainText();
}

QString SignupDialog::TName()
{
    return tname;
}

QDate SignupDialog::CompeteDate()
{
    return ui->dateEdit->date();
}

int SignupDialog::ThreepointNum()
{
    QString s_three = ui->textEditThree->toPlainText();
    int three = s_three.toFloat();
    return  three;
}

int SignupDialog::ReboundNum()
{
    QString s_rebound = ui->textEditRebound->toPlainText();
    int rebound = s_rebound.toFloat();
    return rebound;
}

int SignupDialog::DunkNum()
{
    QString t = ui->textEditDunk->toPlainText();
    int temp = t.toFloat();
    return temp;
}

int SignupDialog::StealNum()
{
    QString t = ui->textEditSteal->toPlainText();
    int temp = t.toFloat();
    return temp;
}

int SignupDialog::Score()
{
    QString t = ui->textEditScore->toPlainText();
    int temp = t.toFloat();
    return temp;
}

void SignupDialog::on_comboTeamname_currentIndexChanged(const QString &arg1)
{
    tname=arg1;
}
