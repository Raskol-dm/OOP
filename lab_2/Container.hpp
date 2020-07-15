#include "Container.h"
using namespace std;

namespace mathvector {
    size_t Container::getSize() const {
        return size;
    }

    bool Container::isEmpty() const {
        return size == 0;
    }

    void Container::resize(size_t newSize) {
        setSize(newSize);
    }

    void Container::setSize(size_t newSize) {
        size = newSize;
    }
}
