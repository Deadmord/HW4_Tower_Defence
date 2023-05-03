#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Fraction.h"
#include "Player.h"
#include "Tile.h"

class Map
{
public:
	static Map& instance(size_t col, size_t row, std::vector<Player>& players, std::vector<Fraction>& fractions)
	{
		static Map inst(col, row, players, fractions);
		return inst;
	};
	void init();
	void print();
	void printField();

	std::vector<int> playerPads(std::string player_ID);
	std::vector<std::string> fractionPlayers(std::string fraction_ID);
private:
	Map(size_t col, size_t row, std::vector<Player>& players, std::vector<Fraction>& fractions);
	Map(Map const&);
	Map& operator= (Map const&);
private:
	const size_t col;
	const size_t row;
	std::vector<Tile> pads;
	std::vector<Player>& players;
	std::vector<Fraction>& fractions;


};

template<class T>
std::string name_by_id(std::vector<T>& arr, std::string id);

std::string name_by_id(std::vector<Fraction>& arr, std::string id);