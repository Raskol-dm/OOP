#include "Iterator.h"
#include "Error.h"
#include <time.h>

namespace mathvector {

    template <typename T>
    Iterator<T>::Iterator(const Iterator<T> &iter){ // Конструктор ( индекс позиции )
        this->position = iter.position;
    }

    template <typename T>
    Iterator<T>::Iterator(shared_ptr<T[]> p, size_t pos) { // ( указатель на массив и позицию )
        this->ptr = p;
        this->position = pos;
    }



    template <typename T>
    T &Iterator<T>::operator*() { // Position - добавить проверку!
        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        auto thisPtr = this->ptr.lock();

        T *data = thisPtr.get();

        return *(data + this->position); // a[1] == *(a+1) адресная арифметика
    }

    template <typename T>
    const T Iterator<T>::operator*() const {
        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        auto thisPtr = this->ptr.lock();
        T *data = thisPtr.get();

        return *(data + this->position);
    }

    template <typename T>
    T *Iterator<T>::operator->() {

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }
        auto thisPtr = this->ptr.lock();
        T *data = thisPtr.get();

        return data + this->position;
    }

    template <typename T>
    const T *Iterator<T>::operator->() const {

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        auto thisPtr = this->ptr.lock();
        T *data = thisPtr.get();

        return data + this->position;
    }

    template <typename T>
    Iterator<T>& Iterator<T>::operator=(const Iterator<T> &iter) {
        ptr = iter.ptr;
        position = iter.position;

        return *this;
    }

    template <typename T>
    Iterator<T>& Iterator<T>::operator++() { // проверка на обрыв

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }
        position++;
        return *this;
    }

    template <typename T>
    Iterator<T>& Iterator<T>::operator+=(int n) {

        ptr += n;

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return *this;
    }

    template <typename T>
    Iterator<T> Iterator<T>::operator++(int) {
        Iterator<T> res(*this);
        operator++();

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return res;
    }

    template <typename T>
    Iterator<T> Iterator<T>::operator+(int n) {
        Iterator<T> res(*this);
        res += n;

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return res;
    }

    template <typename T>
    Iterator<T>& Iterator<T>::operator--() {
        position--;

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return *this;
    }

    template <typename T>
    Iterator<T> Iterator<T>::operator--(int) {
        Iterator<T> res(*this);
        operator--();

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return res;
    }

    template <typename T>
    Iterator<T> Iterator<T>::operator-(int n) {
        Iterator<T> res(*this);
        res -= n;

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return res;
    }

    template <typename T>
    Iterator<T>& Iterator<T>::operator-=(int n) {
        ptr -= n;

        time_t t_time = time(NULL);

        if (this->ptr.expired()) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return *this;
    }

    template <typename T>
    bool Iterator<T>::operator==(const Iterator& iter) {
        auto thisPtr = ptr.lock();
        auto iterPtr = iter.ptr.lock();

        time_t t_time = time(NULL);

        if ((ptr.expired() && iter.ptr.expired())) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return thisPtr.get() == iterPtr.get() && position == iter.position;
    }

    template <typename T>
    bool Iterator<T>::operator!=(const Iterator& iter) {
        return !(*this == iter);
    }

    /* ___________________________________________ IteratorConst ____________________________________________________ */
    template <typename T>
    IteratorConst<T>::IteratorConst(const Iterator<T> &iter) {
        this->position = iter.position;
        this->ptr = iter.ptr;
    }

    template <typename T>
    IteratorConst<T>::IteratorConst(std::shared_ptr<T> p, size_t pos) {
        this->ptr = p;
        this->position = pos;
    }


    template <typename T>
    const T &IteratorConst<T>::operator*() const {
        auto thisPtr = this->ptr.lock();
        time_t t_time = time(NULL);
        if (!thisPtr) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        T *data = thisPtr.get();

        return *(data + this->position);
    }

    template <typename T>
    const T *IteratorConst<T>::operator->() const {
        auto thisPtr = this->ptr.lock();
        time_t t_time = time(NULL);
        if (!thisPtr) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        T *data = thisPtr.get();

        return data + this->position;
    }

    template <typename T>
    IteratorConst<T>& IteratorConst<T>::operator=(const IteratorConst<T> &iter){
        ptr = iter.ptr;
        position = iter.position;

        return *this;
    }

    template <typename T>
    IteratorConst<T>& IteratorConst<T>::operator++() {
        position++;
        return *this;
    }

    template <typename T>
    IteratorConst<T> IteratorConst<T>::operator++(int) {
        IteratorConst<T> res(*this);
        operator++();
        return res;
    }

    template <typename T>
    IteratorConst<T>& IteratorConst<T>::operator--() {
        position--;
        return *this;
    }

    template <typename T>
    IteratorConst<T> IteratorConst<T>::operator--(int) {
        IteratorConst<T> res(*this);
        operator--();
        return res;
    }

    template <typename T>
    bool IteratorConst<T>::operator==(const IteratorConst& iter) const{
        auto thisPtr = ptr.lock();
        auto iterPtr = iter.ptr.lock();

        time_t t_time = time(NULL);

        if (!(thisPtr && iterPtr)) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return thisPtr.get() == iterPtr.get() && position == iter.position;
    }

    template <typename T>
    bool IteratorConst<T>::operator!=(const IteratorConst& iter) const{
        return !(*this == iter);
    }

}
