#ifndef PANCAKEHOUSEMENUITERATOR_H
#define PANCAKEHOUSEMENUITERATOR_H

#include "iterator.h"
#include "menuitem.h"
#include <cstddef>
#include <list>

class PancakeHouseMenuIterator : public Iterator
{
public:
    explicit PancakeHouseMenuIterator(const std::list<MenuItem> &items);

    bool hasNext() const override;
    MenuItem next() override;

private:
    const std::list<MenuItem> &_items;
    std::list<MenuItem>::const_iterator _iterator;
};

#endif // PANCAKEHOUSEMENUITERATOR_H
