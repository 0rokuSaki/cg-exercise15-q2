/*****************************************************************//**
 * \file   main.cpp
 * \brief  My solution for Q2 in exersice ('Maman') 15 in Computer Graphics (20562) course.
 *
 * This program draws a 2D Cardinal Spline with a given set of control poitns and a tention parameter.
 * Calculations are based on the formulas in page 421 in the book
 * 'Computer Graphics with OpenGL, 4th edition' by Donald Hearn and Pauline Baker.
 * 
 * The Cardinal Spline in this example is simillar to the spline presented here:
 * https://en.wikipedia.org/wiki/File:Cardinal_Spline_Example.png
 *
 * Repo link: https://github.com/0rokuSaki/cg-exercise15-q2
 *
 * *** BUILD INSTRUCTIONS (VS2019/VS2022 Windows 10/11) ***
 * 1. Setup OpenGL: https://www.geeksforgeeks.org/how-to-setup-opengl-with-visual-studio-2019-on-windows-10/.
 * 2. Select x86 Debug configuration.
 * 3. Build the solution (ctrl + shift + B).
 *
 * \author aaron
 * \date   May 2023
 *********************************************************************/

#include <Windows.h>
#include <GL/glut.h>

#include <iostream>
#include <vector>
#include <cmath>

#include "Constants.h"
#include "WcPoint3D.h"


GLdouble cardinalMatrix[CARDINAL_MATRIX_SIZE][CARDINAL_MATRIX_SIZE];
std::vector<WcPoint3D> controlPoints;

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


void initCardinalMatrix(const GLdouble t)
{
    const GLdouble s = CALCULATE_S(t);

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


void initControlPoints(void)
{
    controlPoints.push_back(WcPoint3D(23, 24, 0));
    controlPoints.push_back(WcPoint3D(123, 64, 0));
    controlPoints.push_back(WcPoint3D(167, 200, 0));
    controlPoints.push_back(WcPoint3D(18, 285, 0));
    controlPoints.push_back(WcPoint3D(293, 467, 0));
    controlPoints.push_back(WcPoint3D(699, 205, 0));
    controlPoints.push_back(WcPoint3D(487, 181, 0));
    controlPoints.push_back(WcPoint3D(358, 222, 0));
    controlPoints.push_back(WcPoint3D(262, 130, 0));
    controlPoints.push_back(WcPoint3D(238, 24, 0));
}


void displayCardinalSplineSection(const WcPoint3D& p0, const WcPoint3D& p1, const WcPoint3D& p2, const WcPoint3D& p3)
{
    WcPoint3D coefs[CARDINAL_MATRIX_SIZE];

    /* Calculate M_c * [ P_k-1 P_k P_k+1 P_k+2] */
    coefs[0] = (p0 * cardinalMatrix[0][0]) + (p1 * cardinalMatrix[0][1]) + (p2 * cardinalMatrix[0][2]) + (p3 * cardinalMatrix[0][3]);
    coefs[1] = (p0 * cardinalMatrix[1][0]) + (p1 * cardinalMatrix[1][1]) + (p2 * cardinalMatrix[1][2]) + (p3 * cardinalMatrix[1][3]);
    coefs[2] = (p0 * cardinalMatrix[2][0]) + (p1 * cardinalMatrix[2][1]) + (p2 * cardinalMatrix[2][2]) + (p3 * cardinalMatrix[2][3]);
    coefs[3] = (p0 * cardinalMatrix[3][0]) + (p1 * cardinalMatrix[3][1]) + (p2 * cardinalMatrix[3][2]) + (p3 * cardinalMatrix[3][3]);

    glLineWidth(LINE_WIDTH);
    glColor3d(POINT_COLOR);
    glBegin(GL_LINE_STRIP);

    for (GLdouble u = U_MIN; u <= U_MAX; u += U_INCREMENT)
    {
        const GLdouble u2 = pow(u, 2);
        const GLdouble u3 = pow(u, 3);

        /* Left-multiply coefs by [ u^3 u^2 u 1 ] */
        WcPoint3D plotPoint = (coefs[0] * u3) + (coefs[1] * u2) + (coefs[2] * u) + coefs[3];

        glVertex3d(plotPoint.getX(), plotPoint.getY(), plotPoint.getZ());
    }

    glEnd();
    glFlush();
}


void displayCardinalSpline(void)
{
    if (controlPoints.size() < MIN_NUM_OF_CTRL_PTS)
    {
        std::cerr << "[Warning] Not enougth control points to plot cardinal spline." << std::endl;
        return;
    }

    for (GLuint i = 1; i <= controlPoints.size() - MIN_NUM_OF_CTRL_PTS + 1; i++)
    {
        displayCardinalSplineSection(controlPoints[i - 1], controlPoints[i], controlPoints[i + 1], controlPoints[i + 2]);
    }

    if (glGetError() != GL_NO_ERROR)
    {
        std::cerr << "[Warning] OpenGL has encountered an error (error code = " << glGetError() << ")." << std::endl;
    }
    else
    {
        std::cout << "[Info] Successfully created cardinal spline." << std::endl;
    }
}


/* Callback for 'glutDisplayFunc' */
void displayCallback(void)
{
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(WORLD_COORD);

    glClear(GL_COLOR_BUFFER_BIT);

    displayCardinalSpline();
}


/* Assigns callback functions for events */
void registerCallbacks(void)
{
    glutDisplayFunc(displayCallback);
}


int main(int argc, char** argv)
{
    initCardinalMatrix(0); // Initialize cardinal matrix with t = 0
    initControlPoints();   // Initialize control points

    /* Initialize OpenGL */
    createWindow(argc, argv);  // Create the display-window
    registerCallbacks();       // Assign callback functions for events
    glutMainLoop();            // Display everything and wait

	return 0;
}
