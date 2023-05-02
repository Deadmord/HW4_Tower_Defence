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
	Map(size_t col, size_t row, std::vector<Player>& players, std::vector<Fraction>& fractions) : col(col), row(row), players(players), fractions(fractions) {};
	void init()		//generate random map with concrete type, plaers, and fractions
	{
		auto clc_passability = [](tile_type lend_type) -> float
		{
			switch (lend_type)
			{
				case tile_type::field:
					return 1;
				case tile_type::hill:
					return 0.5;
				case tile_type::swamp:
					return 0.25;
				case tile_type::mountain:
					return 0.0;
				default:
					return 0.0;
			}
		};
			
		srand(time(0));

		for (int i(0); i < col * row; i++)
		{
			int lend_type_rand = rand() % int(int(tile_type::num_tile_type) * 1.5) - int(int(tile_type::num_tile_type) * 0.5);
			lend_type_rand = lend_type_rand < 0 ? 0 : lend_type_rand;
			tile_type lend_type = tile_type(lend_type_rand);

			float passability = clc_passability(lend_type);

			int res_type_rand = rand() % int(int(resource_type::num_res_type) * 1.5) - int(int(resource_type::num_res_type) * 0.5);
			res_type_rand = res_type_rand < 0 ? 0 : res_type_rand;
			resource_type res_type = resource_type(res_type_rand);

			int mining_speed = 0;

			int occupation_rand = rand() % int(players.size() * 1.5) - int(players.size() * 0.5) + 1;
			occupation_rand = occupation_rand < 0 ? 0 : occupation_rand;

			std::string occupation = occupation_rand <= 0 ? "0" : players[occupation_rand - 1].ID();

			float influence = 0;
			int tower_level = 0;

			pads.push_back(Tile(lend_type, passability, res_type, mining_speed, occupation, influence, tower_level));
		}
	}
	void print()
	{
		std::cout << '\n' << "Print map:" << '\n';
		for (auto& element : pads)
		{
			std::cout << int(element.LendType()) << " ";
		}
		std::cout << '\n';
	}

	std::vector<int> PlayerPads(std::string player_ID);
	std::vector<std::string> FractionPlayers(std::string fraction_ID);
private:
	const size_t col;
	const size_t row;
	std::vector<Tile> pads;
	std::vector<Player>& players;
	std::vector<Fraction>& fractions;

	//количество клеток каждого типа

};

