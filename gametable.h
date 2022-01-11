#ifndef GAMETABLE_H
#define GAMETABLE_H
#include"game.h"
#include<vector>
#include<QVector>

class GameTable
{
public:
    GameTable();
    bool ReadGameFromFile(const QString &aReadFileName);
    bool SaveGameToFile(const QString &aSaveFileName);

    void AddGame(Game & game);
    Game & GetGame(int index);
    int GetGameNum();
protected:
    QVector <Game> m_games; //比赛列表
    int m_number; //比赛总数
};

#endif // GAMETABLE_H
