TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

QT += sql core

LIBS += -LC:/SFML/lib


CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include



SOURCES += main.cpp \
    filedatasource.cpp \
    databasedatasource.cpp \
    datasource.cpp \
    singletonsprovider.cpp \
    basicinterface.cpp \
    user.cpp \

HEADERS += \
    filedatasource.h \
    databasedatasource.h \
    datasource.h \
    singletonsprovider.h \
    basicinterface.h \
    user.h \


