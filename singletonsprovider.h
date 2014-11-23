#ifndef SINGLETONSPROVIDER_H
#define SINGLETONSPROVIDER_H

#include "filedatasource.h"
#include "databasedatasource.h"

//Klasa zapewniajaca dostep do wszytskich singletonow dostepnych w aplikacji
class SingletonsProvider{

public:
    static SingletonsProvider& getInstance();       //Zwraca singleton samego siebie
    FileDataSource& getInstanceOfFileDataSource();  //Singleton plikowego zrodla danych
    DatabaseDataSource& getInstanceOfDatabaseDataSource();  //Singleton bazodanowego żrodla danych

protected:

private:
    SingletonsProvider();
};

#endif // SINGLETONSPROVIDER_H
