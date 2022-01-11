#include "selectdialog.h"
#include "ui_selectdialog.h"
#include <QButtonGroup>

SelectDialog::SelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
{
    ui->setupUi(this);    
    m_iSelectIndex = 0;    
}

SelectDialog::~SelectDialog()
{
    delete ui;
}


void SelectDialog::on_comboSpecialItem_currentIndexChanged(const QString &arg1)
{
    m_teamname=arg1;
}

