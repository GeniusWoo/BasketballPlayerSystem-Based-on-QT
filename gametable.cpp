#include "gametable.h"
#include <qfile.h>
#include <QTextStream>
#include <QTextCodec>
GameTable::GameTable()
{
    m_number=0;
}

bool GameTable::ReadGameFromFile(const QString &aReadFileName){
    QFile aFile(aReadFileName);
        if(!aFile.exists()) //文件不存在
            return false;
        if(!aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //以文本方式打开
            return false;
        QTextStream aStream(&aFile); //用文本流读取文件
        aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字

        //初始化
        m_games.clear();
        m_number = 0;

        //逐个读取运动员信息
        aStream>>m_number; //运动员总数
        Game temp;
        if(m_number>0)
        {
            for(int i=0; i<m_number; i++)
            {
                temp.ReadGame(aStream);
                m_games.push_back(temp);
            }
        }
        aFile.close();//关闭文件
        return true;
}

bool GameTable::SaveGameToFile(const QString &aSaveFileName)
{
    QFile aFile(aSaveFileName);
    if(!aFile.open(QIODevice::WriteOnly| QIODevice::Text)) //保存为文本
        return false;
    QTextStream aStream(&aFile);//用文本流保存文件
    aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字

    //逐个写入比赛信息
    aStream<<m_number<<'\n';//比赛总数
    if(m_number>0)
    {
        for(int i=0; i<m_number; i++)
            m_games[i].SaveGame(aStream);
    }
    aFile.close(); //关闭文件
    return true;
}


void GameTable::AddGame(Game &game){
    m_games.push_back(game);
    m_number++;
}

int GameTable::GetGameNum(){
    m_number=m_games.size();
    return m_number;
}

Game & GameTable::GetGame(int index){
    return m_games[index];
}
