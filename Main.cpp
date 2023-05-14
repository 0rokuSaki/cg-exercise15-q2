/*****************************************************************//**
 * \file   main.cpp
 * \brief  My solution for Q2 in exersice ('Maman') 15 in Computer Graphics (20562) course.
 *
 *
 * Repo link: https://github.com/0rokuSaki/cg-exersice15-q2
 *
 * *** BUILD INSTRUCTIONS (VS2019/VS2022 Windows 10/11) ***
 * 1. Setup OpenGL: https://www.geeksforgeeks.org/how-to-setup-opengl-with-visual-studio-2019-on-windows-10/.
 * 2. Select x86 Debug configuration.
 * 3. Build the solution (ctrl + shift + B).
 *
 * *** HOW TO RUN THE PROGRAM ***
 * 
 *
 * \author aaron
 * \date   May 2023
 *********************************************************************/

#include <Windows.h>
#include <GL/glut.h>

#include <vector>
#include <cmath>

#include "Constants.h"
#include "WcPoint3D.h"


GLdouble cardinalMatrix[4][4];
GLdouble t;


 /* Creates and initializes GLUT display-window. */
void createWindow(int argc, char** argv)
{
    /* Create the window */
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowPosition(WINDOW_INIT_POS);      // Set top-left window position
    glutInitWindowSize(WINDOW_INIT_SIZE);         // Set window width and height
    glutCreateWindow(WINDOW_TITLE);               // Create window

    /* Initialize the window */
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // Set window color to white
}


void resetCardinalMatrix(void)
{
    const GLdouble s = (1.0 - t) / 2.0;

    /* Initialize cardinal matrix */
    cardinalMatrix[0][0] = -s;
    cardinalMatrix[0][1] = 2.0 - s;
    cardinalMatrix[0][2] = s - 2.0;
    cardinalMatrix[0][3] = s;

    cardinalMatrix[1][0] = 2.0 * s;
    cardinalMatrix[1][1] = s - 3.0;
    cardinalMatrix[1][2] = 3.0 - 2.0 * s;
    cardinalMatrix[1][3] = -s;

    cardinalMatrix[2][0] = -s;
    cardinalMatrix[2][1] = 0.0;
    cardinalMatrix[2][2] = s;
    cardinalMatrix[2][3] = 0.0;

    cardinalMatrix[3][0] = 0.0;
    cardinalMatrix[3][1] = 1.0;
    cardinalMatrix[3][2] = 0.0;
    cardinalMatrix[3][3] = 0.0;
}


void displayCardinalSplineSection(const WcPoint3D& p0, const WcPoint3D& p1, const WcPoint3D& p2, const WcPoint3D& p3)
{
    for (GLdouble u = 0.0; u <= 1.0; u += INCREMENT)
    {
        const GLdouble u2 = pow(u, 2);
        const GLdouble u3 = pow(u, 3);
    }

    resetCardinalMatrix();
}


void displayCardinalSpline(const std::vector<WcPoint3D> &points)
{
    
}


/* Callback for 'glutDisplayFunc' */
void displayCallback(void)
{
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(WORLD_COORD);
}


/* Assigns callback functions for events */
void registerCallbacks(void)
{
    glutDisplayFunc(displayCallback);
}


int main(int argc, char** argv)
{
    /* Initialize OpenGL */
    createWindow(argc, argv);  // Create the display-window
    registerCallbacks();       // Assign callback functions for events
    glutMainLoop();            // Display everything and wait

	return 0;
}
