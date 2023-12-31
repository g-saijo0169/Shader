#include "Ball.h"
#include "Engine/Model.h"


//コンストラクタ
Ball::Ball(GameObject* parent)
	: GameObject(parent, "Ball"), hModel_{-1}
{
}

//初期化
void Ball::Initialize()
{
	hModel_ = Model::Load("Assets/Ball.fbx");
	assert(hModel_ >= 0);
}

//更新
void Ball::Update()
{
	transform_.rotate_.y += 5.0f;
}

//描画
void Ball::Draw()
{
	//Transform TrsBall;
	//TrsBall.position_ = XMFLOAT3(-2, 3, 2);
	//Model::SetTransform(hModel_, TrsBall);
	//Model::Draw(hModel_);
}

//開放
void Ball::Release()
{
}