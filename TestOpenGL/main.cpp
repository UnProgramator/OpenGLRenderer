#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "test_triangle.h"
#include "SimplePolygon.h"
#include "glutils.h"
#include "SimpleCuber.h"
#include <windows.h>

using std::operator""s;

//#if _WIN64
//int WinMain()
//#elif _WIN32
//int main()
//#endif
int main()
{
    GLFWwindow* window;
    //test_triangle t1, t2;
    //SimplePolygon t1(5);
    SimpleCuber c;
    SimpleCuber c2;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1080, 1080, "Simulation", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Glew could not be initialized acordingly";
        glfwTerminate();
        return 2;
    }


    float vertices[] = {
        -0.5, 0.5,  0.5, 1.0, 1.0, 1.0, 1.0,
         0.5, 0.5,  0.5, 0.0, 1.0, 1.0, 1.0,
         -0.5,  -0.5,  0.5, 1.0, 0.0, 1.0, 1.0,
        0.5, - 0.5,  0.5, 1.0, 1.0, 0.0, 1.0,

        -0.5, 0.5, -0.5, 0.5, 1.0, 0.5, 1.0,
         0.5, 0.5, -0.5, 1.0, 0.7, 0.0, 1.0,
         -0.5, -0.5, -0.5, 0.7, 1.0, 0.0, 1.0,
        0.5,  -0.5, -0.5, 0.1, 0.1, 0.1, 1.0
    };

    /*unsigned int indices[] = {
        0, 1, 2, 3,
        3, 2, 6, 7, 
        4, 0, 3, 7,
        4, 5, 1, 0,
        1, 5, 6, 2,
        5, 4, 7, 6
    };*/
    
    unsigned int indices[] = {
       4, 0, 1,
       1, 5, 4,
       4, 6, 2,
       2, 0, 4,
       0, 2, 3,
       3, 1, 0,
       1, 3, 7,
       7, 5, 1,
       5, 7, 6,
       6, 4 ,5,
       6, 2, 7,
       7, 3, 2
    };

    c.init(vertices);
    c.setIndexBuffer(indices);

    std::cout << "wile_loop\n";

    c2.init(vertices);
    c2.setIndexBuffer(indices);

    std::cout << "wile_loop\n";

    c.setProgramm("D:\\Scoala\\Licenta\\TestOpenGL\\TestOpenGL\\vertexShaderTest.glsl"s, "D:\\Scoala\\Licenta\\TestOpenGL\\TestOpenGL\\fragmentShaderTest.glsl"s);
    c2.setProgramm("D:\\Scoala\\Licenta\\TestOpenGL\\TestOpenGL\\vertexShaderTest.glsl"s, "D:\\Scoala\\Licenta\\TestOpenGL\\TestOpenGL\\fragmentShaderTest.glsl"s);
    //float vertex2[9] = { 0.5f,   -0.5f, 0,
    //                     -0.5f,   0.5f, 0,
    //                    0.5f,    0.5f, 0 };
    //t2.initOpenGL(vertex2, 9);

    glEnable(GL_BLEND);

    glBlendFunc(GL_ONE, GL_ZERO);

    glDepthFunc(GL_LESS);
 
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    c2.move(0.5f, 0.f, -0.5f);
    c.move(-0.5f, 0.f, 0.f);

    std::cout << "wile_loop\n";

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //t2.draw();
        c.rotateZ(0.1);
        c.draw();

        c2.rotateZ(-0.1);
        c2.draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        Sleep(100);
    }

    glfwTerminate();
    return 0;
}
