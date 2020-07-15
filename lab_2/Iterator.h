#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iterator>

namespace mathvector {
    template <typename T> class Iterator: public std::iterator<std::input_iterator_tag, T> { // стандартный файл из библиотеки
    public:
        Iterator(const Iterator<T> &iter);
        Iterator(std::shared_ptr<T[]> p, size_t pos = 0);

        Iterator<T>& operator=(const Iterator<T> &iter);

        operator bool() const; // приведение типа

        Iterator<T>& operator++();
        Iterator<T> operator++(int);
        Iterator<T> operator+(int n);
        Iterator<T>& operator+=(int n);

        Iterator<T>& operator--();
        Iterator<T> operator--(int);
        Iterator<T> operator-(int n);
        Iterator<T>& operator-=(int n);


        T &operator*();
        const T operator*() const;
        T *operator->();
        const T *operator->() const;

        bool operator==(const Iterator& iter);
        bool operator!=(const Iterator& iter);

    protected:
        std::weak_ptr<T[]> ptr; // указатель на мой итератор
        size_t position;
    };



    template <typename T>
    class IteratorConst : public std::iterator<std::input_iterator_tag, T> {
    public:
        IteratorConst(const Iterator<T> &iter);
        IteratorConst(std::shared_ptr<T> p, size_t pos = 0);

        IteratorConst<T>& operator=(const IteratorConst<T> &iter);

        IteratorConst<T>& operator++();
        IteratorConst<T> operator++(int);
        IteratorConst<T> operator+(int n);
        IteratorConst<T>& operator+=(int n);

        IteratorConst<T>& operator--();
        IteratorConst<T> operator--(int);
        IteratorConst<T> operator-(int n);
        IteratorConst<T>& operator-=(int n);

        const T& operator*() const;
        const T *operator->() const;
        operator bool() const;

        bool operator==(const IteratorConst& iter) const;
        bool operator!=(const IteratorConst& iter) const;

    protected:
        std::weak_ptr<T> ptr;
        size_t position;
    };

};

#include "Iterator.hpp"
#endif // ITERATOR_H
