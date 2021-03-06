//
// File: main.cpp
// Transformations.
// y.s.n@live.com, 2015-06-08
//
// Model transformation & view transformation
//  glMatrixMode(GL_MODELVIEW)
//  glTranslate*
//  glRotate*
//  glScale*
//
// Projection transformation
//  glMatrixMode(GL_PROJECTION)
//  glFrustum
//  glPerspective
//  glOthto
//
// Viewport transformation
//  glViewport
//
#include "GL/glut.h"

static int day = 1;
// day的变化：从0到359
void display(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);
    // 绘制红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // 绘制蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // 绘制黄色的“月亮”
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day/30.0*360.0 - day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);
    glFlush();

	glutSwapBuffers();
}

void idleFunc()
{
	static int _count = 0;
	if (_count++ % 20000 == 0) {
		day++;
		day %= 360;
		display();
	}
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Point Line Polygon Circle");
    glutDisplayFunc(display);
	glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}
