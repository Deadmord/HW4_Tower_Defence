#pragma once
#include "Map.h"
//-------------------Helpers---------------------
int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
	return (row * numberOfColumnsInArray) + col;
}

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
template<class T>
std::string name_by_id(std::vector<T>& arr, std::string id)
{
	//if (id == "0") return "-------";
	size_t find_pos = std::find_if(arr.begin(), arr.end(), [id](T Obj) { return id == Obj.ID(); }) - arr.begin();
	if (find_pos >= arr.size()) return "Not found";
	return arr[find_pos].Name();
};

std::string name_by_id(std::vector<Fraction>& arr, std::string id)
{
	//if (id == "0") return "-------";
	size_t find_pos = std::find_if(arr.begin(), arr.end(), [id](Fraction Obj) { return id == Obj.ID(); }) - arr.begin();
	if (find_pos >= arr.size()) return "Not found";
	return arr[find_pos].Name();
};

//--------------------Map-Body----------------------

Map::Map(size_t col, size_t row, std::vector<Player>& players, std::vector<Fraction>& fractions) : col(col), row(row), players(players), fractions(fractions) {};
void Map::init()		//generate random map with concrete type, plaers, and fractions
{
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
void Map::print()
{
	std::cout << '\n' << "Print map:" << '\n';
	for (auto& element : pads)
	{
		std::cout 
			<< tile_type_name(element.LendType()) << " \t"
			<< element.Passability() << " \t"
			<< resource_type_name(element.Resource()) << " \t"
			<< element.MiningSpeed() << " \t"
			<< name_by_id(players, element.Occupation()) << " \t"
			<< element.Influence() << " \t"
			<< element.TowerLevel() << " \t"
			<< "\n";
	}
	std::cout << '\n';
}

void Map::printField() {

	for (int i(0); i < col; i++)
	{
		if (i % 2) std::cout << "  ";
		else std::cout << " __ "; 
	}
	std::cout << "\n";

	for (int j(0); j < row; j++)
	{
		for (int i(0); i < col; i++)
		{
			if (i % 2) std::cout << "__";
			else std::cout << "/  \\";
		}
		if(j) std::cout << "/";
		std::cout << "\n";

		std::cout << "\\";
		for (int i(0); i < col; i++)
		{
			if (i % 2) std::cout << "/  \\";
			else std::cout << "__";
		}
		std::cout << "\n";
	}

	std::cout << " ";
	for (int i(0); i < col; i++)
	{
		if (i % 2) std::cout << "\\__/";
		else std::cout << "  "; 
	}
	std::cout << "\n";
}



std::vector<int> Map::playerPads(std::string player_ID) 
{
	std::vector<int> res;
	
	for (int i(0); i < pads.size(); i++)
	{
		if(pads[i].Occupation() == player_ID)
			res.push_back(i);
	}
	return res;
};
std::vector<std::string> Map::fractionPlayers(std::string fraction_ID) 
{
	std::vector<std::string> res;

	for (int i(0); i < players.size(); i++)
	{
		if (players[i].Fraction() == fraction_ID)
			res.push_back(players[i].ID());
	}
	return res;
};
