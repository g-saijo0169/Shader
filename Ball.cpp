#include "Ball.h"
#include "Engine/Model.h"


//�R���X�g���N�^
Ball::Ball(GameObject* parent)
	: GameObject(parent, "Ball"), hModel_{-1}
{
}

//������
void Ball::Initialize()
{
	hModel_ = Model::Load("Assets/Ball.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Ball::Update()
{
	transform_.rotate_.y += 2.0f;
}

//�`��
void Ball::Draw()
{
	Transform TrsBall;
	TrsBall.position_ = XMFLOAT3(0, 1, 0);
	Model::SetTransform(hModel_, TrsBall);
	Model::Draw(hModel_);
}

//�J��
void Ball::Release()
{
}