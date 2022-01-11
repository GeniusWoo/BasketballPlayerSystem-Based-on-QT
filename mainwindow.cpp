#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdir.h"
#include "qfiledialog.h"
#include "signupdialog.h"
#include "player.h"
#include "game.h"
#include <QStandardItem>
#include <qvariant.h>
#include <QMessageBox>
#include <QAbstractItemDelegate>
#include <QModelIndex>
#include "readonlydelegate.h"
#include "selectdialog.h"
#include "selectitem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/SysLogo.png"));  //设置logo
    ui->ShowInfotableView->setSelectionMode(QAbstractItemView::SingleSelection); //单次选择
    ui->ShowInfotableView->setSelectionBehavior(QAbstractItemView::SelectItems); //选中一个item

    sportsmanInforModel = new QStandardItemModel();

    //建立关联
    ui->ShowInfotableView->setModel(sportsmanInforModel);

    connect(ui->ShowInfotableView->itemDelegate(), &QAbstractItemDelegate::closeEditor, this, &MainWindow::on_ShowInfotableView_changed);

    m_iCurTable = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sportsmanInforModel;
}

void MainWindow::on_actionOpen_triggered()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择比赛信息文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

    if(aFileName.isEmpty())
        return;

    //创建成功，打开文件

    g_InfoTable.ReadGameFromFile(aFileName);
    ShowGameTable();

    dlgTitle = "选择球员信息文件";
    QString bFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

    if(aFileName.isEmpty())
        return;

    //创建成功，打开文件

    m_InfoTable.ReadPlayerFromFile(bFileName);
    ShowPlayerTable();
}

void MainWindow::on_actionSave_triggered()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "保存比赛文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if(aFileName.isEmpty())
        return;

    g_InfoTable.SaveGameToFile(aFileName);

    dlgTitle = "保存球员信息文件";
    QString bFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if(aFileName.isEmpty())
        return;

    m_InfoTable.SavePlayerToFile(bFileName);

}

void MainWindow::on_actionbaoming_triggered()
{
    SignupDialog dlgSignup(this);
    int ret = dlgSignup.exec(); //以模态方式显示对话框
    if(ret==QDialog::Accepted)
    {//OK按钮被按下
        Player tempsportman;
        Game tempgame;
        tempgame.Date = dlgSignup.CompeteDate();
        tempgame.Name=dlgSignup.Name();
        tempgame.teamName=dlgSignup.TName();
        tempgame.threepointNum=dlgSignup.ThreepointNum();
        tempgame.reboundNum=dlgSignup.ReboundNum();
        tempgame.dunkNum=dlgSignup.DunkNum();
        tempgame.stealNum=dlgSignup.StealNum();
        tempgame.Score=dlgSignup.Score();
        tempsportman.Name = dlgSignup.Name();
        tempsportman.teamName = dlgSignup.TName();
        tempsportman.threepointNum=dlgSignup.ThreepointNum();
        tempsportman.reboundNum=dlgSignup.ReboundNum();
        tempsportman.dunkNum=dlgSignup.DunkNum();
        tempsportman.stealNum=dlgSignup.StealNum();
        tempsportman.Score=dlgSignup.Score();
        bool isTeamlist=false; //队名是否已存在
        int k=0;
        for(;k<teamlist.size();k++)
            if(tempgame.teamName==teamlist[k]) {
                isTeamlist=true;
                break;
            }
        if(!isTeamlist) teamlist.push_back(tempgame.teamName);
        g_InfoTable.AddGame(tempgame);
        bool Isin=false;   //判断该球员信息是否已存在，若存在则在原信息上添加，否则新建球员
        int i=0;
        for(;i<m_InfoTable.GetPlayerNum();i++){
            if(tempsportman.Name==m_InfoTable.GetPlayer(i).Name&&tempsportman.teamName==m_InfoTable.GetPlayer(i).teamName)
            {
                Isin=true;
                break;
            }
        }
        if(Isin){ //已存在，修改已有信息
            m_InfoTable.GetPlayer(i).addThreepointNum(tempsportman.threepointNum);
            m_InfoTable.GetPlayer(i).addReboundNum(tempsportman.reboundNum);
            m_InfoTable.GetPlayer(i).addDunkNum(tempsportman.dunkNum);
            m_InfoTable.GetPlayer(i).addStealNum(tempsportman.stealNum);
            m_InfoTable.GetPlayer(i).addScore(tempsportman.Score);
            m_InfoTable.GetPlayer(i).gamesNum++;
        }
        else m_InfoTable.AddPlayer(tempsportman);
        ShowGameTable();
    }

}

void MainWindow::ShowGameTable()
{
    m_iCurTable = 1; //当前显示球员比赛信息
    sportsmanInforModel->clear();
    sportsmanInforModel->setColumnCount(8); //8列

    //表头
    //姓名，球队，比赛日期，三分，篮板，扣篮，抢断，得分
    QStringList templist;
    templist.append("姓名");
    templist.append("球队");
    templist.append("比赛日期");
    templist.append("三分球数");
    templist.append("篮板");
    templist.append("扣篮");
    templist.append("抢断次数");
    templist.append("得分");
    sportsmanInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = g_InfoTable.GetGameNum(); //行数（不含标题）
    sportsmanInforModel->setRowCount(RowCnt);

    //遍历，插入数据
    QStandardItem *aTempItem; //临时的item
    QString tempStr;
    for(int i=0; i<RowCnt; ++i)
    {
        Game tempgame=g_InfoTable.GetGame(i);
        aTempItem = new QStandardItem(tempgame.Name);
        sportsmanInforModel->setItem(i, 0, aTempItem);

        aTempItem = new QStandardItem(tempgame.teamName);
        sportsmanInforModel->setItem(i, 1, aTempItem);

        tempStr = tempgame.Date.toString("yyyy-MM-dd");
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 2, aTempItem);

        tempStr = QString::number(tempgame.threepointNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 3, aTempItem);

        tempStr = QString::number(tempgame.reboundNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 4, aTempItem);

        tempStr = QString::number(tempgame.dunkNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 5, aTempItem);

        tempStr = QString::number(tempgame.stealNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 6, aTempItem);

        tempStr = QString::number(tempgame.Score);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 7, aTempItem);
    }
    //设置号码为只读
    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);

}

void MainWindow::ShowPlayerTable()
{
    m_iCurTable = 2;//显示球员个人数据
    sportsmanInforModel->clear();
    sportsmanInforModel->setColumnCount(8);
    // 姓名 | 球队 | 三分球总数 | 篮板 | 扣篮 | 抢断次数 | 得分总数 | 比赛场数
    QStringList templist;
    templist.append("姓名");
    templist.append("球队");
    templist.append("三分球总数");
    templist.append("篮板");
    templist.append("扣篮");
    templist.append("抢断次数");
    templist.append("得分总数");
    templist.append("比赛场数");
    sportsmanInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = m_InfoTable.GetPlayerNum(); //行数
    sportsmanInforModel->setRowCount(RowCnt);

    //遍历，插入数据
    QStandardItem *aTempItem; //临时的item
    QString tempStr;
    m_InfoTable.RankScore(); //计算排名
    for(int i=0; i<RowCnt; ++i)
    {
        Player tempsportman=m_InfoTable.GetPlayer(i);

        aTempItem = new QStandardItem(tempsportman.Name);
        sportsmanInforModel->setItem(i, 0, aTempItem);

        aTempItem = new QStandardItem(tempsportman.teamName);
        sportsmanInforModel->setItem(i, 1, aTempItem);

        tempStr = QString::number(tempsportman.threepointNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 2, aTempItem);

        tempStr = QString::number(tempsportman.reboundNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 3, aTempItem);

        tempStr = QString::number(tempsportman.dunkNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 4, aTempItem);

        tempStr = QString::number(tempsportman.stealNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 5, aTempItem);

        tempStr = QString::number(tempsportman.Score);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 6, aTempItem);

        tempStr = QString::number(tempsportman.gamesNum);
        aTempItem = new QStandardItem(tempStr);
        sportsmanInforModel->setItem(i, 7, aTempItem);

    }

    //设置只读
    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(2, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(4, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(6, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(8, readOnlyDelegate);

}

void MainWindow::ShowWinSpecialItemList(int itemID)
{
    m_iCurTable = 3;//显示单项技术名单
    sportsmanInforModel->clear();
    sportsmanInforModel->setColumnCount(7); //7列

    // 姓名 | 球队 | 三分 | 篮板 | 扣篮 | 抢断 | 得分
    QStringList templist;
    templist.append("姓名");
    templist.append("球队");
    templist.append("场均三分");
    templist.append("场均篮板");
    templist.append("场均扣篮");
    templist.append("场均抢断");
    templist.append("场均得分");
    sportsmanInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = 3; //行数
    sportsmanInforModel->setRowCount(3);

    //遍历，插入数据
    QStandardItem *aTempItem; //临时的item
    QString tempStr;
    switch (itemID) {     //根据选择计算排名
    case 0:
        m_InfoTable.RankThreepoint();break;
    case 1:
        m_InfoTable.RankRebound();break;
    case 2:
        m_InfoTable.RankDunk();break;
    case 3:
        m_InfoTable.RankSteal();break;
    case 4:
        m_InfoTable.RankScore();break;
    default:
        break;
    }

    int rang=0; //行号
    for(int i=0; i<m_InfoTable.GetPlayerNum(); ++i)
    {

        Player tempsportman=m_InfoTable.GetPlayer(i);
        if(tempsportman.m_place<=3){

            aTempItem = new QStandardItem(tempsportman.Name);
            sportsmanInforModel->setItem(rang, 0, aTempItem);

            aTempItem = new QStandardItem(tempsportman.teamName);
            sportsmanInforModel->setItem(rang, 1, aTempItem);

            tempStr = QString::number(float(tempsportman.threepointNum)/tempsportman.gamesNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 2, aTempItem);

            tempStr = QString::number(float(tempsportman.reboundNum)/tempsportman.gamesNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 3, aTempItem);

            tempStr = QString::number(float(tempsportman.dunkNum)/tempsportman.gamesNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 4, aTempItem);

            tempStr = QString::number(float(tempsportman.stealNum)/tempsportman.gamesNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 5, aTempItem);

            tempStr = QString::number(float(tempsportman.Score)/tempsportman.gamesNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 6, aTempItem);

            rang++;
        }
        if(rang>=3) break;
    }

    //设置只读
    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(2, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(4, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(6, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(8, readOnlyDelegate);


}

void MainWindow::ShowSpecialList(QString teamname)
{
    m_iCurTable = 4;//显示球队筛选列表
    sportsmanInforModel->clear();
    sportsmanInforModel->setColumnCount(8);
    // 姓名 | 球队 | 三分球总数 | 篮板 | 扣篮 | 抢断次数 | 得分总数 | 比赛场数
    QStringList templist;
    templist.append("姓名");
    templist.append("球队");
    templist.append("三分球总数");
    templist.append("篮板");
    templist.append("扣篮");
    templist.append("抢断次数");
    templist.append("得分总数");
    templist.append("比赛场数");
    sportsmanInforModel->setHorizontalHeaderLabels(templist);

    int RowCnt = m_InfoTable.GetPlayerNum(); //行数
    sportsmanInforModel->setRowCount(RowCnt);

    //遍历，插入数据
    QStandardItem *aTempItem; //临时的item
    QString tempStr;
    m_InfoTable.RankScore(); //计算排名
    int rang=0; //行号
    for(int i=0; i<RowCnt; ++i)
    {
        Player tempsportman=m_InfoTable.GetPlayer(i);
        if(tempsportman.teamName==teamname){

            aTempItem = new QStandardItem(tempsportman.Name);
            sportsmanInforModel->setItem(rang, 0, aTempItem);

            aTempItem = new QStandardItem(tempsportman.teamName);
            sportsmanInforModel->setItem(rang, 1, aTempItem);

            tempStr = QString::number(tempsportman.threepointNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 2, aTempItem);

            tempStr = QString::number(tempsportman.reboundNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 3, aTempItem);

            tempStr = QString::number(tempsportman.dunkNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 4, aTempItem);

            tempStr = QString::number(tempsportman.stealNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 5, aTempItem);

            tempStr = QString::number(tempsportman.Score);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 6, aTempItem);

            tempStr = QString::number(tempsportman.gamesNum);
            aTempItem = new QStandardItem(tempStr);
            sportsmanInforModel->setItem(rang, 7, aTempItem);
            rang++;
        }
    }

    //设置只读
    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(2, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(4, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(6, readOnlyDelegate);
    ui->ShowInfotableView->setItemDelegateForColumn(8, readOnlyDelegate);


}

void MainWindow::on_actionxianshibaom_triggered()
{
    ShowGameTable();

}

void MainWindow::on_actionhengji_triggered()
{
    ShowPlayerTable();
}

void MainWindow::on_ShowInfotableView_changed()
{

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    //父类的保持
    QMainWindow::resizeEvent(event);

    int x = this->frameGeometry().width();
    int y = this->frameGeometry().height();

    //窗口改变大小的时候列表控件跟着改变
    ui->ShowInfotableView->setGeometry(5,5,x*0.99,y*0.99);
}

void MainWindow::on_actionlingjiangmingdan_triggered()
{
    SelectItem dlgSelectDlg(this);
    int ret = dlgSelectDlg.exec(); //以模态方式显示对话框
    int temp;
    if(ret==QDialog::Accepted){
        temp=dlgSelectDlg.m_iSelectIndex;
        ShowWinSpecialItemList(temp);
    }

}

void MainWindow::on_actionmingdanshaixuan_triggered()
{
    SelectDialog dlgSelectDlg(this);
    int ret = dlgSelectDlg.exec(); //以模态方式显示对话框
    QString tname;
    if(ret==QDialog::Accepted)
    {
        tname=dlgSelectDlg.m_teamname;
        ShowSpecialList(tname);
    }

}
