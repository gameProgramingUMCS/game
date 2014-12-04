#include "game.h"

//Game &Game::getInstance(){          //Zwraca singleton obiektu
//    static Game instance = Game();
//    return instance;
//}

#define RequredFPS 60.0

static int FPS;

void Game::run(){                   //Uruchamia glowna petle gry

    sf::Clock clock;
    sf::Clock fpsClock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1/RequredFPS);
    sf::Time oneSecond = sf::seconds(1);
    static int tmpframeQuantity = 0;
    FPS = 0;

    while(mainWindow.isOpen()){

        processEvent();
        timeSinceLastUpdate += clock.restart();

        while(timeSinceLastUpdate > timePerFrame){                      //Wykonywanie updateu w rownych ostepach czasu
            timeSinceLastUpdate -= timePerFrame;
            processEvent();
            update(timePerFrame);

            tmpframeQuantity++;
        }

        if(fpsClock.getElapsedTime() > oneSecond){                      //Sprawdzanie co sekunda ilosci klatek
            FPS = tmpframeQuantity;
            tmpframeQuantity = 0;
            fpsClock.restart();
        }

        render();
    }
}

Game::Game():mainWindow(sf::VideoMode(640,480),"Tank 2.0"){
}

void Game::processEvent(){          //Odpowiada ze obsluge wszelkich zdarzen

    sf::Event catchedEvent;

    while(mainWindow.pollEvent(catchedEvent)){
        SingletonsProvider::getInstance().getInstanceOfEventManager().manageEvent(catchedEvent);
    }
}

void Game::update(sf::Time deltaTime){                //Uaktualnia stan logiki gry

}

void Game::render(){                //Renderowanie obrazu
    mainWindow.clear();

    printf("frame -> %d \n", FPS);

//    if(SingletonsProvider::getInstance().getInstanceOfEventManager().didShowFPS()){

//        sf::Text text;
//        sf::Font font;
//        text.setFont(font); // font is a sf::Font
//        text.setString("Hello world");
//        text.setCharacterSize(24); // in pixels, not points!
//        text.setColor(sf::Color::Red);
//        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
//        mainWindow.draw(text);
//    }


    mainWindow.display();
}
