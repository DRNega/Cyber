#include "ShotStraight.h"
#include "game.h"

ShotStraight::ShotStraight()
{
}

void ShotStraight::init()
{
    // èâä˙ë¨ìxÇê›íË
    m_vec.x = 4.0f;
    m_vec.y = 4.0f;
}

void ShotStraight::update()
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
}
