#include "playerstable.h"
#include<QFile>
#include<QTextStream>
#include<QTextCodec>
PlayersTable::PlayersTable()
{
    m_number=0;
}
void PlayersTable::RankThreepoint(){
    int i, j;
    int total = m_sportmans.size();
    for(i=0; i<total;i++)
    {
        Player & sportman = m_sportmans[i]; //获取当前运动员的引用
        float temp = sportman.threepointNum/sportman.gamesNum;
        int rank = 1;

        //遍历获取当前球员的排名
        j=0;
        while(j<total)
        {
            if(temp<m_sportmans[j].threepointNum/m_sportmans[j].gamesNum)
                rank++;
            j++;
        }
        sportman.m_place = rank;
    }
}

void PlayersTable::RankRebound(){
    int i, j;
    int total = m_sportmans.size();
    for(i=0; i<total;i++)
    {
        Player & sportman = m_sportmans[i]; //获取当前运动员的引用
        float temp = sportman.reboundNum/sportman.gamesNum;
        int rank = 1;

        //遍历获取当前球员的排名
        j=0;
        while(j<total)
        {
            if(temp<float(m_sportmans[j].reboundNum)/m_sportmans[j].gamesNum)
                rank++;
            j++;
        }
        sportman.m_place = rank;
    }
}

void PlayersTable::RankDunk(){
    int i, j;
    int total = m_sportmans.size();
    for(i=0; i<total;i++)
    {
        Player & sportman = m_sportmans[i]; //获取当前运动员的引用
        float temp = sportman.dunkNum/sportman.gamesNum;
        int rank = 1;

        //遍历获取当前球员的排名
        j=0;
        while(j<total)
        {
            if(temp<float(m_sportmans[j].dunkNum)/m_sportmans[j].gamesNum)
                rank++;
            j++;
        }
        sportman.m_place = rank;
    }
}

void PlayersTable::RankSteal(){
    int i, j;
    int total = m_sportmans.size();
    for(i=0; i<total;i++)
    {
        Player & sportman = m_sportmans[i]; //获取当前运动员的引用
        float temp = sportman.stealNum/sportman.gamesNum;
        int rank = 1;

        //遍历获取当前球员的排名
        j=0;
        while(j<total)
        {
            if(temp<float(m_sportmans[j].stealNum)/m_sportmans[j].gamesNum)
                rank++;
            j++;
        }
        sportman.m_place = rank;
    }
}

void PlayersTable::RankScore(){
    int i, j;
    int total = m_sportmans.size();
    for(i=0; i<total;i++)
    {
        Player & sportman = m_sportmans[i]; //获取当前运动员的引用
        float temp = sportman.Score/sportman.gamesNum;
        int rank = 1;

        //遍历获取当前球员的排名
        j=0;
        while(j<total)
        {
            if(temp<float(m_sportmans[j].Score)/m_sportmans[j].gamesNum)
                rank++;
            j++;
        }
        sportman.m_place = rank;
    }
}

bool PlayersTable::ReadPlayerFromFile(const QString &aReadFileName)
{
    QFile aFile(aReadFileName);
    if(!aFile.exists()) //文件不存在
        return false;
    if(!aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //以文本方式打开
        return false;
    QTextStream aStream(&aFile); //用文本流读取文件
    aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字

    //初始化
    m_sportmans.clear();
    m_number = 0;

    //逐个读取运动员信息
    aStream>>m_number; //运动员总数
    Player tempSportman;
    if(m_number>0)
    {
        for(int i=0; i<m_number; i++)
        {
            tempSportman.ReadPlayer(aStream);
            m_sportmans.push_back(tempSportman);
        }
    }
    aFile.close();//关闭文件
    return true;
}

bool PlayersTable::SavePlayerToFile(const QString &aSaveFileName)
{
    QFile aFile(aSaveFileName);
    if(!aFile.open(QIODevice::WriteOnly| QIODevice::Text)) //保存为文本
        return false;
    QTextStream aStream(&aFile);//用文本流保存文件
    aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字

    //逐个写入运动员信息
    aStream<<m_number<<'\n';//运动员总数
    if(m_number>0)
    {
        for(int i=0; i<m_number; i++)
            m_sportmans[i].SavePlayer(aStream);
    }
    aFile.close(); //关闭文件
    return true;
}

void PlayersTable::AddPlayer(Player &player){
    m_sportmans.push_back(player);
    m_number++;
}

Player & PlayersTable::GetPlayer(int index){
    return m_sportmans[index];
}

int PlayersTable::GetPlayerNum(){
    m_number = m_sportmans.size();
    return m_number;
}

