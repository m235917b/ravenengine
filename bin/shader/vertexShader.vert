#version 430

// Input vertex data, different for all executions of this shader.
layout (location = 0) in vec3 vertexPosition_modelspace;

// Notice that the "1" here equals the "1" in glVertexAttribPointer
layout (location = 1) in vec3 normal;

layout (location = 2) in vec2 inTexCoord;
  
// Values that stay constant for the whole mesh.
uniform mat4 MVP;

// Output data ; will be interpolated for each fragment.
out vec2 texCoord;
  
void main()
{
  	// Output position of the vertex, in clip space : MVP * position
  	gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);

    	texCoord = inTexCoord;
}
