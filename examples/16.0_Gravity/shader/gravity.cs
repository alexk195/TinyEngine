#version 430

layout(local_size_x = 32, local_size_y = 32) in;

layout (std430, binding = 0) buffer position {
  vec4 p[];
};

layout (std430, binding = 1) buffer velocity {
  vec4 v[];
};

layout (std430, binding = 2) readonly buffer mass {
  float m[];
};

uniform int size;
const float dt = 0.000005f;
const float G = 10.0f;

vec3 force(vec3 pB, vec3 pA){

  const vec3 dir = pB - pA;
  const float dist = length(dir);
  if(abs(dist) < 1E-4) return vec3(0);
  return normalize(dir)/(dist*dist);

}

void main() {

  const uint index = gl_LocalInvocationID.x;//*8+gl_GlobalInvocationID.y;

  if(index > size) 
    return;

  vec4 F = vec4(0.0f);
  for(int i = 0; i < size; i++){

    if(i == index)
      continue;

    F.xyz += G*force(p[i].xyz, p[index].xyz)*m[i];

  }

  //Black-Hole
  // F.xyz += G*force(vec3(0), p[index].xyz)*5;

  v[index] += dt*F;
  p[index] += dt*v[index];

};