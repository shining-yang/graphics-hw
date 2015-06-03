//
// File: main.cpp
// Try to draw point, line, polygon, circle.
// y.s.n@live.com, 2015-06-03
//

#include <math.h>
#include "gl/glut.h"

static const GLfloat PI = 3.14159265f;
static const GLfloat g_arrayVertex[][2] = {
    { -0.8f, -0.5f },
    { -0.5f, 0.8f },
    { 0.6f, 0.4f },
    { 0.8f, -0.8f },
};

void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Point
    glColor3f(0.5f, 0.8f, 0.0f);
    glPointSize(3.0f);

    glBegin(GL_POINTS);
    for (int i = 0; i < sizeof(g_arrayVertex) / sizeof(g_arrayVertex[0]); i++) {
        glVertex2fv(g_arrayVertex[i]);
    }
    glEnd();

    // Line | Polygon
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glPolygonMode(GL_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sizeof(g_arrayVertex) / sizeof(g_arrayVertex[0]); i++) {
        glVertex2fv(g_arrayVertex[i]);
    }
    glEnd();

    // Circle
    glColor3f(0, 0, 1);
    glPointSize(1);
    glBegin(GL_LINE_LOOP);
    int share = 360;
    for (int i = 0; i < share; i++) {
        glVertex2f(cos(2 * PI * i / share), sin(2 * PI * i / share));
    }
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Point Line Polygon Circle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}