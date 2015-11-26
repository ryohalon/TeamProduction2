#pragma once 
#include "../../Share/Share.h"
#include "../Unitplayer.h"
#include "../Unitenemy.h"

class LancerP : public Unitplayer{
private:


public:
	

	LancerP(int number = 0){
		status = new Status(70,70,0,10,0);
		unitlist = new Unitlist(number,Vec2i((int)pos.x(),(int)pos.y()));
		color = Color::blue;
	};

	Status GetLancerStatus(){
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

class LancerE : public Unitenemy{
private:


public:


	LancerE(int number = 0){
		status = new Status(70, 70, 0, 10, 0);
		unitlist = new Unitlist(number, Vec2i((int)pos.x(), (int)pos.y()));
		color = Color::cyan;
	};

	Status GetLancerStatus(){
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
