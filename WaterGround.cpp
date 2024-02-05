#include "WaterGround.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"


//�R���X�g���N�^
WaterGround::WaterGround(GameObject* parent)
	: GameObject(parent, "WaterGround"), hModel_{ -1 }
{
}

//������
void WaterGround::Initialize()
{
	hModel_ = Model::Load("Assets//WaterGround.fbx");
	assert(hModel_ >= 0);

	Camera::SetPosition(XMVECTOR({ 0,1,-5,0 }));
	Camera::SetTarget(XMVECTOR({ 0,0,0,0 }));
}

//�X�V
void WaterGround::Update()
{
}

//�`��
void WaterGround::Draw()
{
	/*Transform TrsWaterGround;
	TrsWaterGround.position_ = XMFLOAT3(-2, 3, 2);*/

	//Model::SetTransform(hModel_, transform_);
	//Model::Draw(hModel_);
}

//�J��
void WaterGround::Release()
{
}