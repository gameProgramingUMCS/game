#include "user.h"

#define MainDescription "USER DESCRIPTION:\n"

User::User(){
    this->typeOfStorable = UserType;
    this->name = "exmplName";
    this->login= "exmplLogin";
    this->password= "exmplpass";
    this->isActive = false;
    this->id = "0";
}

User::User(sf::String name, sf::String login, sf::String password){
    this->typeOfStorable = UserType;
    this->name = name;
    this->login = login;
    this->password = password;
    this->isActive = false;
    this->id = "0";
}

bool User::save(TypeOfDataSource type){         //Zwraca true jesli zapis sie powiodl
    bool saveAreFinished;

    //Kod Zapisu
    return saveAreFinished;
}

bool User::read(TypeOfDataSource type){         //Zwrac true jesli odczyt sie powiodl
    bool readAreFinished;

    //Kod odczytu
    return readAreFinished;
}

sf::String User::describe(){                    //Zwraca opis uzytkownika
    sf::String result, tmp;
    (isActive)?(tmp = "YES"):(tmp = "NO");

    result += MainDescription;
    result += "    Id -> "+ id + "\n";
    result += "    name -> " + name + "\n";
    result += "    login -> "+ login + "\n";
    result += "    password -> "+ password + "\n";
    result += "    isActive -> "+ tmp +"\n";
    return result;
}

void User::operator=(const User &anotherUser){

    this->id = anotherUser.id;
    this->name = anotherUser.name;
    this->login = anotherUser.name;
    this->password = anotherUser.password;
    this->isActive = anotherUser.isActive;
}

bool User::operator==(const User &anotherUser){
    if(this->id == anotherUser.id){
        return true;
    }else{
        return false;
    }
}

sf::String User::getPassword() const
{
    return password;
}

void User::setPassword(const sf::String value)
{
    password = value;
}

sf::String User::getLogin() const
{
    return login;
}


sf::String User::getName() const
{
    return name;
}


sf::String User::getId() const
{
    return id;
}


bool User::getIsActive() const
{
    return isActive;
}

void User::setIsActive(bool value)
{
    isActive = value;
}


