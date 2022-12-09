#include "DxLib.h"
#include "Shot.h"
#include "player.h"
#include "game.h"
#include <cmath>

namespace
{
    // 弾の速度
    constexpr float kSpeed = 10.0f;

    // 当たり判定の半径
    constexpr float kColRadius = 8.0f;
}

Shot::Shot()
{
    m_handle = -1;
}

void Shot::init()
{
    m_pos.x = Game::kScreenWidth / 2;
    m_pos.y = Game::kScreenHeight - 150.0f;
    m_psize.x = 80.0f;
    m_psize.y = 25.0f;



    // 初期速度を設定
    m_vec.x = 4.0f;
    m_vec.y = 4.0f;
    m_isExist = true;
}

void Shot::setHandle(int handle)
{
    m_handle = handle;
}

void Shot::setPos(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
}

void Shot::update()
{
    m_pos += m_vec;
    if (m_pos.x < 0.0f)
    {
        m_pos.x = 0.0f;
        m_vec.x *= -1.0f;
    }
    if (m_pos.x > Game::kScreenWidth)
    {
        m_pos.x = Game::kScreenWidth;
        m_vec.x *= -1.0f;
    }
    if (m_pos.y < 0.0f)
    {
        m_pos.y = 0.0f;
        m_vec.y *= -1.0f;
    }
    if (m_pos.y > Game::kScreenHeight)
    {
        m_pos.y = Game::kScreenHeight;
        m_vec.y *= -1.0f;
    }
    else if (m_pos.y > Game::kScreenHeight - 100)
    {
        m_pos.y = Game::kScreenHeight - 100;
        m_vec.y *= -1.0f;
    }
}

void Shot::draw()
{
    DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
    DrawCircle(getCenter().x, getCenter().y, getRadius(), GetColor(255, 255, 0), true);
}

float Shot::getRadius() const
{
    return kColRadius;
}

Vec2 Shot::getCenter() const
{
    int sizeX = 0;
    int sizeY = 0;
    if (GetGraphSize(m_handle, &sizeX, &sizeY) == -1)
    {
        // サイズが取得できなかった場合は左上位置を渡しておく
        return m_pos;
    }
    Vec2 result = m_pos;
    result.x += sizeX / 2;
    result.y += sizeY / 2;

    return result;
}

void Shot::bound(Vec2 targetPos)
{
    // 反射方向
    Vec2 boundDir = m_pos - targetPos;
    // 現在の速度と同じ速度にする
    float speed = m_vec.length();

    // 反射方向に現在の速度で移動するようにする
    m_vec = boundDir.normalize() * speed;
}

//ShotStraight::ShotStraight()
//{
//
//}
//
//void ShotStraight::init()
//{
//    // 初期速度を設定
//    m_vec.x = 4.0f;
//    m_vec.y = 4.0f;
//}
//
//void ShotStraight::update()
//{
//}

//void ShotStraight::update()
//{
//    m_pos += m_vec;
//    if (m_pos.x < 0.0f)
//    {
//        m_pos.x = 0.0f;
//        m_vec.x *= -1.0f;
//    }
//    if (m_pos.x > Game::kScreenWidth)
//    {
//        m_pos.x = Game::kScreenWidth;
//        m_vec.x *= -1.0f;
//    }
//    if (m_pos.y < 0.0f)
//    {
//        m_pos.y = 0.0f;
//        m_vec.y *= -1.0f;
//    }
//    if (m_pos.y > Game::kScreenHeight)
//    {
//        m_pos.y = Game::kScreenHeight;
//        m_vec.y *= -1.0f;
//    }
//}

//ShotSin::ShotSin()
//{
//    m_sinRate = 0.0f;
//}
//
//void ShotSin::init()
//{
//    // 初期速度を設定
//    m_vec.x = 1.0f;
//    m_vec.y = 0.0f;
//}
//
//void ShotSin::setPos(float x, float y)
//{
//    Shot::setPos(x, y);
//    m_basePos = m_pos;
//}
//
//void ShotSin::update()
//{
//    m_basePos += m_vec;
//    m_sinRate += 0.05f;
//
//    m_pos = m_basePos;
//    m_pos.y += sinf(m_sinRate) * 128.0f;
//}