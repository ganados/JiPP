#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <exception>

#include <lab5\employee.hpp>

class noDepartment : public std::exception{
    virtual const char *what() const throw(){
        return "This department does not exist";
    }
};

class duplicateID : public std::exception{
    virtual const char *what() const throw(){
        return "Tried to add already existing ID";
    }
};

class noWorker : public std::exception{
    virtual const char *what() const throw(){
        return "There is no worker with that ID";
    }
};

#endif