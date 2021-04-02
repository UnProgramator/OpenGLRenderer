#version 330 core

layout(location = 0) out vec4 color;

varying vec4 vColor;

void main()
{
	color = vColor;
}
