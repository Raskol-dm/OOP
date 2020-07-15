#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <cstddef>
using namespace std;

namespace mathvector {

    class Container {  // мой шаблон, от которого я буду наследовать вектор
    public:
        bool isEmpty() const;
        size_t getSize() const;
        virtual void resize(size_t newSize);

        virtual ~Container() = 0;

    protected:
        size_t size;

        virtual void setSize(size_t newSize);
    };

    Container::~Container() = default;
}

#include "Container.hpp"


#endif // CONTAINER_H
