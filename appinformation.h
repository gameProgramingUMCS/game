#ifndef APPINFORMATION_H
#define APPINFORMATION_H

enum TypeOfApp{ //Typ aplikacji serwer lub klient
    Server,
    Client
};

//Klasa pozwala ustawiac/czytac infromacje o aplikacji
//To ona definiuje czy dana aplikacja jest serwerem czy klientem
class AppInformation{

public:
    static AppInformation& getInstance();          //Zwraca instancje

    TypeOfApp getType() const;

private:
    AppInformation();
    TypeOfApp type;

};

#endif // APPINFORMATION_H
