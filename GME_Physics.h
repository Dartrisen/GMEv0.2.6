//-----------------------------------------------
// Graph_Mode_Engine version 0.2.6
// GME_PHYSICS
// Part of GMEv0.2.6
// Copyright (c) 2012-2016. All rights reserved.
//-----------------------------------------------

#ifndef __GME_PHYSICS_H__
#define __GME_PHYSICS_H__

#include <iostream>
#include <math.h>
#include "GME_Vector.h"

using namespace std;

namespace GME
{
namespace GME_PHYSICS
{
//-------------------------
// GME - Classic Particle
//-------------------------

class ClassicParticle
{
public:
                    ClassicParticle();
        virtual     ~ClassicParticle();
        explicit    ClassicParticle(Vector3& r, Vector3&v, Vector3& a);
        Vector3     position;
        Vector3     velocity;
        Vector3     acceleration;
        float       radius;
        float       mass;
    virtual void    move (const float dt);
    virtual bool    collisionDetect(ClassicParticle& a, ClassicParticle& b) const;
    virtual void    solver(ClassicParticle& a, ClassicParticle& b) const;
};

ClassicParticle::ClassicParticle()
{
	position = Vector3();
    	velocity = Vector3();
	acceleration = Vector3();
}

ClassicParticle::ClassicParticle(Vector3& r, Vector3& v, Vector3& a)
{
	position = (Vector3) r;
    	velocity = (Vector3) v;
	acceleration = (Vector3) a;
}

ClassicParticle::~ClassicParticle()
{

}

void ClassicParticle::move(const float dt)
{
    position += velocity * dt;
    velocity += acceleration * dt;
}

bool ClassicParticle::collisionDetect(ClassicParticle& a, ClassicParticle& b) const
{
	if((a.position-b.position).abs() < (a.radius + b.radius))
		return true;
	else return false;
}

void ClassicParticle::solver(ClassicParticle& a, ClassicParticle& b) const
{
	Vector3 penetrationDirection = (b.position-a.position).normalize();
	float penetrationDepth = (a.radius + b.radius) - (b.position-a.position).abs();
    	a.position -= penetrationDirection * penetrationDepth * 1.0f;
    	b.position += penetrationDirection * penetrationDepth * 1.0f;
}

//------------------------------
// GME - Position Based Particle
//------------------------------

class PositionBasedParticle: public ClassicParticle
{
public:
                    PositionBasedParticle();
        virtual     ~PositionBasedParticle();
        explicit    PositionBasedParticle(Vector3& r, Vector3& a);
        Vector3     position;
        Vector3     acceleration;
        Vector3     delta;
        float       radius;
    virtual void    move(const float dt);
    virtual bool    collisionDetect(PositionBasedParticle& a, PositionBasedParticle& b) const;
    virtual void    solver(PositionBasedParticle& a, PositionBasedParticle& b);
    virtual void    push(Vector3 delta);
};

PositionBasedParticle::PositionBasedParticle()
{
	position = Vector3();
	delta = Vector3();
	acceleration = Vector3();
}

PositionBasedParticle::~PositionBasedParticle()
{

}
    
PositionBasedParticle::PositionBasedParticle(Vector3& r, Vector3& a)
{
    position = (Vector3) r;
    acceleration = (Vector3) a;
}

void PositionBasedParticle::move(const float dt)
{
    delta += acceleration * dt * dt;
    position += delta;
}
    
bool PositionBasedParticle::collisionDetect(PositionBasedParticle& a, PositionBasedParticle& b) const
{
    if((a.position-b.position).abs() < (a.radius + b.radius))
        return true;
    else return false;
}
    
void PositionBasedParticle::solver(PositionBasedParticle& a, PositionBasedParticle& b)
{
        Vector3 penetrationDirection = (b.position-a.position).normalize();
        float penetrationDepth = (a.radius + b.radius) - (b.position-a.position).abs();
        a.push(-penetrationDirection * penetrationDepth * 0.1f);
        b.push(penetrationDirection * penetrationDepth * 0.1f);
    
        Vector3 relativeVelocity = (a.delta - b.delta);
        float bounce = 0.0f;
        float velocity = (1.0f + bounce) * (relativeVelocity * penetrationDirection);
    
        if(velocity>0)
        {
            a.delta += penetrationDirection * velocity * 0.5f;
            b.delta -= penetrationDirection * velocity * 0.5f;
        }


}

void PositionBasedParticle::push(Vector3 delta)
{
  position += delta;
  delta += delta;
}

}//end namespace GME_MATH
}//end namespace GMEngine

#endif /* __GME_PHYSICS_H__ */
