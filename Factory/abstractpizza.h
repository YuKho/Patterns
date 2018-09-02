#ifndef ABSTRACTPIZZA_H
#define ABSTRACTPIZZA_H

#include <iosfwd>
#include <string>

class AbstractPizza
{
public:
    virtual ~AbstractPizza() = default;
    virtual void cut() const = 0;
    virtual void prepare() const = 0;
    virtual void bake() const = 0;
    virtual void box() const = 0;
    virtual std::ostream& print(std::ostream &os) const = 0;

    std::string name() const;
    void setName(std::string name);

private:
    std::string _name;
};

std::ostream &operator << (std::ostream &os, const AbstractPizza &pizza);

#endif // ABSTRACTPIZZA_H
