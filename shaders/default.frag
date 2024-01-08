#version 330

in vec2 texCoord;
out vec4 fragColor;
uniform sampler2D tex0;

void main()
{
    fragColor = texture(tex0, texCoord);
}