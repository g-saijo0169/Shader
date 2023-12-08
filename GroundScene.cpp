#include "GroundScene.h"
#include "Arrow.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

//�R���X�g���N�^
GroundScene::GroundScene(GameObject* parent)
	: GameObject(parent, "GroundScene"), hModel_(-1), hGround_(-1),hLightBall_(-1),lightSourcePosition_(0),pCBStageScene_(0)
{
}

void GroundScene::IntConstantBuffer()
{
}

//������
void GroundScene::Initialize()
{
	hModel_ = Model::Load("Assets/Torus.fbx");
	assert(hModel_ >= 0);
	
}

//�X�V
void GroundScene::Update()
{
	if (Input::IsKey(DIK_S))
	{
		XMFLOAT4 p = GetLightPos();
		XMFLOAT4 margin{ p.x - 0.0f, p.y - 0.0f, p.z - 0.1f, p.w - 0.0f };

		SetLightPos(margin);
	}
	XMFLOAT4 tmp{ GetLightPos() };
	trLightBall.position_ = { tmp.x, tmp.y, tmp.z };

	CBUFF_GROUND cb;
	cb.lightPosition = lightSourcePosition_;
	XMStoreFloat4(&cb.eyePos, Camera::GetEyePosition());


	Direct3D::pContext_->UpdateSubresource(pCBStageScene_, 0, NULL, &cb, 0, 0);

	Direct3D::pContext_->VSSetConstantBuffers(1, 1, &pCBStageScene_);
	Direct3D::pContext_->PSSetConstantBuffers(1, 1, &pCBStageScene_);
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