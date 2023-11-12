#include "Stdafx.h"
#include "OpenScene.h"

HRESULT OpenScene::init(void)
{
	D2DMANAGER->loadImageD2D("Ÿ��Ʋ", L"Resources/Images/title/layer1.png",
		WINSIZE_X, WINSIZE_Y,1, 1);
	
	D2DMANAGER->loadImageD2D("�ι���", L"Resources/Images/title/opening2.png",
		WINSIZE_X, WINSIZE_Y,1,1);
	
	D2DMANAGER->loadImageD2D("�ι���2", L"Resources/Images/title/opening3.png",
		WINSIZE_X, WINSIZE_Y, 1, 1);

	D2DMANAGER->loadImageD2D("��ƼŬ", L"Resources/Images/title/particle.png",
		44, 44,1,1);
	D2DMANAGER->loadImageD2D("��ƼŬ1", L"Resources/Images/title/particle.png",
		44, 44, 1, 1);
	D2DMANAGER->loadImageD2D("��ƼŬ2", L"Resources/Images/title/particle.png",
		44, 44, 1, 1);
	D2DMANAGER->loadImageD2D("��ƼŬ3", L"Resources/Images/title/particle.png",
		44, 44, 1, 1);

	_new=IMAGEMANAGER->addFrameImage("������", "Resources/Images/title/startimg22.bmp",
		130, 60,1,2, true, RGB(255, 0, 255));
	_option=IMAGEMANAGER->addFrameImage("�ɼ�", "Resources/Images/title/optionimg22.bmp",
		130, 60, 1, 2, true, RGB(255, 0, 255));
	_end=IMAGEMANAGER->addFrameImage("��", "Resources/Images/title/exitimg22.bmp",
		130, 60, 1, 2, true, RGB(255, 0, 255));
	rc1 = RectMakeCenter(WINSIZE_X / 2 , WINSIZE_Y / 3 + 280, 250, 80);
	rc2 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 350, 250, 80);
	rc3 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 420, 250, 80);
	clicked = false;

		return S_OK;
}

void OpenScene::release(void)
{


}

void OpenScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		clicked = true;
	}
	_new->setFrameY(0);
	_option->setFrameY(0);
	_end->setFrameY(0);

}

void OpenScene::render(void)
{
	IMAGEMANAGER->render("����â����", getMemDC(),WINSIZE_X/2,WINSIZE_Y/3);
	if (clicked)
	{
		IMAGEMANAGER->frameRender("������", getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y / 3 + 270, _new->getFrameX(), _new->getFrameY());
		IMAGEMANAGER->frameRender("�ɼ�", getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y / 3 + 340, _option->getFrameX(), _option->getFrameY());
		IMAGEMANAGER->frameRender("��", getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y / 3 + 410, _end->getFrameX(), _end->getFrameY());

	}
	/*if (KEYMANAGER->isToggleKey(VK_RBUTTON))
	{
		DrawRectMake(getMemDC(), rc1);
		DrawRectMake(getMemDC(), rc2);
		DrawRectMake(getMemDC(), rc3);
	}*/
}

void OpenScene::d2drender(void)
{
	D2DMANAGER->render("Ÿ��Ʋ", 0,0 ,0,0);
	D2DMANAGER->render("�ι���", 0, 0, 0, 0);

	if (clicked)
	{
		D2DMANAGER->render("�ι���2", 0, 0, 0, 0);
	}
	if (clicked && PtInRect(&rc1, _ptMouse))
	{
		_new->setFrameY(1);
	}
	if (clicked && PtInRect(&rc2, _ptMouse))
	{
		_option->setFrameY(1);
	}
	if (clicked && PtInRect(&rc3, _ptMouse))
	{
		_end->setFrameY(1);
	}
	
	D2DMANAGER->render("��ƼŬ", 160+cosf(DEGREE_RADIAN(60)), 500+RND->getFromIntTo(100,300), 0, 0);
	D2DMANAGER->render("��ƼŬ1", RND->getFromIntTo(300, 400), RND->getFromIntTo(300, 500), 0, 0);
	D2DMANAGER->render("��ƼŬ2", RND->getFromIntTo(400, 500), RND->getFromIntTo(200, 600), 0, 0);
	D2DMANAGER->render("��ƼŬ3", RND->getFromIntTo(800, 1000), RND->getFromIntTo(400, 700), 0, 0);

	{
	char xar[120];
	wsprintf(xar, "x, y: %d %d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), 1191, 24, xar, strlen(xar));

	}
}	
	
	

