#pragma once
#include "../Share/Share.h"
struct UI{
	Vec2f pos;
	Vec2f size;
};
class Ui{
private:
	Font font = Font("res/meiryo.ttc");
	int font_size = 40;
	UI command_board;
	UI command;
	UI status_board;
	float angle;
	float animation;
	int instruction;
	bool action;
	
	

	//Get���
	int number;
	bool attack;
	bool skill;
	Vec2i player_pos;
	float cost;
public:
	Ui();
	void Update();
	void Draw(Status status);
	void BoardDraw();
	Direction OperatePlayer();
	void AttakPlayer();
	void SkillPlayer();
	void Move();
	void Animation();
	void OperateCursor();
	void Select();

	void SetDir(Direction set);
	void SetUnitNum(int set);
	void SetUnitPos(Vec2i pos);
	void SetPlayerCost(int cost);
	
	int GetUnitNum();
	bool IsAttacked();
	bool IsSkilled();
	Vec2i GetUnitPos();
	int GetPlayerCost();
};