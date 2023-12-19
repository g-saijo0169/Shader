#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"
#include <vector>


#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

using std::vector;

class Texture;

class Fbx
{
	//�}�e���A��
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;
		XMFLOAT4 ambiemt;
		XMFLOAT4 specular;
		float	 shininess;
	};

	struct CBUFF_MODEL
	{
		XMMATRIX	matWVP;			//���[���h�r���[�v���W�F�N�V����
		XMMATRIX	matW;			//���[���h�ϊ��̂�
		XMMATRIX	matNormal;		//�X�P�[��X���s�ړ��̋t�s��
		XMFLOAT4	diffuseColor;	
		XMFLOAT4	ambientColor;	
		XMFLOAT4	specularColor;	
		FLOAT		shininess;

		BOOL		isTextured;
	};

	struct VERTEX
	{
		XMVECTOR position;//�ʒu
		XMVECTOR uv; //�e�N�X�`�����W
		XMVECTOR normal; //�@���x�N�g��
	};

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����
	int materialCount_;	//�}�e���A���̌�

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	MATERIAL* pMaterialList_;
	vector <int> indexCount_;
	
	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
	HRESULT InitMaterial(fbxsdk::FbxNode* pNode);
	
	Texture* pToonTex_;
public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};