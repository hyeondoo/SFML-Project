#pragma once

#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Particle.h"

class Solver
{
private:
	std::vector<Particle*> _particles;
	
	Vec2f _constraintCenter;
	float _constraintRadius;

public:
	Solver();

	void Start();
	void Update(float deltaTime);	
	void Render(sf::RenderTarget& renderTarget);

private:
	void ApplyConstraint();
};
