#pragma once

#include <SFML/Graphics.hpp>

#include "Verlet.hpp"


class Particle
{
private:
	VerletData2D _verlet;

	Vec2f _gravity = { 0.f, 980.f };
	float _radius = 30.f;
	sf::Color _color = {255,255,255};

public:
	Particle(Vec2f pos) {};
	void Update(float deltaTime);
	void Render(sf::RenderTarget& renderTarget);

	float GetRadius() 
	{
		return _radius;
	}
	VerletData2D GetVerletData() 
	{
		return _verlet;
	}
	void SetVerletData(VerletData2D verlet)
	{
		_verlet = verlet;
	}
};