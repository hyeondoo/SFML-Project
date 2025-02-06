
#include "Particle.h"

void Particle::Update(float deltaTime)
{
	_verlet.acceleration += _gravity;

	_verlet.UpdatePosition(deltaTime);
}

void Particle::Render(sf::RenderTarget& renderTarget)
{
	sf::CircleShape shape(_radius);
	shape.setFillColor(_color);
	shape.setOrigin(Vec2f(_radius/2.f, _radius/2.f));
	shape.setPosition(_verlet.position_cur);
	shape.setPointCount(32);

	renderTarget.draw(shape);
}