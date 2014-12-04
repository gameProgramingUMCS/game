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

AppInformation &SingletonsProvider::getInstanceOfAppInformation(){          //Singleton obiektu dostarczajacego danych o aplikacji
    return AppInformation::getInstance();
}

EventManager &SingletonsProvider::getInstanceOfEventManager(){              //Singleton obiektu zarzadzajacego eventami
    return EventManager::getInstance();
}


