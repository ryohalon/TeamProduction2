#pragma once
#include "../../../Share/Share.h"
#include "../../../Classbase.h"
#include "../../../Unit/Job/Lancer.h"
#include "../../../Unit/Job/Warrior.h"
#include "../../../Unit/Unitplayer.h"

class Unitselect : public Classbase{

private:
	Font font = Font("res/meiryo.ttc");
	Texture pop_tex = Texture("res/Texture/CharaPon.png");
	int font_size = 50;

	std::list<Unitplayer*>& p_list_;

	
	std::list<Vec2f> pos;

	LancerP lancer;
	WarriorP warrior;

	int select_job;
	bool player_or_enemy = true;
	int num;
	int count = 1;
	bool pop_animation = false;
	Vec2f pop_offset_pos = Vec2f::Zero();
	int animation_time = 0;
	Color selectjob_color[static_cast<int>(Job::JOB_MAX)];

	void SelectJob();
	void ShiftJob();

	void JobDraw();
	void PopAnimation();
	void UiDraw();
	
	void StatusDraw();
public:

	Unitselect(std::list<Unitplayer*>& p_list);


	void Setup();
	void Update();
	void Draw();
	Scenename Shift();


};