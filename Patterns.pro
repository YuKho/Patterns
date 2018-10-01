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
    Command/macrocommand.cpp \
    Adapter/adapters.cpp \
    Facade/hometheaterfacade.cpp \
    Facade/electronics.cpp \
    TemplateMethod/caffeinebeverage.cpp \
    TemplateMethod/beverages.cpp \
    Iterator/dinermenu.cpp \
    Iterator/menuitem.cpp \
    Iterator/dinermenuiterator.cpp \
    Iterator/pancakehousemenu.cpp \
    Iterator/pancakehousemenuiterator.cpp \
    Iterator/waitress.cpp \
    Composite/compositemenu.cpp \
    Composite/compositemenuitem.cpp \
    Composite/compositewaitress.cpp
    State/state.cpp

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
    Command/macrocommand.h \
    Adapter/turkeys.h \
    Adapter/ducks.h \
    Adapter/adapters.h \
    Facade/hometheaterfacade.h \
    Facade/electronics.h \
    TemplateMethod/caffeinebeverage.h \
    TemplateMethod/beverages.h \
    Iterator/dinermenu.h \
    Iterator/menu.h \
    Iterator/iterator.h \
    Iterator/menuitem.h \
    Iterator/dinermenuiterator.h \
    Iterator/pancakehousemenu.h \
    Iterator/pancakehousemenuiterator.h \
    Iterator/waitress.h \
    Composite/menucomponent.h \
    Composite/compositemenu.h \
    Composite/compositemenuitem.h \
    Composite/compositewaitress.h \
    State/state.h
