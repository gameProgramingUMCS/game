#include "singletonsprovider.h"

SingletonsProvider::SingletonsProvider(){

}

SingletonsProvider& SingletonsProvider::getInstance(){          //Zwraca singleton samego siebie
    static SingletonsProvider instance;
    return instance;
}

FileDataSource &SingletonsProvider::getInstanceOfFileDataSource()   //Singleton plikowego zrodla danych
{
    return FileDataSource::getInstance();
}

DatabaseDataSource &SingletonsProvider::getInstanceOfDatabaseDataSource()   //Singleton bazodanowego żrodla danych
{
    return DatabaseDataSource::getInstance();
}


