#ifndef ADAPTERS_H
#define ADAPTERS_H

#include "ducks.h"
#include "turkeys.h"
#include <memory>

class Turkey;

class TurkeyObjectAdapter final : public AbstractDuck
{
public:
    explicit TurkeyObjectAdapter(std::shared_ptr<Turkey> source);
    void quack() const override;
    void fly() const override;

private:
    std::shared_ptr<Turkey> _adaptee;
};

class TurkeyClassAdapter final : public AbstractDuck, public WildTurkey
{
public:
    void quack() const override;
    void fly() const override;
};

#endif // ADAPTERS_H
