#include "eventmanager.h"
#include "singletonsprovider.h"

static TypeOfApp typeOfApp;        //Typ aplikacji


void EventManager::manageEvent(sf::Event event){

    this->moveUp = false;
    this->moveDown = false;
    this->moveLeft = false;
    this->moveRight = false;
    this->rotateLeft = false;
    this->rotateRight = false;
    this->showFPS = false;

    if(typeOfApp == Client){
        behaviorForClient(event);
    }else if(typeOfApp == Server){
        behaviorForServer(event);
    }
}

bool EventManager::didShowFPS() const{

    return showFPS;
}

void EventManager::behaviorForServer(sf::Event event){          //Oblsluga zachownia w odpowiedzi na event dla serwera

    switch(event.type){

    case sf::Event::Closed:
        //Zamkniecie okna
        break;
    case sf::Event::KeyPressed:
        catchInputForServer(event.key.code, true);
        break;
    case sf::Event::KeyReleased:
        catchInputForServer(event.key.code, false);
        break;
    }
}

void EventManager::behaviorForClient(sf::Event event){          //Oblsluga zachownia w odpowiedzi na event dla klienta

    switch(event.type){

    case sf::Event::Closed:
        //Zamkniecie okna

        break;
    case sf::Event::KeyPressed:
        catchInputForClient(event.key.code, true);
        break;
    case sf::Event::KeyReleased:
        catchInputForClient(event.key.code, false);
        break;
    }
}

void EventManager::catchInputForClient(sf::Keyboard::Key key, bool isPressed){      //Przechytujemy kody klawiszy dla klienta

    switch(key){
    case sf::Keyboard::W:
        moveUp = isPressed;
        break;
    case sf::Keyboard::S:
        moveDown = isPressed;
        break;
    case sf::Keyboard::A:
        moveLeft = isPressed;
        break;
    case sf::Keyboard::D:
        moveRight = isPressed;
        break;
    case sf::Keyboard::Space:
        fireMain = isPressed;
        break;
    case sf::Keyboard::RShift:
        fireSecond = isPressed;
        break;
    case sf::Keyboard::Numpad0:

        if(!isPressed){
           showFPS = !showFPS;
        }
        break;
    }
}
void EventManager::catchInputForServer(sf::Keyboard::Key key, bool isPressed){      //Przechytujemy kody klawiszy dla serwera
    switch(key){
    case sf::Keyboard::Numpad0:

        if(!isPressed){
            printf("num 0 \n");
        }

        break;
    case sf::Keyboard::Numpad1:

        if(!isPressed){
             printf("num 1 \n");
        }

        break;
    case sf::Keyboard::Numpad2:

        if(!isPressed){
             printf("num 2 \n");
        }

        break;
    case sf::Keyboard::Numpad3:

        if(!isPressed){
             printf("num 3 \n");
        }

        break;
    case sf::Keyboard::Numpad4:

        if(!isPressed){
             printf("num 4 \n");
        }

        break;
    case sf::Keyboard::Numpad5:

        if(!isPressed){
             printf("num 5 \n");
        }

        break;
    }
}

EventManager &EventManager::getInstance(){
    static EventManager instance = EventManager();
    return instance;
}

EventManager::EventManager(){
    typeOfApp = SingletonsProvider::getInstance().getInstanceOfAppInformation().getType();        //Pobieramy typ aplikacji
}
