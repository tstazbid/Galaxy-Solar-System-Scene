/*

Project Name: Galaxy Solar System Scene
Author Name: Md Tazbidus Samad Tazbid
Email: tazbid717@gmail.com

*/

#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

float angle = 0.0;
float rotationSpeed = 0.001; // rotation speed of planet

// Define some MACROS
#define FPS 1000 // Frames per second
#define KEY_ESC 27 // ASCII value for Escape key

const int numStars = 100; // Number of stars in the galaxy
float starX[numStars];    // X positions of stars
float starY[numStars];    // Y positions of stars
float starSpeed[numStars]; // Speed of stars

void initializeStars()
{
    // Initialize random seed
    srand(time(NULL));

    // Generate random positions and speeds for stars
    for (int i = 0; i < numStars; ++i)
    {
        starX[i] = rand() % 1100;
        starY[i] = rand() % 700;
        starSpeed[i] = ((rand() % 4) + 1) / 10.0; // Speed ranges from 0.1 to 0.4
    }
}

void reshapeFunc(int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, x, 0, y);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}

void Draw_Circles()
{
    glClearColor(0, 0, 0, 1); // Black color
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Draw stars
    glColor3f(1.0, 1.0, 1.0); // White color for stars
    glPointSize(2.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < numStars; ++i)
    {
        glVertex2f(starX[i], starY[i]);
    }
    glEnd();

    // Draw orbits
    int numSegments = 100; // increase the value for smooth orbit line
    glColor3f(0.3, 0.3, 0.3); // Grey color for orbits

    // Mercury orbit
    int mercuryOrbitRadius = 100;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); //calculates the angle in radians
        float x = 300 + mercuryOrbitRadius * cosf(theta); // x position
        float y = 300 + mercuryOrbitRadius * sinf(theta); // y position
        glVertex2f(x, y);
    }
    glEnd();

    // Venus orbit
    int venusOrbitRadius = 150;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = 300 + venusOrbitRadius * cosf(theta);
        float y = 300 + venusOrbitRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Earth orbit
    int earthOrbitRadius = 200;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = 300 + earthOrbitRadius * cosf(theta);
        float y = 300 + earthOrbitRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Mars orbit
    int marsOrbitRadius = 280;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = 300 + marsOrbitRadius * cosf(theta);
        float y = 300 + marsOrbitRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Jupiter orbit
    int jupiterOrbitRadius = 380;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = 300 + jupiterOrbitRadius * cosf(theta);
        float y = 300 + jupiterOrbitRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Saturn orbit
    int saturnOrbitRadius = 460;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = 300 + saturnOrbitRadius * cosf(theta);
        float y = 300 + saturnOrbitRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Uranus orbit
    int uranusOrbitRadius = 540;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = 300 + uranusOrbitRadius * cosf(theta);
        float y = 300 + uranusOrbitRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Neptune orbit
    int neptuneOrbitRadius = 620;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = 300 + neptuneOrbitRadius * cosf(theta);
        float y = 300 + neptuneOrbitRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // SUN
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    glPushMatrix();
    glTranslatef(300, 300, 0); // sun position
    int sunRadius = 50;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = sunRadius * cosf(theta);  // rcos theta
        float y = sunRadius * sinf(theta);  // rsin theta
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Mercury
    glColor3f(0.5, 0.5, 0.5); // Grey color
    glPushMatrix();
    glTranslatef(300 + 100 * cos(angle * 0.5), 300 + 100 * sin(angle * 0.5), 0);
    glRotatef(angle * 1.5, 0, 0, 1);
    int mercuryRadius = 10;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = mercuryRadius * cosf(theta);
        float y = mercuryRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Venus
    glColor3f(0.8, 0.5, 0.2); // Orange color
    glPushMatrix();
    glTranslatef(300 + 150 * cos(angle * 0.4), 300 + 150 * sin(angle * 0.4), 0);
    glRotatef(angle * 1, 0, 0, 1);
    int venusRadius = 15;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = venusRadius * cosf(theta);
        float y = venusRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Earth
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glPushMatrix();
    glTranslatef(300 + 200 * cos(angle * 0.3), 300 + 200 * sin(angle * 0.3), 0);
    glRotatef(angle * 2, 0, 0, 1);
    int earthRadius = 20;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = earthRadius * cosf(theta);
        float y = earthRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Moon
    glColor3f(0.7, 0.7, 0.7); // Grey color
    glPushMatrix();

    glTranslatef(300 + 200 * cos(angle * 0.3) + 40 * cos(angle * 0.8), 300 + 200 * sin(angle * 0.3) + 40 * sin(angle * 0.8), 0);
    glRotatef(angle * 2, 0, 0, 1);
    int moonRadius = 6;

    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = moonRadius * cosf(theta);
        float y = moonRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Mars
    glColor3f(0.8, 0.2, 0.2); // Red color
    glPushMatrix();
    glTranslatef(300 + 280 * cos(angle * 0.25), 300 + 280 * sin(angle * 0.25), 0);
    glRotatef(angle * 3, 0, 0, 1);
    int marsRadius = 18;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = marsRadius * cosf(theta);
        float y = marsRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Jupiter
    glColor3f(0.7, 0.7, 0.7); // Grey color
    glPushMatrix();
    glTranslatef(300 + 380 * cos(angle * 0.2), 300 + 380 * sin(angle * 0.2), 0);
    glRotatef(angle * 0.5, 0, 0, 1);
    int jupiterRadius = 30;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = jupiterRadius * cosf(theta);
        float y = jupiterRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

// Saturn
    glColor3f(0.8, 0.8, 0.6); // Light yellow color
    glPushMatrix();
    glTranslatef(300 + 460 * cos(angle * 0.15), 300 + 460 * sin(angle * 0.15), 0);
    glRotatef(angle * 0.4, 0, 0, 1);
    int saturnRadius = 25;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = saturnRadius * cosf(theta);
        float y = saturnRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Uranus
    glColor3f(0.4, 0.8, 0.9); // Cyan color
    glPushMatrix();
    glTranslatef(300 + 540 * cos(angle * 0.1), 300 + 540 * sin(angle * 0.1), 0);
    glRotatef(angle * 0.3, 0, 0, 1);
    int uranusRadius = 22;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = uranusRadius * cosf(theta);
        float y = uranusRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Neptune
    glColor3f(0.2, 0.2, 0.8); // Dark blue color
    glPushMatrix();
    glTranslatef(300 + 620 * cos(angle * 0.08), 300 + 620 * sin(angle * 0.08), 0);
    glRotatef(angle * 0.2, 0, 0, 1);
    int neptuneRadius = 21;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = neptuneRadius * cosf(theta);
        float y = neptuneRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();


    glutSwapBuffers();
}

void update(int value)
{
    // Update star positions based on their speeds
    for (int i = 0; i < numStars; ++i)
    {
        starX[i] += starSpeed[i];

        // Wrap around stars that go beyond the screen
        if (starX[i] > 1100)
        {
            starX[i] = 0;
        }
    }

    angle += rotationSpeed;
    if (angle > 360)
    {
        angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1100, 700);
    glutCreateWindow("Solar System");
    glutReshapeFunc(reshapeFunc);

    initializeStars(); // Initialize star positions and speeds

    glutDisplayFunc(Draw_Circles);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
