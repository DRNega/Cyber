#pragma once
#include "SceneBase.h"
#include "player.h"
#include "Shot.h"
#include <vector>

class Enemy;

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
		m_hitEnemyCount = 0;
		m_hitObjectCount = 0;
		m_hitEnemyCount = 0;
		m_hitObjectCount = 0;
		//m_hObjectGrahic = -1;

		m_hPlayerGraghic = -1;
		m_hEnemyGraghic = -1;
		//m_hObjectGrahic = -1;
		//m_pShot = nullptr;
	}
	virtual ~SceneMain() {}


	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;

	virtual void draw();

	//	virtual bool isEnd() { return m_isEnd; }
private:

	int m_hitEnemyCount; //�G�ɒe�������������̃J�E���g
	int m_hitObjectCount; //�I�u�W�F�N�g�ɒe�������������̃J�E���g

	static constexpr int kShotNum = 1;

	//�v���C���[�O���t�B�b�N�n���h��
	int m_hPlayerGraghic;
	int m_hEnemyGraghic;
	int m_hShotGraghic;
	int m_hBackgroundGraphic;

	//�v���C���[
	Player m_player;
	Shot m_shot[kShotNum];

	//std::vector<Object*> m_pObjectVt;
	std::vector<Player*> m_pPlayerVt;
	std::vector<Enemy*>  m_pEnemyVt;
	//std::vector<Shot*>  m_pShotVt;
};

//#pragma once
//
//#include "player.h"
//#include "Enemy.h"
//
//class SceneMain
//{
//public:
//	SceneMain();
//	virtual ~SceneMain();
//
//	// ������
//	void init();
//	// �I������
//	void end();
//
//	// ���t���[���̏���
//	void update();
//	// ���t���[���̕`��
//	void draw();
//	// �����蔻��`�F�b�N����
//	void checkCollision();
//
//	
//
//	// �G�̐���
//	void createEnemy();
//
//	virtual bool isGameEnd() { return m_isGameEnd; }
//	virtual bool isEnd() { return m_isEnd; }
//
//private:
//		// �G�̍ő�o����
//	static constexpr int kEnemyMax = 5;
//
//private:
//	// �w�i�̃O���t�B�b�N�n���h��
//	int m_hBackgroundGraphic;
//
//	// �v���C���[�̃O���t�B�b�N�n���h��
//	int m_hPlayerGraphic;
//	int m_hPlayerDeadGraphic;
//
//	// �e�̃O���t�B�b�N�n���h��
//	int m_hShotGraphic;
//
//	// �G�̃O���t�B�b�N�n���h��
//	int m_hEnemyGraphic;
//
//	// �t�H���g�T�C�Y
//	int m_fontSize;
//
//	// �Q�[���̐�������
//	int m_gameTimeRemaining;
//	// �Q�[���I�[�o�[���̒x������
//	int m_GameOverDelay;
//
//	// �v���C���[
//	Player m_player;
//
//	// �G
//	Enemy m_Enemy;
//
//	// �Q�[���I��
//	bool m_isGameEnd;
//	bool m_isEnd;
//};