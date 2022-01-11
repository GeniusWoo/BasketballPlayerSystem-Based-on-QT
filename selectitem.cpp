#include "selectitem.h"
#include "ui_selectitem.h"

SelectItem::SelectItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectItem)
{
    ui->setupUi(this);
    m_iSelectIndex = 0;
}

SelectItem::~SelectItem()
{
    delete ui;
}


void SelectItem::on_comboSelectItem_currentIndexChanged(const QString &arg1)
{
    if(arg1=="场均三分") m_iSelectIndex=0;
    else if(arg1=="场均篮板") m_iSelectIndex=1;
    else if(arg1=="场均扣篮") m_iSelectIndex=2;
    else if(arg1=="场均抢断") m_iSelectIndex=3;
    else if(arg1=="场均得分") m_iSelectIndex=4;
}
