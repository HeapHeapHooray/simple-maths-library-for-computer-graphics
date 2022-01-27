#ifndef VECTOR4_H
#define VECTOR4_H

#include <iostream>
#include <math.h>
#include <array>
#include "Vector3.h"
#include "Matrix4.h"


class Vector4
{
public:
    float x,y,z,w;
    
    Vector4(float x,float y,float z,float w): x(x),y(y),z(z),w(w) {}
    
    Vector4(const Vector4& vector): x(vector.x),y(vector.y),z(vector.z),w(vector.w) {}

    Vector4(const Vector3& vector,float w): x(vector.x),y(vector.y),z(vector.z),w(w) {}
    
    inline Vector4 add(const Vector4& vector) const
    {
    return Vector4::add(*this,vector);
    }
    
    inline Vector4 subtract(const Vector4& vector) const
    {
    return Vector4::subtract(*this,vector);
    }
    
    inline Vector4 multiplyByScalar(const float scalar) const 
    {
    return Vector4::multiplyByScalar(*this,scalar);
    }

    inline Vector4 multiplyByMatrix4(const Matrix4& matrix) const
    {
        return Vector4::multiplyByMatrix4(*this,matrix);
    }
    
    inline float dot(const Vector4& vector) const
    {
    return Vector4::dot(*this,vector);
    }
    
    inline float magnitude() const
    {
    return sqrt(x*x + y*y + z*z + w*w);
    }
    
    inline Vector4 normalize() const 
    {
    const float mag = (*this).magnitude();
     
    return Vector4(x / mag,y / mag, z / mag,w / mag);
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const Vector4& vector)
    {
    stream << "< " << vector.x << " , " << vector.y << " , " << vector.z << " , " << vector.w << " > ";
    return stream;
    }
    
    inline static Vector4 add(Vector4 lhs,const Vector4& rhs)
    {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    
    return lhs;
    }
    
    inline static Vector4 subtract(Vector4 lhs,const Vector4& rhs)
    {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    
    return lhs;
    }
    
    inline static Vector4 multiplyByScalar(Vector4 lhs,const float rhs)
    {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;
        
    return lhs;
    }

    inline static Vector4 multiplyByMatrix4(const Vector4& lhs,const Matrix4& rhs)
    {
    std::array<float,16> matrixElements = rhs.getElements();

    std::array<float,4> result = {0.0f,0.0f,0.0f,0.0f};

    result[0] = lhs.x*matrixElements[4*0 + 0] + lhs.y*matrixElements[4*1 + 0] + lhs.z*matrixElements[4*2 + 0] + lhs.w*matrixElements[4*3 + 0];
    result[1] = lhs.x*matrixElements[4*0 + 1] + lhs.y*matrixElements[4*1 + 1] + lhs.z*matrixElements[4*2 + 1] + lhs.w*matrixElements[4*3 + 1];
    result[2] = lhs.x*matrixElements[4*0 + 2] + lhs.y*matrixElements[4*1 + 2] + lhs.z*matrixElements[4*2 + 2] + lhs.w*matrixElements[4*3 + 2];
    result[3] = lhs.x*matrixElements[4*0 + 3] + lhs.y*matrixElements[4*1 + 3] + lhs.z*matrixElements[4*2 + 3] + lhs.w*matrixElements[4*3 + 3];

    Vector4 result_as_vec4 = Vector4(result[0],result[1],result[2],result[3]);

    return result_as_vec4;
    }
    
    inline static float dot(const Vector4& lhs,const Vector4& rhs)
    {
    return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z + lhs.w*rhs.w;
    }
    
};



#endif