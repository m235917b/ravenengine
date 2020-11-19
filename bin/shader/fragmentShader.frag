#version 430

// Interpolated values from the vertex shaders
in vec2 texCoord;

layout (binding = 0) uniform sampler2D texsampler;

out vec3 color;

void main()
{
  	color = texture(texsampler, texCoord).rgb;
}
