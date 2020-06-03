// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:

void printMatrix(mat3 m) {
    printf("--MATRIX--\n");
    printf("%f %f %f\n", m[0][0], m[0][1], m[0][2]);
    printf("%f %f %f\n", m[1][0], m[1][1], m[1][2]);
    printf("%f %f %f\n", m[2][0], m[2][1], m[2][2]);
}

void printVector(vec3 v) {

}

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
    // YOUR CODE FOR HW1 HERE
    //mat3 res = R(degrees) * axis;
    
    // Rodrigues rotation formula
    // Rotation matrix R = cos(angle)*I + sin(angle)*K + (1-cos(angle))*(K*transpose(K))
    // K is the cross-product matrix of the given axis

    vec3 K1 = vec3(0, -axis.z, axis.y);
    vec3 K2 = vec3(axis.z, 0, -axis.x);
    vec3 K3 = vec3(-axis.y, axis.x, 0);
    mat3 K = mat3(K1, K2, K3);

    float radians = glm::radians(degrees);

    mat3 identityMatrix;
    mat3 A = sin(radians)*K;
    mat3 B = (1 - cos(radians)) * (K * glm::transpose(K)); // glm::matrixCompMult(K, K);

    // wikipedia rotation matrix

    mat3 result = cos(radians)*identityMatrix + A + B;
    result[0] = glm::normalize(result[0]);
    result[1] = glm::normalize(result[1]);
    result[2] = glm::normalize(result[2]);
    
    return result;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE

    vec3 result;
    mat3 rotationMatrix = rotate(degrees, up);
    //printMatrix(rotationMatrix);
    result.x = glm::dot(rotationMatrix[0], eye);
    result.y = glm::dot(rotationMatrix[1], eye);
    result.z = glm::dot(rotationMatrix[2], eye);

    eye = result;

    printf("DONE!\n");
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE

    vec3 result;
    vec3 foo = glm::normalize(glm::cross(eye, up));

    mat3 rotationMatrix = rotate(degrees, foo);
    printMatrix(rotationMatrix);
    result.x = glm::dot(rotationMatrix[0], eye);
    result.y = glm::dot(rotationMatrix[1], eye);
    result.z = glm::dot(rotationMatrix[2], eye);

    eye = result;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}