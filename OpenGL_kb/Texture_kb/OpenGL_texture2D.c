// 
// gcc OpenGL_texture2D.c  -lGL -lGLU -lglut
//
// Example illustrating textures
//
//

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;

/*
// Makes a chessboard texture
void makeCheckImage(void)
{
   int i, j, c;
    
   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = ((((i&0x8)==0)^((j&0x8))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}
*/


void makeCheckImage(void)
{
  int i, j, c;

  for(j=0;  j<checkImageHeight;  j++)  // Make alpha values of all = 255
    for(i=0; i<checkImageWidth;  i++)
      checkImage[i][j][3] = 255;
    

  for(j=0;  j<checkImageHeight;  j++)
  {
    for(i=0; i<checkImageWidth;  i++)
    {
      if(i>=0  && i<32    &&    j>=0 && j<32)
      {
        checkImage[i][j][0] = 255;
        checkImage[i][j][1] = 0;
        checkImage[i][j][2] = 0;
      }
      
      if(i>=32 && i<64   &&    j>=0 && j<32)
      {
        checkImage[i][j][0] = 0;
        checkImage[i][j][1] = 255;
        checkImage[i][j][2] = 0;
      }

      if(i>=0 && i<32  &&  j>=32 && j<64)
      {
        checkImage[i][j][0] = 0;
        checkImage[i][j][1] = 0;
        checkImage[i][j][2] = 255;
      }
      
      if(32<=i<64  &&  32<=j<64)
      if(i>=32 && i<64   &&    j>=32 && j<64)
      {
        checkImage[i][j][0] = 255;
        checkImage[i][j][1] = 0;
        checkImage[i][j][2] = 255;
      }
    }
  }
}



void init(void)
{    
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);

   makeCheckImage();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   glGenTextures(1, &texName);
   glBindTexture(GL_TEXTURE_2D, texName);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, 
                checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, 
                checkImage);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
   glBindTexture(GL_TEXTURE_2D, texName);

   glBegin(GL_QUADS);
     // draw a square
     /*
     glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -2.0, 0.0);
     glTexCoord2f(0.0, 1.0); glVertex3f(-2.0,  2.0, 0.0);
     glTexCoord2f(1.0, 1.0); glVertex3f( 2.0,  2.0, 0.0);
     glTexCoord2f(1.0, 0.0); glVertex3f( 2.0, -2.0, 0.0);
     */

     // Draw a parallalogram
     glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -2.0, 0.0);
     glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  2.0, 0.0);
     glTexCoord2f(1.0, 1.0); glVertex3f( 3.0,  2.0, 0.0);
     glTexCoord2f(1.0, 0.0); glVertex3f( 2.0, -2.0, 0.0);

   glEnd();

   glFlush();
   glDisable(GL_TEXTURE_2D);
}


void reshape(int w, int h)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(400, 400);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Test - 7");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);

   glutMainLoop();
   return 0; 
}
