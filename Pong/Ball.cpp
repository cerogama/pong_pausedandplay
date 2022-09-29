#include "Ball.h"
// This the constructor function
Ball::Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;
	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);

}


FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}
RectangleShape Ball::getShape()
{
	return m_Shape;
}

//Le dice al main en que dirección la bola está viajando
//No necesitamos getYVelocity porque nos basta con X
float Ball::getXVelocity()
{
	return m_DirectionX;
}

void Ball::reboundSides()
{
	//Si choca en las paredes me va a devolver la dirección contraria por eso el -
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBat()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatOrTop()
{
	//Si choca en el techo me va a rebotar desde arriba hacia abajo
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundLeft()
{
	//Reiniciamos la posición porque ya que tocó el piso entonces el jugador pierde.
	m_Position.y = 0;
	m_Position.x = 500;
	m_DirectionY = m_DirectionY;
}

void Ball::update(Time dt)
{
	// Update the ball's position
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	// Move the ball
	m_Shape.setPosition(m_Position);
}