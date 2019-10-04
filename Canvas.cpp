#include "Canvas.h"

void renderScene(){	//Zeichenfunktion	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClearColor(1, 0.5, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0, 3, 5, 0, 0, 0, 0, 1, 0);

	glPushMatrix();
		glTranslatef(0, 0.3, 0.51);

		glPushMatrix();
			glTranslatef(0.2, 0, 0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.2, 0, 0);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glScalef(1, 0.2, 1);
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int width, int height){
	// Matrix f�r Transformation: Frustum->viewport
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen
	glLoadIdentity();
	// Viewport definieren
	glViewport(0, 0, width, height);
	// Frustum definieren
	gluPerspective(90, 1, 0.1, 16);
	// Matrix f�r Modellierung/Viewing
	glMatrixMode(GL_MODELVIEW);
}

void animate(int value){	// Hier werden Berechnungen durchgef�hrt, die zu einer Animation der Szene erforderlich sind.
	//Dieser Prozess l�uft im Hintergrund und wird alle 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins inkrementiert und dem Callback wieder uebergeben. 

	glutPostRedisplay();	// RenderScene aufrufen
	
	int wait_msec = 10;	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	glutTimerFunc(wait_msec, animate, ++value);
}

Canvas::Canvas(int argc, char **argv){
    glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);         // Fenster-Konfiguration
	glutCreateWindow("Canvas");   // Fenster-Erzeugung
	glutDisplayFunc( renderScene );         // Zeichenfunktion bekannt machen
	glutReshapeFunc( reshape );
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc( 10, animate, 0);
	init();
	glutMainLoop();
}

void Canvas::init(){	// Hier finden jene Aktionen statt, die zum Programmstart einmalig durchgef�hrt werden m�ssen
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
}