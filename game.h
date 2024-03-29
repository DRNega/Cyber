#pragma once

namespace Game
{
	// ウインドウモード設定
	constexpr bool kWindowMode = true;
	// ウインドウ名
	const char* const kTitkeText = "ゲーム名";
	// ウインドウサイズ
	constexpr int kScreenWidth = 1000;
	constexpr int kScreenHeight = 720;
	constexpr int kScreenInterval = 10;
	constexpr int kScreenWidthHalf = kScreenWidth / 2;
	constexpr int kScreenHeightHalf = kScreenHeight / 2;

	// ゲームのステージサイズ
	constexpr int kStageUpperLimit = 0;
	constexpr int kStageLowerLimit = 620;

	// カラーモード
	constexpr int kColorDepht = 32;		// 32 or 16

	// 背景画像
	const char* const kBackgroundGraph = "data/.jpg";

};