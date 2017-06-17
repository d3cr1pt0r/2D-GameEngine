#version 130

in vec2 vertex_position;
in vec4 vertex_color;

out vec4 fragment_color;

void main() {
	gl_Position = vec4(vertex_position.x, vertex_position.y, 0.0, 1.0);
	fragment_color = vertex_color;
}