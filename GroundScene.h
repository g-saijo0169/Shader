#pragma once
#include "Engine/GameObject.h"

//�����V�[�����Ǘ�����N���X
class GroundScene : public GameObject
{
	
	int hModel_[2];
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
};