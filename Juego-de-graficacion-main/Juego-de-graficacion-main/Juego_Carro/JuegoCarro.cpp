//Librerias
#include "stdafx.h"
#include <windows.h>
#include <GL/glut.h>
#include "ImageLoader.h"
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>



using namespace std;
static double tras = 0.1;

//variables que recorren la matriz_logica logica
int masx = 0;
int masz = 0;

int bandera1 = 0;
int bandera3 = 0;
int bandera4 = 0;
int bandera5 = 0;
int bandera6 = 0;
int bandera7 = 0;
int bandera8 = 0;
int bandera9 = 0;
int bandera10 = 0;
int bandera11 = 0;
int bandera12 = 0;

//comprobar el valor de las banderas
int flag = 0;

//se encarga del movimiento del escenario
static int movimiento = 0;

//limites del movimiento
boolean topeIzquierda = false, topeDerecha = false;

//tiempo limite del juego
int tiempo = 1000;

//etiquetas de texto
static char* textoTiempo = "";
static char* etiqueta = "ESQUIVA Y LLEGA AL FINAL";

static int angulo = 0;
static int direccion[] = { 0,30,60,90,120,150,180,210,240,270,300,330 };
//posicion logica
static int posz = 5, posx = 63;
//posicion de la vista
static double posicionz = -22, posicionx = 30;

static int matriz_logica[69][12] = {
	//1
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//2
	{1,1,1,1,4,4,4,4,4,1,1,1},
	{1,1,1,1,4,4,4,4,4,1,1,1},
	{1,1,1,1,4,4,4,4,4,1,1,1},

	//3
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	//4
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//5
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	//6
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},

	//7
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	//8
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//9
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	//10
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//11
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	//12
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//13
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	//14
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//15
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	//16
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//17
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	{1,1,1,1,0,0,1,1,1,1,1,1},
	//18
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//19
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,0,0,1,1,1},
	//20
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},

	//21 posicion logica
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//22
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,1,1,1},
	//23
	{1,1,1,0,0,0,0,0,0,1,1,1},
	{1,1,1,0,0,0,0,0,0,1,1,1},
	{1,1,1,0,0,0,0,0,0,1,1,1},
};



static int ubicar_figuras[23][4] = {
{ 1,4,4,1 },
{ 1,0,0,1 },
{ 1,3,0,1 },
{ 1,0,0,1 },
{ 1,0,5,1 },
//5
{ 1,0,0,1 },
{ 1,3,0,1 },
{ 1,0,0,1 },
{ 1,0,5,1 },
{ 1,0,0,1 },
//10
{ 1,3,0,1 },
{ 1,0,0,1 },
{ 1,0,5,1 },
{ 1,0,0,1 },
{ 1,3,0,1 },
//15
{ 1,0,0,1 },
{ 1,0,5,1 },
{ 1,0,0,1 },
{ 1,3,0,1 },
{ 1,0,0,1 },
//20
{ 1,0,0,1 },
{ 1,2,0,1 },
{ 1,1,1,1 }

};



GLuint _pared, _suelo, _cielo, _final, _ladrillo, _ladrillo2;


//Carga las imagenes
GLuint cargarImagen(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}


void añadirImagen() {
	Image* edificio = loadBMP("edi.bmp");
	Image* suelo = loadBMP("suelo.bmp");
	Image* cielo = loadBMP("prueba.bmp");
	Image* meta = loadBMP("final.bmp");
	Image* arriba = loadBMP("arriba.bmp");
	Image* ladri = loadBMP("ladrillo.bmp");
	Image* ladri2 = loadBMP("ladrillo2.bmp");


	_pared = cargarImagen(edificio);
	_suelo = cargarImagen(suelo);
	_final = cargarImagen(meta);
	_cielo = cargarImagen(cielo);
	_ladrillo = cargarImagen(ladri);
	_ladrillo2 = cargarImagen(ladri2);

	delete meta, edificio, suelo, cielo, ladri, ladri2;
}

void cargarTextura(GLuint _textura) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

//metodo para dibujar texto en pantalla
void inline dibujarTexto(char* arreglo)
{
	unsigned int x;
	for (x = 0; x < strlen(arreglo); x++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, arreglo[x]);
}

//metodo para disminuir el tiempo del juego
void disminuirTiempo() {
	int m=tiempo / 10;
	if (m != 0) {
		
		Sleep(100);
		
		tiempo--;
	}
}

//Metodo para generar los cubos del edificio
void generarEdificio(int xmet, int zmet)
{
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

}

//Metodo para generar los cubos de la meta
void generarFinal(int xmet, int zmet)
{
	glPushMatrix();
	cargarTextura(_final);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_final);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_final);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_final);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_final);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_final);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + xmet, 0.4, posicionz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

}

//Metodo para generar obstaculos
void generarObstaculos(int x, int z)
{
	glPushMatrix();
	cargarTextura(_ladrillo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();
}


void generarObstaculos2(int x, int z)
{
	glPushMatrix();
	cargarTextura(_ladrillo2);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo2);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo2);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo2);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo2);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_ladrillo2);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx + x, -0.5, posicionz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();
}

//Metodo para ubicar las figuras
void mostrarfiguras()
{
	int x = -33, z = -40, i, j;

	for (i = 0; i < 23; i++) //Recorriendo matriz grafica
	{
		for (j = 0; j < 4; j++)
		{
			if (ubicar_figuras[i][j] == 1)
			{
				if (i == 23 && j == 1)
				{

				}
				else {

					generarEdificio(x, z);
				}
			}
			else if (ubicar_figuras[i][j] == 3)
			{
				if (i == 23 && j == 1)
				{

				}
				else {

					generarObstaculos(x, z);
				}
			}

			else if (ubicar_figuras[i][j] == 5)
			{
				if (i == 23 && j == 1)
				{

				}
				else {

					generarObstaculos2(x, z);
				}
			}

			else if (ubicar_figuras[i][j] == 4)
			{
				if (i == 23 && j == 1)
				{

				}
				else {

					generarFinal(x, z);
				}
			}
			x = x + 3;
		}
		z = z + 3;
		x = -33; //?
	}
}


//Metodo para reiniciar el juego
void reiniciar() {
	using namespace std;
	tras = 0.1;
	posicionz = -22, posicionx = 30;
	masx = 0;
	masz = 0;
	bandera1 = 0;
	bandera3 = 0;
	bandera4 = 0;
	bandera5 = 0;
	bandera6 = 0;
	bandera7 = 0;
	bandera8 = 0;
	bandera9 = 0;
	bandera10 = 0;
	bandera11 = 0;
	bandera12 = 0;
	flag = 0;
	movimiento = 0;
	topeIzquierda = false, topeDerecha = false;
	angulo = 0;
	posz = 5, posx = 63;
	using namespace std;
	tiempo = 1000;
}

//Metodo para mostrar los elementos
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3d(0.5, 0.5, 0.5);

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	mostrarfiguras();

	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_suelo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx, 0.4, posicionz);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33, -1.6, -42);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(48, -1.6, -42);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(48, -1.6, 30);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-33, -1.6, 30);
	glEnd();
	glPopMatrix();

	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_cielo);
	glRotated(movimiento, 0, 1, 0);
	glTranslated(posicionx, 15, posicionz);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43, -11.6, -52);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(58, -11.6, -52);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(58, -11.6, 40);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-43, -11.6, 40);
	glEnd();
	glPopMatrix();


	glColor3d(256, 266, 256);
	glRasterPos3f(-0.4, 0, -1);

	//Se escribe la etiqueta que se modifican si gano o perdio no es necesario cambiar la posicion
	dibujarTexto(etiqueta);
	//Se cambia la posicion de laetiqueta del tiempo
	glRasterPos3f(-0.5, 1.8, -1.9);
	//Casteo de int a string
	string t = to_string(tiempo/10);

	//Concatenacion
	string texto1 = "TIEMPO:   " + t;
	//Casteo de char* a string
	textoTiempo = const_cast<char*>(texto1.c_str());
	//Se escribe el tiempo en la pantalla
	dibujarTexto(textoTiempo);

	glutSwapBuffers();

}

//Metodo para dar aspecto a la ventana
void reshape(int width, int height) {
	const float ar = (float)width / (float)height;
	double aspect = height / width;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

//Metodo para actualizar la ventana
static void idle(void)
{
	glutPostRedisplay();
	disminuirTiempo();

	if (tiempo/10 == 0) {
		etiqueta = "SE TE ACABO EL TIEMPO INTENTALO DE NUEVO";
		reiniciar();
	}

}

//Eventos de las teclas
static void key(unsigned char key, int x, int y)
{

	// int esferasx = 0;
	//int esferasz = 0;
	int bandera = 0;
	int bandera2 = 0;
	int banderaYO = 0;
	int comprobar = 0;
	int aux1 = 0;
	int aux2 = 0;
	etiqueta = "";


	switch (key)
	{


	case 'a':
		//Para cuando se encuentra en 0
		if (angulo == 0) {
			angulo = 12;//Si angulo es 0 se va a la ultima posicion y regresa
		}
		if (topeIzquierda == false) {
			angulo = angulo--;
			topeDerecha = false;
			if (angulo == 9) {
				topeIzquierda = true;
			}
		}
		movimiento = direccion[angulo];
		cout << movimiento << endl;
		break;

	case 'd':
		if (topeDerecha == false) {
			//Para que despues sea 0
			if (angulo == 11) {
				angulo = -1;
			}

			angulo = angulo + 1;
			topeIzquierda = false;

		}

		if (angulo == 3) {
			topeDerecha = true;
		}
		movimiento = direccion[angulo];
		cout << movimiento << endl;
		break;

	case  'w':
		//Aqui se activa la bandera1
		//Primer asm
		_asm {
			CMP key, 'w'
			JNE fin

			sa3 : MOV EAX, movimiento
			CMP EAX, 0
			JAE validar
			JMP nada
			validar : CMP EAX, 30
			JBE accion
			CMP EAX, 330
			JE accion
			JMP nada
			accion : MOV EDX, posx
			DEC EDX
			MOV masx, EDX
			MOV EDX, posz
			MOV masz, EDX
			MOV flag, 1
			fuera : MOV bandera1, 1
			JMP fin
			nada :
		fin:
		}
		//Fin de primer asm


		if (flag == 1)//entra si se activa la flag 1 para dar ver si se gana o pierde
		{

			if (bandera1 == 1)
			{
				aux1 = matriz_logica[masx][masz];

				cout << aux1 << endl;
				cout << aux2 << endl;
				cout << "Diste un paso" << tiempo << endl;

				if (matriz_logica[masx][masz] == 1) { //con 1 choca
					etiqueta = "¡HAZ PERDIDO CHOCASTE! INTENTALO DE NUEVO:)";
					reiniciar();

				}

				if (matriz_logica[masx][masz] == 4) { // con 4 ya gano, es el final

					etiqueta = "¡ FELICIDADES GANASTE!JUEGO DE NUEVO";
					reiniciar();

				}

			}//fin flag==1

			//Para caminar hacia enfrente
			//Pregunta si es 1 o 3, si no activa bandera dos para que cambie zz y resduzca posx
			//Inicia 2 asm
			_asm {
				MOV EAX, aux1
				CMP EAX, 1
				JE sa4
				CMP EAX, 3
				JE sa4

				sig : MOV bandera2, 1
				JMP sa4
				sa4 :
			}
			//Termina 2 asm

			if (bandera2 == 1)	//Si hay oportunidad de avanzar avanzamos
			{
				// cout << "NO entre" << endl;
				posicionz = posicionz + 1;
				posx = posx - 1;
			}



		} // Termina if de flag=1


		//Fragmento para girar a la derecha con angulo
		//inicia 3 asm
		_asm {
			MOV EAX, movimiento
			CMP EAX, 60
			JAE validar2
			JMP nada3
			validar2 : CMP EAX, 120
			JBE accion2
			JMP nada3
			accion2 : MOV EAX, posx
			MOV masx, EAX
			MOV EAX, posz
			INC EAX
			MOV masz, EAX
			MOV flag, 2
			MOV bandera4, 1
			nada3 :
		} // termina 3 asm, si flag=2 podemos caminar en diagonal anngulo******

		//Si entra camina en diagonal derecha
		if (flag == 2) {

			if (bandera4 == 1)
			{
				aux1 = matriz_logica[masx][masz];
				aux2 = matriz_logica[masx][masz];


			}

			if (matriz_logica[masx][masz] != 1 && matriz_logica[masx][masz] != 3) //Pienso que se debe de poner el 5 del otro bloque, preegunta si no hay bloque y avanza
			{
				posicionx = posicionx - 1;
				posz = posz + 1;

			} // else, poner para el bug de chocar al lado 


		} //Fin de la flag 2



		//Este es para hacer lo de diagonal a la izquierda
		_asm {

			MOV EAX, movimiento
			CMP EAX, 240
			JAE validar9
			JMP nada9
			validar9 : CMP EAX, 300
			JBE accion9
			JMP nada9
			accion9 : MOV EAX, posx
			MOV masx, EAX
			MOV EAX, posz
			DEC EAX
			MOV masz, EAX
			MOV flag, 4
			MOV bandera10, 1
			nada9 :
		}
		//Cuando se va a la izquierda se valida aqui
		if (flag == 4) {

			if (bandera10 == 1)
			{
				aux1 = matriz_logica[masx][masz];
				aux2 = matriz_logica[masx][masz];

			}

			if (matriz_logica[masx][masz] != 1 && matriz_logica[masx][masz] != 3)//Falta el 5?
			{
				posicionx = posicionx + 1;
				posz = posz - 1;

			}
			//Falta else para perder, bug de la diagonal izq


		}

		break;
	}

	glutPostRedisplay();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1900, 5000);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Juego de carreras, Roberto Carlos, Itamar Sarahi, Abiu");
	glutSetCursor(GLUT_CURSOR_NONE);
	añadirImagen();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glClearColor(0, 0.5, 0.7, 1);
	glutMainLoop();

	return 0;
}