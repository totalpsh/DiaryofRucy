#pragma once
#include "Skill.h"

// obb�浹 ���������غ���

class ThunderFlash : public Skill
{
private:
	D2DImageInfo* _frameImage;
	RECT _rcThunder[4];
	int _thunderFrameCount[4];
	int _frameX[4];
	int _frameY[4];



	float _angle;
	float _speed;
	float _range;

	bitset<4> _bThunderFire;

public:

	HRESULT init(void);
	void shot(float x, float y, float fireX, float fireY);
	void animation(void);
	void draw(void);

	ThunderFlash() {}
	~ThunderFlash() {}

};

