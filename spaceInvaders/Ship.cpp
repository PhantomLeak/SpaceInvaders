// file: Ship.cpp
// lab: 11
//by: Dylan Stocking
//org: cop 2001, 2021 10410
//Des: implementation of a player Ship block class object
//-----------------------------------------------------

#include <math.h> // velocity checking
#include "Ship.h"

const float ACCEL_SPEED = 6.0;
const float MAX_SPEED = 300.0;

// Constructors
/**
default constructor - initialize emtpy block
*/
Ship::Ship() 
{
  ship = Block();
	currentX = 0.0;
	currentY = 0.0;
	velocity = 0.0;
}

/**
properties constructor - initialize to parameter values
*/
Ship::Ship(int x, int y, int width, int height, fgcugl::Color color)
{
	ship = Block(x, y, width, height, color);
	currentX = x;
	currentY = y;
	velocity = 0.0;

}

// accessors
//-----------------------------------------------------
// getters
Block Ship::getPaddle() { return ship; }		// READ ONLY
float Ship::getXCoordinate() { return currentX; }
float Ship::getYCoordinate() { return currentY; }
int Ship::getWidth() { return ship.getWidth(); }
int Ship::getHeight() { return ship.getHeight(); }
float Ship::getVelocity() { return velocity; }
fgcugl::Color Ship::getColor() { return ship.getColor(); }

// setters
void Ship::setXCoordinate(float value)
{
	currentX = value;
	ship.setXCoordinate(value);
}
void Ship::setYCoordinate(float value)
{
	currentY = value;
	ship.setYCoordinate(value);
}
void Ship::setWidth(int value) { ship.setWidth(value); }
void Ship::setHeight(int value) { ship.setHeight(value); }
void Ship::setVelocity(float value) { velocity = value; }
void Ship::setColor(fgcugl::Color value) { ship.setColor(value); }

// member methods
//-----------------------------------------------------
int Ship::top() { return ship.top(); }
int Ship::bottom() { return ship.bottom(); }
int Ship::left() { return ship.left(); }
int Ship::right() { return ship.right(); }

/**
* return true if block is empty (width + height is zero)
*/
bool Ship::isEmpty() { return ship.isEmpty(); }

/**
Determine current Ship movement direction from 
its velocity (None = 0, Left = negative, Right = Positive)
Returns:
PaddleDirection - direction Ship is moving
*/

Ship::ShipDirection Ship::currentDirection() 
{
	ShipDirection direction;

	if (fpclassify(velocity) == FP_ZERO)
	{
		direction = None;
	}
	else if (signbit(velocity))
	{
		direction = Left;
	}
	else
	{
		direction = Right;
	}

	return direction;
}

/**
Update location of the Ship each frame relative to lag
and perform collision checking with left and right walls
Parameters:
Next		- user keyboard input
leftWall	- location of left wall
rightWall	- location of right wall
lag			- current frame lag
*/
void Ship::update(ShipDirection next, Block leftWall, Block rightWall, float lag)
{
	ShipDirection curDir = currentDirection();

	// player not holding a direction key
	if (next == None)
	{
		// if Ship is moving
		if (curDir != None)
		{
			// slow Ship to a stop
			if (curDir == Left)
			{
				velocity += ACCEL_SPEED;
			}
			else
			{
				velocity -= ACCEL_SPEED;
			}
		} // Ship is moving
	} 
	// player is holding a direciton key down.
	else
	{
		// accelerate Ship in user direction
		if (next == Left)
		{
			velocity -= ACCEL_SPEED;
		}
		else
		{
			velocity += ACCEL_SPEED;
		} // accel

		// keep speed at or below max
		if (abs(velocity) > MAX_SPEED)
		{
			if (next == Left)
			{
				velocity = -MAX_SPEED;
			}
			else
			{
				velocity = MAX_SPEED;
			}
		}// max speed

	} // Holding direction key

	// adjust Ship position
	currentX += velocity * lag;
	ship.setXCoordinate(currentX);

	// Check for collision with walls
	if (left() < leftWall.right())
	{
		velocity = 0.0;
		setXCoordinate(leftWall.right() + 1);
	}
	else if (right() > rightWall.left())
	{
		velocity = 0.0;
		setXCoordinate(rightWall.left() - getWidth());
	}

}// update



/**
draw a Ship object on the OpenGL window relative to 
current x/y with lag
*/
void Ship::draw(float lag)
{
	float x = currentX + velocity * lag;
	Block currentPos(ship);
	currentPos.setXCoordinate(x);
	currentPos.draw();
}

/**
* draw a Ship with a border by drawing the block passed in on top
* of a background block
*
* Paramaters:
* borderColor	color of the border block
* borderSize	size of the border in pixels
*/
void Ship::drawWithBorder(float lag,fgcugl::Color borderColor, int borderSize)
{
	float x = currentX + velocity * lag;
	float y = currentY;
	int width = ship.getWidth();
	int height = ship.getHeight();
	fgcugl::Color color = ship.getColor()
		;
	// draw background block
	Block background = Block(x, y, width, height, borderColor);
	background.draw();
	Block foreground = Block(x + borderSize, y + borderSize, 
		width - 2 * borderSize,
		height - 2 * borderSize, color);
	foreground.draw();
}