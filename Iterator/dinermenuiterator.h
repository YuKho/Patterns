#ifndef DINERMENUITERATOR_H
#define DINERMENUITERATOR_H

#include "iterator.h"
#include <cstddef>

class DinerMenuIterator : public Iterator
{
public:
    DinerMenuIterator(MenuItem **items, size_t size);

    bool hasNext() const override;
    MenuItem next() override;

private:
    MenuItem **_items = nullptr;
    size_t _size = 0;
    size_t _position = 0;
};

#endif // DINERMENUITERATOR_H
