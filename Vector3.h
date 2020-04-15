#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <math.h>

class Vector3
{
public:
    float x,y,z;
    
    Vector3(float x,float y,float z): x(x),y(y),z(z) {}
    
    Vector3(const Vector3& vector): x(vector.x),y(vector.y),z(vector.z) {}
    
    inline Vector3 add(const Vector3& vector) const
    {
    return Vector3::add(*this,vector);
    }
    
    inline Vector3 subtract(const Vector3& vector) const
    {
    return Vector3::subtract(*this,vector);
    }
    
    inline Vector3 multiplyByScalar(const float scalar) const 
    {
    return Vector3::multiplyByScalar(*this,scalar);
    }
    
    inline float dot(const Vector3& vector) const
    {
    return Vector3::dot(*this,vector);
    }
    
    inline float magnitude() const
    {
    return sqrt(x*x + y*y + z*z);
    }
    
    inline Vector3 normalize() const 
    {
    const float mag = (*this).magnitude();
     
    return Vector3(x / mag,y / mag, z / mag);
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
    {
    stream << "< " << vector.x << " , " << vector.y << " , " << vector.z << " > ";
    return stream;
    }
    
    inline static Vector3 add(Vector3 lhs,const Vector3& rhs)
    {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    
    return lhs;
    }
    
    inline static Vector3 subtract(Vector3 lhs,const Vector3& rhs)
    {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    
    return lhs;
    }
    
    inline static Vector3 multiplyByScalar(Vector3 lhs,const float rhs)
    {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
        
    return lhs;
    }
    
    inline static float dot(const Vector3& lhs,const Vector3& rhs)
    {
    return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
    }
    
    inline static Vector3 cross(const Vector3& lhs,const Vector3& rhs)
    {
    return Vector3(((lhs.y*rhs.z)-(lhs.z*rhs.y)),
                 -((lhs.x*rhs.z)-(lhs.z*rhs.x)),
                  ((lhs.x*rhs.y)-(lhs.y*rhs.x)));
    }
    
};



#endif