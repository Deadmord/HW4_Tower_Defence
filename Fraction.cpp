#include "Fraction.h"

//------------------Fraction-Body--------------------
int Fraction::nextID = 0;

Fraction::Fraction(std::string name) :name(name) { id = std::to_string(++nextID); };

Fraction::Fraction(const Fraction& orig) :name(orig.name) { id = std::to_string(++nextID); } //проверить логику, что присваивать id

Fraction& Fraction::operator=(const Fraction& orig) { name = orig.name; id = std::to_string(++nextID); return(*this); } //проверить логику, что присваивать id

void Fraction::ChangeName(std::string NewName) { name = NewName; }