/**
 * A simple OpenGL program that draws a colorful cube
 * that rotates as you move the arrow keys.
 *
 * Author: Mihalis Tsoukalos
 * Date: Wednesday 04 June 2014
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>


// Rotate X
GLfloat rX = 0;
// Rotate Y
GLfloat rY = 0;

// The coordinates for the vertices of the cube
GLfloat x = 0.05f;
GLfloat y = 0.05f;
GLfloat z = 0.05f;

const unsigned int FRAMES_PER_SECOND = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

//Control when was the last update() called.
int gTimeLastUpdateMs = 0;

void display()
{
	
	// Set Background Color
	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
	
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glRotatef(rX, 0.0f, 1.0f, 0.0f);
	// Reset transformations
	glLoadIdentity();
	
	glPushMatrix();
	// Rotate when user changes rX and rY
	//glRotatef(rX, 1.0f, 0.0f, 0.0f);
	glRotatef(rY, 0.0f, 1.0f, 0.0f);

	// BACK
	glColor3f(0.4f, 0.3f, 0.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
		glVertex3f(-x, y, z);
	glEnd();

	glColor3f(0.5f, 0.3f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, z);
		glVertex3f(x, -y, z);
		glVertex3f(-x, y, z);
	glEnd();

	// FRONT
	// Using 4 trianges!
	glColor3f(0.1f, 0.5f, 0.3f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, -z);
		glVertex3f(0, 0, -z);
		glVertex3f(-x, -y, -z);
	glEnd();

	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, -z);
		glVertex3f(0, 0, -z);
		glVertex3f(x, -y, -z);
	glEnd();

	glColor3f(0.1f, 0.3f, 0.3f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, -z);
		glVertex3f(x, y, -z);
		glVertex3f(0, 0, -z);
	glEnd();

	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(0, 0, -z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, -z);
	glEnd();

	// LEFT
	glColor3f(0.3f, 0.5f, 0.6f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, -y, z);
		glVertex3f(-x, y, -z);
	glEnd();

	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, z);
		glVertex3f(-x, -y, z);
		glVertex3f(-x, y, -z);
	glEnd();

	// RIGHT
	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, z);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, -y, -z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, z);
	glEnd();

	// TOP
	glColor3f(0.6f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(x, y, -z);
		glVertex3f(-x, y, -z);
	glEnd();

	glColor3f(0.6f, 0.1f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, z);
		glVertex3f(x, y, z);
		glVertex3f(-x, y, -z);
	glEnd();

	// BOTTOM
	glColor3f(0.4f, 0.0f, 0.4f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, -y, z);
		glVertex3f(x, -y, z);
	glEnd();

	glColor3f(0.3f, 0.0f, 0.3f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, -y, -z);
		glVertex3f(-x, -y, -z);
		glVertex3f(x, -y, z);
	glEnd();
	glPopMatrix();
//---------------------------------------------------------------------------------------------------
	
	// Rotate when user changes rX and rY
	//glRotatef(rX, 1.0f, 0.0f, 0.0f);
	
	
	glPushMatrix();
	
	glRotatef(rX, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.5,0, 0.0f);
	// BACK
	glColor3f(0.4f, 0.3f, 0.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
		glVertex3f(-x, y, z);
	glEnd();

	glColor3f(0.5f, 0.3f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, z);
		glVertex3f(x, -y, z);
		glVertex3f(-x, y, z);
	glEnd();

	// FRONT
	// Using 4 trianges!
	glColor3f(0.1f, 0.5f, 0.3f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, -z);
		glVertex3f(0, 0, -z);
		glVertex3f(-x, -y, -z);
	glEnd();

	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, -z);
		glVertex3f(0, 0, -z);
		glVertex3f(x, -y, -z);
	glEnd();

	glColor3f(0.1f, 0.3f, 0.3f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, -z);
		glVertex3f(x, y, -z);
		glVertex3f(0, 0, -z);
	glEnd();

	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(0, 0, -z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, -z);
	glEnd();

	// LEFT
	glColor3f(0.3f, 0.5f, 0.6f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, -y, z);
		glVertex3f(-x, y, -z);
	glEnd();

	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, z);
		glVertex3f(-x, -y, z);
		glVertex3f(-x, y, -z);
	glEnd();

	// RIGHT
	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, z);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, -y, -z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, z);
	glEnd();

	// TOP
	glColor3f(0.6f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(x, y, -z);
		glVertex3f(-x, y, -z);
	glEnd();

	glColor3f(0.6f, 0.1f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, y, z);
		glVertex3f(x, y, z);
		glVertex3f(-x, y, -z);
	glEnd();

	// BOTTOM
	glColor3f(0.4f, 0.0f, 0.4f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, -y, z);
		glVertex3f(x, -y, z);
	glEnd();

	glColor3f(0.3f, 0.0f, 0.3f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, -y, -z);
		glVertex3f(-x, -y, -z);
		glVertex3f(x, -y, z);
	glEnd();
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void update(double delta)
{
	//Update the color of the square based on the time
	//gValueR += (GLfloat)//delta;
	//gValueG += (GLfloat)//(delta * 1.3);
	//gValueB += (GLfloat)//(delta * 1.5);

	if(rY < -360){
		rY= 0;
	
	}
	  rY -= 5;

	if(rX > 360){
		rX= 0;
	
	}
	  rX += 5;

}
void internalUpdate(int value)
{
	int timeNowMs = glutGet(GLUT_ELAPSED_TIME);
	double deltaSeconds = (timeNowMs - gTimeLastUpdateMs) / 1000.0;

	// Save the time update() was called
	gTimeLastUpdateMs = timeNowMs;
//	std::cout << "timeNOw = " << timeNowMs << ", deltaSeconds = " << deltaSeconds << std::endl;
//	std::cout << rY << std::endl;
	// Invoke our update() function
	update(deltaSeconds);

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);
}

/*

void keyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT) {
		rY += 5;
	} else if (key == GLUT_KEY_LEFT) {
		rY -= 5;
	} else if (key == GLUT_KEY_DOWN) {
		rX -= 5;
	} else if (key == GLUT_KEY_UP) {
		rX += 5;
	}

	// Request display update
	glutPostRedisplay();
}

*/
int main(int argc, char **argv)
{
	// Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);

	// Create window
	glutCreateWindow("OpenGL Cube");

	// Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(display);
	//glutSpecialFunc(keyboard);
	glutIdleFunc(display);
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);

	// Pass control to GLUT for events
	glutMainLoop();

	return 0;
}
