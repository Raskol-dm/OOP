#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>
using namespace std;

namespace mathvector {
    class UndefinedError : public exception {
    public:
        UndefinedError(long timestamp, string filename, string classname,
                    int line, string info = "Undefined error:");

        virtual const char *what() const throw() override ;

    protected:
        string err_msg;
    };

    class SizeError : public UndefinedError {
    public:
        SizeError(long timestamp, string filename, string classname,
                    int line, string info = "Sizes mismatch:");
        virtual const char *what() const throw();
    };

    class DivisionByZeroError : public UndefinedError {
    public:
        DivisionByZeroError(long timestamp, string filename, string classname,
                  int line, string info = "Division by zero");
        virtual const char *what() const throw();
    };

    class BoundariesError : public UndefinedError {
    public:
        BoundariesError(long timestamp, string filename, string classname,
                            int line, string info = "Index is out of boundaries");
        virtual const char *what() const throw();
    };

    class MemoryError : public UndefinedError {
    public:
        MemoryError(long timestamp, string filename, string classname,
                        int line, string info = "Memory couldn't be allocated");
        virtual const char *what() const throw();
    };

    class WeakPointerError : public UndefinedError {
    public:
        WeakPointerError(long timestamp, string filename, string classname,
                    int line, string info = "Weak pointer is invalid");
        virtual const char *what() const throw() override;
    };

}

#include "Error.hpp"

#endif // ERROR_H
