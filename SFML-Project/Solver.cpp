
#include "Solver.h"

Solver::Solver()
{
	_constraintCenter = { 640, 360 };
	_constraintRadius = 300;
}

void Solver::Start()
{
	_particles.push_back(new Particle(Vec2f(10, 10)));
}

void Solver::Update(float deltaTime)
{
	for (size_t i = 0; i < _particles.size(); i++)
	{
		ApplyConstraint();
		_particles[i]->Update(deltaTime);
	}
}

void Solver::Render(sf::RenderTarget& renderTarget)
{
	for (size_t i = 0; i < _particles.size(); i++)
	{
		_particles[i]->Render(renderTarget);
	}
}

void Solver::ApplyConstraint()
{	
	for (size_t i = 0; i < _particles.size(); i++)
	{
		auto verletData =_particles[i]->GetVerletData();
		float particleRadius = _particles[i]->GetRadius();
		float sqrtParicleRadius = particleRadius* particleRadius;		

		Vec2f v = _constraintCenter - verletData.position_cur;
		
		float dist = sqrt(v.x * v.x + v.y * v.y);
			
		if (dist > _constraintRadius - particleRadius)
		{			
			verletData.position_cur = _constraintCenter - v / dist * _constraintRadius;
			_particles[i]->SetVerletData(verletData);
		}
	}
}