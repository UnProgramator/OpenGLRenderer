#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

varying vec4 vColor;

uniform float uAngle;
uniform vec3 uLocation;

void main()
{
	vColor = color;

    mat4 rotation = mat4(0.0);

	rotation[0][0] =  cos(uAngle);
	rotation[0][2] =  sin(uAngle);
	rotation[2][0] = -sin(uAngle);  
	rotation[2][2] =  cos(uAngle);

	rotation[1][1]=1.0;
	rotation[3][3]=1.0;



	gl_Position = rotation *  vec4(position, 1.0) + vec4(uLocation,0);
}
