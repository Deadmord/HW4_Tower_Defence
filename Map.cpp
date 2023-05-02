#include "Map.h"

//--------------------Map-Body----------------------


void print()
{
	std::string array[]{ "peter", "likes", "frozen", "yogurt" };

	// ��������� ������ element ������� �� �����������
	// ������� �������, ������������ �������� �����
	for (const auto& element : array)
	{
		std::cout << element << ' ';
	}
}

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
	return (row * numberOfColumnsInArray) + col;
}