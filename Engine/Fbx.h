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
    //マテリアル
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
        XMMATRIX    matWVP;//ワールドビュープロジェクション
        XMMATRIX    matW;//ワールド変換
        XMMATRIX    matNormal; //逆行列
        XMFLOAT4    diffuseColor;   //面の色
        XMFLOAT4    ambientColor;
        XMFLOAT4    specularColor;
        FLOAT       shiniess;

        BOOL hasTexture;
        BOOL hasNormalMap;

    };

    struct VERTEX
    {
        XMVECTOR position; //位置
        XMVECTOR uv; //テクスチャ座標
        XMVECTOR normal; //法線ベクトル
        XMVECTOR tangent; //接線ベクトル
    };

    int vertexCount_;   //頂点数
    int polygonCount_;  //ポリゴン数
    int materialCount_; //マテリアルの個数
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