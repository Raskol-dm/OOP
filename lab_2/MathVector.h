#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <initializer_list>
#include <vector>
#include <memory>
using namespace std;

#include "Container.h"
#include "Iterator.h"

namespace mathvector {
    template <typename T> class MathVector: public Container{  // обобщение ( указываю тип )

public:
        MathVector();
        explicit MathVector(size_t initial_size); // конструктор передаю размер и заполняю вектор
        explicit MathVector(const vector<T> &data); // конструктор копирования ( b = [] ; a = [ 1, 2]  => b = [ 1,2 ]  , определяет массив типа Т
        MathVector(T *data, size_t size); //
        MathVector(initializer_list<T> data); // принимает инициализированный список data
        explicit MathVector(const MathVector<T> &vec); // констуктор копирования
        MathVector(MathVector<T>&& vec); // конструктор перемещения
        virtual ~MathVector();


        // реализовать каждый оператор ( ++, -- , )
        MathVector<T> &operator=(const MathVector<T> &vec); // Оператор присваивания с копированием
        MathVector<T> &operator=(MathVector<T> &&vec); // Оп. присв. с перемещением
        MathVector<T> &operator=(initializer_list<T> values); // Оп. присв. с инициализированным списком

        T &operator[](size_t i);  // a[1], идёт обращение к определённому элементу
        const T &operator[](size_t i) const;

        T length() const;
        MathVector<T> norm() const;
        MathVector<T>& normalize();

        MathVector<T> operator&(const MathVector<T> &vec) const; // Умножение двух векторов
        MathVector<T> multiplication(const MathVector<T> &vec) const;

        T operator*(const MathVector<T> &vec) const; // тоже умножение

        T angle(const MathVector<T> &vec) const;

        bool ortogonality(const MathVector<T> &vec) const;
        bool collinearity(const MathVector<T> &vec) const;

        MathVector<T>& addTo(const MathVector<T> &vec); // сложить ( a.addTo(b) )
        MathVector<T> &operator+=(const MathVector<T> &vec); // ( a += b)
        MathVector<T> add(const MathVector<T> &vec) const;
        MathVector<T> operator+(const MathVector<T> &vec) const;
        MathVector<T> operator+() const;

        MathVector<T>& subFrom(const MathVector<T> &vec);
        MathVector<T> &operator-=(const MathVector<T> &vec);
        MathVector<T> sub(const MathVector<T> &vec) const;
        MathVector<T> operator-(const MathVector<T> &vec) const;
        MathVector<T> operator-() const;

        MathVector<T> multiplyTo(T var); // умножает вектор на какое-то число
        MathVector<T> &operator*=(T var);
        MathVector<T> multiply(T *var);
        MathVector<T> operator*(T var) const;

        MathVector<T> devideFrom(T var);
        MathVector<T> &operator/=(T var);
        MathVector<T> devide(T *var);
        MathVector<T> operator/(T var) const;

        bool equals(const MathVector<T> &vec) const; // ( a == b)
        bool operator==(const MathVector<T> &vec) const;

        bool notEquals(const MathVector<T> &vec) const;
        bool operator!=(const MathVector<T> &vec) const;

        IteratorConst<T> begin() const; // как мы будем проходиться по массиву
        IteratorConst<T> end() const;

        Iterator<T> begin();
        Iterator<T> end();

        IteratorConst<T> cbegin() const;
        IteratorConst<T> cend() const;

   private:
        shared_ptr<T[]> coords; // shared_ptr - умный указатель , грамотно работает с памятью; coords - массив
    };
}

#include "MathVector.hpp"


#endif // MATHVECTOR_H
