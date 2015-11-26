#pragma once
#include "../../Share/Share.h"
#include "Unitselect/Unitselect.h"
#include "../../Classbase.h"
#include "../../Map/Map.h"
#include "../../UI/UI.h"
#include "../../Unit/Unitplayer.h"
#include "../../Unit/Unitenemy.h"
#include "Astar/Astar.h"
#include "../../Unit/Job/Lancer.h"
#include "../../Unit/Job/Warrior.h"


class Gamemanager : public Classbase{

private:

	//std::vector<Unitplayer> memo;

	Unitselect* unitselect_ = new Unitselect(l_player);

	Map map_;

	Ui ui_;

	std::list<Unitplayer*> l_player;
	std::list<Unitenemy*> l_enemy;
	Scenename gamechange;

	bool turn;
	int cost;
public:
	Gamemanager();

	void Setup();
	void Update();
	void Draw();
	void Shift();
	Scenename Titleshift();


};