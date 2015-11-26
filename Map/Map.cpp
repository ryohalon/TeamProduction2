#include "Map.h"

void Map::MapDelete()
{
	chip_block.clear();
}

Map::Map()
{
	Setup(1, Vec2i(10, 10));
}

void Map::Setplayerlist(Unitlist player_list)
{
	this->player_list.push_back(player_list);
}
void Map::Setenemylist(Unitlist enemy_list)
{
	this->enemy_list.push_back(enemy_list);
}
void Map::Sethitrange(int hit_range)
{
	this->hit_range = hit_range;
}

bool Map::Isunitmoving(int unit_num, Direction direction)
{
	//player_unitÇÃà⁄ìÆîªíË
	if (unit_num < static_cast<int>(player_list.size()))
	{
		for (auto player : player_list)
		{
			if (player.num == unit_num)
			{
				if (player.pos.x() < 0 ||
					player.pos.x() > static_cast<int>(chip_block.size()) ||
					player.pos.y() < 0 ||
					player.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;


				switch (direction)
				{
				case Direction::NORTH:
					for (auto enemy : enemy_list)
					{
						if (player.pos.x() == enemy.pos.x() &&
							player.pos.y() - 1 == enemy.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (player.pos == player_unit.pos)
							continue;

						if (player.pos.x() == player_unit.pos.x() &&
							player.pos.y() - 1 == player_unit.pos.y())
							return false;
					}

					if (chip_block[player.pos.y() - 1][player.pos.x()].Getmaptype() == Maptype::LOAD)
					{
						player.pos.y()--;

						return true;
					}
					else
						return false;
					break;

				case Direction::SOUTH:
					for (auto enemy : enemy_list)
					{
						if (player.pos.x() == enemy.pos.x() &&
							player.pos.y() + 1 == enemy.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (player.pos == player_unit.pos)
							continue;

						if (player.pos.x() == player_unit.pos.x() &&
							player.pos.y() + 1 == player_unit.pos.y())
							return false;
					}

					if (chip_block[player.pos.y() + 1][player.pos.x()].Getmaptype() == Maptype::LOAD)
					{
						player.pos.y()++;

						return true;
					}
					else
						return false;
					break;

				case Direction::WEST:
					for (auto enemy : enemy_list)
					{
						if (player.pos.x() - 1 == enemy.pos.x() &&
							player.pos.y() == enemy.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (player.pos == player_unit.pos)
							continue;

						if (player.pos.x() - 1 == player_unit.pos.x() &&
							player.pos.y() == player_unit.pos.y())
							return false;
					}

					if (chip_block[player.pos.y()][player.pos.x() - 1].Getmaptype() == Maptype::LOAD)
					{
						player.pos.x()--;

						return true;
					}
					else
						return false;
					break;

				case Direction::EAST:
					for (auto enemy : enemy_list)
					{
						if (player.pos.x() + 1 == enemy.pos.x() &&
							player.pos.y() == enemy.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (player.pos == player_unit.pos)
							continue;

						if (player.pos.x() + 1 == player_unit.pos.x() &&
							player.pos.y() == player_unit.pos.y())
							return false;
					}

					if (chip_block[player.pos.y()][player.pos.x() + 1].Getmaptype() == Maptype::LOAD)
					{
						player.pos.x()++;

						return true;
					}
					else
						return false;
					break;
				}
			}
		}
	}

	//enemy_unitÇÃà⁄ìÆîªíË
	if (unit_num < static_cast<int>(enemy_list.size()))
	{
		for (auto enemy : enemy_list)
		{
			if (enemy.num == unit_num)
			{
				if (enemy.pos.x() < 0 ||
					enemy.pos.x() > static_cast<int>(chip_block.size()) ||
					enemy.pos.y() < 0 ||
					enemy.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;


				switch (direction)
				{
				case Direction::NORTH:
					for (auto enemy_unit : enemy_list)
					{
						if (enemy.pos == enemy_unit.pos)
							continue;

						if (enemy.pos.x() == enemy_unit.pos.x() &&
							enemy.pos.y() - 1 == enemy_unit.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (enemy.pos.x() == player_unit.pos.x() &&
							enemy.pos.y() - 1 == player_unit.pos.y())
							return false;
					}

					if (chip_block[enemy.pos.y() - 1][enemy.pos.x()].Getmaptype() == Maptype::LOAD)
					{
						enemy.pos.y()--;

						return true;
					}
					else
						return false;
					break;

				case Direction::SOUTH:
					for (auto enemy_unit : enemy_list)
					{
						if (enemy.pos == enemy_unit.pos)
							continue;

						if (enemy.pos.x() == enemy_unit.pos.x() &&
							enemy.pos.y() + 1 == enemy_unit.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (enemy.pos.x() == player_unit.pos.x() &&
							enemy.pos.y() + 1 == player_unit.pos.y())
							return false;
					}

					if (chip_block[enemy.pos.y() + 1][enemy.pos.x()].Getmaptype() == Maptype::LOAD)
					{
						enemy.pos.y()++;

						return true;
					}
					else
						return false;
					break;

				case Direction::WEST:
					for (auto enemy_unit : enemy_list)
					{
						if (enemy.pos == enemy_unit.pos)
							continue;

						if (enemy.pos.x() - 1 == enemy_unit.pos.x() &&
							enemy.pos.y() == enemy_unit.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (enemy.pos.x() - 1 == player_unit.pos.x() &&
							enemy.pos.y() == player_unit.pos.y())
							return false;
					}

					if (chip_block[enemy.pos.y()][enemy.pos.x() - 1].Getmaptype() == Maptype::LOAD)
					{
						enemy.pos.x()--;

						return true;
					}
					else
						return false;
					break;

				case Direction::EAST:
					for (auto enemy_unit : enemy_list)
					{
						if (enemy.pos == enemy_unit.pos)
							continue;

						if (enemy.pos.x() + 1 == enemy_unit.pos.x() &&
							enemy.pos.y() == enemy_unit.pos.y())
							return false;
					}

					for (auto player_unit : player_list)
					{
						if (enemy.pos.x() + 1 == player_unit.pos.x() &&
							enemy.pos.y() == player_unit.pos.y())
							return false;
					}

					if (chip_block[enemy.pos.y()][enemy.pos.x() + 1].Getmaptype() == Maptype::LOAD)
					{
						enemy.pos.x()++;

						return true;
					}
					else
						return false;
					break;
				}
			}
		}
	}

	return false;
}

bool Map::Isattackhit(int unit_num, Direction direction)
{
	//player_unitÇÃçUåÇîªíË
	if (unit_num < static_cast<int>(player_list.size()))
	{
		for (auto player : player_list)
		{
			if (player.num == unit_num)
			{
				if (player.pos.x() < 0 ||
					player.pos.x() > static_cast<int>(chip_block.size()) ||
					player.pos.y() < 0 ||
					player.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;

				for (auto enemy : enemy_list)
				{
					switch (direction)
					{
					case Direction::NORTH:
						if (player.pos.x() == enemy.pos.x() &&
							player.pos.y() - 1 == enemy.pos.y())
							return true;
						break;

					case Direction::SOUTH:
						if (player.pos.x() == enemy.pos.x() &&
							player.pos.y() + 1 == enemy.pos.y())
							return true;
						break;

					case Direction::WEST:
						if (player.pos.x() - 1 == enemy.pos.x() &&
							player.pos.y() == enemy.pos.y())
							return true;
						break;

					case Direction::EAST:
						if (player.pos.x() + 1 == enemy.pos.x() &&
							player.pos.y() == enemy.pos.y())
							return true;
						break;
					}
				}
			}
		}

		return false;
	}

	//enemy_unitÇÃçUåÇîªíË
	if (unit_num < static_cast<int>(enemy_list.size()))
	{
		for (auto enemy : enemy_list)
		{
			if (enemy.num == unit_num)
			{
				if (enemy.pos.x() < 0 ||
					enemy.pos.x() > static_cast<int>(chip_block.size()) ||
					enemy.pos.y() < 0 ||
					enemy.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;

				for (auto player : player_list)
				{
					switch (direction)
					{
					case Direction::NORTH:
						if (enemy.pos.x() == player.pos.x() &&
							enemy.pos.y() - 1 == player.pos.y())
							return true;
						break;

					case Direction::SOUTH:
						if (enemy.pos.x() == player.pos.x() &&
							enemy.pos.y() + 1 == player.pos.y())
							return true;
						break;

					case Direction::WEST:
						if (enemy.pos.x() - 1 == player.pos.x() &&
							enemy.pos.y() == player.pos.y())
							return true;
						break;

					case Direction::EAST:
						if (enemy.pos.x() + 1 == player.pos.x() &&
							enemy.pos.y() == player.pos.y())
							return true;
						break;
					}
				}

				return false;
			}
		}
	}

	return false;
}

int Map::Ismagichit(int unit_num, Vec2i cursol_pos)
{
	int cost;

	if (unit_num < static_cast<int>(player_list.size()))
	{
		for (auto player : player_list)
		{
			if (player.pos != cursol_pos)
				continue;

			for (int y = 0; y < static_cast<int>(chip_block.size()); y++)
			{
				for (int x = 0; x < static_cast<int>(chip_block[y].size()); x++)
				{
					cost = (player.pos.x() - cursol_pos.x()) + (player.pos.y() - cursol_pos.y());

					if (cost > hit_range)
						return false;

					for (auto p_unit : player_list)
					{
						if (p_unit.pos == player.pos)
							continue;

						if (p_unit.pos == cursol_pos)
							return p_unit.num;
					}

					for (auto e_unit : enemy_list)
					{
						if (e_unit.pos == cursol_pos)
							return e_unit.num;
					}
				}
			}

			return false;
		}

		return false;
	}

	if (unit_num < static_cast<int>(enemy_list.size()))
	{
		for (auto enemy : enemy_list)
		{
			if (enemy.pos != cursol_pos)
				continue;

			for (int y = 0; y < static_cast<int>(chip_block.size()); y++)
			{
				for (int x = 0; x < static_cast<int>(chip_block[y].size()); x++)
				{
					cost = (enemy.pos.x() - cursol_pos.x()) + (enemy.pos.y() - cursol_pos.y());

					if (cost > hit_range)
						return false;

					for (auto p_unit : player_list)
					{
						if (p_unit.pos == cursol_pos)
							return p_unit.num;
					}

					for (auto e_unit : enemy_list)
					{
						if (e_unit.pos == cursol_pos)
							continue;

						if (e_unit.pos == cursol_pos)
							return e_unit.num;
					}
				}
			}

			return false;
		}
	}

	return false;
}

std::vector<std::vector<int>> Map::GetChipType(){

	for (int y = 0; y < chip_block.size(); y++)
	{
		for (int x = 0; x < chip_block[y].size(); x++)
		{
			chip_data[y][x] = chip_block[y][x].Getmaptype();
		}
	}

	return chip_data;
}


void Map::Setup(int stage, Vec2i map_num)
{
	chip_block = std::vector<std::vector<Block>>(map_num.y(), std::vector<Block>(map_num.x()));
	chip_data = std::vector<std::vector<int>>(map_num.y(), std::vector<int>(map_num.x()));
	hit_range = 0;

	std::string file_name = "res/map_file/stage(" + std::to_string(stage) + ").txt";
	std::ifstream* map_file = new std::ifstream(file_name);

	if (map_file->fail())
	{
		std::cerr << "err" << std::endl;

		exit(0);
	}

	int map_type;

	for (int y = 0; y < map_num.y(); y++)
	{
		for (int x = 0; x < map_num.x(); x++)
		{
			*map_file >> map_type;

			chip_block[y][x].Setmaptype(map_type);
		}
	}

	delete map_file;
}

void Map::Update()
{

}

void Map::Draw()

{
	for (int y = 0; y < static_cast<int>(chip_block.size()); y++)
	{
		for (int x = 0; x < static_cast<int>(chip_block[y].size()); x++)
		{
			switch (chip_block[y][x].Getmaptype())
			{
			case Maptype::LOAD:
				drawFillBox(x*CHIPSIZE_X, y* CHIPSIZE_Y, CHIPSIZE_X - 1, CHIPSIZE_Y - 1, Color::green);
				break;

			case Maptype::NONE:
				break;
			}
		}
	}
}

void Map::Drawcursolpos(Vec2i pos)
{
	for (int y = 0; y < static_cast<int>(chip_block.size()); y++)
	{
		if (y != pos.y())
			continue;

		for (int x = 0; x < static_cast<int>(chip_block[y].size()); x++)
		{
			if (x != pos.x())
				continue;

			drawBox(x * CHIPSIZE_X, y * CHIPSIZE_Y, CHIPSIZE_X - 1, CHIPSIZE_Y - 1, 5, Color::lime);
			return;
		}
	}
}

void Map::DrawMagicrange(int unit_num)
{
	int cost;

	if (unit_num < static_cast<int>(player_list.size()))
	{
		for (auto player : player_list)
		{
			for (int y = 0; y < static_cast<int>(chip_block.size()); y++)
			{
				for (int x = 0; x < static_cast<int>(chip_block[y].size()); x++)
				{
					cost = (player.pos.x() - x) + (player.pos.y() - y);

					if (cost > hit_range || chip_block[y][x].Getmaptype() == Maptype::NONE)
						continue;

					drawBox(x * CHIPSIZE_X, y * CHIPSIZE_Y, CHIPSIZE_X - 1, CHIPSIZE_Y - 1, 5, Color::red);
				}
			}
		}

		return;
	}

	if (unit_num < static_cast<int>(enemy_list.size()))
	{
		for (auto enemy : enemy_list)
		{
			for (int y = 0; y < static_cast<int>(chip_block.size()); y++)
			{
				for (int x = 0; x < static_cast<int>(chip_block[y].size()); x++)
				{
					cost = (enemy.pos.x() - x) + (enemy.pos.y() - y);

					if (cost > hit_range || chip_block[y][x].Getmaptype() == Maptype::NONE)
						continue;

					drawBox(x * CHIPSIZE_X, -y * CHIPSIZE_Y, CHIPSIZE_X - 1, CHIPSIZE_Y - 1, 5, Color::red);
				}
			}
		}

		return;
	}
}