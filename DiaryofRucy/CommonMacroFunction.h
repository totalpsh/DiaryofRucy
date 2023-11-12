#pragma once
// CommonMacroFunction

template <typename InterFaceType>
inline void SafeRelease(InterFaceType** currentScene)
{
	if (*currentScene != nullptr)
	{
		(*currentScene)->Release();
		*currentScene = nullptr;
	}
}

template <typename InterFaceType>
inline InterFaceType* safeAcquire(InterFaceType* newObject)
{
	if (newObject != nullptr)
	{
		//���� ������ ���� �Լ�
		newObject->AddRef();
	}
	return newObject;
}

// ���ο� ��ü�� ���ϋ� ���� ��ü�� ����
template <typename InterFaceType>
inline void SafeSet(InterFaceType** currentObject, InterFaceType* newObject)
{
	safeAcquire(newObject);
	SafeRelease(&currentObject);
	currentObject = newObject;
}

//�����
inline POINT PointMake(int x, int y) // 2D���� ����
{
	POINT pt = { x, y };
	return pt;
}

inline POINTF PointFloatMake(float x, float y)
{
	POINTF pt = { x,y };
	return pt;
}
//�ٱ߱�
inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}
//�簢�� ���� ������
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };
	return rc;
}
//�簢�� �׸��� (��Ʈ�� �̿��ؼ� �׸�)
inline void DrawRectMake(HDC hdc, RECT rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}
// �߾ӿ� �簢�� �����
inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };

	return rc;
}
//�簢�� �׸��� (��ǥ�� ����� ���� �־ �׸�)
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}


// �� �׸���
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}
// ���Ϳ� �� �����
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}


inline void moveRect(RECT rc, POINT pt, int size, int clickX, int clickY)
{
	 rc.left = pt.x - clickX;
	 rc.top = pt.y - clickY;
	 rc.right = rc.left + size;
	 rc.bottom = rc.top + size;

}

// �浹 ���� ������¡
inline RECT CollisionAreaResizing(RECT rcDest, int width, int height)
{
	RECT rc =
	{
		rcDest.left + width / 2, rcDest.top + height / 2, rcDest.right - width / 2, rcDest.bottom - height / 2
	};

	return rc;
}

inline RECT rucyCollisionAreaResizing(RECT rcDest, int width, int height)
{
	RECT rc =
	{
		rcDest.left + width / 2, rcDest.top + height / 2 +20, rcDest.right - width / 2, rcDest.bottom - height / 2 +20
	};

	return rc;
}
