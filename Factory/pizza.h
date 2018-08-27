#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>
#include <iosfwd>

class Pizza
{
public:
    virtual ~Pizza() = default;
    virtual void cut() const = 0;

    void prepare() const;
    void bake() const;
    void box() const;
    std::string getName() const;
    std::ostream &print(std::ostream &os) const;

protected:
    Pizza(std::string name, std::string dough, std::string sauce);
    void addTopping(std::string top);

private:
    std::string _name;
    std::string _dough;
    std::string _sauce;
    std::vector<std::string> _toppings;
};

std::ostream &operator << (std::ostream &os, Pizza *pizza);

#endif // PIZZA_H
