#pragma once
#include "Tile.h"

//--------------------Tile-Body----------------------
Tile::Tile(tile_type lend_type, float passability, resource_type resource_type, int mining_speed, const std::string& occupation, float influence, int tower_level)
    : lend_type(lend_type), passability(passability), resource(resource_type), mining_speed(mining_speed), occupation(occupation), influence(influence), tower_level(tower_level)
{
    std::cout << "Default constructor invoked" << '\n';
};

Tile::Tile(const Tile& orig)
    : lend_type(orig.lend_type), passability(orig.passability), resource(orig.resource), mining_speed(orig.mining_speed), occupation(orig.occupation), influence(orig.influence), tower_level(orig.tower_level)
{
    std::cout << "Copy constructor invoked" << '\n';
};

Tile::Tile(Tile&& orig) noexcept
    : lend_type(orig.lend_type), passability(orig.passability), resource(orig.resource), mining_speed(orig.mining_speed), occupation(std::move (orig.occupation)), influence(orig.influence), tower_level(orig.tower_level)
{
    std::cout << "Move constructor invoked" << '\n';
    
    //orig = Tile();  //такой способ "освобождения" преносимого объекта, приводит к лишним вызовам default and assignment конструкторов
};

Tile& Tile::operator=(const Tile& orig) // проверить смысловую необходимость такого оператора присваивания
{
    std::cout << "Assignment constructor invoked" << '\n';
    mining_speed = (orig.mining_speed);
    occupation = (orig.occupation);
    influence = (orig.influence);
    tower_level = (orig.tower_level);
    return (*this);
};