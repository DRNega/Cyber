#include "DxLib.h"

#include "Enemy.h"
#include "player.h"
#include "SceneMain.h"


#include "game.h"

#include <cassert>
#include <vector>

namespace
{
	//�G�̐�
	constexpr int kEnemyNum = 84;
}

void SceneMain::init()
{
	//�O���t�B�b�N�n���h���̃��[�h
	//m_hPlayerGraghic = LoadGraph("data/player.png");
	m_hEnemyGraghic = LoadGraph("data/brok2.png");
	//m_hPlayerShotGraghic = LoadGraph("data/playerShot.png");

	Vec2 pos;

	Player* pPlayer = new Player;
	pPlayer->init();
	//pPlayer->setHandle(m_hPlayerGraghic);
	pPlayer->setMain(this);
	m_pPlayerVt.push_back(pPlayer);

	

	//�G�̐���
	for (int i = 0; i < kEnemyNum; i++)
	{

		Enemy* pEnemy = new Enemy;
		pEnemy->init();
		pEnemy->setHandle(m_hEnemyGraghic);
		pEnemy->setMain(this);

		pos.x = static_cast<float>(i % 14) * 60.0f + 250.0f; //���܂�
		pos.y = static_cast<float>(i / 14) * 60.0f + 50.0f;

		pEnemy->set(pos);
		m_pEnemyVt.push_back(pEnemy);
		//DrawBox(500, 50, 550, 60, 0xfff000, true);
	}

	////�I�u�W�F�N�g�̐���
	//for (int i = 0; i < 4; i++)
	//{
	//	Object* pObject = new Object;
	//	pObject->init();
	//	pObject->setHandle(m_hObjectGrahic);

	//	pObject->setMain(this);

	//	pos.x = static_cast<float>(i % 5) * 150.0f + 120.0f;
	//	pos.y = 400.0f;

	//	pObject->set(pos);
	//	m_pObjectVt.push_back(pObject);
	//}
	// �w�i�摜
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
}

void SceneMain::end()
{
	//�O���t�B�b�N�A�����[�h
	DeleteGraph(m_hPlayerGraghic);
	DeleteGraph(m_hEnemyGraghic);
	DeleteGraph(m_hPlayerShotGraghic);
	
	for (auto& pPlayer : m_pPlayerVt)
	{
		assert(pPlayer);

		delete pPlayer;
		pPlayer = nullptr;
	}

	for (auto& pEnemy : m_pEnemyVt)
	{
		assert(pEnemy);

		delete pEnemy;
		pEnemy = nullptr;
	}

	
}

SceneBase* SceneMain::update()
{
	//�v���C���[
	for (auto& pPlayer : m_pPlayerVt)
	{
		assert(pPlayer);
		pPlayer->update();
	}
	//�G
	for (auto& pEnemy : m_pEnemyVt)
	{
		assert(pEnemy);
		pEnemy->update();
	}
	//�e
	

	return this;
}

//�`��
void SceneMain::draw()
{
	for (auto& pPlayer : m_pPlayerVt)
	{
		assert(pPlayer);
		pPlayer->draw();
	}

	for (auto& pEnemy : m_pEnemyVt)
	{
		assert(pEnemy);
		pEnemy->draw();
	}

	//	DrawFormatString(0, 30, GetColor(255, 255, 255), "�G�̐�:%d", m_pEnemyVt.size());

	// �w�i�摜��ǂݍ���ŕ\��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	

	DrawString(450, 10, "-----�L�[�{�[�h��X�܂���PAD��A�Œe�𔭎˂ł��܂�-----", GetColor(255, 255, 255));
}


