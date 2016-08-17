#include "GME_Vector.h"

inline Vector3::Vector3(const Vector3& r)
{
    this->x = r.x; this->y = r.y; this->z = r.z;
}

inline Vector3::~Vector3()
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
