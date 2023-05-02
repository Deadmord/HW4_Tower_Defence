#include "Map.h"

//--------------------Map-Body----------------------


void print()
{
	std::string array[]{ "peter", "likes", "frozen", "yogurt" };

	// Амперсанд делает element ссылкой на фактический
	// элемент массива, предотвращая создание копии
	for (const auto& element : array)
	{
		std::cout << element << ' ';
	}
}

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
	return (row * numberOfColumnsInArray) + col;
}