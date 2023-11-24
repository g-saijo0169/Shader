#include "Arrow.h"
#include "Engine/Model.h"


//コンストラクタ
Arrow::Arrow(GameObject* parent)
	: GameObject(parent, "Arrow"), hModel_{ -1, -1, -1 }
{
}

//初期化
void Arrow::Initialize()
{
	hModel_[0] = Model::Load("Assets/Arrow.fbx");
	hModel_[1] = Model::Load("Assets/Arrow.fbx");
	hModel_[2] = Model::Load("Assets/Arrow.fbx");

	assert(hModel_[0] >= 0);
}

//更新
void Arrow::Update()
{
}

//描画
void Arrow::Draw()
{
	Transform tx,ty,tz;
	tx.rotate_ = XMFLOAT3(0, 0, 0);
	Model::SetTransform(hModel_[0],tx);
	Model::Draw(hModel_[0]);

	ty.rotate_ = XMFLOAT3(0, 0, 90);
	Model::SetTransform(hModel_[1], ty);
	Model::Draw(hModel_[1]);

	tz.rotate_ = XMFLOAT3(0, -90, 0);
	Model::SetTransform(hModel_[2], tz);
	Model::Draw(hModel_[2]);
}

//開放
void Arrow::Release()
{
}