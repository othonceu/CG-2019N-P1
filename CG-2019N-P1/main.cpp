/**
 *  Prova NP1:
 *  Mostrar dois cubos coloridos girando,
 *  um ao centro da tela e outro orbitando 
 *  ao redor desse primeiro cubo e rotacionado
 *  no próprio eixo.
 *
 *  Autor: Othon Paiva Arêas Costa <othonceu7@gmail.com>
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>


// Rotate X
GLfloat rX = 0;
// Rotate Y
GLfloat rY = 0;
// Rotate -Y
GLfloat rT = 0;

// The coordinates for the vertices of the cube
GLfloat x = 0.05f;
GLfloat y = 0.05f;
GLfloat z = 0.05f;

// Define how many frames per seconds we want our
const unsigned int FRAMES_PER_SECOND = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

//Control when was the last update() called.
int gTimeLastUpdateMs = 0;

void display()
{
	
	// Set Background Color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Reset transformations
	glLoadIdentity();
	
	
	//glRotatef(rY, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
		// Rotate when user changes rX and rY
		glRotatef(rY, 0.0f, 1.0f, 0.0f);
		

		// BACK
		glColor3f(0.4f, 0.3f, 0.5f);
		glBegin(GL_TRIANGLES);
			glVertex3f(x, y, z);
			glVertex3f(x, -y, z);
			glVertex3f(-x, y, z);
		glEnd();

		glColor3f(0.4f, 0.3f, 0.5f);
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

		glColor3f(0.1f, 0.5f, 0.3f);
		glBegin(GL_TRIANGLES);
			glVertex3f(-x, -y, -z);
			glVertex3f(0, 0, -z);
			glVertex3f(x, -y, -z);
		glEnd();

		glColor3f(0.1f, 0.5f, 0.3f);
		glBegin(GL_TRIANGLES);
			glVertex3f(-x, y, -z);
			glVertex3f(x, y, -z);
			glVertex3f(0, 0, -z);
		glEnd();

		glColor3f(0.1f, 0.5f, 0.3f);
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

		glColor3f(0.3f, 0.5f, 0.6f);
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

		glColor3f(0.2f, 0.2f, 0.2f);
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

		glColor3f(0.6f, 0.0f, 0.0f);
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

		glColor3f(0.4f, 0.0f, 0.4f);
		glBegin(GL_TRIANGLES);
			glVertex3f(x, -y, -z);
			glVertex3f(-x, -y, -z);
			glVertex3f(x, -y, z);
		glEnd();
	glPopMatrix();
//---------------------------------------------------------------------------------------------------
	
	// Rotate when user changes rX and rY
	
	
	glRotatef(rX, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
		glTranslatef(0.5,0, 0.0f);
		glRotatef(-rT, 0.0f, 0.0f, 1.0f);
		// BACK
		glColor3f(0.4f, 0.0f, 0.4f);
		glBegin(GL_TRIANGLES);
			glVertex3f(x, y, z);
			glVertex3f(x, -y, z);
			glVertex3f(-x, y, z);
		glEnd();

		glColor3f(0.4f, 0.0f, 0.4f);
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

		glColor3f(0.1f, 0.5f, 0.3f);
		glBegin(GL_TRIANGLES);
			glVertex3f(-x, -y, -z);
			glVertex3f(0, 0, -z);
			glVertex3f(x, -y, -z);
		glEnd();

		glColor3f(0.1f, 0.5f, 0.3f);
		glBegin(GL_TRIANGLES);
			glVertex3f(-x, y, -z);
			glVertex3f(x, y, -z);
			glVertex3f(0, 0, -z);
		glEnd();

		glColor3f(0.1f, 0.5f, 0.3f);
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

		glColor3f(0.3f, 0.5f, 0.6f);
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

		glColor3f(0.2f, 0.2f, 0.2f);
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

		glColor3f(0.6f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
			glVertex3f(-x, y, z);
			glVertex3f(x, y, z);
			glVertex3f(-x, y, -z);
		glEnd();

		// BOTTOM
		glColor3f(0.4f, 0.3f, 0.5f);
		glBegin(GL_TRIANGLES);
			glVertex3f(-x, -y, -z);
			glVertex3f(-x, -y, z);
			glVertex3f(x, -y, z);
		glEnd();

		glColor3f(0.4f, 0.3f, 0.5f);
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
	
	if(rY <= -360)
	{
		rY= 0;
	
	}
	  rY -= 2;

	if(rX >= 360)
	{
		rX= 0;
	
	}
	  rX += 2;

	if(rT >= 360)
	{
		rT= 0;
	
	}
	  rT += 2;

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
