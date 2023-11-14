#include "Stage.h"



//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    //モデルデータのロード
  /*  hPict_ = Sprite::Load("Assets/画像1.jpg");
    assert(hPict_ >= 0);*/
    pSprite = new Sprite;
    pSprite->Initialize();
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
    pSprite->Draw(transform_);
   /* Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);*/
}

//開放
void Stage::Release()
{
}