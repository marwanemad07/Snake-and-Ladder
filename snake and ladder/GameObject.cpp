#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	if(pos.IsValidCell())
		position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

void GameObject::setPosition(CellPosition pos) {
	position = pos;
}

bool GameObject::IsOverLapping(GameObject* newObj) const
{

	return false;
	// Emad,, i'll check if it should be pure or just virtual
}

bool GameObject::IntersectWithSnake(GameObject* newObj) const
{
	return false;
}
bool GameObject::IntersectWithLadder(GameObject* newObj) const
{
	return false;
}

GameObject::~GameObject()
{
}