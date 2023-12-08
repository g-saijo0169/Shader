#pragma once
#include "Engine/GameObject.h"

struct CBUFF_GROUND
{
	XMFLOAT4 lightPosition;
	XMFLOAT4 eyePosition;
};

//■■シーンを管理するクラス
class GroundScene : public GameObject
{
	
	int hModel_;    //モデル番号
	int hGround_;
	int hLightBall_;
	Transform trDonuts;
	Transform trGround;
	Transform trLightBall;
	ID3D11Buffer* pCBStageScene_;

	void IntConstantBuffer();
	XMFLOAT4 lightSourcePosition_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GroundScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void SetLightPos(XMFLOAT4& _pos) { lightSourcePosition_ = _pos; }
	XMFLOAT4 GetLightPos() { return(lightSourcePosition_); }
};