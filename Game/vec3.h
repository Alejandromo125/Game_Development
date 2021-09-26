#ifndef __VEC3_H__
#define __VEC3_H__

#include"Source/Defs.h"
#include <math.h>

template<class TYPE>
class vec3
{
public:
	TYPE x, y, z;
	vec3() {};

	vec3(const vec3<TYPE>& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}
	vec3(const TYPE& x, const TYPE& y, const TYPE& z)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}
//OPERATORS
	vec3 operator -(const vec3& v) const
	{
		p2Vector3 r;

		r.x = x - v.x;
		r.y = y - v.y;
		r.z = z - v.z;

		return(r);
	}

	vec3 operator + (const vec3& v) const
	{
		p2Vector3 r;

		r.x = x + v.x;
		r.y = y + v.y;
		r.z = z - v.z;

		return(r);
	}

	const vec3& operator -=(const vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return(*this);
	}

	const vec3& operator +=(const vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return(*this);
	}

	bool operator ==(const vec3& v) const
	{
		return (x == v.x && y == v.y && z==v.z);
	}

	bool operator !=(const vec3& v) const
	{
		return (x != v.x || y != v.y || z !=v.z);
	}
//METHODS
	bool IsZero() const
	{
		return (x == 0 && y == 0 && z==0);
	}
	vec3& Normalize()
	{
		TYPE a = this->x;
		TYPE b = this->y;
		TYPE c = this->z;

		TYPE S = sqrtf(a ^ 2 + b ^ 2 + c ^ 2);

		return((a / S), (b / S), (c / S));
	}
	vec3& SetToZero()
	{
		x = y = z = 0;
		return(*this);
	}
	bool IsZero() const
	{
		return (x == 0 && y == 0 && z==0);
	}

	TYPE DistanceTo(const vec3& v) const
	{
		TYPE fx = x - v.x;
		TYPE fy = y - v.y;
		TYPE fz = z - v.z;

		return sqrtf((fx * fx) + (fy * fy)+(fz*fz));
	}
};

#endif