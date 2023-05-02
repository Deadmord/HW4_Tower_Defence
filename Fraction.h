#pragma once
#include <string>

class Fraction
{
public:
    //Fraction(); // вопрос: нужен ли тут конструктор по умолчанию

    Fraction(std::string name = "");

    Fraction(const Fraction& orig);

    Fraction& operator=(const Fraction& orig);

    ~Fraction() {};

    std::string ID() { return id; }

    std::string Name() { return name; };

    void ChangeName(std::string NewName);

protected:
    static int nextID;

private:

    std::string name;
    std::string id;
};