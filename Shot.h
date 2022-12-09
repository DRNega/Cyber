#pragma once

#include "Vec2.h"

class SceneMain;

// 敵基底クラス
class Shot
{
public:
    Shot();
    virtual ~Shot() {}

    virtual void init();
    virtual void setHandle(int handle);
    virtual void setPos(float x, float y);
    virtual void update();    // 純粋仮想関数
    virtual void draw();

    // 当たり判定の半径取得
    virtual float getRadius() const;
    // 当たり判定の中心位置取得
    virtual Vec2 getCenter() const;

    virtual void setMain(SceneMain* pMain) { m_pMain = pMain; }

    // ほかの敵に当たった場合の反射処理
    virtual void bound(Vec2 targetPos);

private:
    //SceneMainのポインタ
    SceneMain* m_pMain;
    
    // 画像データ
    int m_handle;
    
    // 表示位置
    Vec2 m_pos;        // position 位置

    // プレイヤーの表示位置
    Vec2 m_psize;
    
    // 移動量
    Vec2 m_vec;        // vector ベクトル

    // 当たり判定の幅と高さ
    Vec2 m_colSize;

    //存在するか
    bool  m_isExist;
};

// まっすぐ移動
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

// サインカーブ移動
//class ShotSin : public Shot
//{
//public:
//    ShotSin();
//    virtual ~ShotSin() {}
//    virtual void init() override;
//    virtual void setPos(float x, float y) override;
//    virtual void update() override;
//private:
//    // サインカーブ移動用
//    Vec2 m_basePos;
//    float m_sinRate;
//};