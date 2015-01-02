#include <stdio.h>    
#include <string.h>    
#include <stdlib.h>   
#include <math.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <gl/glut.h>


//��ʼ����Դ
GLfloat lightPos[] = { 1.0f, 0.0f, -1.0f, 0.5f };
GLfloat  specular[] = { 1.0f, 0.8f, 0.4f, 0.5f};
GLfloat  specref[] =  { 1.0f, 1.0f, 0.3f, 0.1f };
GLfloat  diffuse[] = { 0.6f, 0.8f, 0.2f, 0.5f};

//��ǰ���ڵĿ��
int curw;
int curh;
int swingLeft = 0;
int swingRight = 0;
bool isSwingForward = false;
bool isLighting = false;
int curTurn=180 ;//��ǰ����Ƕ�
int maxAngel = 0;//���ڶ���
int stepDis = 0;//���Ȱڶ��ٶ�
float speed = 0;//ǰ���ٶ�
bool isStand = true;
float curDistanceX=0 , curDistanceZ=0;//��ǰ����
float legDis = 0 ;


void display(void)  
{  
	glClear (GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	//������
	glBegin(GL_QUADS);

	glColor3ub(255,255,255);
	glVertex3f(-8.0f, -3.0f, 4.0f);
	glVertex3f(8.0f, -3.0f, 4.0f);
	glColor3ub(33,33,33);
	glVertex3f(8.0f, -3.0f, -4.0f);
	glVertex3f(-8.0f, -3.0f, -4.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(33,33,33);
	glVertex3f(-8.0f, -3.0f, -4.0f);
	glVertex3f(8.0f, -3.0f, -4.0f);
	glColor3ub(156,66,180);
	glVertex3f(8.0f, 8.0f, -4.0f);
	glVertex3f(-8.0f, 8.0f, -4.0f);
	glEnd();

	//��ջ�������°���
	glPushMatrix();

	//������ϵƽ������ת
	glTranslatef (curDistanceX,0.0,curDistanceZ); //ǰ��  
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);//ת��

	//�ҵ�����ϵ����λ��ת����
	glTranslatef (0.375,0.0, 0.0);
	//�Ƿ������Ҵ���
	glRotatef ((GLfloat) swingRight, 1.0, 0.0, 0.0);
	//�µ�����ϵ��׼�����Ҵ���
	glTranslatef (0.0, -0.5, 0.0);   
	glColor3f(0.5,0.8,0.3);
	//���Ҵ���
	glPushMatrix();
	glScalef (0.4, 1.0, 0.4);
	glutSolidCube(1.0);  
	glPopMatrix();

	//�µ�����ϵ����λ��ת����
	glTranslatef (0.0, -0.5, 0.0);
	//�Ƿ�������С��   
	glRotatef ((GLfloat) legDis, 1.0, 0.0, 0.0);
	//�µ�����ϵ��׼������С��
	glTranslatef (0.0, -0.5, 0.0);  
	glColor3f(0.1,0.5,0.5);
	//����С��
	glPushMatrix();  
	glScalef (0.3, 1.0, 0.3);  
	glutSolidCube(1.0);  
	glPopMatrix();

	//�µ�����ϵ��׼�����ҽ�
	glTranslatef (0.0, -0.5, -0.1); 
	glColor3f(0.8,0.8,0.2);    
	//���ҽ�
	glPushMatrix();  
	glScalef (0.5, 0.1, 0.7);  
	glutSolidCube(1.0);  
	glPopMatrix();

	glPopMatrix ();
	//��ջ
   
	//��ջ�������°���
	glPushMatrix();
	//������ϵƽ������ת
	glTranslatef (curDistanceX,0.0,curDistanceZ);//ǰ��
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);//ת��
   
	//ͬ���������
	glTranslatef (-0.375, 0.0, 0.0);   
	glRotatef ((GLfloat) swingLeft, 1.0, 0.0, 0.0);  
	glTranslatef (0.0, -0.5, 0.0);   
	glColor3f(0.5,0.8,0.3);   
	glPushMatrix();  
	glScalef (0.4, 1.0, 0.4);  
	glutSolidCube(1.0);  
	glPopMatrix();   
	//ͬ������С��
	glTranslatef (0.0, -0.5, 0.0);   
	glRotatef ((GLfloat) legDis, 1.0, 0.0, 0.0);  
	glTranslatef (0.0, -0.5, 0.0);  
	glColor3f(0.1,0.5,0.5);   
	glPushMatrix();  
	glScalef (0.3, 1.0, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();
	//ͬ�������
	glTranslatef (0.0, -0.5, -0.1);
	glColor3f(0.8,0.8,0.2);   
	glPushMatrix();  
	glScalef (0.5, 0.1, 0.7);  
	glutSolidCube(1.0);  
	glPopMatrix();   
	glPopMatrix();   
	//��ջ

	//��ջ�����ز���ͷ��
	glPushMatrix(); 
	glTranslatef (curDistanceX,0.0,curDistanceZ);   
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);  
	//�ز�
	glTranslatef (0.0, 1.0,  0.0);
	glColor3f(1.0,0.7,0.1);   
	glPushMatrix();  
	glScalef (1.4, 2.0, 0.5);  
	glutSolidCube(1.0);  
	glPopMatrix();   
	//ͷ��
	glTranslatef (0.0, 1.25, 0.0);
	glColor3f(0.9,0.9,0.9);   
	glPushMatrix();  
	glScalef (0.5, 0.5, 0.5);  
	glutSolidCube(1.0);  
	glPopMatrix();

	//�۾�
	glTranslatef (0.125, 0.1, -0.25);
	glColor3f(0.2,0.2,0.2);   
	glPushMatrix();  
	glScalef (0.1, 0.1, 0.1);  
	glutSolidCube(1.0);  
	glPopMatrix();

	glTranslatef (-0.25, 0.0, 0.0);
	glColor3f(0.2,0.2,0.2);   
	glPushMatrix();  
	glScalef (0.1, 0.1, 0.1);  
	glutSolidCube(1.0);  
	glPopMatrix();

	//���
	glTranslatef (0.125, -0.25, 0.0);
	glColor3f(0.8,0.2,0.2);   
	glPushMatrix();  
	glScalef (0.3, 0.1, 0.1);  
	glutSolidCube(1.0);  
	glPopMatrix();



	glPopMatrix();
	//��ջ

	//��ջ�����ұ۲���
	glPushMatrix();   
	glTranslatef (curDistanceX,0.0,curDistanceZ);   
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);  
	//�ұ�
	glTranslatef (0.85, 1.75, 0.0); 
	glRotatef ((GLfloat) swingLeft, 1.0, 0.0, 0.0);  
	glTranslatef (0.0, -0.5, 0.0);  
	glColor3f(0.8,0.4,0.5);     
	glPushMatrix();  
	glScalef (0.3, 1.6, 0.4);  
	glutSolidCube(1.0);  
	glPopMatrix();   
	glPopMatrix();
	//��ջ

	//��ջ������۲���
	glPushMatrix();   
	glTranslatef (curDistanceX,0.0,curDistanceZ);   
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);  
	//��� 
	glTranslatef (-0.85, 1.75, 0.0);  
	glRotatef ((GLfloat) swingRight, 1.0, 0.0, 0.0);  
	glTranslatef (0.0, -0.5, 0.0);  
	glColor3f(0.8,0.4,0.5);     
	glPushMatrix();  
	glScalef (0.3, 1.6, 0.4);  
	glutSolidCube(1.0);  
	glPopMatrix();   
	glPopMatrix();
	//��ջ

	glutSwapBuffers();  
}     

 
 /**
	�����ڴ�С�ı�ʱ
 **/
void reshape (int w, int h)  
{   
   curw=w;   
   curh=h;  
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);   
   glMatrixMode (GL_PROJECTION);  
   glLoadIdentity ();  
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);  
   glMatrixMode(GL_MODELVIEW);  
   glLoadIdentity();  
   glTranslatef (0.0, 0.0, -8.0);  
}  
  
void keyEvent(unsigned char key, int x, int y)  
{  
   switch (key) {  
	  case 'c'://���ص�
		 if(isLighting){
			 glDisable(GL_LIGHTING);
			 isLighting = false;
			 glutPostRedisplay();
		 }
		 else{
			 glEnable(GL_LIGHTING);
			 isLighting = true;
			 glutPostRedisplay();
		 }
         break;
      case 'x'://��ת
         curTurn = (curTurn - 5) % 360;  
         glutPostRedisplay(); 
         break;  
      case 'z'://��ת
         curTurn = (curTurn + 5) % 360;  
         glutPostRedisplay();
         break;  
      case 27:  
         exit(0);  
         break;  
      default:  
         break;  
   }  
}


//ʱ�亯��,��ʱˢ��
void timer(int value)
{	
	int tempTurn=curTurn;  
    curDistanceX = curDistanceX - speed*sin((GLfloat)tempTurn/360*3.14*2);  
    curDistanceZ=curDistanceZ- speed*cos((GLfloat)tempTurn/360*3.14*2);  
    if(!isSwingForward){  
        swingLeft = (swingLeft + stepDis);  
        swingRight = (swingRight - stepDis);  
        if(swingLeft>0){legDis=legDis - stepDis*1.2;}  
        else{legDis=legDis + stepDis*1.2;}  
    }  
    else  
    {  
        swingLeft = (swingLeft - stepDis);  
        swingRight = (swingRight + stepDis);  
        if(swingLeft<0){legDis=legDis - stepDis*1.2;}  
        else{legDis=legDis + stepDis*1.2;}  
    }
    if(swingLeft>maxAngel){  
        isSwingForward = true;  
    }  
    if(swingLeft<maxAngel*-1){  
        isSwingForward = false;  
    } 
	display();
	glutPostRedisplay();
	if(!isStand) glutTimerFunc(value ,timer, value);
}

void stand(){
	swingLeft = 0;
	swingRight = 0;
	isSwingForward = false;
	legDis = 0 ;
}



/*���˵�*/
void MenuFunc(int data)
{
	switch(data){
	case 1:
		isStand = true;
		stand();
		break;
	case 2:
		stand();
		maxAngel = 20;
		stepDis = 1;
		speed = 0.02;
		//�������Timer����
		if(isStand) glutTimerFunc(20 ,timer, 20);
		isStand = false;
		break;
	case 3:
		stand();
		maxAngel = 55;
		stepDis = 5;
		speed = 0.04;
		//�������Timer����
		if(isStand) glutTimerFunc(10 ,timer, 10);
		isStand = false;
		break;

	}
}

//��ʼ�������Ȳ�������
void init(void)  
{
	//��Դ

	glEnable(GL_CULL_FACE);
	//glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, diffuse);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,30.0f);
	glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,20.0f);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
	glMateriali(GL_FRONT, GL_SHININESS,8);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

	/*�������˵�������˵���Ŀ���Ӳ˵�*/
	glutCreateMenu(MenuFunc);
	glutAddMenuEntry("վ��",1);
	glutAddMenuEntry("�߶�",2);
	glutAddMenuEntry("����",3);
	glutAddMenuEntry("z,x��������ת��c���ص�",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glEnable(GL_CULL_FACE); // ��������
	glCullFace(GL_BACK); // �õ�����

}  
  

//������
int main(int argc, char** argv)  
{  
   glutInit(&argc, argv);  
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);  
   glutInitWindowSize (800, 700);   
   glutInitWindowPosition (100, 100);  
   glutCreateWindow("���׻�����(z,x��������ת��c���ص�)");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);  
   glutKeyboardFunc(keyEvent);

   glutMainLoop();  
   return 0;  
}  