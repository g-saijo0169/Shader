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
	hModel_ = Model::Load("Assets//Ball3.fbx");
	assert(hModel_ >= 0);

	transform_.position_.y = 0.0f;
	transform_.position_.z = 0.0f;
}

//�X�V
void Ball::Update()
{
	transform_.rotate_.y += 5.0f;
	
}

//�`��
void Ball::Draw()
{
	/*Transform TrsBall;
	TrsBall.position_ = XMFLOAT3(-2, 3, 2);*/
	
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Ball::Release()
{
}