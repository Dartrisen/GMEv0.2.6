//-----------------------------------------------
// Graph_Mode_Engine version 0.2.5
// GME_MATH_VECTORS
// Part of GMEv0.2.5
// Copyright (c) 2012-2015. All rights reserved.
//-----------------------------------------------

#ifndef __MATH_VECTOR_H__
#define __MATH_VECTOR_H__
#include <math.h>
#include <iostream>

using namespace std;

namespace GME
{
namespace GME_PHYSICS
{

//-------------------------
// GME - Vector2d
//-------------------------

class Vector2
{
public:
	float 		x, y;
			Vector2();
			~Vector2();

	explicit	Vector2(const float x, const float y);
			Vector2(const Vector2& r);
	Vector2		operator - () const;
	Vector2& 	operator = (const Vector2& r);
	Vector2 	operator + (const Vector2& r) const;
	Vector2& 	operator += (const Vector2& r);
	Vector2 	operator - (const Vector2& r) const;
	Vector2& 	operator -= (const Vector2& r);
	Vector2 	operator * (const float scalar);
	float 		operator * (const Vector2 &r) const;
	Vector2 	Normalize();
	float 		Angle(Vector2 &a, Vector2 &b);
	void 		Assign(const float x, const float y);
	float 		SqrAbs();
	float 		Abs();
	void 		show();
};

inline Vector2::Vector2(void) // default constructor
{
	x=0.0f; y=0.0f;
}

inline Vector2::Vector2(float x, float y) //constructor
{
	this->x=x; this->y=y;
}

inline Vector2::~Vector2(void)//default destructor
{

}

inline Vector2 Vector2::Normalize(void)
{
	float l = (x*x + y*y);
	return Vector2(x/l, y/l);
}

inline float Vector2::Angle(Vector2 &a, Vector2 &b)
{	
	return (float) (a*b)/(a.Abs()*b.Abs());//don't use a.Abs(), if a=const
}

inline void Vector2::Assign(const float x, const float y)
{
	this->x = x; this->y = y;
}

inline float Vector2::Abs(void)
{
	return (float) sqrt(x*x + y*y);
}

inline float Vector2::SqrAbs(void)
{
	return (float) x*x + y*y;
}

void Vector2::show(void)
{
	cout << x << y <<endl;
}

inline Vector2 Vector2::operator - (void) const
{
	return Vector2(-x, -y);
}

inline Vector2& Vector2::operator = (const Vector2& r)
{
	x = r.x; y = r.y;
	return (*this);
}

inline Vector2 Vector2::operator + (const Vector2& r) const
{
	return Vector2(x + r.x, y + r.y);
}

inline Vector2& Vector2::operator += (const Vector2& r)
{
	x = x + r.x; y = y + r.y;
	return (*this);
}

inline Vector2 Vector2::operator - (const Vector2& r) const
{
	return Vector2(x - r.x, y - r.y);
}

inline Vector2& Vector2::operator -= (const Vector2& r)
{
	x = x - r.x; y = y - r.y;
	return (*this);
}

inline Vector2 Vector2::operator * (const float scalar)//multiplying a vector by scalar
{
	return Vector2(x*scalar, y*scalar);
}

inline float Vector2::operator * (const Vector2 &r) const//dot product
{
	return (float) x*r.x + y*r.y;
}

//----------------------
// GME - Vector3d
//----------------------

class Vector3
{
public:
	float 		x, y, z;
			Vector3();
			~Vector3();

	explicit 	Vector3 (const float x, const float y, const float z);
	Vector3		operator - () const;
	Vector3& 	operator = (const Vector3& r);
	Vector3 	operator + (const Vector3& r) const;
	Vector3& 	operator += (const Vector3& r);
	Vector3 	operator - (const Vector3& r) const;
	Vector3& 	operator -= (const Vector3& r);
	Vector3 	operator * (const Vector3& r);
	Vector3 	operator * (const float scalar);
	float 		operator * (const Vector3& r) const;
	Vector3 	Normalize();
	void 		Assign(const float x, const float y, const float z);
	float 		SqrAbs();
	float 		Abs();
	void 		show();
};

inline Vector3::Vector3(void) // default constructor
{
	x=0.0f; y=0.0f; z=0.0f;
}

inline Vector3::Vector3(const float x, const float y, const float z) //constructor
{
	this->x=x; this->y=y; this->z=z;
}

inline Vector3::~Vector3(void)//default destructor
{

}

inline Vector3 Vector3::Normalize(void)
{
	float l = (x*x + y*y + z*z);
	return Vector3(x/l, y/l, z/l);
}

inline void Vector3::Assign(const float x, const float y, const float z)
{
	this->x = x; this->y = y; this->z = z;
}

inline float Vector3::Abs(void)
{
	return (float) sqrt(x*x + y*y + z*z);
}

inline float Vector3::SqrAbs(void)
{
	return (float) x*x + y*y + z*z;
}

void Vector3::show(void)
{
	cout << x << y << z <<endl;
}

inline Vector3 Vector3::operator - () const
{
	return Vector3(-x, -y, -z);
}

inline Vector3& Vector3::operator = (const Vector3& r)
{
	x = r.x; y = r.y; z = r.z;
	return (*this);
}

inline Vector3 Vector3::operator + (const Vector3& r) const
{
	return Vector3(x + r.x, y + r.y, z + r.z);
}

inline Vector3& Vector3::operator += (const Vector3& r)
{
	x = x + r.x; y = y + r.y; z = z + r.z;
	return (*this);
}

inline Vector3 Vector3::operator - (const Vector3& r) const
{
	return Vector3(x - r.x, y - r.y, z - r.z);
}

inline Vector3& Vector3::operator -= (const Vector3& r)
{
	x = x - r.x; y = y - r.y; z = z - r.z;
	return (*this);
}

inline Vector3 Vector3::operator * (const float scalar)//multiplying a vector by scalar
{
	return Vector3(x*scalar, y*scalar, z*scalar);
}

inline float Vector3::operator * (const Vector3& r) const//dot product
{
	return (float) x*r.x + y*r.y + z*r.z;
}

inline Vector3 Vector3::operator * (const Vector3& r)//cross product
{
	return Vector3 ((y * r.z) - (z * r.y),
		(z * r.x) - (x * r.z),
		(x * r.y) - (y * r.x));
}

}//end namespace GME_MATH
}//end namespace GMEngine

#endif /* __MATH_VECTOR_H__ */
