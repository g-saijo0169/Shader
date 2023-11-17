#include "GroundScene.h"
#include "Engine/Model.h"

//�R���X�g���N�^
GroundScene::GroundScene(GameObject* parent)
	: GameObject(parent, "GroundScene"), hModel_{-1,-1}
{
}

//������
void GroundScene::Initialize()
{
	hModel_[0] = Model::Load("Assets/Ball.fbx");
	hModel_[1] = Model::Load("Assets/Ground.fbx");

	assert(hModel_[0] >= 0);
}

//�X�V
void GroundScene::Update()
{
}

//�`��
void GroundScene::Draw()
{
	Transform trsBall;
	trsBall.position_ = XMFLOAT3(0, 1, 0);
	Model::SetTransform(hModel_[0], trsBall);
	Model::Draw(hModel_[0]);

	Model::SetTransform(hModel_[1], transform_);
	Model::Draw(hModel_[1]);

}

//�J��
void GroundScene::Release()
{
}