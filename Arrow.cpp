#include "Arrow.h"
#include "Engine/Model.h"

//コンストラクタ
Arrow::Arrow(GameObject* parent)
	: GameObject(parent, "Arrow"), hModel_
{
}

//初期化
void Arrow::Initialize()
{


	assert(hModel_[0] >= 0);
}

//更新
void Arrow::Update()
{
}

//描画
void Arrow::Draw()
{
	Model::SetTransform(hModel_[0]);
	Model::Draw(hModel_[0]);

}

//開放
void Arrow::Release()
{
}