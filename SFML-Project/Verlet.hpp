
#pragma once

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Log.hpp"

using Vec2f = sf::Vector2f;

template<typename T>
struct VerletData
{
public:
	T position_cur;
	T position_pre;
	T acceleration;

	VerletData() {}

	VerletData(T position)
	{
		position_cur = position_pre = position;				
	}

	void UpdatePosition(float dt)
	{
		const T velocity = position_cur - position_pre;
		position_pre = position_cur;
		position_cur = position_cur + velocity + acceleration * dt * dt;
		
		acceleration = {};
	}
};

using VerletData2D = VerletData<Vec2f>;