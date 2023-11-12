#include "Stdafx.h"
#include "OpeningScene.h"

HRESULT OpeningScene::init(void)
{
	D2DMANAGER->loadImageD2D("Ÿ��Ʋ", L"Resources/Images/title/layer1.png",
		WINSIZE_X, WINSIZE_Y, 1, 1);

	D2DMANAGER->loadImageD2D("�ι���", L"Resources/Images/title/opening2.png",
		WINSIZE_X, WINSIZE_Y, 1, 1);

	D2DMANAGER->loadImageD2D("�ι���2", L"Resources/Images/title/opening3.png",
		WINSIZE_X, WINSIZE_Y, 1, 1);
	D2DMANAGER->loadImageD2D("����â", L"Resources/Images/title/ó��1.png",
		412, 383);
	D2DMANAGER->loadImageD2D("��ƼŬ", L"Resources/Images/title/particle.png",
		44, 44, 1, 1);

	IMAGEMANAGER->addImage("����", "Resources/Images/title/����2.bmp",
		250, 50);
	D2DMANAGER->loadImageD2D("������", L"Resources/Images/title/������.png",
		486, 167, 1, 1);
	alpha = 0; count = 0;
	alpha1 = 255; count1 = 0;
	palpha = 255; pcount = 0;
	rc1 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 245, 250, 45);
	rc2 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 290, 250, 45);
	rc3 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 340, 250, 45);
	rc4 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 385, 250, 45);

	s1 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 265, 250, 10);
	s2 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 315, 250, 10);
	s3 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 365, 250, 10);
	s4 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 3 + 405, 250, 10);
	//particle1 = RectMakeCenter(200, WINSIZE_Y, 22, 22);
	//particle2 = RectMakeCenter(1000, WINSIZE_Y, 22, 22);
	//particle3 = RectMakeCenter(600, WINSIZE_Y, 22, 22);
	//particle4 = RectMakeCenter(800, WINSIZE_Y, 22, 22);

	for (int i = 0; i < 20; i++)
	{
		Particle _particle;
		_particle.x = RND->getInt(1000);
		_particle.y = WINSIZE_Y - RND->getInt(10);
		_particle.speed = RND->getFromFloatTo(0, 2);
		_particle.sinf = RND->getFromIntTo(1, 5);
		_particle.cosf = 50;
		_particle.rnd = RND->getInt(200);
		_particle.size = RND->getFromIntTo(22, 33);
		_particle.alpha2 = RND->getFloat(1) + 1.0f;
		particle.push_back(_particle);
	}

	clicked = false;
	speed = 0;
	SOUNDMANAGER->addSound("opening", "Resources/audio/�ǾƳ�3_untitled.ogg", true, true);
	SOUNDMANAGER->play("opening",100);
	SOUNDMANAGER->addSound("ui_cursor1", "Resources/audio/ui_cursor.ogg", true, false);
	SOUNDMANAGER->addSound("ui_ok1", "Resources/audio/ui_ok.ogg", true, false);

	newStart = false;
	continued = false;
	
	SOUNDMANAGER->play("������&���", 0.1f);


	return S_OK;
}

void OpeningScene::release(void)
{


}

void OpeningScene::update(void)
{
	if (!clicked)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			clicked = true;
		}
	}
	count++;
	if (count % 3 == 0)
	{
		if (alpha <= 255)
		{
			alpha = 1;
		}
		alpha -= 1.2;

	} //fadeIn	
	count1++;
	if (count1 % 3 == 0)
	{
		if (alpha1 <= 1)
		{
			alpha1 = 255;
		}
		alpha1 -= 50;

	} //fadeIn
	pcount++;
	if (pcount % 3 == 0)
	{
		if (palpha <= 1)
		{
			palpha = 255;
		}
		palpha -= 50;

	} //fadeIn

	for (auto it = particle.begin(); it != particle.end();)
	{
		it->speed += RND->getFromFloatTo(0, 2);
		it->alpha2 -= 0.0030f;

		if (it->speed > WINSIZE_Y / 2)
		{
			it->speed = 0;
			it->alpha2 = 1.0f;
		}
		else
		{
			++it;
		}
	}

	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&rc1, _ptMouse))
		{
			newStart = true;
		}
		else if (PtInRect(&rc2, _ptMouse))
		{
			continued = true;
		}
	}

	if (newStart)
	{
		IMAGEMANAGER->fadeOut();
		if (IMAGEMANAGER->getAlpha() == 255)
		{
			SCENEMANAGER->chanegeScene("�ε���");
		}
	}

	if (continued)
	{
		_loadGame = true;
		IMAGEMANAGER->fadeOut();
		if (IMAGEMANAGER->getAlpha() == 255)
		{
			SCENEMANAGER->chanegeScene("�ε���");
		}
	}



	//speed++;
}

void OpeningScene::render(void)
{
	IMAGEMANAGER->render("����â����", getMemDC(), WINSIZE_X / 2, WINSIZE_Y / 3);

}

void OpeningScene::d2drender(void)
{
	D2DMANAGER->render("Ÿ��Ʋ", 0, 0, WINSIZE_X, WINSIZE_Y);
	D2DMANAGER->render("�ι���", 0, 0, WINSIZE_X, WINSIZE_Y);
	D2DMANAGER->alphaRender("������", WINSIZE_X / 2 - 250, WINSIZE_Y - 200, palpha);
	if (clicked)
	{
		{
			D2DMANAGER->render("�ι���", 0, 0, WINSIZE_X, WINSIZE_Y);
			D2DMANAGER->render("�ι���2", 0, 0, WINSIZE_X, WINSIZE_Y);
		}

		D2DMANAGER->render("����â", WINSIZE_X / 2 - 160, WINSIZE_Y / 3 + 180, 300, 260);



		for (auto it = particle.begin(); it != particle.end(); it++)
		{
			//cout << it->speed << endl;
			D2DMANAGER->alphaRender("��ƼŬ", it->x + sinf((it->sinf)) * it->speed
				, it->y - it->rnd - (cosf(DEGREE_RADIAN(it->cosf))) * it->speed
				, it->size, it->size,
				it->alpha2);

		}

	}

	{
		char xar[120];
		wsprintf(xar, "x, y: %d %d", _ptMouse.x, _ptMouse.y);
		TextOut(getMemDC(), 1191, 24, xar, strlen(xar));

	}
}

void OpeningScene::UIrender(void)
{

	if (clicked && PtInRect(&rc1, _ptMouse))
	{
		
		IMAGEMANAGER->alphaRender("����", getMemDC(), rc1.left, rc1.top, alpha1);
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SOUNDMANAGER->play("ui_ok1", 100);
			SOUNDMANAGER->stop("opening");
			SCENEMANAGER->chanegeScene("����������");
		}
	}
	if (clicked && PtInRect(&s1, _ptMouse))
	{
		SOUNDMANAGER->play("ui_cursor1", 100);
	}
	if (clicked && PtInRect(&s2, _ptMouse))
	{
		SOUNDMANAGER->play("ui_cursor1", 100);
	}
	if (clicked && PtInRect(&s3, _ptMouse))
	{
		SOUNDMANAGER->play("ui_cursor1", 100);
	}
	if (clicked && PtInRect(&s4, _ptMouse))
	{
		SOUNDMANAGER->play("ui_cursor1", 100);
	}
	if (clicked && PtInRect(&rc2, _ptMouse))
	{
		IMAGEMANAGER->alphaRender("����", getMemDC(), rc2.left, rc2.top, alpha1);
	}
	if (clicked && PtInRect(&rc3, _ptMouse))
	{
		IMAGEMANAGER->alphaRender("����", getMemDC(), rc3.left, rc3.top, alpha1);
	}
	if (clicked && PtInRect(&rc4, _ptMouse))
	{
		IMAGEMANAGER->alphaRender("����", getMemDC(), rc4.left, rc4.top, alpha1);
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SOUNDMANAGER->play("ui_ok1", 100);
			SCENEMANAGER->chanegeScene("��ü����");
		}
	}

	IMAGEMANAGER->alphaRender("������", getMemDC(), IMAGEMANAGER->getAlpha());
}



