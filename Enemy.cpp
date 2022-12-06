#include "DxLib.h"
#include "Enemy.h"
#include "SceneMain.h"
#include "game.h"
namespace
{
	//�G�̃T�C�Y
	constexpr int kSize = 30;

}


Enemy::Enemy()
{
	m_handle = -1;
	m_waitFrame = 0;
	m_slide = 0;
	m_moveCount = 0;

	m_pMain = nullptr;
	m_isExist = false;
}

void Enemy::bound(Vec2 targetPos)
{
	// ���˕���
	Vec2 boundDir = m_pos - targetPos;
	// ���݂̑��x�Ɠ������x�ɂ���
	float speed = m_vec.length();





	// ���˕����Ɍ��݂̑��x�ňړ�����悤�ɂ���
	m_vec = boundDir.normalize() * speed;
}

void Enemy::init()
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_colSize.x = kSize;
	m_colSize.y = kSize;
	
	m_vec.y = 0;
	m_isExist = true;
	m_waitFrame = 0;
	m_slide = -1;
	m_moveCount = 0;
}

void Enemy::set(Vec2 pos)
{
	m_pos = pos;
}
void Enemy::end()
{

}
void Enemy::update()
{
	//m_waitFrame--;
	//if (m_waitFrame <= 0)
	//{
	//	m_moveCount += m_slide;
	//	if (m_slide > 0)  //�E�����̈ړ�
	//	{
	//		
	//		if (m_moveCount >= 0)
	//		{
	//			m_pos.y += 20.0f;
	//			m_slide = -1;
	//		}
	//	}
	//	if (m_slide < 0) //�������̈ړ�
	//	{
	//		
	//		if (m_moveCount <= -10)
	//		{
	//			m_pos.y += 20.0f;
	//			m_slide = 1;
	//		}
	//	}
	//}


	if (m_pos.y >= Game::kScreenHeight - 100.0f)
	{

	}
}

void Enemy::draw()
{
	//����ł���G�͕\�����Ȃ�
	if (!m_isExist) return;

	//	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_colSize.x, m_pos.y + m_colSize.y, GetColor(0, 255, 255), true);
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	//LoadGraph("data/syuriken2.jpg");
	//DrawBox(500, 50, 550, 60, 0xfff000, true);
}

//�G�ƒe�̓����蔻��
bool Enemy::isCol(Shot& shot)
{
	//���݂��Ă��Ȃ��ꍇ
	if (!m_isExist)return false;
	//if (!shot.isExist()) return false;

	////�e��ł����̂��G�̏ꍇ�����蔻����Ȃ��ɂ���
	//if (!shot.isGetShotPlayer()) return false;

	//if (shot.getLeft() > getRight()) return false;
	//if (shot.getRight() < getLeft()) return false;
	//if (shot.getUp() > getBottom())  return false;
	//if (shot.getBottom() < getUp())  return false;

	return true;
}

//�v���C���[���G�̍��W���傫���Ȃ�����Q�[�����I�������邽��
bool Enemy::isCompare(Player& player)
{
	if (player.getLeft() > getRight()) return false;
	if (player.getRight() < getLeft()) return false;
	if (player.getUp() > getBottom())  return false;
	if (player.getBottom() < getUp())  return false;

	return true;
}

void Enemy::enemyDead()
{
	m_isExist = false;
}
