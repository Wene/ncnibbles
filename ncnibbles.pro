TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lncurses

SOURCES += main.cpp \
    snake.cpp \
    snakepart.cpp \
    snakefood.cpp

HEADERS += \
    snake.h \
    snakepart.h \
    snakefood.h

