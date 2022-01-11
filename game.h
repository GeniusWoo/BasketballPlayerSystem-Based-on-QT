#ifndef GAME_H
#define GAME_H
#include<QDate>
#include<QString>
#include<QTextStream>
//比赛类，含单场比赛球员数据和比赛日期
class Game
{
public:
    Game();
    //读写文件
    void SaveGame(QTextStream &aStream);
    void ReadGame(QTextStream &aStream);

    QString Name;
    QString teamName;
    int threepointNum;
    int reboundNum;
    int dunkNum;
    int stealNum;
    int Score;
    int gamesNum;
    QDate Date;

};

#endif // GAME_H
