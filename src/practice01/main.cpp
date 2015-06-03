//
// File: main.cpp
// Application entry-point.
//
#include "gl/glut.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-0.5f, 0.0f, 0.5, 0.5);
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 320);
    glutCreateWindow("simple gl window");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
