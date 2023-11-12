#include "Stdafx.h"
#include "EndScene.h"

HRESULT EndScene::init(void)
{
	D2DMANAGER->loadImageD2D("����1", L"Resources/Images/title/game_over.png",
		WINSIZE_X, WINSIZE_Y, 1, 1);
	D2DMANAGER->loadImageD2D("����2", L"Resources/Images/title/game_over1.png",
		WINSIZE_X, WINSIZE_Y, 1, 1);
	D2DMANAGER->loadImageD2D("����3", L"Resources/Images/title/game_over2.png",
		WINSIZE_X, WINSIZE_Y, 1, 1);

	_new = IMAGEMANAGER->addFrameImage("������", "Resources/Images/title/startimg22.bmp",
		130, 60, 1, 2, true, RGB(255, 0, 255));
	_end = IMAGEMANAGER->addFrameImage("��", "Resources/Images/title/exitimg22.bmp",
		130, 60, 1, 2, true, RGB(255, 0, 255));

	rc1 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 280, 250, 80);
	rc2 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 350, 250, 80);

	return S_OK;
}

void EndScene::release(void)
{


}

void EndScene::update(void)
{
	_new->setFrameY(0);
	_end->setFrameY(0);
}

void EndScene::render(void)
{
	IMAGEMANAGER->frameRender("������", getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y / 3 + 270, _new->getFrameX(), _new->getFrameY());
	IMAGEMANAGER->frameRender("��", getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y / 3 + 340, _end->getFrameX(), _end->getFrameY());
	AddFontResourceA("���.ttf");
	//���� �ؽ�Ʈ
	int i, j;
	char str[128];
	HFONT font;
	HFONT oldFont;

	font = CreateFont
	(
		30, 0, 0, 0, 30,
		0, 0, 0,
		HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH, TEXT("���")
	);
	oldFont = (HFONT)SelectObject(getMemDC(), font);
	SetBkMode(getMemDC(), TRANSPARENT);
	wsprintf(str, "������. ���� ���� ���� ���̾�.");
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			TextOut(getMemDC(), 46 + i, 46 + j, str, strlen(str));
		}
	}
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	TextOut(getMemDC(), WINSIZE_X / 3, WINSIZE_Y / 2-50, str, strlen(str));
	SetTextColor(getMemDC(), RGB(0, 0, 0));

	SelectObject(getMemDC(), oldFont);
	RemoveFontResourceA("���.ttf");
}

void EndScene::d2drender(void)
{
	D2DMANAGER->render("����1", 0, 0, 0, 0);
	D2DMANAGER->render("����2", 0, 0, 0, 0);
	D2DMANAGER->render("����3", 0, 0, 0, 0);
	if ( PtInRect(&rc1, _ptMouse))
	{
		_new->setFrameY(1);
	}
	if ( PtInRect(&rc2, _ptMouse))
	{
		_end->setFrameY(1);
	}


}
