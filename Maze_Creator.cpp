/**
*  Maze Creator  v.1.3 -  by  rodrivas78  -  C++ / OpenGL / glut

   You can use to create mazes, complex terrains or intricated pathways and scenarios.
   It is not intended to generate 'standart' labyrinths (for that search for Prim's or Eller´s algorithm).
   When used with Photoshop (for post-processing the generated image, not as plug-in) becomes very good to create 
   natural/organic/fractured terrains or patterns (see example images). 

   Instructions: 
   When the execution starts, it generates an apparentely 'chaotic' image. Proceed with a "Print Screen" and 
   open it on Photoshop. Zoom in the image between 800 to 1000 times. Choose a region/sector 
   of the image (that you think has an interesting pattern) and cut it and save as RAW file
   (PRAW / 8BIM / No intercaleted order) and open it as  a 'highmap' in your favorite 3D modeling 
   software or game engine (Unity, Unreal Engine etc.). 

   Tips:
   To achieve a more organic or natural result, apply (artistic) filters in Photoshop.
   For variations you can tweak some variables: 'zoom', 'w', 'yF', 'xF' and 'z' (see optional formulas below).
   z=x1+y1  [or] z=(x1-y1+c1)+(2*x*y+c2)  [or]  z=(x*x+y*y)+(c1+c2)  
   yF=yF=(2*x^2)*y+c2   [or]   yF=2*x*y+c2  
   ->>Do not forget to resize the image to the same size of the terrain before creating the RAW file<<-

  Any problem, critics or suggestions, contact me:  rrivas2009@gmail.com
   
   For more information, see:
   ecosplatonicos.blospot.com.br
*
*/

#define GLUT_DISABLE_ATEXIT_HACK 
#include <glut.h>
#include <cstring>

GLdouble a = 1000.0;   
GLsizei b = 1000.0;   
int x;
int y;
int x1; 
int y1;
int xF;  
int yF;
GLfloat c1; 
GLfloat c2;  
int i;   
int z;
int w;
int c;
double zoom = 1.3; //Define valor do zoom

	void Draw() 
	{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

c2=-180;
c1=-180;
x=-180;
y=-180;

for(i=0;i<=2000000;i++) 
{	
	c1++;	
	if(c1==1080) 
	{   
		c2++;
		c1=-1080;			
		if(c2==1080)
			break;		
	y=c2;
	}
	x=c1;	
	
	for(w=0;w<=30;w++)  //try w<=2 to w<=80 or even higher. (Usually) the more iterations, the greater density.
	{		
	x1=x*x;
	y1=y*y;	
	// for different patterns you can use other formulas to obtain 'z', 'xF', 'yF' and 'x':
	z=(x1-y1+c1)+(2*x*y+c2);  // Less dense	
	//z=(x*x+y*y)+(c1+c2); // Denser 1
	//z=x1+y1; // Denser 2
	xF=x1+y1+c1;  
	//xF=(x1*y1^2)+c1;
	//xF=x1-y1+c1;
	yF=(2*x^2)*y+c2;
	//yF=2*x*y+c2;	    
	x=xF;y=yF;
	//x=xF+xF;y=yF+yF;	   		

		if(z<2) 
		{
		glColor3f(1.0, 1.0, 1.0); //white 
		glBegin(GL_POINTS);
		glVertex2f(c1,c2);
		}	
		else if(z>2){
		glColor3f(0.0, 0.0, 0.0); //black
		glBegin(GL_POINTS);
		glVertex2f(c1,c2);
		}
   	}
}
glEnd();  
glFlush();
}
	
void update()
{    	 				
glutPostRedisplay();      
}

void Initialize() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);    
	a = 1000.0*zoom;  
	b = 1000.0*zoom;   
}

 void reshape(int w, int h)
{
    glViewport(0, 0, a, b); 
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000.0, 1000.0*zoom, -1000.0, 1000.0*zoom); 
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Maze Creator");
	Initialize();
	glutDisplayFunc(Draw);
	glutIdleFunc(update);
    glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
