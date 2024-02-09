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
	hModel_ = Model::Load("Assets//Ball3.fbx");
	assert(hModel_ >= 0);

	transform_.position_.y = 0.0f;
	transform_.position_.z = 0.0f;
}

//更新
void Ball::Update()
{
	transform_.rotate_.y += 5.0f;
	
}

//描画
void Ball::Draw()
{
	/*Transform TrsBall;
	TrsBall.position_ = XMFLOAT3(-2, 3, 2);*/
	
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Ball::Release()
{
}