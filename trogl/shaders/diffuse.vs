#version 330


in vec4 position;
in vec4 normal;
in vec2 uvMap;

uniform mat4 MW;
uniform mat4 MV;
uniform mat4 MP;

uniform mat4 shadowMV;
uniform mat4 shadowMP;

out vec4 vertexPosition;
out vec3 vertexNormal;
out vec2 vertexUV;

out vec4 shadowCoord;


const mat4 biasM = mat4(
0.5, 0.0, 0.0, 0.0,
0.0, 0.5, 0.0, 0.0,
0.0, 0.0, 0.5, 0.0,
0.5, 0.5, 0.5, 1.0
);


void main()
{
    vertexPosition = MV * MW * position;
	vertexNormal = (MV * MW * normal).xyz;
	vertexUV = uvMap;

    gl_Position = MP * MV * MW * position;
	shadowCoord = biasM * shadowMP * shadowMV * MW * position;
}
