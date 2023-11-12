#pragma once
#include "Enemy.h"

class Snake : public Enemy
{
private:
	//SnakeState _snakeState;
	int _speed;
	bool attackInit;

	
	

public:

	HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);
	void draw(void);
	void d2drender(void);
	void stateUpdate();
	void animation();

	bool bulletCountFire();



	Snake(State snakeState = IDLE) {}
	~Snake() {}
};

