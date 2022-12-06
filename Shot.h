#pragma once

#include "Vec2.h"

// 敵基底クラス
class Shot
{
public:
    Shot();
    virtual ~Shot() {}

    virtual void init();
    virtual void setHandle(int handle);
    virtual void setPos(float x, float y);
    virtual void update() = 0;    // 純粋仮想関数
    virtual void draw();

    // 当たり判定の半径取得
    virtual float getRadius() const;
    // 当たり判定の中心位置取得
    virtual Vec2 getCenter() const;

    // ほかの敵に当たった場合の反射処理
    virtual void bound(Vec2 targetPos);

protected:
    // 画像データ
    int m_handle;
    // 表示位置
    Vec2 m_pos;        // position 位置
    // 移動量
    Vec2 m_vec;        // vector ベクトル
};

// まっすぐ移動
class ShotStraight : public Shot
{
public:
    ShotStraight();
    virtual ~ShotStraight() {}

    virtual void init() override;
    virtual void update() override;
private:

};

// サインカーブ移動
class ShotSin : public Shot
{
public:
    ShotSin();
    virtual ~ShotSin() {}
    virtual void init() override;
    virtual void setPos(float x, float y) override;
    virtual void update() override;
private:
    // サインカーブ移動用
    Vec2 m_basePos;
    float m_sinRate;
};