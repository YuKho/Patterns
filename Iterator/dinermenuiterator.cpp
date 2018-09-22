#include "dinermenuiterator.h"

DinerMenuIterator::DinerMenuIterator(MenuItem *items, size_t size)
    : _items(items), _size(size)
{
}

bool DinerMenuIterator::hasNext() const
{
    return _position < _size;
}

MenuItem DinerMenuIterator::next()
{
    return _items[_position++];
}
