#pragma once
#include "DxLib.h"
#include "Vec2.h"

class ShotStraight
{
public:
    ShotStraight();
    virtual ~ShotStraight() {}



    virtual void init();
    virtual void update();
private:

protected:
    // �摜�f�[�^
    int m_handle;
    // �\���ʒu
    Vec2 m_pos;        // position �ʒu
    // �ړ���
    Vec2 m_vec;        // vector �x�N�g��
};

