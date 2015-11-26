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

	//for���ŉ񂵂�push_back()���Ă�������
	void Setplayerlist(Unitlist);
	void Setenemylist(Unitlist);

	//�͈͂̂���Z���g�����ɔ͈͂�Set���Ă�������
	void Sethitrange(int);

	//(�s�����郆�j�b�g�̔ԍ�, �s���������)
	bool Isunitmoving(int, Direction);
	bool Isattackhit(int, Direction);

	//���@�U���̔���
	//���@�U�����郆�j�b�g�̔ԍ��ƍU���ꏊ��I���������̃J�[�\���̈ʒu
	//�_���[�W���󂯂郆�j�b�g�̔ԍ���Ԃ�
	//���Ȃ��Ƃ���false��Ԃ�
	int Ismagichit(int, Vec2i);

	

	//�i�}�b�v�̃i���o�[, �}�b�v�̐��j
	void Setup(int, Vec2i);
	void Update();
	void Draw();

	//�J�[�\���̃}�b�v�`�b�v�ł̍��W��n����
	//���w���Ă���ꏊ�����点��
	void Drawcursolpos(Vec2i);

	//���@�U���͈̔͂̕`��
	void DrawMagicrange(int);


	//Astar�ɓn��0��1�̔���
	std::vector<std::vector<int>> GetChipType();
};