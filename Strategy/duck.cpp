#include "duck.h"
#include "behaviors.h"
#include <cstdio>
#include <utility>

Duck::Duck(std::shared_ptr<FlyBehavior> flyBehavior, std::shared_ptr<QuackBehavior> quackBehavior)
    : _flyBehavior(std::move(flyBehavior)), _quackBehavior(std::move(quackBehavior))
{
}

void Duck::swim() const
{
    puts("All ducks float, even decoys!");
}

void Duck::performQuack() const
{
    if (_quackBehavior)
        _quackBehavior->quack();
    else
        puts("I haven't quack behavior");
}

void Duck::performFly() const
{
    if (_flyBehavior)
        _flyBehavior->fly();
    else
        puts("I haven't fly behavior");
}

void Duck::setFlyBehavior(std::shared_ptr<FlyBehavior> flyBehavior)
{
    _flyBehavior = std::move(flyBehavior);
}

void Duck::setQuackBehavior(std::shared_ptr<QuackBehavior> quackBehavior)
{
    _quackBehavior = std::move(quackBehavior);
}

MallardDuck::MallardDuck() : Duck(std::make_shared<FlyWithWings>(), std::make_shared<Quack>())
{
}

void MallardDuck::display()
{
    puts("I'm mallar duck.");
}

ModelDuck::ModelDuck() : Duck(std::make_shared<FlyNoWay>(), std::make_shared<MuteQuack>())
{
}

void ModelDuck::display()
{
    puts("I'm model duck.");
}

void RedheadDuck::display()
{
    puts("I'm read-head duck.");
}

void DecoyDuck::display()
{
    puts("I'm decoy duck.");
}
