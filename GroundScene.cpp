#include "GroundScene.h"
#include "Arrow.h"
#include "Engine/Model.h"

//コンストラクタ
GroundScene::GroundScene(GameObject* parent)
	: GameObject(parent, "GroundScene"), hModel_{ -1 }
{
}

//初期化
void GroundScene::Initialize()
{
	hModel_ = Model::Load("Assets/torus.fbx");
	assert(hModel_ >= 0);
}

//更新
void GroundScene::Update()
{
}

//描画
void GroundScene::Draw()
{

	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

//開放
void GroundScene::Release()
{
}