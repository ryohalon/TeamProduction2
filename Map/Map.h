#pragma once
#include "Block/Block.h"


class Map
{
private:

	std::vector<std::vector<Block>> chip_block;
	std::vector<std::vector<int>> chip_data;

	std::list<Unitlist> player_list;
	std::list<Unitlist> enemy_list;
	int hit_range;

	void MapDelete();

public:

	Map();

	//for文で回してpush_back()してください
	void Setplayerlist(Unitlist);
	void Setenemylist(Unitlist);

	//範囲のある技を使う時に範囲をSetしてください
	void Sethitrange(int);

	//(行動するユニットの番号, 行動する向き)
	bool Isunitmoving(int, Direction);
	bool Isattackhit(int, Direction);

	//魔法攻撃の判定
	//魔法攻撃するユニットの番号と攻撃場所を選択した時のカーソルの位置
	//ダメージを受けるユニットの番号を返す
	//いないときはfalseを返す
	int Ismagichit(int, Vec2i);

	

	//（マップのナンバー, マップの数）
	void Setup(int, Vec2i);
	void Update();
	void Draw();

	//カーソルのマップチップでの座標を渡せば
	//今指している場所を光らせる
	void Drawcursolpos(Vec2i);

	//魔法攻撃の範囲の描写
	void DrawMagicrange(int);


	//Astarに渡す0か1の判定
	std::vector<std::vector<int>> GetChipType();
};