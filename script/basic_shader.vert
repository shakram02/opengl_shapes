#version 430 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 pos;
layout(location = 1) uniform mat4 transform;

void main(){
    gl_Position = transform * vec4(pos,1.0f);
}
