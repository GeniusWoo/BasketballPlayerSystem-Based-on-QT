#include "game.h"

Game::Game()
{
}

void Game::SaveGame(QTextStream &aStream){
    aStream<<Name<<'\t';
    aStream<<teamName<<'\t';
    aStream<<threepointNum<<'\t';
    aStream<<reboundNum<<'\t';
    aStream<<dunkNum<<'\t';
    aStream<<stealNum<<'\t';
    aStream<<Score<<'\t';
    aStream<<Date.year()<<'\t'<<Date.month()<<'\t'<<Date.day()<<'\n';
}

void Game::ReadGame(QTextStream &aStream){
    int year, month, day;
    aStream>>Name;
    aStream>>teamName;
    aStream>>threepointNum;
    aStream>>reboundNum;
    aStream>>dunkNum;
    aStream>>stealNum;
    aStream>>Score;
    aStream>>year>>month>>day;
    Date.setDate(year,month,day);
}
