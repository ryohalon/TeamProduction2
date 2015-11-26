#include "Unitselect.h"

Unitselect::Unitselect(std::list<Unitplayer*>& p_list) :
p_list_(p_list)
{
	select_job = 0;
	font.size(font_size);


}


void Unitselect::Setup(){




}

void Unitselect::Update(){
	SelectJob();
	ShiftJob();


}

void Unitselect::Draw(){

	for (auto itr = p_list_.begin(); itr != p_list_.end(); ++itr)
	{
		(*itr)->Draw();
	}


	JobDraw();
	UiDraw();
	StatusDraw();
	PopAnimation();


}

Scenename Unitselect::Shift(){
	if (env.isPushKey('A')){
		return Scenename::GAMEMAIN;
	}
	return Scenename::UNITSELECT;
	env.flushInput();
}


void Unitselect::SelectJob(){

	if (count <= 5)
		switch (select_job)
	{
		case static_cast<int> (Job::WARRIOR) :
			if (env.isPushKey(GLFW_KEY_ENTER))
			{
				pop_animation = true;
				animation_time = 0;
				p_list_.push_back(new WarriorP(count));
				count++;
				for (auto itr = p_list_.begin(); itr != --p_list_.end(); ++itr)
				{
					(*itr)->SetSelectPos(Vec2f(200, 0));
					num = (*itr)->GetNum();
				}
			}
											 break;
		case static_cast<int> (Job::LANCER) :

			if (env.isPushKey(GLFW_KEY_ENTER))
			{
				pop_animation = true;
				animation_time = 0;
				p_list_.push_back(new LancerP(count));
				count++;
				for (auto itr = p_list_.begin(); itr != --p_list_.end(); ++itr)
				{
					(*itr)->SetSelectPos(Vec2f(200, 0));
					num = (*itr)->GetNum();

				}
			}
											break;
		case static_cast<int> (Job::JOB_MAX) :
			// playerとenemyを反転する
			if (env.isPushKey(GLFW_KEY_ENTER))
			{
				player_or_enemy = !!!!!!!!!!!!!!!!!!!!!!!!!!!player_or_enemy;
			}
											 break;
	}
}

void Unitselect::ShiftJob(){
	if (env.isPushKey(GLFW_KEY_LEFT))
	{
		if (select_job < static_cast<int>(Job::JOB_MAX))
		{
			select_job++;
		}
	}
	if (env.isPushKey(GLFW_KEY_RIGHT))
	{
		if (select_job > 0)
		{
			select_job--;
		}
	}
}

void Unitselect::JobDraw(){
	drawFillBox((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::WARRIOR), HEIGHT / 4, 100, 200,
				selectjob_color[static_cast<int>(Job::WARRIOR)]);

	drawFillBox((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::LANCER), HEIGHT / 4, 100, 200,
				selectjob_color[static_cast<int>(Job::LANCER)]);
}

void Unitselect::PopAnimation(){
	Vec2f animation_pos;
	if (pop_animation == true)
	{
		for (auto itr = p_list_.begin(); itr != p_list_.end(); ++itr)
		{
			animation_pos = Vec2f(-100, -50) + (*itr)->GetSelectPos();
		}
		drawAnimation(animation_pos, Vec2f(300, 300), pop_offset_pos, Vec2f(256, 256), pop_tex, 30, 5, 0, animation_time);
		if (animation_time > 29 * 5)
		{
			animation_time = 0;
			pop_animation = false;
		}
	}
}

void Unitselect::UiDraw(){
	Vec2f warrior_draw_pos = Vec2f((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::WARRIOR),
								   HEIGHT / 4);
	Vec2f lancer_draw_pos = Vec2f((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::LANCER),
								  HEIGHT / 4);
	Vec2f select_job_pos = Vec2f(-100, 300);

	selectjob_color[static_cast<int>(Job::WARRIOR)] = warrior.GetColor();
	selectjob_color[static_cast<int>(Job::LANCER)] = lancer.GetColor();

	if (select_job == static_cast<int>(Job::WARRIOR))
	{
		SelectTriangle(Vec2f(warrior_draw_pos.x() + 50, warrior_draw_pos.y() + 220));
	}
	if (select_job == static_cast<int>(Job::LANCER))
	{
		SelectTriangle(Vec2f(lancer_draw_pos.x() + 50, lancer_draw_pos.y() + 220));
	}
	if (select_job == static_cast<int>(Job::JOB_MAX)){
		SelectTriangle(Vec2f(select_job_pos.x() + 200, select_job_pos.y() + 50));
	}

	font.draw("ウォーリアー", Vec2f(warrior_draw_pos.x() - 50, warrior_draw_pos.y() - 100),
			  Color::white);

	font.draw("ランサー", Vec2f(lancer_draw_pos.x() - 50, lancer_draw_pos.y() - 100),
			  Color::white);

	if (player_or_enemy)
	{
		font.draw("プレイヤーセレクト", Vec2f(select_job_pos.x(), select_job_pos.y()),
				  Color::white);
	}
	else
	{
		font.draw("エネミーセレクト", Vec2f(select_job_pos.x(), select_job_pos.y()),
				  Color::white);
	}
}

void Unitselect::StatusDraw(){
	Status status;

	if (select_job == static_cast<int>(Job::WARRIOR)){
		status.hp = warrior.GetWarriorStatus().hp;
		status.power = warrior.GetWarriorStatus().power;
		status.magic_power = warrior.GetWarriorStatus().magic_power;
		status.defense = warrior.GetWarriorStatus().defense;
		status.magic_defense = warrior.GetWarriorStatus().magic_defense;
	}
	if (select_job == static_cast<int>(Job::LANCER)){
		status.hp = lancer.GetLancerStatus().hp;
		status.power = lancer.GetLancerStatus().power;
		status.magic_power = lancer.GetLancerStatus().magic_power;
		status.defense = lancer.GetLancerStatus().defense;
		status.magic_defense = lancer.GetLancerStatus().magic_defense;
	}

	font.draw("体力　　　　" + std::to_string(status.hp),
			  Vec2f(-WIDTH / 3, 200 - font_size), Color::white);

	font.draw("攻撃力　　　" + std::to_string(status.power),
			  Vec2f(-WIDTH / 3, 200 - font_size * 2), Color::white);

	font.draw("魔法攻撃力　" + std::to_string(status.magic_power),
			  Vec2f(-WIDTH / 3, 200 - font_size * 3), Color::white);

	font.draw("防御力　　　" + std::to_string(status.defense),
			  Vec2f(-WIDTH / 3, 200 - font_size * 4), Color::white);

	font.draw("魔法防御力　" + std::to_string(status.magic_defense),
			  Vec2f(-WIDTH / 3, 200 - font_size * 5), Color::white);
}