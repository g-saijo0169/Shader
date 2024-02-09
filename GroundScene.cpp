#include "GroundScene.h"
#include "Arrow.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

//namespace {
//};

//コンストラクタ
GroundScene::GroundScene(GameObject* parent)
	: GameObject(parent, "GroundScene"), hModel_(-1), hGround_(-1),lightSourcePosition_(0,5,-10,0)
{
}

void GroundScene::IntConstantBuffer()
{
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CBUFF_GROUND);
	cb.Usage = D3D11_USAGE_DEFAULT;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = 0;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	HRESULT hr;
	hr = Direct3D::pDevice_->CreateBuffer(&cb, nullptr, &pCBStageScene_);
	if (FAILED(hr))
	{
		MessageBox(NULL, "コンスタントバッファの作成に失敗しました", "エラー", MB_OK);
	}
}

//初期化
void GroundScene::Initialize()
{
	//hModel_ = Model::Load("Assets/Ground.fbx");
	//hModel_ = Model::Load("Assets/WaterGround.fbx");
	hLightBall_ = Model::Load("Assets/Ball.fbx");

	//assert(hModel_ >= 0);
	assert(hLightBall_ >= 0);

	trDonuts.position_ = { 0,0,0 };
	trDonuts.rotate_ = { 0,0,0 };
	trDonuts.scale_ = { 0.2,0.2,0.2};

	trLightBall.position_ = { 0,0,0 };
	trLightBall.rotate_ = { 0,0,0 };
	trLightBall.scale_ = { 0.3,0.3,0.3 };



	IntConstantBuffer();

}

//更新
void GroundScene::Update()
{
	//trDonuts.rotate_.y += 0.5f;
	if (Input::IsKey(DIK_RIGHT))
	{
		XMFLOAT4 p = GetLightPos();
		XMFLOAT4 margin{ p.x + 0.1f, p.y + 0.0f, p.z + 0.0f, p.w + 0.0f };

		//Model::GetModel(hModel_)->SetLightPos(margin);
		SetLightPos(margin);
	}
	if (Input::IsKey(DIK_LEFT))
	{
		XMFLOAT4 p = GetLightPos();
		XMFLOAT4 margin{ p.x - 0.1f, p.y - 0.0f, p.z - 0.0f, p.w - 0.0f };

		/// Model::GetModel(hModel_)->SetLightPos(margin);
		SetLightPos(margin);
	}
	if (Input::IsKey(DIK_UP))
	{
		XMFLOAT4 p = GetLightPos();
		XMFLOAT4 margin{ p.x - 0.0f, p.y + 0.1f, p.z - 0.0f, p.w - 0.0f };

		//Model::GetModel(hModel_)->SetLightPos(margin);
		SetLightPos(margin);
	}
	if (Input::IsKey(DIK_DOWN))
	{
		XMFLOAT4 p = GetLightPos();
		XMFLOAT4 margin{ p.x - 0.0f, p.y - 0.1f, p.z - 0.0f, p.w - 0.0f };

		//Model::GetModel(hModel_)->SetLightPos(margin);
		SetLightPos(margin);
	}
	if (Input::IsKey(DIK_W))
	{
		XMFLOAT4 p = GetLightPos();
		XMFLOAT4 margin{ p.x - 0.0f, p.y - 0.0f, p.z + 0.1f, p.w + 0.0f };

		//Model::GetModel(hModel_)->SetLightPos(margin);
		SetLightPos(margin);
	}
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
	XMStoreFloat4(&cb.eyePosition, Camera::GetEyePosition());


	Direct3D::pContext_->UpdateSubresource(pCBStageScene_, 0, NULL, &cb, 0, 0);

	Direct3D::pContext_->VSSetConstantBuffers(1, 1, &pCBStageScene_);
	Direct3D::pContext_->PSSetConstantBuffers(1, 1, &pCBStageScene_);
}

//描画
void GroundScene::Draw()
{

	//Model::SetTransform(hModel_, trDonuts);
	//Model::Draw(hModel_);

	Model::SetTransform(hLightBall_, trLightBall);
	Model::Draw(hLightBall_);

}

//開放
void GroundScene::Release()
{
}