#include "Fraction.h"

//------------------Fraction-Body--------------------
int Fraction::nextID = 0;

Fraction::Fraction(std::string name) :name(name) { id = std::to_string(++nextID); };

Fraction::Fraction(const Fraction& orig) :name(orig.name) { id = orig.id; } //��������� ������, ��� ����������� id

Fraction& Fraction::operator=(const Fraction& orig) { name = orig.name; id = orig.id; return(*this); } //��������� ������, ��� ����������� id

void Fraction::ChangeName(std::string NewName) { name = NewName; }