#ifndef ITERATOR_H
#define ITERATOR_H

#include "menuitem.h"

class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual MenuItem next() = 0;
};

#endif // ITERATOR_H
