#pragma once
#include "SceneBase.h"
#include "player.h"
#include "Shot.h"
#include <vector>

class Enemy;

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
		m_hitEnemyCount = 0;
		m_hitObjectCount = 0;
		m_hitEnemyCount = 0;
		m_hitObjectCount = 0;
		//m_hObjectGrahic = -1;

		m_hPlayerGraghic = -1;
		m_hEnemyGraghic = -1;
		//m_hObjectGrahic = -1;
		//m_pShot = nullptr;
	}
	virtual ~SceneMain() {}


	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;

	virtual void draw();

	//	virtual bool isEnd() { return m_isEnd; }
private:

	int m_hitEnemyCount; //敵に弾が当たった時のカウント
	int m_hitObjectCount; //オブジェクトに弾が当たった時のカウント

	static constexpr int kShotNum = 1;

	//プレイヤーグラフィックハンドル
	int m_hPlayerGraghic;
	int m_hEnemyGraghic;
	int m_hShotGraghic;
	int m_hBackgroundGraphic;

	//プレイヤー
	Player m_player;
	Shot m_shot[kShotNum];

	//std::vector<Object*> m_pObjectVt;
	std::vector<Player*> m_pPlayerVt;
	std::vector<Enemy*>  m_pEnemyVt;
	//std::vector<Shot*>  m_pShotVt;
};

//#pragma once
//
//#include "player.h"
//#include "Enemy.h"
//
//class SceneMain
//{
//public:
//	SceneMain();
//	virtual ~SceneMain();
//
//	// 初期化
//	void init();
//	// 終了処理
//	void end();
//
//	// 毎フレームの処理
//	void update();
//	// 毎フレームの描画
//	void draw();
//	// 当たり判定チェック処理
//	void checkCollision();
//
//	
//
//	// 敵の生成
//	void createEnemy();
//
//	virtual bool isGameEnd() { return m_isGameEnd; }
//	virtual bool isEnd() { return m_isEnd; }
//
//private:
//		// 敵の最大出現数
//	static constexpr int kEnemyMax = 5;
//
//private:
//	// 背景のグラフィックハンドル
//	int m_hBackgroundGraphic;
//
//	// プレイヤーのグラフィックハンドル
//	int m_hPlayerGraphic;
//	int m_hPlayerDeadGraphic;
//
//	// 弾のグラフィックハンドル
//	int m_hShotGraphic;
//
//	// 敵のグラフィックハンドル
//	int m_hEnemyGraphic;
//
//	// フォントサイズ
//	int m_fontSize;
//
//	// ゲームの制限時間
//	int m_gameTimeRemaining;
//	// ゲームオーバー時の遅延時間
//	int m_GameOverDelay;
//
//	// プレイヤー
//	Player m_player;
//
//	// 敵
//	Enemy m_Enemy;
//
//	// ゲーム終了
//	bool m_isGameEnd;
//	bool m_isEnd;
//};