#version 330

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec2 vertex_uv;
layout(location = 3) in vec4 vertex_color;

out vec4 fragment_color;

uniform mat4 MVP;

void main() {
	fragment_color = vertex_color;
	gl_Position = MVP * vec4(vertex_position.xyz, 1.0);
}