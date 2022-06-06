// Texturas.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <windows.h>
#include <glut.h>
#include <GL/glu.h>
#include "ImageLoader.h"
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;
static int lados = 0;
static double pi = 3.14159265358979323846;
static double x = 0.7, y = 0.0, z = -0.1;
static double tras = 0.1;
static double zz = 0, xx = 0;
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
int flag = 0;
static int r = 0;
bool salir = false;
static char* texto = "ENCUENTRA TODAS LAS FIGURAS PARA HALLAR LA SALIDA";
static int angulo = 0;
static int direccion[] = { 0,30,60,90,120,150,180,210,240,270,300,330 };
static int matriz[72][81] = { { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,2,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
static int cuadros[24][27]= { { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1 },
{ 1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,1,0,1 },
{ 1,0,1,0,1,0,1,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,0,0,1 },
{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1 },
{ 1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1 },
{ 1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,1 },
{ 1,1,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,0,1 },
{ 1,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,1,0,1 },
{ 1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1 },
{ 1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1 },
{ 1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1 },
{ 1,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,1 },
{ 1,1,1,1,0,1,0,1,1,0,1,2,0,1,0,1,0,1,1,1,0,1,1,0,1,1,1 },
{ 1,0,0,0,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,1 },
{ 1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1,1 },
{ 1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1 },
{ 1,0,1,0,1,0,1,1,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1 },
{ 1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1 },
{ 1,0,1,1,1,0,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,1,0,1,1,0,1 },
{ 1,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
static int posz = 34, posx = 41;
static int esferas[5][2];
using namespace std;
static int piezas[5] = { 0,0,0,0,0 };
static int contador = 0;
static int posiblesCuadros[62][2] = { { 37,34 },{ 4,4 },{ 7,4 },{ 14,4 },{ 16,4 },
{ 13,5 },{ 12,25 },{ 22,11 },{ 31,20 },{ 23,28 },
{ 17,34 },{ 4,30 },{ 13,16 },{ 33,7 },{ 38,13 },
{ 33,28 },{ 13,18 },{ 35,37 },{ 22,40 },{ 6,46 },
{ 10,40 },{ 19,48 },{ 47,10 },{ 66,4 },{ 63,22 },
{ 43,19 },{ 56,4 },{ 56,34 },{ 51,22 },{ 38,49 },
{ 40,43 },{ 46,30 },{ 10,54 },{ 25,48 },{ 15,52 },
{ 55,49 },{ 16,52 },{ 57,28 },{ 58,10 },{ 43,4 },
{ 28,13 },{ 2,2 },{ 61,15 },{ 55,40 },{ 67,30 },
{ 61,26 },{ 19,20 },{ 59,43 },{ 67,43 },{ 67,52 },
{ 67,61 },{ 33,55 },{ 13,58 },{ 67,74 },{ 4,67 },
{ 16,67 },{ 49,76 },{ 43,76 },{ 22,67 },{ 58,55 },
{ 49,59 },{ 32,73 } };

GLuint _pared,_cubito,_suelo,_cielo; 


GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}


void initRendering() {
	Image* lado1 = loadBMP("3.bmp");
	Image* cbt = loadBMP("1.bmp");
	Image* suelo = loadBMP("suelo5.bmp");
	Image* sky = loadBMP("skya.bmp");

	_pared = loadTexture(lado1);
	_cubito = loadTexture(cbt);
	_suelo = loadTexture(suelo);
	_cielo = loadTexture(sky);
	delete lado1;
	delete cbt;
	delete suelo;
	delete sky;
	}

void cargarTextura(GLuint _textura) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void inline drawString(char *s)
{
	unsigned int i;
	for (i = 0; i<strlen(s); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}

void generarCubo(int xmet, int zmet)
{
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
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
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
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
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
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
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
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
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
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
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
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

void generarCubito(int x, int z)
{
	glPushMatrix();
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
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
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
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
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
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
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
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
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
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
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
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

void mostrarcuadros()
{
	int x = -33, z = -40, i, j;

	for (i = 0; i<24; i++)
	{
		for (j = 0; j<27; j++)
		{
			if (cuadros[i][j] == 1)
			{
				if (i == 23 && j == 1 && salir)
				{

				}
				else {

					generarCubo(x, z);
				}
			}
			x = x + 3;
		}
		z = z + 3;
		x = -33;
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3d(0.5, 0.5, 0.5);
	
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	mostrarcuadros();

	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_suelo);
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 0.4, zz);

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
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 15, zz);



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

	int x = -34, z = -41, i, j;

	for (i = 0; i<72; i++)
	{
		for (j = 0; j<81; j++)
		{
			if (matriz[i][j] == 3)
			{
				glColor3d(0.6, 0.6, 0.6);
				generarCubito(x, z);
			}
			x = x + 1;
		}
		z = z + 1;
		x = -34;
	}


	glColor3d(256,266,256);
	glRasterPos3f(-0.4, 0, -1);
	
	drawString(texto);

	glutSwapBuffers();
}

void reshape(int width, int height){
	const float ar = (float)width / (float)height;
	double aspect = height / width;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

static void idle(void)
{
	glutPostRedisplay();
}

void genesferas()
{
	srand(time(0));
	for (int k = 0; k<5; k++)
	{
		int num1 = (int)rand() % 62;
		int pos0 = (posiblesCuadros[num1][1] - 34);
		int pos1 = (posiblesCuadros[num1][0] - 41);
		bool flag = true;
		for (int n = 0; n<5; n++)
		{
			if (esferas[n][0] == pos0 && esferas[n][1] == pos1)
			{
				flag = false;
			}
		}

		if (flag)
		{
			esferas[k][0] = pos0;
			printf("esferas 0: %d", esferas[k][0] + 34);
			esferas[k][1] = pos1;
			printf("esferas 1: %d\n", esferas[k][1] + 41);
			matriz[posiblesCuadros[num1][0]][posiblesCuadros[num1][1]] = 3;
		}
		else {
			k--;
		}

	}
}



static void key(unsigned char key, int x, int y)
{
	
	int esferasx = 0;
	int esferasz = 0;
	int bandera = 0;
	int bandera2 = 0;
	int banderaYO = 0;
	int comprobar = 0;
	int aux1 = 0;
	int aux2 = 0;
	
	switch (key)
	{
	case '+':
		_asm {
			CMP key, '+'
			JE isMas
			JMP adios
			isMas :
			CMP r, 0
				JAE limite
				JMP esOtro
				limite :
			CMP r, 30
				JBE asigna
				JMP esOtro
				asigna :
			MOV bandera, 1
				MOV EAX, posx
				DEC EAX
				MOV masx, EAX
				MOV EAX, posz
				MOV masz, EAX
				JMP adios
				esOtro :
			CMP r, 330
				JE asigna
				CMP r, 60
				JNAE no
				CMP r, 120
				JNBE no
				MOV bandera, 1
				MOV EAX, posx
				MOV masx, EAX
				MOV EAX, posz
				INC EAX
				MOV masz, EAX
				JMP adios
				no :
			CMP r, 150
				JNAE nou
				CMP r, 210
				JNBE nou
				MOV bandera, 1
				MOV EAX, posx
				INC EAX
				MOV masx, EAX
				MOV EAX, posz
				MOV masz, EAX
				JMP adios

				nou :
			CMP r, 240
				JNAE adios
				CMP r, 300
				JNBE adios
				MOV bandera, 1
				MOV EAX, posx
				MOV masx, EAX
				MOV EAX, posz
				DEC EAX
				MOV masz, EAX
				adios :
		}

		if (bandera == 1) {
			esferasx = (esferas[contador][0]) + 34;
			esferasz = (esferas[contador][1]) + 41;
		}
		_asm {
			CMP bandera, 1
			JNE bye
			MOV EAX, posx
			CMP esferasx, EAX
			JNE bye
			MOV EAX, posz
			CMP esferasz, EAX
			JNE bye
			MOV	banderaYO, 1
			INC contador
			bye :
		}

		if (banderaYO == 1) {
			piezas[contador] = 1;
			texto = "Has encontrado la pieza correcta!";
			matriz[masx][masz] = 0;

			int l;
			comprobar = 0;
			for (l = 0; l < 5; l++)
			{
				if (piezas[l] == 1)
				{
					comprobar = comprobar + 1;
				}
			}

			if (comprobar == 5)
			{
				texto = "VE A BUSCAR LA SALIDA";
				salir = true;
				matriz[69][3] = 0;
				matriz[69][4] = 0;
				matriz[69][5] = 0;
				matriz[70][3] = 0;
				matriz[70][4] = 0;
				matriz[70][5] = 0;
				matriz[71][3] = 0;
				matriz[71][4] = 0;
				matriz[71][5] = 0;
			}

		}
		else {
			texto = "Sigue intentando con otra pieza!";
		}


		break;

	case 'a':

		_asm {
			CMP key, 'a'
			JNE sa
			MOV EAX, angulo

			CMP EAX, 0
			JE igual

			DEC EAX
			MOV angulo, EAX
			JMP sa

			igual : MOV EAX, 11
					MOV angulo, EAX
					sa :
		}
		r = direccion[angulo];
		cout << r << endl;
		break;
	case 'd':
      _asm{
		   CMP key, 'd'
			JNE sa2
			MOV EAX, angulo

			CMP EAX, 0
			JE cero
			CMP EAX, 11
			JE once

			INC EAX
			MOV angulo,EAX
			JMP sa2
			cero : MOV EAX, 1
			       MOV angulo, EAX
			       JMP sa2

			once : MOV EAX, 0
			MOV angulo, EAX
			sa2 :
	   }
	    r = direccion[angulo];
		break;

	case 'w':
		
		texto = " ";
		_asm{ CMP key,'w'
			  JNE fin

			  sa3 : MOV EAX,r
			        CMP EAX,0
					JAE validar
					JMP nada
						validar : CMP EAX,30
								  JBE accion
			                      CMP EAX, 330
			                      JE accion
			                      JMP nada
			                      accion : MOV EDX, posx
			                      DEC EDX
						    	  MOV masx,EDX
								  MOV EDX, posz
								  MOV masz,EDX
				                  MOV flag,1
             			fuera : MOV bandera1,1
			            JMP fin
			            nada :
	                    fin:
		 }
		if (flag == 1)
		{
		
			if (bandera1 == 1)
			{
				aux1 = matriz[masx][masz];
				
				cout << aux1 << endl;
				cout << aux2 << endl;
			}

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

			if (bandera2 == 1)
			{
				cout << "NO entre" << endl;
				zz = zz + 1;
				posx = posx - 1;
			}
			
			_asm {
				MOV EAX, masx
				CMP EAX, 71
				JE two
				JMP nada2
				two : MOV EDX, masz
					  CMP EDX, 3
					  JE exito

					  CMP EDX, 4
					  JE exito

					  CMP EDX, 5
					  JE exito
					  JMP nada2
					  exito : MOV bandera3, 1
							  nada2 :
			}
			if (bandera3 == 1)
			{
				texto = "HAS LLEGADO AL FINAL";

			}
		}
		_asm {
				MOV EAX, r
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
									 MOV flag,2
									 MOV bandera4, 1
									 nada3 :
		}
		if (flag == 2) {
	
			if (bandera4 == 1)
			{
				aux1 = matriz[masx][masz];
				aux2 = matriz[masx][masz];
			}
			
			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
			{
				xx = xx - 1;
				posz = posz + 1;
			}

		
			_asm {
				MOV EAX, masx
				CMP EAX, 71
				JE two2

				JMP nada5
				two2 : MOV EAX, masz
					   CMP EAX, 3
					   JE exito2

					   CMP EAX, 4
					   JE exito2

					   CMP EAX, 5
					   JE exito2
					   JMP nada5
					   exito2 : MOV bandera6, 1
								nada5 :
			}
			
			if (bandera6 == 1)
			{
			
				texto = "¡FELICIDADES GAME OVER :)!";
			}
		}
		_asm {
				MOV EAX, r
				CMP EAX, 150
				JAE validar6
				JMP nada6
				validar6 : CMP EAX, 210
						   JBE accion6
						   JMP nada6
						   accion6 : MOV EAX, posx
									 INC EAX
									 MOV masx, EAX
									 MOV EAX, posz
									 MOV masz, EAX
									 MOV flag,3
									 MOV bandera7, 1
									 nada6 :
		}
		if (flag == 3) {
			
			if (bandera7 == 1)
			{
				aux1 = matriz[masx][masz];
				aux2 = matriz[masx][masz];
			}
			
			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
			{
				zz = zz - 1;
				posx = posx + 1;
			}

			_asm {
				MOV EAX, masx
				CMP EAX, 71
				JE two8

				JMP nada8
				two8 : MOV EAX, masz
					   CMP EAX, 3
					   JE exito8

					   CMP EAX, 4
					   JE exito8

					   CMP EAX, 5
					   JE exito8
					   JMP nada8
					   exito8 : MOV bandera9, 1
								nada8 :
			}

			if (bandera9 == 1)
			{
				
				texto = "¡HAS LLEGADO AL FINAL!";
			}
		}
	
		_asm {
		
				MOV EAX, r
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
									 MOV flag,4
									 MOV bandera10, 1
									 nada9 :
		}
		if (flag == 4) {
			
			if (bandera10 == 1)
			{
				aux1 = matriz[masx][masz];
				aux2 = matriz[masx][masz];
			}
			
			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
			{
				xx = xx + 1;
				posz = posz - 1;
			}

			_asm {
				MOV EAX, masx
				CMP EAX, 71
				JE two11

				JMP nada11
				two11 : MOV EAX, masz
						CMP EAX, 3
						JE exito11

						CMP EAX, 4
						JE exito11

						CMP EAX, 5
						JE exito11
						JMP nada11
						exito11 : MOV bandera12, 1
								  nada11 :
			}
			
			if (bandera12 == 1)
			{
			
				texto = "¡HAS LLEGADO AL FINAL!";
			}
		}
		
		break;
	}

	glutPostRedisplay();
}



int main(int argc, char **argv) {
	genesferas();
	glutInit(&argc, argv);
	glutInitWindowSize(1900, 5000);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Laberinto By Aurelio,Adrian,Jesus");
	glutSetCursor(GLUT_CURSOR_NONE);
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); 
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glClearColor(0, 0.5, 0.7, 1);
	glutMainLoop();
	return 0;
}