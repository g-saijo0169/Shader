#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"
#include <vector>

#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")


class Texture;

class Fbx
{
    //�}�e���A��
    struct MATERIAL
    {
        Texture* pTexture;
        Texture* pNormalMap;
        XMFLOAT4    diffuse;
        XMFLOAT4    amibent;
        XMFLOAT4    specular;
        float   shiness;
    };

    struct CBUFF_MODEL
    {
        XMMATRIX    matWVP;//���[���h�r���[�v���W�F�N�V����
        XMMATRIX    matW;//���[���h�ϊ�
        XMMATRIX    matNormal; //�t�s��
        XMFLOAT4    diffuseColor;   //�ʂ̐F
        XMFLOAT4    ambientColor;
        XMFLOAT4    specularColor;
        FLOAT       shiniess;

        BOOL hasTexture;
        BOOL hasNormalMap;

    };

    struct VERTEX
    {
        XMVECTOR position; //�ʒu
        XMVECTOR uv; //�e�N�X�`�����W
        XMVECTOR normal; //�@���x�N�g��
        XMVECTOR tangent; //�ڐ��x�N�g��
    };

    int vertexCount_;   //���_��
    int polygonCount_;  //�|���S����
    int materialCount_; //�}�e���A���̌�
    int* indexCount_;
    ID3D11Buffer* pVertexBuffer_;
    ID3D11Buffer** pIndexBuffer_;
    ID3D11Buffer* pConstantBuffer_;
    MATERIAL* pMaterialList_;


    void InitVertex(fbxsdk::FbxMesh* mesh);
    void InitIndex(fbxsdk::FbxMesh* mesh);
    void IntConstantBuffer();
    void InitMaterial(fbxsdk::FbxNode* pNode);
    Texture* pToonTex_;
public:

    Fbx();
    HRESULT Load(std::string fileName);
    void    Draw(Transform& transform);
    void    Release();
};