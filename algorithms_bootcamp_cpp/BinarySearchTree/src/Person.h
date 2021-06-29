#ifndef Person_h
#define Person_h

#include <string>
#include <ostream>

class Person
{
    std::string name;
    int age = 0;

public:

    Person(std::string const &name, int age);

    void setAge(int age);
    int getAge() const;

    void setName(const std::string &name);
    const std::string &getName() const;

    bool operator<(const Person &other) const;
    bool operator>(const Person &other) const;
    friend std::ostream &operator<<(std::ostream &stream, const Person &person);

};

#endif
