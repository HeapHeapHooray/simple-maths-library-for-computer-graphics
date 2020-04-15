#ifndef MATRIX_FACTORY_H
#define MATRIX_FACTORY_H
#include "Vector3.h"
#include "Matrix4.h"
#include <array>
#include <math.h>
#include "commons.h"

namespace MatrixFactory {

Matrix4 createIdentityMatrix()
{
std::array<float,16> identityMatrix = 
{1,0,0,0,
 0,1,0,0,
 0,0,1,0,
 0,0,0,1};

return Matrix4(identityMatrix);

}

Matrix4 createTranslationMatrix(const Vector3& translation)
{
std::array<float,16> translationMatrix = {1,0,0,0,
                                          0,1,0,0,
                                          0,0,1,0,
                                          translation.x,translation.y,translation.z,1};
return Matrix4(translationMatrix);
}

Matrix4 createScaleMatrix(const Vector3& scale)
{
std::array<float,16> scaleMatrix = {scale.x,0,0,0,
                                    0,scale.y,0,0,
                                    0,0,scale.z,0,
                                    0,0,0,1};
return Matrix4(scaleMatrix);
}

Matrix4 createRotationMatrix(const float angle,const Vector3 &axis)
{
    const float x = axis.x;
    const float y = axis.y;
    const float z = axis.z;
    
    const float radians_angle = convertToRadians(angle);
    
    const float c = cos(radians_angle);
    const float s = sin(radians_angle);
    
    std::array<float,16> rotationMatrix = 
     { x*x*(1.0f-c)+c,   x*y*(1.0f-c)-z*s, x*z*(1.0f-c)+y*s, 0.0f,
       y*x*(1.0f-c)+z*s, y*y*(1.0f-c)+c,   y*z*(1.0f-c)-x*s, 0.0f,
       z*x*(1.0f-c)-y*s, z*y*(1.0f-c)+x*s, z*z*(1.0f-c)+c,   0.0f,
       0.0f,             0.0f,             0.0f,             1.0f };
       
    return Matrix4(rotationMatrix);
}

Matrix4 createPerspectiveProjectionMatrix(const float fov,const float aspect,const float near,const float far)
{

const float tan_of_fov_divided_by_two = tan(convertToRadians(fov)*0.5);

std::array<float,16> perspectiveMatrix = 
{ 1/(aspect*tan_of_fov_divided_by_two),0,0,0,
  0,(1/tan_of_fov_divided_by_two),0,0,
  0,0,(-(far+near)/(far-near)),-1,
  0,0,-((2*far*near)/(far-near)),0};
  
return Matrix4(perspectiveMatrix);  
    
}

Matrix4 createOrthographicProjectionMatrix(const float left,const float right,const float bottom,const float top,const float near,const float far)
{
    
std::array<float,16> orthographicMatrix = 
{ 2/(right-left),0,0,0,
  0,2/(top-bottom),0,0,
  0,0,-2/(far-near),0,
  -((right+left)/(right-left)),-((top+bottom)/(top-bottom)),-((far+near)/(far-near)),1};

return Matrix4(orthographicMatrix);

}

}



#endif