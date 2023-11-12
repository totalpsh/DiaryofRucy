#include "Stdafx.h"
#include "SceneChanger.h"
HRESULT SceneChanger::init(void)
{
	for (int i = 0; i < Eindex::ENDGAME; i++)
	{
		_index[i]._rc = RectMakeCenter(100 + i % 4 *150, 100 + i / 4 * 50, 150, 50);
	}

	// ���⿡ �� �ڽ� �߰� ��
	
	 wsprintf(_index[Eindex::REPORT]._name,"�� ���� x");
	 wsprintf(_index[Eindex::OPENING]._name, "������");
	 wsprintf(_index[Eindex::STAGE]._name,"��������");
	 wsprintf(_index[Eindex::GAMEOVER]._name,"���ӿ���");
	 wsprintf(_index[Eindex::ENDING]._name,"����");
	 wsprintf(_index[Eindex::LOADING]._name,"�ε�");
	 wsprintf(_index[Eindex::JSON]._name, "json");

	 SOUNDMANAGER->stop("opening");
	 SOUNDMANAGER->stop("liebestraum_short");
	 SOUNDMANAGER->stop("die");

	// ���⿡ �� �ڽ� �߰� ��
	return S_OK;
}

void SceneChanger::release(void)
{

} 

void SceneChanger::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "�����Ͻðڽ��ϱ�?", "���� Ȯ��", MB_OKCANCEL) == IDOK)
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < Eindex::ENDGAME; i++)
		{
			if (PtInRect(&_index[i]._rc, _ptMouse))
			{
				switch (i)
				{
				
				case Eindex::REPORT:
					SCENEMANAGER->chanegeScene("x�ڰ�����");
					break;

				case Eindex::OPENING:
					SCENEMANAGER->chanegeScene("�����׾�");
					break;

				case Eindex::STAGE:
					SCENEMANAGER->chanegeScene("����������");
					break;

				case Eindex::GAMEOVER:
					SCENEMANAGER->chanegeScene("���ӿ�����");
					break;
				case Eindex::ENDING:
					SCENEMANAGER->chanegeScene("������");
					break;

				case Eindex::LOADING:
					SCENEMANAGER->chanegeScene("�ε���");
					break;
				case Eindex::JSON:
					SCENEMANAGER->chanegeScene("json1");
					break;
				default:

					break;
				}
			}
		}
	}

	
}

void SceneChanger::render(void)
{
	SetTextAlign(getMemDC(), TA_CENTER);
	for (int i = 0; i < Eindex::ENDGAME; i++)
	{
		DrawRectMake(getMemDC(), _index[i]._rc);
		TextOut(getMemDC(), _index[i]._rc.left + (_index[i]._rc.right - _index[i]._rc.left) / 2,
			_index[i]._rc.top + 13, _index[i]._name, strlen(_index[i]._name));
	}
	SetTextAlign(getMemDC(), TA_LEFT);
}
