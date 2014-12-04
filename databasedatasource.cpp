#include "databasedatasource.h"
#include <QDebug>
#include <QDir>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include "assert.h"

#define ClientDatabaseName "ClientDatabase.db"
#define ServerDatabaseName "ServerDatabase.db"

DatabaseDataSource::DatabaseDataSource(TypeOfDataSource type):DataSource(type){

    bool didDatabaseAlreadyExists = isDatabaseExists();
    TypeOfApp typApp = getAppInformation().getType();

    if(typApp == Client){
         assert(this->createConnectionDatabaseForClient());        //Tworzymy polacznie do bazy danych klienta
    }else{
        assert(this->createConnectionDatabaseForServer());        //Tworzymy polacznie do bazy danych serwera
    }

    if(!didDatabaseAlreadyExists){                             //Jesli baza danych juz istniala to nie przygotowujemy jej juz robimy tpo tylko jesli jeszcze nie istnieje

        if(typApp == Client){
            assert(this->prepareBasicDatabaseStructure(  (this->commonStatements() + this->clientStatements())  )); //Jesli klient to wykonuje zapytania wspolne i klienta
        }else{
            assert(this->prepareBasicDatabaseStructure(  (this->commonStatements() + this->serverStatements())  )); //Jesli serwer to zapytania wspolne i serwera
        }
    }
}

DatabaseDataSource::~DatabaseDataSource(){
    if(database.isOpen()){
        database.close();
    }
}

bool DatabaseDataSource::prepareBasicDatabaseStructure(QStringList listOfStatements){           //Wykonuje wyrazenia podane w liscie (wyrazenia do kreowania podstawowej struktury bazy danych creat'y i inserty)
    bool result = true;
    if(listOfStatements.count() == 0){
        qDebug()<<"Nie podano zadnych wyrazen do wykonania"<<endl;
        result = false;
    }else{

        database.transaction();
        QSqlQuery query;
        for(int i = 0; i < listOfStatements.count(); i++){

            if(query.exec(listOfStatements.at(i)) == false){
                result = false;

                qDebug()<<query.lastError().text()<<endl;
                assert(database.rollback());                //Wycofujemy transakcje jesli nastapil jakis blad
                break;
            }

            assert(!query.isSelect());                       //Wywalamy aplikacje jesli w zapytaniu jest select
        }

        if(result){         //Jesli nie bylo zadnych errorow to commitujemy transakcjie
            database.commit();
        }
    }

    return result;
}

DatabaseDataSource& DatabaseDataSource::getInstance(){      //Zwraca instancje singletonu
    static DatabaseDataSource instance(Database);
    return instance;
}

bool DatabaseDataSource::createConnectionDatabaseForClient(){                                  //Tworzy baze i polaczenie jesli nie isnieje lub polacznie jesli isnieje
    bool result = true;

    database = QSqlDatabase::addDatabase("QSQLITE");

    QString pt = getPath().append(QDir::separator()).append(ClientDatabaseName);
    database.setDatabaseName(pt);

    if(!database.isOpen()){         //Jesli polaczenie nie jest otwarte

       if(!database.open()){
           qDebug()<<"Blad otwierania bazy danych klienta "<<endl;
           result = false;
       }else{
           qDebug()<<"Otworzono/Utworzono kliencka baze danych "<<endl;
       }
    }

    return result;
}

bool DatabaseDataSource::createConnectionDatabaseForServer(){                              //Tworzy baze i polaczenie jesli nie isnieje lub polacznie jesli isnieje
    bool result = true;

    database = QSqlDatabase::addDatabase("QSQLITE");

    QString pt = getPath().append(QDir::separator()).append(ServerDatabaseName);
    database.setDatabaseName(pt);

    if(!database.isOpen()){         //Jesli polaczenie nie jest otwarte

       if(!database.open()){
           qDebug()<<"Blad otwierania bazy danych serwera "<<endl;
           result = false;
       }else{
           qDebug()<<"Otworzono/Utworzono serwerowa baze danych "<<endl;
       }
    }

    return result;
}

QStringList DatabaseDataSource::commonStatements(){         //Zwraca liste wyrazen(do wykonania) wspolnych dla serwera i klienta
    QStringList list;

    list.append("CREATE TABLE IF NOT EXISTS \"USERS\" (`ID` INTEGER PRIMARY KEY AUTOINCREMENT,`NAME` TEXT,`Login` CHAR(50),`Password`	TEXT,`IsActive`	INTEGER DEFAULT '1')");

    return list;
}

QStringList DatabaseDataSource::clientStatements(){         //Zwraca liste wyrazen(do wykonania) dla klienta
    QStringList result;
    //Tutaj beda zamieszczane wyrazenia tylko dla klienta
    return result;
}

QStringList DatabaseDataSource::serverStatements(){         //Zwraca liste wyrazen(do wykonania) dla serwera
    QStringList result;
    //Tutaj beda zamieszczane wyrazenia tylko dla serwera
    return result;
}

bool DatabaseDataSource::isDatabaseExists(){                //Zwraca true jesli baza danych juz istnieje
    QString pt = getPath().append(QDir::separator()).append(ClientDatabaseName);
    if(QFile(pt).exists()){
        qDebug()<<"Baza danych istniala"<<endl;
        return true;
    }else{
        qDebug()<<"Baza danych nie istniala"<<endl;
        return false;
    }
}
