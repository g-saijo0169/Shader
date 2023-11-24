#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Stage.h"
#include "GroundScene.h"
#include "Arrow.h"
#include "Engine/Texture.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

void TestScene::Initialize()
{
	//Instantiate<Stage>(this);
	Instantiate<GroundScene>(this);
	Instantiate<Arrow>(this);

}

void TestScene::Update()
{

}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
