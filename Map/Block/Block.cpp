#include "Block.h"

Block::Block()
{

}

const Maptype Block::Getmaptype()
{
	return map_type;
}

const void Block::Setmaptype(int map_type)
{
	this->map_type = static_cast<Maptype>(map_type);
}

void Block::Setup()
{

}

void Block::Update()
{

}

void Block::Draw()
{

}