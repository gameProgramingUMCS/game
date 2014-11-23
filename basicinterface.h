#ifndef BASICINTERFACE_H
#define BASICINTERFACE_H

#include "datasource.h"
#include "singletonsprovider.h"
#include <SFML/System/String.hpp>

//Typy danych do przechowania jakimi mozna operowac
enum StorableType{
    UserType,
    SettingsType,
};

//Abstrakcyjna klasa (interfejs) zapewniajacy mozliwosc zapisu odczytu
class Storable{

public:
    virtual bool save(TypeOfDataSource type = Database) = 0;            //Zapisuje dane do podanego zrodla, zwraca true jesli zawpis sie powiodl
    virtual bool read(TypeOfDataSource type = Database) = 0;            //Odczytuje dane z podanego zrodla, zwraca true jesli odczyt sie powiodl
    virtual sf::String describe() = 0;                                  //Zwrac opis zawartosci obiektu

protected:
    DataSource& getDataSource(TypeOfDataSource type);               //Zwraca datasource wskazanego typu
    StorableType typeOfStorable;                                        //Typ przechowywancych danych

private:
};


#endif // BASICINTERFACE_H
