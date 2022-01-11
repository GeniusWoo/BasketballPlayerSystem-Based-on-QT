#include "player.h"

//initial funtion
Player::Player()
{
    gamesNum=1;m_place=1;
}
Player::Player(QString name,QString tname,int tN,int rN,int dN,int sN,int score){
    Name=name;teamName=tname;threepointNum=tN;reboundNum=rN;
    dunkNum=dN;stealNum=sN;Score=score;gamesNum=1;m_place=1;
}
void Player::addDunkNum(int n){
    dunkNum+=n;
}
void Player::addGamesNum(int n){
    gamesNum+=n;
}
void Player::addReboundNum(int n){
    reboundNum+=n;
}
void Player::addScore(int n){
    Score+=n;
}
void Player::addStealNum(int n){
    stealNum+=n;
}
void Player::addThreepointNum(int n){
    threepointNum+=n;
}

void Player::SavePlayer(QTextStream &aStream){
    aStream<<Name<<'\t';
    aStream<<teamName<<'\t';
    aStream<<threepointNum<<'\t';
    aStream<<reboundNum<<'\t';
    aStream<<dunkNum<<'\t';
    aStream<<stealNum<<'\t';
    aStream<<Score<<'\t';
    aStream<<gamesNum<<'\t';
    aStream<<'\n';
}
void Player::ReadPlayer(QTextStream &aStream){
    aStream>>Name;
    aStream>>teamName;
    aStream>>threepointNum;
    aStream>>reboundNum;
    aStream>>dunkNum;
    aStream>>stealNum;
    aStream>>Score;
    aStream>>gamesNum;
}
