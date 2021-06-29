#include "Person.h"

Person::Person(std::string const &_name, int _age)
    : name(_name)
    , age(_age)
{}


void Person::setAge(int age)
{
    this->age = age;
}

int Person::getAge() const
{
    return age;
}

void Person::setName(const std::string &name)
{
    this->name = name;
}

const std::string &Person::getName() const
{
    return name;
}

bool Person::operator<(const Person &other) const
{
    return age < other.age;
}

bool Person::operator>(const Person &other) const
{
    return age > other.age;
}

std::ostream &operator<<(std::ostream &stream, const Person &person)
{
    stream << person.name << '-' << person.age;
    return stream;
}
