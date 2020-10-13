# version 330 core
// Do not use any version older than 330!

/* This is the fragment shader for reading in a scene description, including 
   lighting.  Uniform lights are specified from the main program, and used in 
   the shader.  As well as the material parameters of the object.  */

// Inputs to the fragment shader are the outputs of the same name of the vertex shader.
// Note that the default output, gl_Position, is inaccessible!
in vec3 myNormal; 
in vec4 myVertex; 

// You will certainly need this matrix for your lighting calculations
uniform mat4 modelview;

// This first defined output of type vec4 will be the fragment color
out vec4 fragColor;

uniform vec3 color;

const int numLights = 10; 
uniform bool enablelighting; // are we lighting at all (global).
uniform vec4 lightposn[numLights]; // positions of lights 
uniform vec4 lightcolor[numLights]; // colors of lights
uniform int numused;               // number of lights used

// Now, set the material parameters.
// I use ambient, diffuse, specular, shininess. 
// But, the ambient is just additive and doesn't multiply the lights.  

uniform vec4 ambient; 
uniform vec4 diffuse; 
uniform vec4 specular; 
uniform vec4 emission; 
uniform float shininess; 

void main (void) 
{       
    if (enablelighting) {       
        vec4 finalcolor; 

        // YOUR CODE FOR HW 2 HERE
        // A key part is implementation of the fragment shader
        const vec3 eyePosition = vec3(0,0,0);
        vec3 myPosition = myVertex.xyz / myVertex.w;    // dehomogenize
        vec3 eyeDirection = normalize(eyePosition - myPosition);
        vec3 normal = normalize(myNormal);

        // Directional light source
        if (isDirectionalLight) {
            vec3 direction = normalize(lightposn[i]);
            vec3 halfVector = normalize(direction + eyeDirection);
            vec4 fragmentColor = ComputeLight(direction, lightcolor[i], normal,
                                 halfVector, diffuse, specular, shininess);
        
        }
        // Point light source
        else if (isPointLight) {
            vec3 position = lightposn[i].xyz / lightposn[i].w; // dehomoginize
            vec3 direction = normalize(position - myPosition);
            // no attenuation
            vec3 halfVector = normalize(direction + eyeDirection);
            vec4 fragmentColor = ComputeLight(direction, lightcolor[i], normal,
                                 halfVector, diffuse, specular, shininess);

        } else {
            // Not a valid light source
        }
        // A sum of ambient and computed color values from all light sources
        finalColor = ambient + color0 + color1 + color2 + ....; 

        // Color all pixels black for now, remove this in your implementation!
        finalcolor = vec4(0.0f, 0.0f, 0.0f, 1.0f);

        fragColor = finalcolor; 
    } else {
        fragColor = vec4(color, 1.0f); 
    }
}

vec4 ComputeLight(const in vec3 direction, const in vec4 lightcolor, const in vec3 normal,
                  const in vec3 halfvec, const in vec4 myDiffuse, const in vec4 mySpecular,
                  const in float myShininess)
{
    // Computes the lambertian shading
    float nDotL = dot(normal, direction);
    vec4 lambert = myDiffuse * lightColor * max(nDotL, 0.0);

    // Computes the specular shading
    float nDotH = dot(normal, halfvec);
    vec4 phong = mySpecular * lightColor * pow(max(nDotH, 0.0), myShininess);

    vec4 retval = lambert + phong;
    return retval;
}
