#include <iostream>
#include <string>
#include <vector>
#include <utility> // for std::move

#include "Map.h"

//----------------------Main-------------------------
int main()
{
    Fraction left;
    left.ChangeName("Left");
    Fraction midle = { "Midle" };
    Fraction right("Right");
    
    std::cout << left.ID() << " " << left.Name() << '\n';
    std::cout << midle.ID() << " " << midle.Name() << '\n';
    std::cout << right.ID() << " " << right.Name() << '\n';
    std::cout << '\n';

    Player Player_A(left.ID());
    Player_A.ChangeName("Player_A");
    Player Player_B(right.ID(), "Player_B");

    std::cout << Player_A.ID() << " " << Player_A.Name() << " " << Player_A.Fraction() << '\n';
    std::cout << Player_B.ID() << " " << Player_B.Name() << " " << Player_B.Fraction() << '\n';
    std::cout << '\n';

    Tile Tile00;
    Tile Tile01(tile_type::swamp, 0.25, resource_type::iron, 5, "2", 0.75, 7);
    Tile Tile02(Tile01);
    Tile Tile03(std::move(Tile(tile_type::hill, 0.5, resource_type::gold, 2, "1", 0.33, 9)));


    std::cout << (int)Tile00.LendType() << " " << Tile00.Passability() << " " << (int)Tile00.Resource() << " " << Tile00.MiningSpeed() << " " << Tile00.Occupation() << " " << Tile00.Influence() << " " << Tile00.TowerLevel() << '\n';
    std::cout << (int)Tile01.LendType() << " " << Tile01.Passability() << " " << (int)Tile01.Resource() << " " << Tile01.MiningSpeed() << " " << Tile01.Occupation() << " " << Tile01.Influence() << " " << Tile01.TowerLevel() << '\n';
    std::cout << (int)Tile02.LendType() << " " << Tile02.Passability() << " " << (int)Tile02.Resource() << " " << Tile02.MiningSpeed() << " " << Tile02.Occupation() << " " << Tile02.Influence() << " " << Tile02.TowerLevel() << '\n';
    std::cout << (int)Tile03.LendType() << " " << Tile03.Passability() << " " << (int)Tile03.Resource() << " " << Tile03.MiningSpeed() << " " << Tile03.Occupation() << " " << Tile03.Influence() << " " << Tile03.TowerLevel() << '\n';

    std::vector<Player> players { Player_A, Player_B };
    std::vector<Fraction> fractions { left, midle, right };
    Map Map(6,5, players, fractions);
    Map.init();
    Map.print();

    std::cout << " __    __    __    __  \n";
    std::cout << "/  \\__/  \\__/  \\__/  \\ \n";
    std::cout << "\\__/  \\__/  \\__/  \\__/ \n";
    std::cout << "/  \\__/  \\__/  \\__/  \\ \n";
    std::cout << "\\__/  \\__/  \\__/  \\__/ \n";
    std::cout << "/  \\__/  \\__/  \\__/  \\ \n";
    std::cout << "\\__/  \\__/  \\__/  \\__/ \n";
    std::cout << "/  \\__/  \\__/  \\__/  \\ \n";
    std::cout << "\\__/  \\__/  \\__/  \\__/ \n";
}

