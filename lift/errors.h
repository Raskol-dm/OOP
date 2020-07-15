#ifndef _ERRORS_H
#define _ERRORS_H
#include <exception>

class CommonError : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Undefined error";
    }
};

class SizeError : public CommonError
{
public:
    virtual const char *what() const throw()
    {
        return "Sizes mismatch";
    }
};

class DivisionByZeroError : public CommonError
{
public:
    virtual const char *what() const throw()
    {
        return "Division by zero";
    }
};

class BoundariesError : public CommonError
{
public:
    virtual const char *what() const throw()
    {
        return "Index is out of boundaries";
    }
};

class MemoryError : public CommonError
{
public:
    virtual const char *what() const throw()
    {
        return "Memory couldn't be allocated";
    }
};

#endif // _ERRORS_H
