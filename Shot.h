#pragma once

#include "Vec2.h"

class SceneMain;

// �G���N���X
class Shot
{
public:
    Shot();
    virtual ~Shot() {}

    virtual void init();
    virtual void setHandle(int handle);
    virtual void setPos(float x, float y);
    virtual void update();    // �������z�֐�
    virtual void draw();

    // �����蔻��̔��a�擾
    virtual float getRadius() const;
    // �����蔻��̒��S�ʒu�擾
    virtual Vec2 getCenter() const;

    virtual void setMain(SceneMain* pMain) { m_pMain = pMain; }

    // �ق��̓G�ɓ��������ꍇ�̔��ˏ���
    virtual void bound(Vec2 targetPos);

private:
    //SceneMain�̃|�C���^
    SceneMain* m_pMain;
    
    // �摜�f�[�^
    int m_handle;
    
    // �\���ʒu
    Vec2 m_pos;        // position �ʒu

    // �v���C���[�̕\���ʒu
    Vec2 m_psize;
    
    // �ړ���
    Vec2 m_vec;        // vector �x�N�g��

    // �����蔻��̕��ƍ���
    Vec2 m_colSize;

    //���݂��邩
    bool  m_isExist;
};

// �܂������ړ�
//class ShotStraight : public Shot
//{
//public:
//    ShotStraight();
//    virtual ~ShotStraight() {}
//
//    virtual void init() override;
//    virtual void update() override;
//private:
//
//};

// �T�C���J�[�u�ړ�
//class ShotSin : public Shot
//{
//public:
//    ShotSin();
//    virtual ~ShotSin() {}
//    virtual void init() override;
//    virtual void setPos(float x, float y) override;
//    virtual void update() override;
//private:
//    // �T�C���J�[�u�ړ��p
//    Vec2 m_basePos;
//    float m_sinRate;
//};