//#include "Dice.h"
//#include "Engine/Model.h"
//#include "Engine/Camera.h"
//
//
////�R���X�g���N�^
//Dice::Dice(GameObject* parent)
//	: GameObject(parent, "Dice"), hModel_{ -1 }
//{
//}
//
////������
//void Dice::Initialize()
//{
//	hModel_ = Model::Load("Assets/TranslucentDice.fbx");
//	assert(hModel_ >= 0);
//
//	Camera::SetPosition(XMVECTOR({ 0,1,-5,0 }));
//	Camera::SetTarget(XMVECTOR({ 0,0,0,0 }));
//}
//
////�X�V
//void Dice::Update()
//{
//	transform_.rotate_.y += 5.0f;
//}
//
////�`��
//void Dice::Draw()
//{
//	/*Transform TrsDice;
//	TrsDice.position_ = XMFLOAT3(-2, 3, 2);*/
//
//	Model::SetTransform(hModel_, transform_);
//	Model::Draw(hModel_);
//}
//
////�J��
//void Dice::Release()
//{
//}