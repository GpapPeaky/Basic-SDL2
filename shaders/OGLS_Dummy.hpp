#include <string>

/**
 * @brief Dummy vertex shader string
 */
const std::string OGLS_DummyV =
    "#version 410 core\n"
    "in vec4 pos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(pos.x, pos.y, pos.z, pos.w);\n"
    "}\n";

/**
 * @brief Dummy fragment shader string
 */
const std::string OGLS_DummyF = 
    "#version 410 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0f, 0.5f, 0.0f, 1.0f);\n"
    "}\n";
