#include "Vector3.h"

float Vector3::distanceFrom(const Vector3& vec)
{
	return (float)sqrt((x - vec.getX()) * (x - vec.getX()) + (y - vec.getY()) * (y - vec.getY()) + (z - vec.getZ()) * (z - vec.getZ()));	
}

float Vector3::length()
{
	return (float)sqrt(x*x + y*y + z*z);
}

float Vector3::dot(const Vector3& vec)
{
	return  x * vec.getX() + y * vec.getY() + z * vec.getZ();
}

void Vector3::normalize()
{
	x/=length();
	y/=length();
	z/=length();
}

Vector3& Vector3::normalized()
{
	float X,Y,Z;
	X = x / length();
	Y = y / length();
	Z = z / length();
	return Vector3(X,Y,Z);
}

void Vector3::increment(float amount, float xmask, float ymask, float zmask)
{
	x += xmask * amount;
	y += ymask * amount;
	z += zmask * amount;
}

void Vector3::set(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Vector3::print()
{
	printf("[%.3f, %.3f, %.3f]\n", x, y, z);
}
