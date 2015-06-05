//
// File: main.cpp
// Program entry point to demostrate GL
// y.s.n@live.com, 2015-06-05
//

#include "GL/glut.h"

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0.5);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glFrontFace(GL_CCW);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0, -0.5);
	glVertex2f(0, 0);
	glVertex2f(-0.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0);
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Counter-Clock-Wise");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

