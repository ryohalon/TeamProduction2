#pragma once 
#include "../../Share/Share.h"
#include "../Unitplayer.h"
#include "../Unitenemy.h"

class WarriorP : public Unitplayer{
private:


public:

	WarriorP(int number = 0){
		status = new Status(100, 50, 0, 10, 0);
		unitlist = new Unitlist(number, Vec2i((int)pos.x(), (int)pos.y()));
		color = Color::red;
	}

	Status GetWarriorStatus(){
		return Status{
			status->hp,
			status->power,
			status->magic_power,
			status->defense,
			status->magic_defense,
		};
	}

	Color GetColor(){
		return color;
	}
};

class WarriorE : public Unitenemy{
private:


public:

	WarriorE(int number = 0){
		status = new Status(100, 50, 0, 10, 0);
		unitlist = new Unitlist(number, Vec2i((int)pos.x(), (int)pos.y()));
		color = Color::lime;
	}

	Status GetWarriorStatus(){
		return Status{
			status->hp,
			status->power,
			status->magic_power,
			status->defense,
			status->magic_defense,
		};
	}

	Color GetColor(){
		return color;
	}
};
