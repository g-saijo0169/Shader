#include "Stage.h"



//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    //���f���f�[�^�̃��[�h
  /*  hPict_ = Sprite::Load("Assets/�摜1.jpg");
    assert(hPict_ >= 0);*/
    pSprite = new Sprite;
    pSprite->Initialize();
}

//�X�V
void Stage::Update()
{
}

//�`��
void Stage::Draw()
{
    pSprite->Draw(transform_);
   /* Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);*/
}

//�J��
void Stage::Release()
{
}