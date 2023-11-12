#include "Stdafx.h"
#include "MainGame.h"
#include "TeamReport.h"
#include "OpeningScene.h"
#include "StageScene.h"
#include "GameOverScene.h"
#include "EndingScene.h"
#include "SceneChanger.h"
#include "LoadingScene.h"
#include "JsonDataScene.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	_resources.init();


	SCENEMANAGER->addScene("��ü����", new SceneChanger);
	SCENEMANAGER->addScene("x�ڰ�����", new TeamReport);
	SCENEMANAGER->addScene("�����׾�", new OpeningScene);
	SCENEMANAGER->addScene("���ӿ�����", new GameOverScene);
	SCENEMANAGER->addScene("����������", new StageScene);
	SCENEMANAGER->addScene("������", new EndingScene);
	SCENEMANAGER->addScene("�ε���", new LoadingScene);
	SCENEMANAGER->addScene("json1", new JsonDataScene);

	
	SCENEMANAGER->chanegeScene("�����׾�");
	Json::Value;
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	//_curruntGame->release();
}

void MainGame::update(void)
{
	GameNode::update();

	SCENEMANAGER->update();
	SOUNDMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{	
		SCENEMANAGER->chanegeScene("��ü����");
	}

	

}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	//===============================================
	SCENEMANAGER->render();
	D2DMANAGER->beginDraw();
	SCENEMANAGER->d2drender();
	D2DMANAGER->endDraw();
	SCENEMANAGER->UIrender();
	if(KEYMANAGER->isToggleKey(VK_F1)) TIMEMANAGER->render(getMemDC());



	//=================================================
	this->getBackBuffer()->render(getHDC());
}
