//#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <windows.h>
#include <iostream>
#include <cmath>

double rotate_x = 0.0 ;  // 3
double rotate_y = 0.0 ;  // 4
double rotate_z = 0.0 ;  // 5

double scale = 1.0 ; // To increase 1, to decrease 2

double translate_x = 0.0 ; // w (Increase), s (Decrease)
double translate_y = 0.0 ; // a (Increase), d (Decrease)

int backgroundColor[] = { 215 , 243 , 250 } ;

float vertices[8][3] = {
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

float vertexColors[8][3] = {
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};

// Draw a quadrilateral ( square ) from given four vertex indices
void quad(int a,int b,int c,int d) {
    glBegin(GL_QUADS);

    glColor3fv(vertexColors[a]);  // Vertex 'a' color
    glVertex3fv(vertices[a]);     // Vertex 'a' position

    glColor3fv(vertexColors[b]);  // Vertex 'b' color
    glVertex3fv(vertices[b]);     // Vertex 'b' position

    glColor3fv(vertexColors[c]);  // Vertex 'c' color
    glVertex3fv(vertices[c]);     // Vertex 'c' position

    glColor3fv(vertexColors[d]);  // Vertex 'd' color
    glVertex3fv(vertices[d]);     // Vertex 'd' position

    glEnd();
}

// Draw six faces of the cube by drawing
// six squares with `quad`.
void drawCube() {
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
}

void NormalKeyHandler (unsigned char key, int x, int y) {
    if( key == '1' ) {
        scale += 0.1 ;
    }
    else if( key == '2' ) {
        scale -= 0.1 ;
    }
    else if( key == '3' ) {
        rotate_x += 5 ;
    }
    else if( key == '4' ) {
        rotate_y += 5 ;
    }
    else if( key == '5' ) {
        rotate_z += 5 ;
    }
    else if( key == 'w' ) {
        translate_x += 0.1 ;
    }
    else if( key == 's' ) {
        translate_x -= 0.1 ;
    }
    else if( key == 'a' ) {
        translate_y += 0.1 ;
    }
    else if( key == 'd' ) {
        translate_y -= 0.1 ;
    }

    // Refresh the display
    glutPostRedisplay();
}

void display()
{
    glClearColor( backgroundColor[0] / 256.0 , backgroundColor[1] / 256.0 , backgroundColor[2] / 256.0 , 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // READ: https://jsantell.com/model-view-projection
    // MODEL: Model coordinates to world coordinates
    // VIEW: world coordinates to camera space
    // PROJECTION: camera space to screen coordinates
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    gluPerspective( 60, 4/3 , 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt
        (
        3, 3, 3, // Camera position
        0, 0, 0, // Target position (camera is looking at the origin)
        0, 0, 1  // Up vector - reference line for the camera
        );

    // Rotate along X-axis with rotate_x degrees
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    // Rotate along Y-axis with rotate_y degrees
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    // Scale along all three directions with factor of `scale`
    glScalef( scale , scale , scale ) ;

    // Translate along x-direction
    glTranslatef( translate_x , 0.0 , 0.0 ) ;
    // Translate along y-direction
    glTranslatef( 0.0 , translate_y , 0.0 ) ;

    drawCube();

    glFlush();
}

int main( int argc, char **argv ) {
    glutInit( &argc, argv );

    // Initializes OpenGL Display Mode
    // GLUT_RGBA -> Allows RGBA buffers for display ( A represents alpha channel )
    // GLUT_DEPTH -> Allows depth buffer
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH );

    // Initialize Window size and its position
    glutInitWindowSize( 640 , 480 );
    glutInitWindowPosition( 300 , 300 ) ;

    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glutKeyboardFunc (NormalKeyHandler);
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
    return 0;
}

/*
Installation:-1) $ sudo apt-get update
              2) $ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

Compile:- $ g++ main.cpp -o firstOpenGlApp -lglut -lGLU -lGL

Run:- $ ./firstOpenGlApp

*/


