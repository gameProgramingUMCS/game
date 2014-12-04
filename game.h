#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "singletonsprovider.h"

//Glowna klasa obslugujaca rozgrywke
class Game{

public:
    void run();                         //Uruchamia glowna petle gry
    Game();

private:
    void processEvent();                //Odpowiada ze obsluge wszelkich zdarzen
    void update(sf::Time deltaTime);    //Uaktualnia stan logiki gry
    void render();                      //Renderowanie obrazu

    sf::RenderWindow mainWindow;
};

#endif // GAME_H
