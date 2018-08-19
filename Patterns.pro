TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    patterntester.cpp

HEADERS += \
    Strategy/duck.h \
    Observer/weatherdata.h \
    patterntester.h
