#ifndef ABSTRACTPIZZA_H
#define ABSTRACTPIZZA_H

#include <iosfwd>
#include <string>

class AbstractPizza
{
public:
    explicit AbstractPizza(std::string name);
    virtual ~AbstractPizza() = default;

    std::string name() const;

    void bake() const;
    void box() const;

    virtual void cut() const;
    virtual void prepare() = 0;

    virtual std::ostream& print(std::ostream &os) const = 0;

private:
    std::string _name;
};

std::ostream &operator << (std::ostream &os, const AbstractPizza &pizza);

#endif // ABSTRACTPIZZA_H
