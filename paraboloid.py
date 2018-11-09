from OpenGL.GLUT import *
from OpenGL.GLU import *
from OpenGL.GL import *
#Paraboloide DE BASE QUADRADA(HARDCODED)

def paraboloid():
    x0 = -4;
    xf = 4;
    z = -5;
    zfi = 10;
    delta = 0.5;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUAD_STRIP)
    glColor3f(0.0,0.0,1.0)
    while z < zfi:
        x = x0;
        while x <xf:
            glVertex3f(x,f(x,z),z)
            glVertex3f(x,f(x,z+delta),z+delta)
            x = x+delta;
        z = z + delta;
    glEnd()

def abacaxi():
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glRotatef(1,4,5,10)
    paraboloid()
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
gluPerspective(45,800.0/600.0,0.5,30.0)
glTranslatef(0.0,0.0,-20)
#glRotatef(45,1,1,1)
glutTimerFunc(50,timer,1)
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE )
glutMainLoop()
