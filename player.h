#pragma once

#include "Vec2.h"

class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player() {}

	// グラフィックデータ設定
	virtual void setHandle(int handle) { m_handle = handle; }

	virtual void init();

	virtual void setMain(SceneMain* pMain) { m_pMain = pMain; }

	virtual void update();

	virtual void draw();

	bool isExist() { return m_isExist; }

	//弾との当たり判定
	//bool isCol(Shot& shot);

	void playerDead();

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getUp()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }
	Vec2 getColSize() const { return m_colSize; }

	// ほかの敵に当たった場合の反射処理
	virtual void bound(Vec2 targetPos);

private:

	// グラフィックハンドル
	int m_handle;

	//ショットの発射間隔
	int m_shotInterval;

	//SceneMainのポインタ
	SceneMain* m_pMain;

	// 当たり判定の幅と高さ
	Vec2 m_colSize;

	//表示位置
	Vec2 m_pos;

	//移動
	Vec2 m_vec;

	//存在するか
	bool  m_isExist;

	// 画像サイズ
	int m_height;
	int m_width;

};
