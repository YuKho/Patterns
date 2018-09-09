#ifndef ADAPTERS_H
#define ADAPTERS_H

#include "ducks.h"
#include <memory>

class Turkey;

class TurkeyAdapter : public SimpleDuck
{
public:
    explicit TurkeyAdapter(std::shared_ptr<Turkey> source);
    void quack() const override;
    void fly() const override;

private:
    std::shared_ptr<Turkey> _adaptee;
};

#endif // ADAPTERS_H
