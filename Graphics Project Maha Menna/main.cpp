/*
Graphics Project 2D Project
Maha Khaled - 20101086
Menna Amr - 20102899

*/
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


void display();
void reshape(int w, int h);
void timer(int);


void init(){
    glClearColor(0.0,0.0,0.4,0);
    }

double angle;
double radius;

//animation variables
double rotAngle=0;
float xPos=-10;
float xPosCloud=-5;
float yPos=0;
float lift=0;
float rotFlag=0;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("20101086 20102899");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000, timer, 0);

    init();
    glutMainLoop();

    return 0;

}



//Alien SpaceShip Maha
void alienSpaceship(){

    //Top Semicircle
    glLineWidth(5);
    glColor3f(1,1,0);
    //glTranslatef(0,5,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=180;i++){
        radius = 1;
        angle = i*M_PI/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

    //Spaceship bottom
    //Trapezoid

    glLineWidth(5);
    glTranslatef(-1,0,0);
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(2,0);
    glVertex2f(2,0);
    glVertex2f(3.5,-1);
    glVertex2f(3.5,-1);
    glVertex2f(-1.5,-1);

    glEnd();

    //Bottom Yellow Semicircle
    glLineWidth(5);
    glColor3f(1,1,0);
    glTranslatef(1,0.6,0);
    glBegin(GL_POLYGON);
    for(int i=210;i<=330;i++){
        radius = 1.15;

        angle = i*M_PI/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

    //Bottom Grey Semicircle

    glLineWidth(5);
    glColor3f(0.8,0.8,0.8);
    glTranslatef(0,1.47,0);
    glBegin(GL_POLYGON);
    for(int i=230;i<=310;i++){
        radius = 4;
        angle = i*M_PI/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

    //Spaceship Yellow circles

    //Centre circle
    glColor3f(1,1,0);
    glTranslatef(0,-3.55,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        radius = 0.2;
        angle = i*3.14/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

    //First right circle
    glTranslatef(0.75,0.1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        radius = 0.2;
        angle = i*3.14/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

    //Rightmost circle
    glTranslatef(0.75,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        radius = 0.2;
        angle = i*3.14/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

    //Leftmost circle
    glTranslatef(-3,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        radius = 0.2;
        angle = i*3.14/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

    //first left circle
    glTranslatef(0.75,-0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        radius = 0.2;
        angle = i*3.14/180;
        glVertex2f(radius*cos(angle), radius*sin(angle));
    }
    glEnd();

}

//Trapezoid to abduct human Menna
void lightBeam(){

    glColor4f(1,0,0,0.3);
    glBegin(GL_POLYGON);

    glVertex2f(0,5);
    glVertex2f(-7,-6);
    glVertex2f(9,-6);
    glVertex2f(2,5);

    glEnd();
}


//Human Menna

void human(){
    glColor3f(1,1,1);
    radius=0.5;

    //head
    glBegin(GL_POLYGON);
    for (double i=0; i<360; i++){
        angle=i*M_PI/180;
        glVertex2f(radius*cos(angle)+xPos, radius*sin(angle)+lift);
    }
    glEnd();
    glLineWidth(2.5);
    glBegin(GL_LINES);
    //body
    glVertex2f(0+xPos,-0.45+lift);
    glVertex2f(0+xPos,-3+lift);

    //left leg
    glVertex2f(0+xPos,-3+lift);
    glVertex2f(-1+xPos,-5+lift);

    //right leg
    glVertex2f(0+xPos,-3+lift);
    glVertex2f(1+xPos,-5+lift);

    //left arm
    glVertex2f(0+xPos,-1.5+lift);
    glVertex2f(-1.5+xPos,-2+yPos+lift);

    //right arm
    glVertex2f(0+xPos,-1.5+lift);
    glVertex2f(1.5+xPos,-2+yPos+lift);

    glEnd();
    glPushMatrix();
    glRotatef(rotAngle,0,0,1);
    glColor3f(1,0.5,0);

    //skateboard body
    glBegin(GL_POLYGON);

    glVertex2f(-3+xPos,-5);
    glVertex2f(-2+xPos,-5.5);
    glVertex2f(2+xPos,-5.5);
    glVertex2f(3+xPos,-5);

    glEnd();
    glColor3f(0,0,0);
    //skateboard wheels
    //left

    glBegin(GL_POLYGON);
    radius=0.3;
    for (double i=0; i<360; i++){
        angle=i*M_PI/180;
        glVertex2f(-2+radius*cos(angle)+xPos, radius*sin(angle)-5.65);
    }

    glEnd();


    //right
    glBegin(GL_POLYGON);
    radius=0.3;
    for (double i=0; i<360; i++){
        angle=i*M_PI/180;
        glVertex2f(2+radius*cos(angle)+xPos, radius*sin(angle)-5.65);
    }

    glEnd();

glPopMatrix();

}

//Clouds Maha
void clouds(){

    // Top cloud circle
    glLineWidth(5);
    glColor3f(1,1,1);
    glTranslatef(-7,2,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
    radius = 1;

    angle = i*M_PI/180;
    glVertex2f(radius*cos(angle)+xPosCloud, radius*sin(angle));
    }
    glEnd();

    //Centre bottom circle
    glLineWidth(5);
    glColor3f(1,1,1);
    glTranslatef(0,-0.5,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
    radius = 0.7;

    angle = i*M_PI/180;
    glVertex2f(radius*cos(angle)+xPosCloud, radius*sin(angle));
    }
    glEnd();

    //Left bottom circle
    glLineWidth(5);
    glColor3f(1,1,1);
    glTranslatef(-1,-0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
    radius = 0.7;

    angle = i*M_PI/180;
    glVertex2f(radius*cos(angle)+xPosCloud, radius*sin(angle));
    }
    glEnd();

    //Right bottom circle
    glLineWidth(5);
    glColor3f(1,1,1);
    glTranslatef(2,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
    radius = 0.7;

    angle = i*M_PI/180;
    glVertex2f(radius*cos(angle)+xPosCloud, radius*sin(angle));
    }
    glEnd();


}

//Moon Menna
void moon(){

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    radius=1;
    for (double i=0; i<360; i++){
        angle=i*M_PI/180;
        glVertex2f(8+radius*cos(angle), 8+radius*sin(angle));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0.4);
    for (double i=0; i<360; i++){
        angle=i*M_PI/180;
        glVertex2f(7.5+radius*cos(angle), 7.9+radius*sin(angle));
    }

    glEnd();

}

//Stars Maha
void stars(){

    glColor3f(1,1,0);
    glBegin(GL_POLYGON);

    glVertex2f(0.1,0.4);
    glVertex2f(0.5,0.5);
    glVertex2f(0.1,0.6);
    glVertex2f(0,1.0);
    glVertex2f(-0.1,0.6);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.1,0.4);
    glVertex2f(0,0);

    glEnd();

}
//Road Maha
void road(){

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);

    glVertex2f(-6, 3);
    glVertex2f(30, 3);
    glVertex2f(30, -5);
    glVertex2f(-6, -5);

    glEnd();
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    moon();
    lightBeam();
    human();
    glTranslatef(1,6,0);
    alienSpaceship();
    glTranslatef(-3,0,0);
    clouds();
    glTranslatef(25,-3,0);
    clouds();
    glTranslatef(0,3,0);
    stars();
    glTranslatef(-10,0,0);
    stars();
    glTranslatef(-14,-2,0);
    stars();
    glTranslatef(3,-3,0);
    stars();
    glTranslatef(1,-11.55,0);
    road();



    glFlush();
    glutSwapBuffers();

}



void reshape(int w, int h)
{

    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(60, GLfloat(w)/GLfloat(h), 1, 256);
    gluOrtho2D(-15, 15, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

//Animation Menna
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    if(xPos<1){
        xPos+=0.3;
    }
    else if (yPos<2) {
            yPos+=1;
    }

    else if(lift<15){
        lift+=0.8;
        rotAngle+=0.9;

    }
    else{
            if(rotFlag<3.7){
                rotFlag+=0.2;
                rotAngle-=0.9;
               }

    }
    if(xPosCloud<30)
    xPosCloud+=0.05;

}
