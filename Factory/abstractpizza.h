#ifndef ABSTRACTPIZZA_H
#define ABSTRACTPIZZA_H

#include <iosfwd>
#include <string>

class AbstractPizza
{
public:
    virtual ~AbstractPizza() = default;

    std::string name() const;

    void bake() const;
    void box() const;

    virtual void cut() const;
    virtual void prepare() = 0;
    virtual std::ostream& print(std::ostream &os) const = 0;

protected:
    explicit AbstractPizza(std::string name);

private:
    std::string _name;
};

std::ostream &operator << (std::ostream &os, const AbstractPizza &pizza);
std::ostream &operator << (std::ostream &os, AbstractPizza *pizza);

#endif // ABSTRACTPIZZA_H
