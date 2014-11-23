#ifndef USER_H
#define USER_H

#include "basicinterface.h"
#include <SFML/System/String.hpp>

//Klasa uzytkownika, implementuje interfejs storable (ma mozliwosc zapisu i odczytu z i do wskazanego zrodla danych)
class User: public Storable{

public:
    User();
    User(sf::String name, sf::String login, sf::String password);

    bool getIsActive() const;                   //Mozna pobierac wszystkie informacje
    sf::String getId() const;
    sf::String getName() const;
    sf::String getLogin() const;
    sf::String getPassword() const;

    void setPassword(const sf::String value);  //Mozna zmieniac tylko haslo i aktywnosc
    void setIsActive(bool value);

    sf::String describe();                      //Zwraca opis uzytkownika
    bool save(TypeOfDataSource type);           //Zwraca true jesli zapis sie powiodl
    bool read(TypeOfDataSource type);           //Zwrac true jesli odczyt sie powiodl

    void operator=(const User & anotherUser);
    bool operator==(const User &anotherUser);

protected:

private:
    sf::String name, login, password;
    sf::String id;
    bool isActive;

};

#endif // USER_H
