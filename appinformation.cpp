#include "appinformation.h"

AppInformation::AppInformation():type(Client){          //Ustawiamy typ aplikacji na klienta

}

AppInformation &AppInformation::getInstance(){
    static AppInformation instance = AppInformation();
    return instance;
}

TypeOfApp AppInformation::getType() const
{
    return type;
}

