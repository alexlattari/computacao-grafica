from OpenGL.GLUT import *
from OpenGL.GLU import *
from OpenGL.GL import *
from math import *

def build(HEIGHT, RADIUS, NUM_SLICES):
    ANGLE = (2 * pi)/NUM_SLICES
    points = []

    for i in range(NUM_SLICES+1):
        x = RADIUS * cos(ANGLE*i)
        y = RADIUS * sin(ANGLE*i)
        points.append((x, y))

    glBegin(GL_POLYGON)
    glColor((1, 0, 0))
    for (x, y) in points:
        glVertex((x, y, HEIGHT))
    glEnd()

    glBegin(GL_POLYGON)
    glColor((0, 0, 1))
    for (x, y) in points:
        glVertex((x, y, -HEIGHT))
    glEnd()

    glBegin(GL_TRIANGLE_STRIP)
    glColor(0, 1, 0)
    for (x, y) in points:
        glVertex(x, y, HEIGHT)
        glVertex(x, y, -HEIGHT)
    glEnd()
	
def abacaxi():
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glRotatef(2,1,3,0)
    build(1,0.5,26)
    glutSwapBuffers()

def timer(i):
    glutPostRedisplay()
    glutTimerFunc(50,timer,1)	
	

glutInit(sys.argv)
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE)
glutInitWindowSize(800,600)
glutCreateWindow("Cylinder")
glutDisplayFunc(abacaxi)
glEnable(GL_MULTISAMPLE)
glEnable(GL_DEPTH_TEST)
glClearColor(0.,0.,0.,1.)
gluPerspective(45,800.0/600.0,0.1,50.0)
glTranslatef(0.0,0.0,-10)
#glRotatef(45,1,1,1)
glutTimerFunc(50,timer,1)
glutMainLoop()
