#pragma once

#include "Vec2.h"

class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player() {}

	// �O���t�B�b�N�f�[�^�ݒ�
	virtual void setHandle(int handle) { m_handle = handle; }

	virtual void init();

	virtual void setMain(SceneMain* pMain) { m_pMain = pMain; }

	virtual void update();

	virtual void draw();

	bool isExist() { return m_isExist; }

	//�e�Ƃ̓����蔻��
	//bool isCol(Shot& shot);

	void playerDead();

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getUp()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// ���̎擾
	Vec2 getPos() const { return m_pos; }
	Vec2 getColSize() const { return m_colSize; }

	// �ق��̓G�ɓ��������ꍇ�̔��ˏ���
	virtual void bound(Vec2 targetPos);

private:

	// �O���t�B�b�N�n���h��
	int m_handle;

	//�V���b�g�̔��ˊԊu
	int m_shotInterval;

	//SceneMain�̃|�C���^
	SceneMain* m_pMain;

	// �����蔻��̕��ƍ���
	Vec2 m_colSize;

	//�\���ʒu
	Vec2 m_pos;

	//�ړ�
	Vec2 m_vec;

	//���݂��邩
	bool  m_isExist;

	// �摜�T�C�Y
	int m_height;
	int m_width;

};
