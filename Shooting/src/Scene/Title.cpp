#include "Title.h"

// コンストラクタ
Title::Title(void)
{
}

// デストラクタ
Title::~Title(void)
{
}

// 初期化
void Title::Init(void)
{
	// ゲーム開始フラグの初期化
	StartGame = false;

	// 点滅用のタイマーの初期化
	BlinkTimer = 0;

	// PRESS ENTER表示フラグ
	ShowPressKey = true;
}

// 更新
void Title::Update(void)
{
	BlinkTimer++;

	// 30フレームごとにPRESS ENTERの表示の切り替えさせる
	if (BlinkTimer >= 30)
	{
		ShowPressKey = !ShowPressKey;

		BlinkTimer = 0;
	}

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		StartGame = true;
	}
}

// 描画
void Title::Draw(void)
{
	// タイトルのロゴ
	DrawString(180, 100, "************************", GetColor(255, 255, 255));
	DrawString(180, 130, "*    SPACE INVADER    *", GetColor(0, 255, 0));
	// サブタイトル
	DrawString(220, 220, "DEFEND THE EARTH", GetColor(255, 255, 0));
	// PRESS ENTER点滅表示
	if (ShowPressKey)
	{
		DrawString(250, 320, "PRESS ENTER", GetColor(255, 255, 255));
	}
	// 操作説明

	DrawString(200,420,"ENTER : GAME START",GetColor(255, 255, 255));

	DrawString(200,450,"ESC : EXIT",GetColor(255, 255, 255));
}

// 解放
void Title::Release(void)
{
}

// ゲーム開始判定の取得
bool Title::IsStartGame() const
{
	return StartGame;
}
