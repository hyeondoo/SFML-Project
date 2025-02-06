
#include "GameLoop.h"

void GameLoop::Start()
{
	_solver.Start();
}

void GameLoop::Update(float deltaTime)
{
	_solver.Update(deltaTime);
}

void GameLoop::Render(sf::RenderTarget& renderTarget)
{
	_solver.Render(renderTarget);
}