#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

out vec3 color;
out vec2 texCoord;

uniform float scale;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
  gl_Position = vec4(aPos.x * scale, aPos.y * scale, aPos.z * scale, 1.0);
  color = aColor;
  texCoord = aTex;
}