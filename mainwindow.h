#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playerstable.h"
#include "gametable.h"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //显示比赛信息
    void ShowGameTable();
    //显示球员信息
    void ShowPlayerTable();
    //显示筛选技术项目名单
    void ShowWinSpecialItemList(int itemID);
    //显示筛选球队名单
    void ShowSpecialList(QString teamname);

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_actionOpen_triggered();//打开文件操作

    void on_actionSave_triggered();

    void on_actionbaoming_triggered();

    void on_actionxianshibaom_triggered();

    void on_actionhengji_triggered();

    void on_ShowInfotableView_changed();

    void on_actionlingjiangmingdan_triggered();

    void on_actionmingdanshaixuan_triggered();

private:
    Ui::MainWindow *ui; //窗口类
    QStandardItemModel * sportsmanInforModel; //显示表格信息数据模型
    PlayersTable m_InfoTable; //数据汇总类
    GameTable g_InfoTable;
    QVector<QString>teamlist; //球队列表

    int m_iCurTable; //当前表格显示的信息，0--初始状态；1--球员比赛数据；2--球员数据；3--筛选单项前三球员数据；4--筛选球队优秀球员数据
};
#endif // MAINWINDOW_H
