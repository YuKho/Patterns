TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    patterntester.cpp \
    Strategy/duck.cpp

HEADERS += \
    patterntester.h \
    Strategy/duck.h \
    Observer/weatherdata.h \
    Strategy/behaviors.h
