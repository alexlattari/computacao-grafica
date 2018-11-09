from OpenGL.GLUT import *
from OpenGL.GLU import *
from OpenGL.GL import *
#Paraboloide DE BASE QUADRADA(HARDCODED)

def prism():
	yLen = 4;
	xLen = 8;
	zLen = 5;
        glBegin(GL_QUADS);
        glVertex4d(0.0, 0.0, 0.0, 1.0);
        glVertex4d(0.0, yLen, 0.0, 1.0);
        glVertex4d(xLen, yLen, 0.0, 1.0);
        glVertex4d(xLen, 0.0, 0.0, 1.0);

        glVertex4d(0.0, 0.0, 0.0, 1.0);
        glVertex4d(0.0, 0.0, zLen, 1.0);
        glVertex4d(0.0, yLen, zLen, 1.0);
        glVertex4d(0.0, yLen, 0.0, 1.0);

    	glVertex4d(0.0, 0.0, 0.0, 1.0);
        glVertex4d(0.0, 0.0, zLen, 1.0);
        glVertex4d(0.0, yLen, zLen, 1.0);
        glVertex4d(0.0, yLen, 0.0, 1.0);

        glEnd();

def abacaxi():
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glRotatef(2,1,3,0)
    prism()
    glutSwapBuffers()
 
def timer(i):
    glutPostRedisplay()
    glutTimerFunc(50,timer,1)

def f(x,z):
    return x**2 + z**2

# PROGRAMA PRINCIPAL
glutInit(sys.argv)
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE)
glutInitWindowSize(800,600)
glutCreateWindow("Paraboloid")
glutDisplayFunc(abacaxi)
glEnable(GL_MULTISAMPLE)
glEnable(GL_DEPTH_TEST)
glClearColor(0.,0.,0.,1.)
gluPerspective(45,800.0/600.0,0.1,50.0)
glTranslatef(0.0,0.0,-10)
#glRotatef(45,1,1,1)
glutTimerFunc(50,timer,1)
glutMainLoop()
