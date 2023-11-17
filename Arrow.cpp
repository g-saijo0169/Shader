#include "Arrow.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Arrow::Arrow(GameObject* parent)
	: GameObject(parent, "Arrow"), hModel_
{
}

//������
void Arrow::Initialize()
{


	assert(hModel_[0] >= 0);
}

//�X�V
void Arrow::Update()
{
}

//�`��
void Arrow::Draw()
{
	Model::SetTransform(hModel_[0]);
	Model::Draw(hModel_[0]);

}

//�J��
void Arrow::Release()
{
}