// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:

void Transform::printMatrix(mat4 m) {
    printf("--MATRIX--\n");
    printf("%f %f %f %f\n", m[0][0], m[0][1], m[0][2], m[0][3]);
    printf("%f %f %f %f\n", m[1][0], m[1][1], m[1][2], m[1][3]);
    printf("%f %f %f %f\n", m[2][0], m[2][1], m[2][2], m[2][3]);
    printf("%f %f %f %f\n", m[3][0], m[3][1], m[3][2], m[3][3]);
}

void Transform::printMatrix(mat3 m) {
    printf("--MATRIX--\n");
    printf("%f %f %f\n", m[0][0], m[0][1], m[0][2]);
    printf("%f %f %f\n", m[1][0], m[1][1], m[1][2]);
    printf("%f %f %f\n", m[2][0], m[2][1], m[2][2]);
}

void printVector(vec3 v) {
    printf("--VECTOR--\n");
    printf("%f %f %f\n", v[0], v[1], v[2]);
}

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
    // YOUR CODE FOR HW1 HERE
    
    // Rodrigues rotation formula
    // Rotation matrix R = cos(angle)*I + sin(angle)*K + (1-cos(angle))*(K*transpose(K))
    // K is the cross-product matrix of the given axis

    // create the cross-product matrix
    vec3 cp1 = vec3(0, -axis.z, axis.y);
    vec3 cp2 = vec3(axis.z, 0, -axis.x);
    vec3 cp3 = vec3(-axis.y, axis.x, 0);
    mat3 crossProductMatrix = mat3(cp1, cp2, cp3);

    // create the outer product matrix
    vec3 op1 = vec3(axis.x * axis.x, axis.x * axis.y, axis.x * axis.z);
    vec3 op2 = vec3(axis.x * axis.y, axis.y * axis.y, axis.y * axis.z);
    vec3 op3 = vec3(axis.x * axis.z, axis.y * axis.z, axis.z * axis.z);
    mat3 outerProductMatrix = mat3(op1, op2, op3);

    mat3 identityMatrix(1.0);
    mat3 A = sin(glm::radians(degrees)) * crossProductMatrix;
    mat3 B = (1 - cos(glm::radians(degrees))) * outerProductMatrix;

    // wikipedia rotation matrix

    mat3 result = cos(glm::radians(degrees)) * identityMatrix + B + A;
    result[0] = normalize(result[0]);
    result[1] = normalize(result[1]);
    result[2] = normalize(result[2]);
    
    return result;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE

    vec3 result(1.0);
    mat3 rotationMatrix = rotate(degrees, up);
    eye = rotationMatrix * eye;
    up = rotationMatrix * up;
/*
    eye.x = rotationMatrix[0][0] * eye[0] + rotationMatrix[1][0] * eye[1] + rotationMatrix[2][0] * eye[2];
    eye.y = rotationMatrix[0][1] * eye[0] + rotationMatrix[1][1] * eye[1] + rotationMatrix[2][1] * eye[2];
    eye.z = rotationMatrix[0][2] * eye[0] + rotationMatrix[1][2] * eye[1] + rotationMatrix[2][2] * eye[2];

    up.x = rotationMatrix[0][0] * up[0] + rotationMatrix[1][0] * up[1] + rotationMatrix[2][0] * up[2];
    up.y = rotationMatrix[0][1] * up[0] + rotationMatrix[1][1] * up[1] + rotationMatrix[2][1] * up[2];
    up.z = rotationMatrix[0][2] * up[0] + rotationMatrix[1][2] * up[1] + rotationMatrix[2][2] * up[2];
*/
}

int i = 2;
// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE

    vec3 result(1.0);
    vec3 axisOfRotation = normalize(cross(eye, up)); // swapping eye and up changes the rotation direction
    mat3 rotationMatrix = rotate(degrees, axisOfRotation);

    eye = rotationMatrix * eye;
    up = rotationMatrix * up;

/*
    eye.x = rotationMatrix[0][0] * eye[0] + rotationMatrix[1][0] * eye[1] + rotationMatrix[2][0] * eye[2];
    eye.y = rotationMatrix[0][1] * eye[0] + rotationMatrix[1][1] * eye[1] + rotationMatrix[2][1] * eye[2];
    eye.z = rotationMatrix[0][2] * eye[0] + rotationMatrix[1][2] * eye[1] + rotationMatrix[2][2] * eye[2];

    up.x = rotationMatrix[0][0] * up[0] + rotationMatrix[1][0] * up[1] + rotationMatrix[2][0] * up[2];
    up.y = rotationMatrix[0][1] * up[0] + rotationMatrix[1][1] * up[1] + rotationMatrix[2][1] * up[2];
    up.z = rotationMatrix[0][2] * up[0] + rotationMatrix[1][2] * up[1] + rotationMatrix[2][2] * up[2];
*/

}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

    printf("\n\n");

    vec3 f = (normalize(-eye));
    vec3 s = (normalize(cross(f, up)));
    vec3 r = (cross(s, f));

    mat4 Result(1);
    Result[0][0] = s.x;
    Result[1][0] = s.y;
    Result[2][0] = s.z;

    Result[0][1] = r.x;
    Result[1][1] = r.y;
    Result[2][1] = r.z;

    Result[0][2] = -f.x;
    Result[1][2] = -f.y;
    Result[2][2] = -f.z;

    Result[3][0] = -dot(s, eye);
    Result[3][1] = -dot(r, eye);
    Result[3][2] = dot(f, eye);
    printf("Result:\n");
    printMatrix(Result);

    vec3 w = glm::normalize(-eye);
    vec3 u = glm::normalize(glm::cross(w,up));
    vec3 v = glm::cross(u,w);

    //mat4 lookAtMat(1);
    vec4 lookAtVecU = vec4(u.x, v.x, -w.x, 0);
    vec4 lookAtVecV = vec4(u.y, v.y, -w.y, 0);
    vec4 lookAtVecW = vec4(u.z, v.z, -w.z, 0);
    vec4 lookAtVecH = vec4(-dot(u, eye), -dot(v, eye), dot(w, eye), 1);
    mat4 lookAtMatrix = mat4(lookAtVecU, lookAtVecV, lookAtVecW, lookAtVecH);
    
    printf("LookAt A:\n");
    printMatrix(lookAtMatrix);

    //return Result;

    lookAtMatrix = mat4(1);
    lookAtMatrix[0][0] = u.x;
    lookAtMatrix[1][0] = u.y;
    lookAtMatrix[2][0] = u.z;
    lookAtMatrix[3][0] = -dot(u, eye);

    lookAtMatrix[0][1] = v.x;
    lookAtMatrix[1][1] = v.y;
    lookAtMatrix[2][1] = v.z;
    lookAtMatrix[3][1] = -dot(v, eye);

    lookAtMatrix[0][2] = -w.x;
    lookAtMatrix[1][2] = -w.y;
    lookAtMatrix[2][2] = -w.z;
    lookAtMatrix[3][2] = dot(w, eye);

    printf("LookAt B:\n");
    printMatrix(lookAtMatrix);

    return lookAtMatrix;
    
    //------------------------------------------------------
    
    vec3 zaxis = normalize(-eye);
    vec3 xaxis = normalize(cross(zaxis, up));
    vec3 yaxis = cross(xaxis, zaxis);

    zaxis = -zaxis;

    mat4 viewMatrix = {
      vec4(xaxis.x, xaxis.y, xaxis.z, -dot(xaxis, eye)),
      vec4(yaxis.x, yaxis.y, yaxis.z, -dot(yaxis, eye)),
      vec4(zaxis.x, zaxis.y, zaxis.z, dot(zaxis, eye)),
      vec4(0, 0, 0, 1)
    };

    mat4 viewMatrixB = {
      vec4(xaxis.x, yaxis.x, zaxis.x, 0),
      vec4(xaxis.y, yaxis.y, zaxis.y, 0),
      vec4(xaxis.z, yaxis.z, zaxis.z, 0),
      vec4(-dot(xaxis, eye), -dot(yaxis, eye), -dot(zaxis, eye), 1)
    };
    printMatrix(viewMatrix);
    printMatrix(viewMatrixB);
    
    //lookAtMat = translationMat * rotationMat;// *translationMat;

  // You will change this return call
    return viewMatrixB;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}