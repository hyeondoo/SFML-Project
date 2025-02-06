#pragma once

#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Solver.h"

class GameLoop
{
private:
	Solver _solver;

public:
	void Start();
	void Update(float deltaTime);
	void Render(sf::RenderTarget& renderTarget);
};