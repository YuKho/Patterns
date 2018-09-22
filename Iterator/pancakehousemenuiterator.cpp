#include "pancakehousemenuiterator.h"

PancakeHouseMenuIterator::PancakeHouseMenuIterator(const std::list<MenuItem> &items)
    : _items(items)
{
    _iterator = _items.cbegin();
}

bool PancakeHouseMenuIterator::hasNext() const
{
    return _iterator != _items.cend();
}

MenuItem PancakeHouseMenuIterator::next()
{
    return *_iterator++;
}
