TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    patterntester.cpp \
    Strategy/duck.cpp \
    Observer/weatherstation.cpp \
    Observer/weatherobservers.cpp \
    Decorator/beverage.cpp \
    Factory/pizza.cpp \
    Factory/SimpleFactory/simplepizza.cpp \
    Factory/nypizzaingredientfactory.cpp \
    Factory/pizzas.cpp \
    Factory/chicagopizzaingredientfactory.cpp \
    Factory/abstractpizza.cpp \
    Factory/pizzastore.cpp \
    Command/devices.cpp \
    Command/commands.cpp \
    Command/macrocommand.cpp

HEADERS += \
    patterntester.h \
    Strategy/duck.h \
    Strategy/behaviors.h \
    Observer/weatherstation.h \
    Observer/weatherobservers.h \
    Decorator/beverage.h \
    Factory/SimpleFactory/simplepizzafactory.h \
    Factory/pizza.h \
    Factory/SimpleFactory/simplepizza.h \
    Factory/SimpleFactory/simplepizzastore.h \
    Factory/pizzastore.h \
    Factory/chicagopizzastore.h \
    Factory/nypizzastore.h \
    Factory/pizzaingredientfactory.h \
    Factory/nypizzaingredientfactory.h \
    Factory/pizzas.h \
    Factory/ingredients.h \
    Factory/chicagopizzaingredientfactory.h \
    Factory/abstractpizza.h \
    Singleton/singelton.h \
    Command/command.h \
    Command/devices.h \
    Command/remotecontrol.h \
    Command/commands.h \
    Command/macrocommand.h
