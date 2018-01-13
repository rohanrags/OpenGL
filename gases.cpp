
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

GLfloat spin,state;

void sprint(int x,int y,int z,char *st)
{
	int l,i;
	l=strlen(st);
	glRasterPos3i(x,y,z);
	for(i=0;i<l;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st[i]);
}

static void TimeEvent(int t)
{
	 spin++;
	 if(spin>360) spin=0;
	 glutPostRedisplay();
	 glutTimerFunc(100,TimeEvent,1);
}

void color_menu(int id)
{
 switch(id)
 {
  case 1:glClearColor(1.0,1.0,0.0,1.0); break;
  case 2:glClearColor(1.0,0.0,1.0,1.0); break;
  case 3:glClearColor(0.0,1.0,1.0,1.0); break;
  case 4:glClearColor(0.0,0.0,0.0,0.0); break;
  case 5:exit(0);
 }
}

void mymenu1()
{
 glutCreateMenu(color_menu);
 glutAddMenuEntry("yellow",1);
 glutAddMenuEntry("pink",2);
 glutAddMenuEntry("blue",3);
 glutAddMenuEntry("black",4);
 glutAddMenuEntry("exit",5);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
}



void Draw_atom_He(GLfloat x,GLfloat y,GLfloat z,int elec,int orbit)
{
	glColor3f(1.0,0.0,5.0);
	sprint(-22,25,2,"HELIUM");
	sprint(20,25,2," 1st:2");
	glRotatef(60,1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(x,y,z);
	glColor3f(1.0,0.0,0.0);
    glutSolidSphere(5,16,8);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
    glRotatef(orbit,0,0,1);
	glutWireTorus(0.12,10,16,32);
	glPushMatrix();
	glTranslatef(0,10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0,-10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}


void Draw_atom_Ne(GLfloat x,GLfloat y,GLfloat z,int elec,int orbit)
{
	int i;
	glColor3f(1.0,0.0,5.0);
	sprint(-22,25,2,"NEON");
	sprint(20,25,2," 1st:2");
    sprint(20,22,2," 2nd:8");
	glRotatef(60,1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(x,y,z);
	glColor3f(1.0,0.0,0.0);
    glutSolidSphere(5,16,8);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
    glRotatef(orbit,0,0,1);
	glutWireTorus(0.12,10,16,32);
	glPushMatrix();
	glTranslatef(0,10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0,-10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(25.0,1.0,0.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,15,16,32);
	for(i=0;i<8;i++)
	{
		glPushMatrix();
		glRotatef((360/8)*i,0.0,0.0,1.0);
		glTranslatef(0,15,0);
		glColor3f(0.0,1.0,0.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	glPopMatrix();
    glPopMatrix();
	glPopMatrix();
}

void Draw_atom_Ar(GLfloat x,GLfloat y,GLfloat z,int elec,int orbit)
{
	int i;
	glColor3f(1.0,0.0,5.0);
	sprint(-22,25,2,"ARGON");
	sprint(20,25,2," 1st:2");
    sprint(20,22,2," 2nd:8");
	sprint(20,19,2," 3rd:8");
	glRotatef(60,1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(x,y,z);
	glColor3f(1.0,0.0,0.0);
    glutSolidSphere(5,16,8);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
    glRotatef(orbit,0,0,1);
	glutWireTorus(0.12,10,16,32);
	glPushMatrix();
	glTranslatef(0,10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0,-10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPopMatrix();
//	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(25.0,1.0,0.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,15,16,32);
	for(i=0;i<8;i++)
	{
		glPushMatrix();
		glRotatef((360/8)*i,0.0,0.0,1.0);
		glTranslatef(0,15,0);
		glColor3f(0.0,1.0,0.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	//glPopMatrix();
	glPopMatrix();
	glPopMatrix();

    glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(60.0,1.0,0.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,20,16,32);
	for(i=0;i<8;i++)
	{
		glPushMatrix();
		glRotatef((360/8)*i,0.0,0.0,1.0);
		glTranslatef(0,20,0);
		glColor3f(1.0,0.0,1.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	glPopMatrix();
    glPopMatrix();
	glPopMatrix();
}
void Draw_atom_Kr(GLfloat x,GLfloat y,GLfloat z,int elec,int orbit)
{
	int i;
	glColor3f(1.0,0.0,5.0);
	sprint(-22,25,2,"KRYPTON");
	sprint(20,25,2," 1st:2");
    sprint(20,22,2," 2nd:8");
	sprint(20,19,2," 3rd:18");
	sprint(20,16,2," 4th:8");
	glRotatef(60,1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(x,y,z);
	glColor3f(1.0,0.0,0.0);
    glutSolidSphere(5,16,8);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
    glRotatef(orbit,0,0,1);
	glutWireTorus(0.12,10,16,32);
	glPushMatrix();
	glTranslatef(0,10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0,-10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPopMatrix();
//	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(25.0,1.0,0.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,15,16,32);
	for(i=0;i<8;i++)
	{
		glPushMatrix();
		glRotatef((360/8)*i,0.0,0.0,1.0);
		glTranslatef(0,15,0);
		glColor3f(0.0,1.0,0.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	//glPopMatrix();
	glPopMatrix();
	glPopMatrix();

    glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(60.0,1.0,0.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,20,16,32);
	for(i=0;i<18;i++)
	{
		glPushMatrix();
		glRotatef((360/18)*i,0.0,0.0,1.0);
		glTranslatef(0,20,0);
		glColor3f(1.0,0.0,1.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	glPopMatrix();
    glPopMatrix();
	 glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(60.0,0.0,1.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,25,16,32);
	for(i=0;i<8;i++)
	{
		glPushMatrix();
		glRotatef((360/8)*i,0.0,0.0,1.0);
		glTranslatef(0,25,0);
		glColor3f(0.0,1.0,1.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void Draw_atom_Xe(GLfloat x,GLfloat y,GLfloat z,int elec,int orbit)
{
	int i;
	glColor3f(1.0,0.0,5.0);
	sprint(-22,25,2,"XENON");
	sprint(20,25,2," 1st:2");
    sprint(20,22,2," 2nd:8");
	sprint(20,19,2," 3rd:18");
	sprint(20,16,2," 4th:18");
	sprint(20,13,2," 5th:8");
	glRotatef(60,1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(x,y,z);
	glColor3f(1.0,0.0,0.0);
    glutSolidSphere(5,16,8);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
    glRotatef(orbit,0,0,1);
	glutWireTorus(0.12,10,16,32);
	glPushMatrix();
	glTranslatef(0,10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0,-10,0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(1,16,8);
	glPopMatrix();
	glPopMatrix();
//	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(25.0,1.0,0.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,15,16,32);
	for(i=0;i<8;i++)
	{
		glPushMatrix();
		glRotatef((360/8)*i,0.0,0.0,1.0);
		glTranslatef(0,15,0);
		glColor3f(0.0,1.0,0.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	//glPopMatrix();
	glPopMatrix();
	glPopMatrix();

    glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(60.0,1.0,0.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,20,16,32);
	for(i=0;i<18;i++)
	{
		glPushMatrix();
		glRotatef((360/18)*i,0.0,0.0,1.0);
		glTranslatef(0,20,0);
		glColor3f(1.0,0.0,1.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	glPopMatrix();
    glPopMatrix();
	 glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(60.0,0.0,1.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,25,16,32);
	for(i=0;i<18;i++)
	{
		glPushMatrix();
		glRotatef((360/18)*i,0.0,0.0,1.0);
		glTranslatef(0,25,0);
		glColor3f(0.0,1.0,1.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	 glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glRotatef(120.0,0.0,1.0,0.0);
	glRotatef(360-orbit,0,0,1);
	glutWireTorus(0.12,30,16,32);
	for(i=0;i<8;i++)
	{
		glPushMatrix();
		glRotatef((360/8)*i,0.0,0.0,1.0);
		glTranslatef(0,30,0);
		glColor3f(1.0,1.0,0.0);
		glutSolidSphere(1,16,8);
		glPopMatrix();
    }
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void invalid()
{
	glColor3f(1.0,0,5.0);
	sprint(-10,0,2,"Please Press a KEY from 1 to 5 only !");
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30.0,30.0,-30.0,30.0,-100.0,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0,0.0,0.0);
	sprint(-30,25,2,"1-HELIUM");
	sprint(-30,20,2,"2-NEON");
	sprint(-30,15,2,"3-ARGON");
	sprint(-30,10,2,"4-KRYPTON");
    sprint(-30,5,2,"5-XENON");
	sprint(-30,-8,2,"Right click to view options");
	glColor3f(0.0,1.0,0.0);
	sprint(-17,28,2,"ELECTRONIC CONFIGURATION OF NOBLE GASES");
	sprint(-30,28,2,"Keyboard Input");
	sprint(-30,0,2,"Mouse Input");
	sprint(20,28,2,"Orbit:Electrons");
	if(state==1)
		Draw_atom_He(0,0,0,1,spin++);
	if(state==2)
		Draw_atom_Ne(0,0,0,1,spin++);
	if(state==3)
		Draw_atom_Ar(0,0,0,1,spin++);
	if(state==4)
		Draw_atom_Kr(0,0,0,1,spin++);
	if(state==5)
		Draw_atom_Xe(0,0,0,1,spin++);
	if(state==7)
		invalid();
	
	mymenu1();

	glutSwapBuffers();
}

void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
/*void color()
{
	display();
}
void menu(int id)
{
 switch(id)
 {
  case 1:color();break;
  case 2:exit(0);
 }
}
void mytmenu()
{
 glutCreateMenu(menu);
 glutAddMenuEntry("color",1);
 glutAddMenuEntry("Exit",2);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
}

*/
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	 case '1':state=1;
		      break;
     case '2':state=2;
		      break;
     case '3':state=3;
		      break;
	 case '4':state=4;
		      break;
	 case '5':state=5;
		      break;
     default :state=7;
    }
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1200,1700);
	glutInitWindowPosition(10,10);
	glutCreateWindow(argv[0]);
	glutSetWindowTitle("Electronic Configuration Of Noble Gases");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(10,TimeEvent,1);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

