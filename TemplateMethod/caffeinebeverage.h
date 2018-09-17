#ifndef CAFFEINEBEVERAGE_H
#define CAFFEINEBEVERAGE_H

class CaffeineBeverage
{
public:
    virtual ~CaffeineBeverage() = default;
    virtual void brew() const = 0;
    virtual void addCondiments() const = 0;

    void prepareRecipe();

private:
    void boilWater() const;
    void pourInCup() const;
};

#endif // CAFFEINEBEVERAGE_H
