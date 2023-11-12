#include "Stdafx.h"
#include "TeamReport.h"


HRESULT TeamReport::init(void)
{
	//_obb = new OBBCollision;
	_switch = false;
	_initNum = 0;
	const vector<string> tempStr = {
	"��ȣ�� : ����",
	"������ : �� �����Ͻó���?" ,
	"�ڼ��� : ��������",
	"�ڼ��� : �Ⱦ� ���ҷ�", 
	"��ȣ�� : ��� �������� �������� ���۵Ǿ�",
	"�ڼ��� :  �׸� �Ͻʼ� ����",
	"������ : ��",
	"������ : ���̿� ���̿�",
	"������ : ġŲ�� ���ƿ�",
	"�ڼ��� : ����~~~~~~~~�Ϥ�������������������������!!!",
	"������ : ġŲ�� �Ⱦ��",
	"������ : ġŲ�� ���ƿ�",
	"������ : ���� ����̶����... �ܹ��� ���� ������",
	"�ڼ��� : �� �� ����� ���ܾ���������!!",
	"�ڼ��� : �� �� �����???",
	"������ : �ϳ��Ѽ� �ϸ� �¾�Ĵ翡�� �������� ����",
	"������ : ���� �ſ������",
	"������ : ��������������",
	"��ȣ�� : ����... �� �� ����...",
	"�ڼ��� : ���� �ؽ�Ʈ �߽�",
	"�ڼ��� : �����̶��... ������ �̷��Զ� ���� ������..."
	"������ : �����Ϳ��� �۾��� �ؾߵǴ°ű���..",
	"������ : �ٸ��б� ������ �۾��߾��׿�",
	"������ : ���� ���� ������ ���ڽ��ϴ�",
	"������ : �ֳĸ� ���Ḧ �����Űŵ��",
	"��ȣ�� : �� �׷� �ֵ�� �� ���ְ� �Ծ���",
	"��ȣ�� : �̷��� �� �׾�~~",

	 /*���⿡ �̾ �߰��� ��*/};

	_curFrameX2 = 2;
	_curFrameY2 = 1;

	_curFrameX3 = 3;
	_curFrameY3 = 2;
	//_img->init(getMemDC());

	_img= D2DMANAGER->loadImageD2D("�ӽ�", L"Resources/Images/Effect/60FPS_AC3T026_Nova_02.png",
		960, 3840,5,20);
	////_img = D2DMANAGER->addFrameImage(getMemDC(),"�ӽ�", L"Resources/Images/Effect/60FPS_AC3T026_Nova_02.png",
	////	960, 3840, 5, 20);
	////
	//_img2=D2DMANAGER->loadImageD2D("�ӽ�2", L"Resources/Images/Effect/60FPS_ACQ021_Fire.png",
	//	960, 3840,5,20);

	//_img3=D2DMANAGER->loadImageD2D("�ӽ�3", L"Resources/Images/Effect/60FPS_AC3T018_Tempest_02.png",
	//	960, 3840);

	//D2DMANAGER->loadImageD2D("�׽�Ʈ��", L"Resources/Images/test/actor1.png", 60, 60);

	testAngle = 0;
	for (int i = 0; i < tempStr.size(); i++)
	{
		int x, y;
		if (!_switch)
		{
			x = i * 40;
			y = i * 30;
		}
		else
		{		
			x = WINSIZE_X-((i- _initNum) * 40) - 100;
			y = (i - _initNum) * 30;
		}
		if (y >= WINSIZE_Y - 80)
		{
			_switch = true;
			// �ؽ�Ʈ�� y�� winsizeY���� ���� �� �����ʱ�ȭ �����ִ� ����
			_initNum = i;
			
		}
		_vXpoint.emplace_back(x, y, tempStr[i]);
	}

	rc1 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 300, 100);
	rc2 = RectMakeCenter(WINSIZE_X / 2-100, WINSIZE_Y / 2-200, 300, 100);

	return S_OK;
}

void TeamReport::release(void)
{
	/*SAFE_DELETE(_img);
	SAFE_DELETE(_img2);
	SAFE_DELETE(_img3);*/
}

void TeamReport::update(void)
{
	
	if(KEYMANAGER->isStayKeyDown(VK_RIGHT)) testAngle++;
	if(KEYMANAGER->isStayKeyDown(VK_LEFT)) testAngle--;

	//cout << testAngle << endl;

}

void TeamReport::render(void)
{
	//for (const auto& textPrint : _vXpoint)
	//{
	//	FONTMANAGER->drawText(getMemDC(), textPrint._x, textPrint._y, (char*)textPrint._str.c_str());
	//}
	// 
	DrawRectMake(getMemDC(), rc1);
	//DrawRectMake(getMemDC(), rc2);
	
	//if (_obb->isOBBCollision(rc1, 0, rc2, testAngle))
	//{
	//	cout << "�ȰŴ�?" << endl;
	//}
	//else
	//{
	//	cout << "�ȵȰŴ�?" << endl;

	//}

	//_obb->drawRotatedRect(getMemDC(), rc2, DEGREE_RADIAN(testAngle));
	//if (_obb->isOBBCollision(rc1, 0, rc2, DEGREE_RADIAN(testAngle)))
	//{
	//	cout << testAngle << endl;
	//	cout << "�浹" << endl;
	//	FONTMANAGER->drawText(getMemDC(), WINSIZE_X/2  + 200, WINSIZE_Y / 2, "�浹");
	//}

	OBBDrawRotatedRect(getMemDC(), rc2, DEGREE_RADIAN(testAngle));
	if (isOBBCollision(rc1, 0, rc2, DEGREE_RADIAN(testAngle)))
	{
		cout << testAngle << endl;
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X / 2 + 200, WINSIZE_Y / 2, "�浹",30, 600, RGB(0,0,0));
	}

}


void TeamReport::d2drender(void)
{

	//_curFrameX++;
	//if (_img->maxFrameX < _curFrameX)
	//{
	//	_curFrameX = 0;
	//	_curFrameY++;
	//	if (_img->maxFrameY < _curFrameY)
	//	{
	//		_curFrameX = 0;
	//		_curFrameY = 0;
	//	}
	//}
	//D2DMANAGER->alphaRender("�ӽ�2", 0, 0,WINSIZE_X,WINSIZE_Y, 0.5f);
	////D2DMANAGER->frameAlphaRender("�ӽ�",0,0,_curFrameX,_curFrameY,WINSIZE_X,WINSIZE_Y,0.5f);
	//D2DMANAGER->frameRotateRender("�ӽ�",0,0,_curFrameX,_curFrameY,WINSIZE_X,WINSIZE_Y,testAngle);
	//
	//D2DMANAGER->rotateRender("�׽�Ʈ��", WINSIZE_X/ 2, WINSIZE_Y / 2, testAngle, 1.f);
	//_curFrameX2++;
	//if (_img2->maxFrameX < _curFrameX2)
	//{
	//	_curFrameX2 = 0;
	//	_curFrameY2++;
	//	if (_img2->maxFrameY < _curFrameY2)
	//	{
	//		_curFrameX2 = 0;
	//		_curFrameY2 = 0;
	//	}
	//}
	//D2DMANAGER->frameAlphaRender("�ӽ�2", 0, 0, _curFrameX2, _curFrameY2, WINSIZE_X, WINSIZE_Y,0.5f);


	////_curFrameX3++;
	//if (_img3->maxFrameX < _curFrameX3)
	//{
	//	_curFrameX3 = 0;
	//	_curFrameY3++;
	//	if (_img3->maxFrameY < _curFrameY3)
	//	{
	//		_curFrameX3 = 0;
	//		_curFrameY3 = 0;
	//	}
	//}
	//D2DMANAGER->frameRender("�ӽ�3", 0, 0, _curFrameX3, _curFrameY3, WINSIZE_X, WINSIZE_Y);

}
