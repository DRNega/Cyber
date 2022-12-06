#include "DxLib.h"
#include "game.h"

#include "SceneTitle.h"	
#include "SceneMain.h"
#include "game.h"

void SceneTitle::init()
{
	m_textPosX = 250;
	m_textPosY = 300;
	// �w�i�摜
	m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);

	
	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
		//m_isEnd = true;
	}

	return this;
}
void SceneTitle::draw()
{
	// �w�i�摜��ǂݍ���ŕ\��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	DrawString(m_textPosX + 350, m_textPosY, "�u���b�N����", GetColor(255, 255, 255));
	DrawString(m_textPosX + 200, m_textPosY + 30, "�L�[�{�[�h��Z�܂���PAD��A�������ăQ�[���X�^�[�g", GetColor(255, 255, 255));
}