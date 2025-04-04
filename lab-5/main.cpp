#include<windows.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

// Global variables for coordinates and slope calculation
float x1, y1, x2, y2, m;
float dx, dy;

// Function to display the DDA line
void display(void)
{
    // Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color for the line (green)
    glColor3f(1.0, 0.0, .0);
    glBegin(GL_POINTS);
// DDA algorithm implementation
//condition-1: when x1 <= x2 && y1 <= y2

    if (m > 0 && m <= 1) // Case: Slope between 0 and 1
    {
        while (x1 <= x2 && y1 <= y2) //x1, y1 smaller then x2, y2
        {
            x1 = x1 + 1;          // Increment x by 1
            y1 = y1 + m;          // Increment y by slope (m)
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1);         // Print the coordinates
        }
    }
    else if (m > 1) // Case: Slope greater than 1
    {
        while (x1 <= x2 && y1 <= y2) //x1, y1 smaller then x2, y2
        {
            x1 = x1 + (1 / m);   // Increment x by 1/m
            y1 = y1 + 1;         // Increment y by 1
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1);         // Print the coordinates
        }
    }
//condition-2: when x1 >= x2 && y1 >= y2
    if (m > 0 && m <= 1) // Case: Slope between 0 and 1
    {
        while (x1 >= x2 && y1 >= y2)
        {
            x1 = x1 - 1; // Decrease x by 1
            y1 = y1 - m; // Decrease y by slope (m)
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1); // Print the coordinates
        }
    }
    else if (m > 1) // Case: Slope greater than 1
    {
        while (x1 >= x2 && y1 >= y2)
        {
            x1 = x1 - (1 / m); // Decrease x by 1/m
            y1 = y1 - 1; // Decrease y by 1
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1); // Print the coordinates
        }
    }

//horizontal
//Condition-3: when m=0 and  y1 == y2 && x1 <= x2
    if(m==0)
    {
        while (y1 == y2 && x1 <= x2) //y1 and y2 equal x1 smaller then x2
        {
            x1 = x1+1;          // Increment x by 1
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1);         // Print the coordinates
        }
    }

//vertical
//Condition-4: when m=1 and x1==x2 && y1<=y2
    else if(m==1)
    {
        while (x1==x2 && y1<=y2) // x1 and x2 equal y1 less then y2
        {
            y1 = y1+1;          // Increment y by slope (m)
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1); // Print the coordinates
        }
    }
//horizontal
//Condition-3: when m=0 and  y1 == y2 && x1 >= x2
    if(m==0)
    {
        while (y1 == y2 && x1 >=x2) //y1 and y2 equal x1 greater then x2
        {
            x1 = x1-1;          // Decrease x by 1
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1);         // Print the coordinates
        }
    }
//vertical
//Condition-4: when m=1 and x1==x2 && y1>=y2
    else if(m==1)
    {
        while (x1==x2 && y1>=y2)
        {
            y1 = y1-1;          // Decrease y by slope (m)
            glVertex3f(x1 / 100, y1 / 100, 0.0); // Plot the point
            printf("%f %f\n", x1, y1);// Print the coordinates
        }
    }
    glEnd();

    // Flush the buffer to render the points
    glFlush();
}

// Function to initialize OpenGL settings
void init(void)
{
    // Set the background color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // Initialize viewing parameters
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// Main function
int main(int argc, char** argv)
{
    // Input the coordinates for the line
    printf("Enter value of X1: ");
    scanf("%f", &x1);
    printf("Enter value of Y1: ");
    scanf("%f", &y1);
    printf("Enter value of X2: ");
    scanf("%f", &x2);
    printf("Enter value of Y2: ");
    scanf("%f", &y2);

    // Calculate differences and slope
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;

    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");

    // Call initialization function
    init();

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}
