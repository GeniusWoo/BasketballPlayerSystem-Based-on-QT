#ifndef PLAYERSTABLE_H
#define PLAYERSTABLE_H
#include"player.h"
#include<vector>
#include<QVector>

class PlayersTable
{
public:
    PlayersTable();
    //对场均单项排序
    void RankThreepoint();
    void RankRebound();
    void RankDunk();
    void RankSteal();
    void RankScore();

    bool ReadPlayerFromFile(const QString &aReadFileName);
    bool SavePlayerToFile(const QString &aSaveFileName);

    void AddPlayer(Player & player);
    Player & GetPlayer(int index);
    int GetPlayerNum();
protected:
    QVector<Player>m_sportmans;   //球员列表
    int m_number;   //运动员总数
};

#endif // PLAYERSTABLE_H
