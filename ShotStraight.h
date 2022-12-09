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
    // 画像データ
    int m_handle;
    // 表示位置
    Vec2 m_pos;        // position 位置
    // 移動量
    Vec2 m_vec;        // vector ベクトル
};

