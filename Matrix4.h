#ifndef MATRIX4_H
#define MATRIX4_H
#include <iostream>
#include <array>

class Matrix4 
{
private:

std::array<float,16> elements = {0,0,0,0,
                                 0,0,0,0,
                                 0,0,0,0,
                                 0,0,0,0};

public:

Matrix4()
{
elements = {0,0,0,0,
            0,0,0,0,
            0,0,0,0,
            0,0,0,0};
}

Matrix4(float (&elements)[16])
{
for(uint8_t i = 0;i<16;++i) (*this).elements[i] = elements[i];
}

Matrix4(const std::array<float,16>& elements)
{
for(uint8_t i = 0;i<16;++i) (*this).elements[i] = elements[i];
}

Matrix4(const Matrix4& matrix)
{
for(uint8_t x = 0;x<4;++x)
    for(uint8_t y=0;y<4;++y)
        elements[y*4+x] = matrix.getElement(x,y);
}

float getElement(const uint8_t column,const uint8_t row) const
{
return elements[row*4 + column];
}

void setElement(const uint8_t column,const uint8_t row,const float value)
{
elements[row*4 + column] = value;
}

std::array<float,16> getElements() const
{
return std::array<float,16>(elements);
}

inline Matrix4 add(const Matrix4& matrix)
{
return Matrix4::add(*this,matrix);
}

inline Matrix4 subtract(const Matrix4& matrix)
{
return Matrix4::subtract(*this,matrix);
}

inline Matrix4 multiply(const Matrix4& matrix)
{
    return Matrix4::multiply(*this,matrix);
}

inline Matrix4 multiplyByScalar(const float scalar)
{
    return Matrix4::multiplyByScalar(*this,scalar);
}

static Matrix4 add(const Matrix4& lhs,const Matrix4& rhs)
{
std::array<float,16> lhs_elements = lhs.getElements();
const std::array<float,16> rhs_elements = rhs.getElements();

for(uint8_t i = 0; i < 16; ++i) lhs_elements[i] += rhs_elements[i];

return Matrix4(lhs_elements);
}

static Matrix4 subtract(const Matrix4& lhs,const Matrix4& rhs)
{
std::array<float,16> lhs_elements = lhs.getElements();
const std::array<float,16> rhs_elements = rhs.getElements();

for(uint8_t i = 0; i < 16; ++i) lhs_elements[i] -= rhs_elements[i];

return Matrix4(lhs_elements);
}

static Matrix4 multiplyByScalar(Matrix4 lhs,const float rhs)
{
for(uint8_t x = 0;x<4;++x)
    for(uint8_t y = 0;y<4;++y)
        lhs.setElement(x,y,lhs.getElement(x,y)*rhs);
        
return lhs;
}

static Matrix4 multiply(const Matrix4& lhs,const Matrix4& rhs)
{
const std::array<float,16> l = lhs.getElements();
const std::array<float,16> r = rhs.getElements();
std::array<float,16> result = {0,0,0,0,
                               0,0,0,0,
                               0,0,0,0,
                               0,0,0,0};

result[4*0 + 0] = l[4*0 + 0]*r[4*0 + 0] + l[4*0 + 1]*r[4*1 + 0] + l[4*0 + 2]*r[4*2 + 0]  + l[4*0 + 3]*r[4*3 + 0];
result[4*0 + 1] = l[4*0 + 0]*r[4*0 + 1] + l[4*0 + 1]*r[4*1 + 1] + l[4*0 + 2]*r[4*2 + 1]  + l[4*0 + 3]*r[4*3 + 1];
result[4*0 + 2] = l[4*0 + 0]*r[4*0 + 2] + l[4*0 + 1]*r[4*1 + 2] + l[4*0 + 2]*r[4*2 + 2]  + l[4*0 + 3]*r[4*3 + 2];
result[4*0 + 3] = l[4*0 + 0]*r[4*0 + 3] + l[4*0 + 1]*r[4*1 + 3] + l[4*0 + 2]*r[4*2 + 3]  + l[4*0 + 3]*r[4*3 + 3];

result[4*1 + 0] = l[4*1 + 0]*r[4*0 + 0] + l[4*1 + 1]*r[4*1 + 0] + l[4*1 + 2]*r[4*2 + 0]  + l[4*1 + 3]*r[4*3 + 0];
result[4*1 + 1] = l[4*1 + 0]*r[4*0 + 1] + l[4*1 + 1]*r[4*1 + 1] + l[4*1 + 2]*r[4*2 + 1]  + l[4*1 + 3]*r[4*3 + 1];
result[4*1 + 2] = l[4*1 + 0]*r[4*0 + 2] + l[4*1 + 1]*r[4*1 + 2] + l[4*1 + 2]*r[4*2 + 2]  + l[4*1 + 3]*r[4*3 + 2];
result[4*1 + 3] = l[4*1 + 0]*r[4*0 + 3] + l[4*1 + 1]*r[4*1 + 3] + l[4*1 + 2]*r[4*2 + 3]  + l[4*1 + 3]*r[4*3 + 3];

result[4*2 + 0] = l[4*2 + 0]*r[4*0 + 0] + l[4*2 + 1]*r[4*1 + 0] + l[4*2 + 2]*r[4*2 + 0]  + l[4*2 + 3]*r[4*3 + 0];
result[4*2 + 1] = l[4*2 + 0]*r[4*0 + 1] + l[4*2 + 1]*r[4*1 + 1] + l[4*2 + 2]*r[4*2 + 1]  + l[4*2 + 3]*r[4*3 + 1];
result[4*2 + 2] = l[4*2 + 0]*r[4*0 + 2] + l[4*2 + 1]*r[4*1 + 2] + l[4*2 + 2]*r[4*2 + 2]  + l[4*2 + 3]*r[4*3 + 2];
result[4*2 + 3] = l[4*2 + 0]*r[4*0 + 3] + l[4*2 + 1]*r[4*1 + 3] + l[4*2 + 2]*r[4*2 + 3]  + l[4*2 + 3]*r[4*3 + 3];

result[4*3 + 0] = l[4*3 + 0]*r[4*0 + 0] + l[4*3 + 1]*r[4*1 + 0] + l[4*3 + 2]*r[4*2 + 0]  + l[4*3 + 3]*r[4*3 + 0];
result[4*3 + 1] = l[4*3 + 0]*r[4*0 + 1] + l[4*3 + 1]*r[4*1 + 1] + l[4*3 + 2]*r[4*2 + 1]  + l[4*3 + 3]*r[4*3 + 1];
result[4*3 + 2] = l[4*3 + 0]*r[4*0 + 2] + l[4*3 + 1]*r[4*1 + 2] + l[4*3 + 2]*r[4*2 + 2]  + l[4*3 + 3]*r[4*3 + 2];
result[4*3 + 3] = l[4*3 + 0]*r[4*0 + 3] + l[4*3 + 1]*r[4*1 + 3] + l[4*3 + 2]*r[4*2 + 3]  + l[4*3 + 3]*r[4*3 + 3];

return Matrix4(result);
}

friend std::ostream& operator<<(std::ostream& stream,const Matrix4& matrix)
{
stream << "{ " << matrix.getElement(0,0) << " , " << matrix.getElement(1,0) << " , "<< matrix.getElement(2,0) << " , " << matrix.getElement(3,0) << " }" << std::endl;
stream << "{ " << matrix.getElement(0,1) << " , " << matrix.getElement(1,1) << " , "<< matrix.getElement(2,1) << " , " << matrix.getElement(3,1) << " }" << std::endl;
stream << "{ " << matrix.getElement(0,2) << " , " << matrix.getElement(1,2) << " , "<< matrix.getElement(2,2) << " , " << matrix.getElement(3,2) << " }" << std::endl;
stream << "{ " << matrix.getElement(0,3) << " , " << matrix.getElement(1,3) << " , "<< matrix.getElement(2,3) << " , " << matrix.getElement(3,3) << " }";

return stream;
}

};



#endif
