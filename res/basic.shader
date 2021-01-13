#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 fragColor;
void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   fragColor = aColor;
};



#shader fragment
#version 330 core
out vec4 glFragColor;
in vec3 fragColor;
void main()
{
   glFragColor = vec4(fragColor, 1.0f);
};
