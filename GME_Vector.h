//-----------------------------------------------
// Graph_Mode_Engine version 0.2.5
// GME_MATH_VECTORS
// Part of GMEv0.2.5
// Copyright (c) 2012-2016. All rights reserved.
//-----------------------------------------------

#ifndef __MATH_VECTOR_H__
#define __MATH_VECTOR_H__
#include <cmath>

//-------------------------
// GME - Vector2d
//-------------------------

class Vector2
{
public:
		float 			x, y;
					Vector2();
					~Vector2();
		explicit 		Vector2(float x, float y);
					Vector2(const Vector2& r);
		Vector2 		operator - () const;
		Vector2&		operator = (const Vector2& r);
		Vector2 		operator + (const Vector2& r) const;
		Vector2& 		operator += (const Vector2& r);
		Vector2 		operator - (const Vector2& r) const;
		Vector2&		operator -= (const Vector2& r);
		Vector2 		operator * (const float scalar);
		float 			operator * (const Vector2& r) const;
        	bool            	operator == (const Vector2& r) const;
        	bool            	compare(const Vector2& r) const;
		Vector2 		normalize();
		float 			angle(const Vector2 &a, const Vector2 &b);
		void 			assign(float x, float y);
		float 			sqrAbs() const;
		float 			abs() const;
};

Vector2::Vector2() // default constructor
{
	this->x = 0.0f; this->y = 0.0f;
}

Vector2::Vector2(float x, float y) //constructor
{
	this->x = x; this->y = y;
}

Vector2::Vector2(const Vector2& r)
{
    this->x = r.x; this->y = r.y;
}

Vector2::~Vector2()//default destructor
{
    
}

bool Vector2::compare(const Vector2& r) const
{
    return ((this->x == r.x) && (this->y == r.y));
}

Vector2 Vector2::normalize()
{
	float l = sqrt(x*x + y*y);
	return Vector2(x/l, y/l);
}

float Vector2::angle(const Vector2 &a, const Vector2 &b)
{
	return (float) (a*b)/(a.abs()*b.abs());
}

void Vector2::assign(float x, float y)
{
	this->x = x; this->y = y;
}

float Vector2::abs() const
{
	return (float) sqrt(x*x + y*y);
}

float Vector2::sqrAbs() const
{
	return (float) x*x + y*y;
}

Vector2 Vector2::operator - () const
{
	return Vector2 (-x, -y);
}

Vector2& Vector2::operator = (const Vector2& r)
{
	this->x = r.x; this->y = r.y;
	return (*this);
}

Vector2 Vector2::operator + (const Vector2& r) const
{
	return Vector2(x + r.x, y + r.y);
}

Vector2& Vector2::operator += (const Vector2& r)
{
	this->x += r.x; this->y += r.y;
	return (*this);
}

Vector2 Vector2::operator - (const Vector2& r) const
{
	return Vector2(x - r.x, y - r.y);
}

Vector2& Vector2::operator -= (const Vector2& r)
{
	this->x -= r.x; this->y -= r.y;
	return (*this);
}

Vector2 Vector2::operator * (const float scalar)
{
	return Vector2(x*scalar, y*scalar);
}

float Vector2::operator * (const Vector2& r) const//dot product
{
	return (float) x*r.x + y*r.y;
}

bool Vector2::operator==(const Vector2& r) const
{
    return compare(r);
}

//----------------------
// GME - Vector3
//----------------------

class Vector3
{
public:
		float 			x, y, z;
					Vector3();
					~Vector3();
		explicit 		Vector3(float x, float y, float z);
					Vector3(const Vector3& r);
		Vector3 		operator - () const;
		Vector3&		operator = (const Vector3& r);
		Vector3 		operator + (const Vector3& r) const;
		Vector3& 		operator += (const Vector3& r);
		Vector3 		operator - (const Vector3& r) const;
		Vector3&		operator -= (const Vector3& r);
		Vector3 		operator * (const float scalar);
		float 			operator * (const Vector3& r) const;
		//Vector3&		operator * (const Vector3& r) const;
        	bool            	operator == (const Vector3& r) const;
        	bool            	compare(const Vector3& r) const;
		Vector3 		normalize();
		float 			angle(const Vector3 &a, const Vector3 &b);
		void 			assign(float x, float y, float z);
		float 			sqrAbs() const;
		float 			abs() const;
};

inline Vector3::Vector3() // default constructor
{
	this->x=0.0f; this->y=0.0f; this->z=0.0f;
}

inline Vector3::Vector3(float x, float y, float z) //constructor
{
	this->x = x; this->y = y; this->z = z;
}

inline Vector3::Vector3(const Vector3& r)
{
    this->x = r.x; this->y = r.y; this->z = r.z;
}

inline Vector3::~Vector3()//default destructor
{

}

inline bool Vector3::compare(const Vector3& r) const
{
    return ( (this->x == r.x) && (this->y == r.y) && (this->z == r.z) );
}

inline Vector3 Vector3::normalize()
{
	float l = sqrt(x*x + y*y + z*z);
	return Vector3(x/l, y/l, z/l);
}

inline float Vector3::angle(const Vector3 &a, const Vector3 &b)
{
	return (float) (a*b)/(a.abs()*b.abs());
}

inline void Vector3::assign(float x, float y, float z)
{
	this->x = x; this->y = y; this->z = z;
}

inline float Vector3::abs() const
{
	return (float) sqrt(x*x + y*y + z*z);
}

inline float Vector3::sqrAbs() const
{
	return (float) x*x + y*y + z*z;
}

inline Vector3 Vector3::operator - () const
{
	return Vector3 (-x, -y, -z);
}

inline Vector3& Vector3::operator = (const Vector3& r)
{
	this->x = r.x; this->y = r.y; this->z = r.z;
	return (*this);
}

inline Vector3 Vector3::operator + (const Vector3& r) const
{
	return Vector3(x + r.x, y + r.y, z + r.z);
}

inline Vector3& Vector3::operator += (const Vector3& r)
{
	this->x += r.x; this->y += r.y; this->z += r.z;
	return (*this);
}

inline Vector3 Vector3::operator - (const Vector3& r) const
{
	return Vector3(x - r.x, y - r.y, z - r.z);
}

inline Vector3& Vector3::operator -= (const Vector3& r)
{
	this->x -= r.x; this->y -= r.y; this->z -= r.z;
	return (*this);
}

inline Vector3 Vector3::operator * (const float scalar)
{
	return Vector3(x*scalar, y*scalar, z*scalar);
}

inline float Vector3::operator * (const Vector3& r) const//dot product
{
	return (float) x*r.x + y*r.y + z*r.z;
}

/*Vector3& Vector3::operator * (const Vector3& r) const//cross product
{
	return Vector3 ((y * r.z) - (z * r.y),
		(z * r.x) - (x * r.z),
		(x * r.y) - (y * r.x));
}*/

inline bool Vector3::operator==(const Vector3& r) const
{
    return compare(r);
}

#endif /* __MATH_VECTOR_H__ */
