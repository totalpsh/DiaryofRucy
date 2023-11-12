#pragma once
#include "GameNode.h"

enum Eindex : int
{
	// ���⿡ �� �߰�
	REPORT,
	OPENING, STAGE,
	GAMEOVER, ENDING,
	LOADING, JSON,


	// �� ����
	ENDGAME,
	SCENECHANGER
};


class SceneChanger : public GameNode
{
private:
	struct tagIndex
	{
		RECT _rc;
		char _name[128];
	};

	tagIndex _index[Eindex::ENDGAME];


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	SceneChanger() {}
	~SceneChanger() {}
};

