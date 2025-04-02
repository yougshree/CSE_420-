#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<cmath>

#define PI 3.14159265358979323846

void drawCircle(float centerx, float centery, float r, int n)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    for(int i=0; i<n; i++)
    {
        float angle=2.0f*PI*i/n;
        float x= r* cos(angle);
        float y= r* sin(angle);
        glVertex2f(centerx+x, centery+y);
    }
    glEnd();
}
// Display callback function to render the shapes
void display(void)
{
    // Clear all pixels (background color)
    glClear(GL_COLOR_BUFFER_BIT);
//(a)house design
//house roof red triangle
    glColor3f(0.9f, 0.1f, 0.1f); // Set color to red
    glBegin(GL_TRIANGLES);       // Start drawing a triangle
    glVertex3f(0.5f, 0.4f, 0.0f); // Bottom-left corner
    glVertex3f(0.9f, 0.4f, 0.0f); // Bottom-right corner
    glVertex3f(0.7f, 0.7f, 0.0f); // Top corner(0.2 and 0.8 average 0.5
    glEnd();

//house base green rectangle
    glColor3f(0.4f, 0.8f, 0.4f); // Set color to green
    glBegin(GL_QUADS);           // Start drawing a quadrilateral
    glVertex3f(0.5f, 0.4f, 0.0f); // Top-left corner
    glVertex3f(0.9f, 0.4f, 0.0f); // Top-right corner
    glVertex3f(0.9f, 0.08f, 0.0f); // Bottom-right corner
    glVertex3f(0.5f, 0.08f, 0.0f); // Bottom-left corner

    glEnd();


// Left Window (Black square)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_QUADS);
    glVertex3f(0.55f, 0.29f, 0.0f); // Bottom-left corner
    glVertex3f(0.65f, 0.29f, 0.0f);  // Bottom-right corner
    glVertex3f(0.65f, 0.36f, 0.0f);   // Top-right corner
    glVertex3f(0.55f, 0.36f, 0.0f);  // Top-left corner
    glEnd();


// Right Window (Black square)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_QUADS);
    glVertex3f(0.75f, 0.29f, 0.0f); // Bottom-left corner
    glVertex3f(0.85f, 0.29f, 0.0f);  // Bottom-right corner
    glVertex3f(0.85f, 0.36f, 0.0f);   // Top-right corner
    glVertex3f(0.75f, 0.36f, 0.0f);  // Top-left corner
    glEnd();

// Door (Blue rectangle)
    glColor3f(0.0f, 0.0f, 0.8f); // Blue color
    glBegin(GL_QUADS);
    glVertex3f(0.65f, 0.08f, 0.0f); // Bottom-left corner
    glVertex3f(0.75f, 0.08f, 0.0f); // Bottom-right corner
    glVertex3f(0.75f, 0.25f, 0.0f); // Top-right corner
    glVertex3f(0.65f, 0.25f, 0.0f); // Top-left corner
    glEnd();

// (b). design the sun
// Draw the sun (Yellow circle)
    drawCircle(0.8,0.85f, 0.12f, 100); // Center at (0.8, 0.8), radius 0.1, with 100 segments

//(c) tree
// Tree Trunk (Brown rectangle)
    glColor3f(0.545f, 0.271f, 0.075f); // Brown color
    glBegin(GL_QUADS);
    glVertex3f(0.15f, 0.08f, 0.0f); // Bottom-left corner
    glVertex3f(0.3f, 0.08f, 0.0f);  // Bottom-right corner
    glVertex3f(0.3f, 0.5f, 0.0f);   // Top-right corner
    glVertex3f(0.15f, 0.5f, 0.0f);  // Top-left corner
    glEnd();

// Tree Top (Enhanced Green Octagon)
    glColor3f(0.0f, 0.7f, 0.0f); // Slightly brighter green color
    glBegin(GL_POLYGON);
    glVertex3f(0.05f, 0.5f, 0.0f);   // Bottom-left corner (extends outward)
    glVertex3f(0.125f, 0.625f, 0.0f); // Mid-left corner (higher for rounded canopy)
    glVertex3f(0.2f, 0.7f, 0.0f);    // Top-left corner (slightly taller)
    glVertex3f(0.275f, 0.7f, 0.0f);  // Top-center
    glVertex3f(0.35f, 0.625f, 0.0f); // Top-right corner
    glVertex3f(0.425f, 0.5f, 0.0f);  // Mid-right corner (extends outward)
    glVertex3f(0.35f, 0.45f, 0.0f);  // Bottom-right corner
    glVertex3f(0.125f, 0.45f, 0.0f); // Bottom-left-mid corner
    glEnd();


// Road Base (Ash-gray rectangle)
glColor3f(0.6f, 0.6f, 0.6f); // Ash/Gray color for the road
glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f); // Bottom-left corner
    glVertex3f(1.0f, 0.0f, 0.0f); // Bottom-right corner
    glVertex3f(1.0f, 0.08f, 0.0f); // Top-right corner
    glVertex3f(0.0f, 0.08f, 0.0f); // Top-left corner
glEnd();

// Lane Markings (White dashed lines)
glColor3f(1.0f, 1.0f, 1.0f); // White color for the lane markings
for (float x = 0.1f; x < 1.0f; x += 0.2f) { // Create evenly spaced dashes
    glBegin(GL_QUADS);
        glVertex3f(x, 0.035f, 0.0f);      // Bottom-left of dash
        glVertex3f(x + 0.08f, 0.035f, 0.0f); // Bottom-right of dash
        glVertex3f(x + 0.08f, 0.045f, 0.0f); // Top-right of dash
        glVertex3f(x, 0.045f, 0.0f);      // Top-left of dash
    glEnd();
}

    glFlush(); // Start processing buffered OpenGL routine
}

// Initialize OpenGL settings
void init(void)
{
    // Set the background (clear) color to sky blue
    glClearColor(0.529, 0.808, 0.922, 0.0);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the orthographic projection (2D view)
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set the display mode (single buffer and RGB colors)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set the initial window size (600x600 pixels)
    glutInitWindowSize(700, 700);

    // Set the initial window position on the screen
    glutInitWindowPosition(100, 100);

    // Create the window with a title
    glutCreateWindow("Basic Shapes in OpenGL");

    // Initialize OpenGL settings
    init();

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0; // ISO C requires main to return int
}
