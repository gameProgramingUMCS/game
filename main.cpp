#include <iostream>
//#include <sqlite3/sqlite3.h>

#include "user.h"
//#include <SFML/Window.hpp>
#include "databasedatasource.h"
using namespace std;

int main(){

cout << "Hello World!" << endl;
// sf::Window window(sf::VideoMode(800, 600), "My window");
// window.setVisible(true);

    Storable *tom = new User();
    cout<<tom->describe().toAnsiString()<<endl;
    SingletonsProvider::getInstance().getInstanceOfDatabaseDataSource();
    //DatabaseDataSource::getInstance();

    system("pause");
    return 0;
}
