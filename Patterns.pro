TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    patterntester.cpp \
    Strategy/duck.cpp \
    Observer/weatherstation.cpp \
    Observer/weatherobservers.cpp

HEADERS += \
    patterntester.h \
    Strategy/duck.h \
    Strategy/behaviors.h \
    Observer/weatherstation.h \
    Observer/weatherobservers.h
