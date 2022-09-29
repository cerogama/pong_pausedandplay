#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat
{
private:
	//m_ member
	Vector2f m_Position;
	// A RectangleShape object
	RectangleShape m_Shape;
	float m_Speed = 1000.0f;
	bool m_MovingUp = false;
	bool m_MovingDown = false;

public:
	//Este constructor sirve para declarar la posición inicial en X  y Y cuando comience el juego.
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	//Bat controls
	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();
	void update(Time dt);
};
