#ifndef DATABASEDATASOURCE_H
#define DATABASEDATASOURCE_H

#include "datasource.h"
#include <QSqlDatabase>
#include <QStringList>

//Klasa bazodanowego zrodla danych zwraca singleton
class DatabaseDataSource: public DataSource{

public:
    static DatabaseDataSource& getInstance();   //Zwraca instancje singletonu

protected:

    bool createConnectionDatabaseForClient();             //Tworzy baze i polaczenie jesli nie istnieje lub polacznie jesli isnieje
    bool createConnectionDatabaseForServer();             //Tworzy baze i polaczenie jesli nie istnieje lub polacznie jesli isnieje

    //Wyrazenia do stworzenia podstawowej struktury bazy danych (operacje Create ewentualnie insert inne sa nie dopuszczane)
    QStringList commonStatements();             //Zwraca liste wyrazen(do wykonania) wspolnych dla serwera i klienta
    QStringList clientStatements();             //Zwraca liste wyrazen(do wykonania) dla klienta
    QStringList serverStatements();             //Zwraca liste wyrazen(do wykonania) dla serwera

    bool isDatabaseExists();                    //Zwraca prawde jesli baza danych istnieje jako plik na komputerze

private:
    DatabaseDataSource(TypeOfDataSource type);
    virtual ~DatabaseDataSource();

    bool prepareBasicDatabaseStructure(QStringList listOfStatements);   //Wykonuje wyrazenia podane w liscie (wyrazenia do kreowania podstawowej struktury bazy danych creat'y i inserty)


    QSqlDatabase database;
};

#endif // DATABASEDATASOURCE_H
