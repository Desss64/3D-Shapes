#include <GL/glu.h>
#include <GL/glut.h>

GLfloat teeter = 0;

void Spin()
{
  teeter = teeter + 0.05;
  if(teeter > 360)
    teeter = 0;
  glutPostRedisplay();
}

void MyInit()
{
   //Background color/transparency
   glClearColor(0, 0, 0, 1);

   //Drawing color
   glColor3f(1, 0, 0);
   glEnable(GL_DEPTH_TEST);
}

//Draws faces
void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(A);//Can pass A[0], A[1], A[2] or just A with glVertex3fv
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();
}

//Creates points for cube
void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
       glColor3f(1, 0, 0);
       Face(V0,V1,V2,V3);//Front

       glColor3f(0, 0, 1);
       Face(V4,V5,V6,V7);//Back

       glColor3f(0.5, 0, 0.5);
       Face(V0,V3,V7,V4);//Left

       glColor3f(0, 1, 0);
       Face(V1,V2,V6,V5);//Right

       glColor3f(1, 1, 0);
       Face(V0,V1,V5,V4);//Top

       glColor3f(0.5, 0.5, 0.5);
       Face(V3,V2,V6,V7);//Bottom
}

void Draw()
{
    //8 vertexes with (x,y,z) each
    GLfloat V[8][3] = {
                               {-0.3, 0.8, 0.3},
                               { 0.3, 0.8, 0.3},
                               { 0.3, -0.8, 0.3},
                               {-0.3, -0.8, 0.3},

                               {-0.3, 0.8, -0.3},
                               {0.3, 0.8, -0.3},
                               {0.3, -0.8, -0.3},
                               {-0.3, -0.8, -0.3},
                             };
    //Clears depth and color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(teeter, 1, 1, 0.5);//Axis of rotation

    //Draw shape here
    Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

    glutSwapBuffers();
}

int main(int C, char *V[])
{
    //Initializes glut window
    glutInit(&C, V);

    glutInitWindowPosition(350, 150);
    glutInitWindowSize(800, 700);

    //Mode (ex: 2D, 3D etc.) & color type
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Rotating Cube Program");
    MyInit();

    //For drawing on graphics window
    glutDisplayFunc(Draw);

    //Spins shape
    glutIdleFunc(Spin);

    //Loops main function and shows glut window
    glutMainLoop();
    return 0;
}
