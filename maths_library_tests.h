#ifndef MATHS_LIBRARY_TESTS_H
#define MATHS_LIBRARY_TESTS_H

#include <iostream>
#include <array>
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "MatrixFactory.h"

namespace MathsLibraryTests
{

void testVector3()
{
    std::cout << "Vector3 Tests: " << std::endl;
    Vector3 vectorA = Vector3(1,2,3);
    const Vector3 vectorB = Vector3(4,5,6);
    std::cout << "Vector A: " << vectorA << std::endl;
    std::cout << "Vector B: " << vectorB << std::endl;
    std::cout << "A + B : " << Vector3::add(vectorA,vectorB) << std::endl;
    std::cout << "A - B : " << vectorB.subtract(vectorA) << std::endl;
    std::cout << "Magnitude of A: " << vectorA.magnitude() << std::endl;
    std::cout << "Dot Product of A and B: " << Vector3::dot(vectorA,vectorB) << std::endl;
    std::cout << "Cross Product of A and B: " << Vector3::cross(vectorA,vectorB) << std::endl;
    std::cout << "Normalized A: " << vectorA.normalize() << std::endl;
    std::cout << "Vector A multiplied by scalar 3 : " << vectorA.multiplyByScalar(3) << std::endl;
}

void testVector4()
{
    std::cout << "Vector4 Tests: " << std::endl;
    Vector4 vectorA = Vector4(1,2,3,4);
    const Vector4 vectorB = Vector4(Vector3(5,6,7),8);
    std::cout << "Vector A: " << vectorA << std::endl;
    std::cout << "Vector B: " << vectorB << std::endl;
    std::cout << "A + B : " << Vector4::add(vectorA,vectorB) << std::endl;
    std::cout << "A - B : " << vectorB.subtract(vectorA) << std::endl;
    std::cout << "Magnitude of A: " << vectorA.magnitude() << std::endl;
    std::cout << "Dot Product of A and B: " << Vector4::dot(vectorA,vectorB) << std::endl;
    std::cout << "Normalized A: " << vectorA.normalize() << std::endl;
    std::cout << "Vector A multiplied by scalar 3 : " << vectorA.multiplyByScalar(3) << std::endl;
}

void testMatrix4()
{
    std::cout << "Matrix4 Tests: " << std::endl;
    float elements[16] = {1,2,3,4,
                      5,6,7,8,
                      9,10,11,12,
                      13,14,15,16};
    Matrix4 matrixA = Matrix4(elements);
    std::cout << "Matrix A: " << std::endl << matrixA << std::endl;
    Matrix4 matrixB = Matrix4(matrixA);
    matrixB.setElement(3,3,42);
    std::cout << "Matrix B: " << std::endl << matrixB << std::endl;
    std::array<float,16> elementsB = matrixB.getElements();
    std::cout << "Elements of Matrix B: ";
    for(uint8_t i = 0;i<15;++i) std::cout << elementsB[i] << " , ";
    std::cout << elementsB[15];
    std::cout << std::endl;
    std::cout << "A + B : " << std::endl << Matrix4::add(matrixA,matrixB) << std::endl;
    std::cout << "A - B : " << std::endl << matrixA.subtract(matrixB) << std::endl;
    std::cout << "A * B : " << std::endl << Matrix4::multiply(matrixA,matrixB) << std::endl;
    std::cout << "Matrix A multiplied by scalar 3 : " << std::endl << matrixA.multiplyByScalar(3) << std::endl;
}

void testMatrixFactory()
{
    std::cout << "Matrix Factory Tests: " << std::endl;
    std::cout << "Identity Matrix: " << std::endl << MatrixFactory::createIdentityMatrix() << std::endl;
    std::cout << "Translation Matrix: " << std::endl << MatrixFactory::createTranslationMatrix(Vector3(1,2,3)) << std::endl;
    std::cout << "Scale Matrix: " << std::endl << MatrixFactory::createScaleMatrix(Vector3(1,2,3)) << std::endl;
    std::cout << "Rotation Matrix: " << std::endl << MatrixFactory::createRotationMatrix(45.0f,Vector3(0,1,0)) << std::endl;
    std::cout << "Perspective Matrix: " << std::endl << MatrixFactory::createPerspectiveProjectionMatrix(45.0f,4.0f/3.0f,0.1f,100.0f) << std::endl;
    std::cout << "Orthographic Matrix: " << std::endl << MatrixFactory::createOrthographicProjectionMatrix(-1,1,-1,1,-300.0f,300.0f) << std::endl;
}

void testAll()
{
    testVector3();
    testVector4();
    testMatrix4();
    testMatrixFactory();
}

}

#endif
