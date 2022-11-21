#include <GL/glut.h>
#include <stdlib.h>



void Remodelagem(int x, int y);
void Cubo();
void Inicia();
void Mostrar();
void Timer();


//GLOBAIS
float Angulo = 0.0;

void Reshape(int x, int y){
 
  float r;
   r = x * 1.0 / y;
  
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0,0, x, y);
   gluPerspective(45.0f, r, 0.1f, 1000);

  
   glMatrixMode(GL_MODELVIEW);
}

void Cubo(){ 

 //   glColor3f(1,1,1);
    glTranslatef(0.0,0.0,-5.0);
    glRotatef(Angulo,1.0, 0.0, 0.0);
    glRotatef(Angulo,0.0, 2.0, 0.0);
    glRotatef(Angulo,0.0, 0.0, 3.0);
    glutSolidCube(1);

 
}

void Timer(int){
     
     glutPostRedisplay();
     glutTimerFunc(1000/60, Timer, 0);
     
     Angulo +=0.8;
      if(Angulo > 360.0){
                Angulo = Angulo-360.0;
 }
}

void Mostrar(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,1);
    glLoadIdentity();
    Cubo();
    glutPostRedisplay();
    glutSwapBuffers();
    }

void Inicia(){
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.5, 1.0f, 0.1f, 1000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    
//    glClearColor(0,0.6, 1,1);
}
 
void key(unsigned char key, int x, int y){
    switch (key) 
    {
        case 27 : 
        case 'q':
            exit(0);
            break;

        case '+':
            Angulo++;
            break;

        case '-':
            if (Angulo>3);
            {
                Angulo--;
            
            }
            break;
    }

    glutPostRedisplay();
}

const GLfloat luz_ambiente[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat luz_difusa[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat luz_especular[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat luz_posicao[] = { 1.0, 1.0, 1.0, 0.0 };

const GLfloat material_ambiente[]    = { 0.0f, 0.0f, 1.0f };
const GLfloat material_difuso[]    = { 1.0f, 1.0f, 1.0f };
const GLfloat material_especular[]   = { 1.0f, 1.0f, 1.0f };
const GLfloat brilho[] = { 100.0f };
 

int main (int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640,480); 
    glutCreateWindow("OBJETOS 3D");
    Inicia();
   
    
    glutDisplayFunc(Mostrar);
    glutReshapeFunc(Reshape);
    glutTimerFunc(0,Timer,0);
    glutKeyboardFunc(key);
     glutPostRedisplay();
    //

   glClearColor(0,0.6, 1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);


    glLightfv(GL_LIGHT0, GL_AMBIENT,  luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicao);


    glMaterialfv(GL_FRONT, GL_AMBIENT,   material_ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material_difuso);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material_especular);
    glMaterialfv(GL_FRONT, GL_SHININESS, brilho);    
   
    
    glutMainLoop();
    
    
    
 return 0;
}
