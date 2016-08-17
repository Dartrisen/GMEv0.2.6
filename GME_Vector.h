//-----------------------------------------------
// Graph_Mode_Engine version 0.2.6
// GME_MATH_VECTORS
// Part of GMEv0.2.6
// Copyright (c) 2012-2016. All rights reserved.
//-----------------------------------------------

#ifndef __MATH_VECTOR_H__
#define __MATH_VECTOR_H__
#include <cmath>

//----------------------
// GME - Vector3d
//----------------------

template<class T>
class Vector3
{
public:
		T 			x, y, z;
					Vector3(): x(0), y(0), z(0){};
		virtual			~Vector3();
		explicit 		Vector3(T x, T y, T z): x(x), y(y), z(z){};
					Vector3(const Vector3& r);
		Vector3 		operator - () const;
		Vector3&		operator = (const Vector3& r);
		Vector3 		operator + (const Vector3& r) const;
		Vector3& 		operator += (const Vector3& r);
		Vector3 		operator - (const Vector3& r) const;
		Vector3&		operator -= (const Vector3& r);
		Vector3 		operator * (const float scalar);
		float 			operator * (const Vector3& r) const;
        	bool            	operator == (const Vector3& r) const;
        	bool            	compare(const Vector3& r) const;
		Vector3 		normalize();
		float 			angle(const Vector3 &a, const Vector3 &b);
		void 			assign(float x, float y, float z);
		float 			sqrAbs() const;
		float 			abs() const;
};

#endif /* __MATH_VECTOR_H__ */
