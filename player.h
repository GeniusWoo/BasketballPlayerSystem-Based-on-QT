#ifndef PLAYER_H
#define PLAYER_H
#include<qstring.h>
#include<QTextStream>
//Basketball Player
class Player
{
public:
    QString Name;      //球员名
    QString teamName;  //队名
    int threepointNum; //三分球数
    int reboundNum;    //篮板数
    int dunkNum;       //扣篮数
    int stealNum;      //抢断数
    int Score;         //总得分
    int gamesNum;      //比赛场数
    int m_place;       //排名，排序时临时使用
    Player();
    Player(QString name,QString tname,int tN,int rN,int dN,int sN,int score);
    //add增加变量函数
    void addThreepointNum(int n);
    void addReboundNum(int n);
    void addDunkNum(int n);
    void addStealNum(int n);
    void addScore(int n);
    void addGamesNum(int n=1);

    //读写文件
    void SavePlayer(QTextStream &aStream);
    void ReadPlayer(QTextStream &aStream);

};

#endif // PLAYER_H
