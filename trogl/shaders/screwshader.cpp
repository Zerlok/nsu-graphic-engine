#include "screwshader.hpp"


const std::string ScrewShader::SRC = "\
#version 120\n\
attribute vec4 position;\
attribute vec4 color;\
uniform float alpha;\
uniform vec4 constColor;\
\
mat3 rotationMatrix(vec3 axis, float angle)\
{\
 axis = normalize(axis);\
 float s = sin(angle);\
 float c = cos(angle);\
 float nc = 1.0 - c;\
 \
 return mat3(nc * axis.x * axis.x + c,           nc * axis.x * axis.y - axis.z * s,  nc * axis.z * axis.x + axis.y * s,\
			 nc * axis.x * axis.y + axis.z * s,  nc * axis.y * axis.y + c,           nc * axis.y * axis.z - axis.x * s,\
			 nc * axis.z * axis.x - axis.y * s,  nc * axis.y * axis.z + axis.x * s,  nc * axis.z * axis.z + c);\
}\
\
int sign(vec3 v)\
{\
 if (v.y > 0.0)\
  return 1;\
 else\
  return -1;\
}\
\
void main() {\
 vec3 pos = position.xyz;\
 \
 pos = pos * rotationMatrix(vec3(0.0, 1.0, 0.0), alpha * sign(pos));\
 gl_Position = gl_ModelViewProjectionMatrix * vec4(pos, 1.0);\
 gl_FrontColor = color * constColor;\
}\
";


ScrewShader::ScrewShader()
		: Shader("Screw Shader", SRC)
{
}


ScrewShader::~ScrewShader()
{
}
