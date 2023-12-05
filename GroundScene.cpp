#include "GroundScene.h"
#include "Arrow.h"
#include "Engine/Model.h"

//�R���X�g���N�^
GroundScene::GroundScene(GameObject* parent)
	: GameObject(parent, "GroundScene"), hModel_{ -1 }
{
}

//������
void GroundScene::Initialize()
{
	hModel_ = Model::Load("Assets/torus.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void GroundScene::Update()
{
}

//�`��
void GroundScene::Draw()
{

	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

//�J��
void GroundScene::Release()
{
}