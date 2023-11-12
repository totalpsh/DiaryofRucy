#pragma once
#include "SingletonBase.h"
#include "GImage.h"

// 1. ��ü�� ���� new
// 2. ���� ����
// �� STL -> Map ->
#pragma region STL ��
/*
 - Ű + ���� ���� ����
	�� ù��° first  -> Ű
	�� �ι�° second -> ��
    
 - �߰��ϴ� ����� insert()�� ����ϰ� Ű�� ����� ���ÿ� �߰��ؾ� �ϴ� pair / make_pair

 - pair() : �ΰ��� �ڷ����� �ϳ��� �����ִ� ����ü (���ø� -> � �ڷ����� OK)

 - make_pair() : pair�� ������ִ� �Լ�
	�� pair.first = x / pair.second = y;
	�� pair = make_pair(x, y);

 - �ϳ��� Ű�� �������� ���� �����ϰ� �ʹٸ� ��Ƽ���� ����ϴ� �͵� ���
 
 - pair�� Ȯ����� ������ �ۼ��ϰų� �ټ��� ��ȯ���� ������ �ʹٸ� tuple�� ����ؾ� �Ѵ�
*/
#pragma endregion

class ImageManager : public SingletonBase<ImageManager>
{
private:
	// char*�� ȣȯ��/�ӵ��鿡�� �Ҿ����ϱ⿡ string�� ���
	typedef map<string, GImage*> mapImageList;
	typedef map<string, GImage*>::iterator mapImageIter;
    
private:
	mapImageList _mImageList;

private:
    int _alpha = 0;
public:
	HRESULT init(void);
	void release(void);

	// �ܵ�ó���� ������ (GImage�� �Ⱦ����)
	// ��1. �����ӿ�ũ �ڵ� ����ġ
	// ��2. ��ü�� (�̹���) �浹 ���ɼ�

    GImage* addImage(string strKey, int width, int height);
    GImage* addImage(string strKey, const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
    GImage* addImage(string strKey, const char* fileName, float x, float y, int width, int height,bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
    GImage* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
    GImage* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
    
    GImage* findImage(string strKey);

    bool deleteImage(string strKey);
    bool deleteAll();

    // ����
    void render(string strKey, HDC hdc);
    void render(string strKey, HDC hdc, int destX, int destY);

    //�̹��� Ŭ����
    void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
    void render(string strKey, HDC hdc, int destX, int destY, int destWidt, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight);

    // ������ ����
    void frameRender(string strKey, HDC hdc, int destX, int destY);
    void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

    // ������ ���� ����
    void frameAlphaRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);

    // ���ķ���
    void alphaRender(string strKey, HDC hdc, BYTE alpha);
    void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
    void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

    // ��������
    void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
    void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);


    void fadeOut(void) { if (_alpha < 255) _alpha += 5; }
    void fadeOut(int speed) { if (_alpha < 255) _alpha += speed; }
    void fadeIn(void) { if (_alpha > 0) _alpha -= 5; }
    int getAlpha(void) { return _alpha; }


	ImageManager() {}
    ~ImageManager() {}
};

