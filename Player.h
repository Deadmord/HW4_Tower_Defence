#pragma once
#include <string>

class Player
{
public:
    //Player(); // вопрос: нужен ли тут конструктор по умолчанию

    Player(std::string fraction_id, std::string name = "");

    Player(const Player& orig);

    Player& operator=(const Player& orig);

    ~Player() {};

    std::string ID() { return id; }

    std::string Name() { return name; };

    void ChangeName(std::string NewName);

    std::string Fraction() { return fraction_id; };

    void ChangeFraction(std::string NewFractionID);

protected:
    static int nextID;

private:

    std::string name;
    std::string id;
    std::string fraction_id;
};

