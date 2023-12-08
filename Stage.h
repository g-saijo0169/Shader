#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"

//◆◆◆を管理するクラス
class Stage : public GameObject
{
    int hPict_;    //モデル番号
    int hGround_;
    int hLightBall_;
    Sprite* pSprite = nullptr;

public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};