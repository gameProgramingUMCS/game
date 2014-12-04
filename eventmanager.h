#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

//Zarzadza przekazywanymi eventami
//Klasa jest singletonem
class EventManager{

public:
    static EventManager& getInstance();
    void manageEvent(sf::Event event);                  //Metoda wykorzystywana do zarzadzania przeychwytywanymi eventami

    bool didShowFPS() const;

protected:

    void behaviorForServer(sf::Event event);            //Obsluga zachowania w odpowiedzi na event dla serwera
    void behaviorForClient(sf::Event event);            //Obsluga zachowania w odpowiedzi na event dla klienta

private:

    void catchInputForClient(sf::Keyboard::Key key, bool isPressed);    //Przechytujemy kody klawiszy dla klienta
    void catchInputForServer(sf::Keyboard::Key key, bool isPressed);    //Przechytujemy kody klawiszy dla serwera

    bool moveUp, moveDown, moveLeft, moveRight;                         //Ustawione oznaczaja jest wlaczony/wcisniety ruch w okreslonym kierunki. Wspolne dla serwera i klienta
    bool rotateLeft, rotateRight;                                       //Ustawione wskazuja ze wystepuje obrot w jedna ze stron. Przeznaczone dla klienta.
    bool fireMain, fireSecond;                                          //Ustawione oznaczaja strzal glowny lub drugiego typu

    bool showFPS;

    EventManager();
};

#endif // EVENTMANAGER_H
