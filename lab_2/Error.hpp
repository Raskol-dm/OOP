#include "Error.h"
#include <string>
using namespace std;

namespace mathvector {
    UndefinedError::UndefinedError(long timestamp, string filename, string classname,
                             int line, string info) {

        err_msg = "\nFile name: " + filename + "\nClass: " + classname +
                  "\nLine#: " + to_string(line) +
                  "\nTime: " + to_string(timestamp) + "Info: " + info;
    }

    SizeError::SizeError(long timestamp, string filename, string classname,
                             int line, string info) :
                             UndefinedError(timestamp,filename,classname, line, info) {};

    const char *UndefinedError::what() const throw() {
        return err_msg.c_str();
    }

    const char *SizeError::what() const throw() {
        return err_msg.c_str();
    }

    DivisionByZeroError::DivisionByZeroError(long timestamp, string filename, string classname,
                         int line, string info) :
            UndefinedError(timestamp,filename,classname, line, info) {};

    const char *DivisionByZeroError::what() const throw() {
        return err_msg.c_str();
    }

    BoundariesError::BoundariesError(long timestamp, string filename, string classname,
                                             int line, string info) :
            UndefinedError(timestamp,filename,classname, line, info) {};

    const char *BoundariesError::what() const throw() {
        return err_msg.c_str();
    }

    MemoryError::MemoryError(long timestamp, string filename, string classname,
                                     int line, string info) :
            UndefinedError(timestamp,filename,classname, line, info) {};

    const char *MemoryError::what() const throw() {
        return err_msg.c_str();
    }

    WeakPointerError::WeakPointerError(long timestamp, string filename, string classname,
                             int line, string info) :
            UndefinedError(timestamp,filename,classname, line, info) {};

    const char *WeakPointerError::what() const throw() {
        return err_msg.c_str();
    }
}
