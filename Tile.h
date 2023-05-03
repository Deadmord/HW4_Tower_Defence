#pragma once
#include <iostream>
#include <string>
#include "Constants.h"

class Tile
{
public:
    Tile(tile_type lend_type = tile_type::field,
        float passability = 1,
        resource_type resource_type = resource_type::no_resources,
        int mining_speed = 0,
        const std::string& occupation = "0",
        float influence = 0,
        int tower_level = 0);

    Tile(const Tile& orig);

    Tile(Tile&& orig) noexcept;

    Tile& operator=(const Tile& orig);

    ~Tile() {};

    tile_type LendType() { return lend_type; }
    float Passability() { return passability; }
    resource_type Resource() { return resource; }

    int MiningSpeed() { return mining_speed; }
    void MiningSpeed(int newSpeed) { mining_speed = newSpeed; }

    std::string Occupation() { return occupation; }
    void Occupation(std::string newOwner) { occupation = newOwner; }

    float Influence() { return influence; }
    void Influence(float newInfluence) { influence = newInfluence; }

    int TowerLevel() { return tower_level; }
    void TowerLevel(int newLevel) { tower_level = newLevel; }

private:
    tile_type const lend_type;
    float const passability;        // 1 to 0
    resource_type const resource;// 0 - no resources
    int mining_speed;               // 0 - no mining, quant/time

    std::string occupation;         //Who ocupate the tile
    float influence;                //Players influence on the tile
    int tower_level;                // 0 - tower is missing

};
