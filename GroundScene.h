#pragma once
#include "Engine/GameObject.h"

struct CBUFF_GROUND
{
	XMFLOAT4 lightPosition;
	XMFLOAT4 eyePosition;
};

//�����V�[�����Ǘ�����N���X
class GroundScene : public GameObject
{
	
	int hModel_;    //���f���ԍ�
	int hGround_;
	int hLightBall_;
	Transform trDonuts;
	Transform trGround;
	Transform trLightBall;
	ID3D11Buffer* pCBStageScene_;

	void IntConstantBuffer();
	XMFLOAT4 lightSourcePosition_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GroundScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetLightPos(XMFLOAT4& _pos) { lightSourcePosition_ = _pos; }
	XMFLOAT4 GetLightPos() { return(lightSourcePosition_); }
};