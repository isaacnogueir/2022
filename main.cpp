#include <gl/glut.h>
#include <math.h>

void Teclado(unsigned char tecla, int um, int dois);
float a, b,c,d;

void inicia(void){
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  // glOrtho(0,600,600,0,-1,1);   
  gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    } 


void desenha(){
   
   glPushMatrix();
   glClear(GL_COLOR_BUFFER_BIT);
 //  glScalef(a,b,1);    
   glTranslatef(c,d,1);           

    glColor3f(0.20, 0.40, 1.0);

//ESTRUTURA externa
 glBegin(GL_LINES);
  glVertex2f(125,290);
  glVertex2f(160,260);

  glVertex2f(125,290);
  glVertex2f(160,320);
 
 glVertex2f(160,260);
  glVertex2f(245,260);
  
  glVertex2f(160,320);
  glVertex2f(215,320);
  
  glVertex2f(245,260);
  glVertex2f(215,320);
  
  glVertex2f(205,257);
  glVertex2f(205,230);
    
  glVertex2f(205,230);
  glVertex2f(171,230);
  
   glVertex2f(205,230);
   glVertex2f(245,230);
   
 glVertex2f(205,230);
   glVertex2f(205,250);
   
   glVertex2f(230, 289);
   glVertex2f(315,290);
   
   glVertex2f(225, 305);
   glVertex2f(315, 304);
   
   glVertex2f(315,290);
   glVertex2f(315, 304);
   
   glVertex2f(315,304);
   glVertex2f(314,270);
   
   
   glVertex2f(300,288);
   glVertex2f(314,270);
 
 
 //partes de fora: helices e escadas
   
   glVertex2f(160,320);  //ESCADA
   glVertex2f(160,342);  
   
   glVertex2f(214,320);  //ESCADA
   glVertex2f(214,340);  
   
   glVertex2f(160,330);  //ESCADA
   glVertex2f(214,330);
   
   glVertex2f(160,320);  //PORTA
   glVertex2f(160,275);  
   
   glVertex2f(214,320);  //PORTA          
   glVertex2f(215,275);
   
   glVertex2f(160,275);  //PORTA  
   glVertex2f(215,275);
        
   
    glEnd();
    
       
 glPopMatrix();       
 glFlush();
}

void Teclado(unsigned char tecla, int um, int dois){

  switch(tecla){
                case '+': a += 0.1;
                          b += 0.1;
                          break;
                case '-': a -= 0.1;
                          b -= 0.1;
                          break;   
                case 27: exit(0);
                break;
                }
                glutPostRedisplay();
  }



int main (int argc, char *argv[]){
    a = 1;
    b = 1;
 
 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Helicóptero");
    glutDisplayFunc(desenha);
    glutKeyboardFunc(Teclado);
    inicia();


    glutMainLoop();
     return 0;
}


