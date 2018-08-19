#ifndef DUCK_H
#define DUCK_H

#include <memory>

class FlyBehavior;
class QuackBehavior;

class Duck
{
public:
    Duck() = default;
    virtual ~Duck() = default;
    virtual void display() = 0;

    void swim() const;
    void performQuack() const;
    void performFly() const;
    void setFlyBehavior(std::shared_ptr<FlyBehavior> flyBehavior);
    void setQuackBehavior(std::shared_ptr<QuackBehavior> quackBehavior);

protected:
    Duck(std::shared_ptr<FlyBehavior> flyBehavior, std::shared_ptr<QuackBehavior> quackBehavior);

private:
    std::shared_ptr<FlyBehavior>   _flyBehavior;
    std::shared_ptr<QuackBehavior> _quackBehavior;
};

class MallardDuck : public Duck
{
public:
    MallardDuck();
    void display() override;
};

class ModelDuck : public Duck
{
public:
    ModelDuck();
    void display() override;
};

class RedheadDuck : public Duck
{
public:
    void display() override;
};

class DecoyDuck : public Duck
{
public:
    void display() override;
};

#endif // DUCK_H
