#include "OGL_Render.hpp"

GLuint OGL_CreateGraphicsPipeline(const std::string& vs, const std::string& fs){
    return OGL_CreateShaderProgram(vs, fs);;
}

void OGL_PreDraw(GLuint graphicsPipeline){
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    
    glViewport(0, 0, WIN_W, WIN_H);
    /* Screen background */
    glClearColor(1.f, 1.f, 0.f, 1.f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glUseProgram(graphicsPipeline); /* Pipeline previously created */

    return;
}

void OGL_Draw(GLuint VAO, GLuint VBO, GLuint IBO){
    /* Select the array and buffer vertex objects */
    glBindVertexArray(VAO);
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    /* Draw the selected arrays */
    /* We need to update the 3 to 6 if we are rendering a quad, instead of a triangle */
    /* 6 Works for triangles as well */
    /* For non index array objects */
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    /* For index arrays */
    glDrawElements(GL_TRIANGLES,
                6, // How many "items" to render
                GL_UNSIGNED_INT, // Type
                0);

    return;
}

void OGL_DrawObject(OGL_VertexObject object){
    OGL_Draw(object.VAO, 0, object.IBO); /* We can call it like this */

    return;
}
