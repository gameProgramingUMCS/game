#include <iostream>
//#include <sqlite3/sqlite3.h>

#include "user.h"
#include "databasedatasource.h"
#include "singletonsprovider.h"
#include "game.h"

using namespace std;

int main(){


    SingletonsProvider::getInstance().getInstanceOfDatabaseDataSource();        //Tworzymy/zwracamy baze danych

    Game game;
    game.run();     //Uruchamiamy glowna petle gry

//    Storable *tom = new User();
//    cout<<tom->describe().toAnsiString()<<endl;

    return 0;
}

