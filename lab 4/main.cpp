#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

float angle=0.0f;
float speed=1.0f;

void drawRectangle()
{
    glColor3f(1.0f,0.0f,0.0f); //red color
    glBegin(GL_QUADS);
    glVertex3f(-0.15f, -0.15f,0.0f); //bottom left(--)
    glVertex3f(0.15f, -0.15f,0.0f); //bottom right(+-)
    glVertex3f(0.15f, 0.15f,0.0f); //top right(++)
    glVertex3f(-0.15f, 0.15f,0.0f); //top left(-+)
    glEnd();

}

void drawTriangle()
{
    glColor3f(1.0f,1.0f,1.0f); // white color
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.2f, -0.2f, 0.0f); // bottom left
    glVertex3f(0.2f, -0.2f, 0.0f);  // bottom right
    glVertex3f(0.0f,0.2f, 0.0f);   // top
    glEnd();
}

void drawTrapezium()
{
    glColor3f(0.0f, 0.0f, 1.0f); // blue color
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -0.2f, 0.0f); // bottom-left corner
    glVertex3f(0.2f, -0.2f, 0.0f);  // bottom-right corner
    glVertex3f(0.1f, 0.2f, 0.0f);  // top-right corner
    glVertex3f(-0.1f, 0.2f, 0.0f); // top-left corner
    glEnd();
}

void drawPentagon()
{
    glColor3f(0.0f, 1.0f, 0.5f); // greenish color
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 0.2f, 0.0f);   // top vertex
    glVertex3f(0.2f, 0.06f, 0.0f);  // top-right vertex
    glVertex3f(0.12f, -0.16f, 0.0f); // bottom-right vertex
    glVertex3f(-0.12f, -0.16f, 0.0f); // bottom-left vertex
    glVertex3f(-0.2f, 0.06f, 0.0f);  // top-left vertex
    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
//draw the rectangle upper-left side
    glPushMatrix();
    glTranslatef(-0.2f, 0.2f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    drawRectangle();
    glPopMatrix();

//draw the triangle upper-right side
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(-angle, 0.0f, 0.0f, 1.0f);
    drawTriangle();
    glPopMatrix();

//draw the trapezium lower-left side
    glPushMatrix();
    glTranslatef(-0.3f, -0.4f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    drawTrapezium();
    glPopMatrix();

//draw the pentagon lower-right side
    glPushMatrix();
    glTranslatef(0.2f, -0.3, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    drawPentagon();
    glPopMatrix();

    glFlush();
}


void update(int value)
{
    angle+=speed;
    if(angle>360.0f)angle-=360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(600,600);
    glutCreateWindow("Rotating Shapes");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,update,0);
    glutMainLoop();
    return 0;
}



