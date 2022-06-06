
# Juego de carreras en 3D

En el siguiente proyecto se desarrolló un Juego en 3D utilizando OpengL. En el juego se simula una carretera con edificios alrededor, la cual se debe de recorrer antes de cierto tiempo evitando chocar con los obstaculos que se encuentran enmedio de la calle.

## Como correr el programa
    1.Descargar Visual Studio  (v. 2015 o 2019). Asegurandose que se descarguen todos lo complementos para poder programar en C++.
    2.Una vez descargado debemos abrir el proyecto en Visual Studio, escogiendo el archivo llamado Texturas.vcxproj.
    3.Abrir las opciones del proyecto principal.
    3.Configuraremos la libreria glut por lo cual debemos de seleccionar configuracion.
    4.Escoger "para todos los ajustes".
    5.Ir a C++, despues a incluciones adicionales y poner la carpeta include. Aplicar cambios.
    6.Ir a Vinculador y en el primero poner en adicionales a lib para después guardar cambios.
    7. Cambiamos a "debug", seleccionamos entrada y en dependencias adicionales escribimos "freeglut.lib".
## Instruciones del juego
El juego consiste en que el usuario debe de llegar a la meta
que se encuentra al otro extremo de la carretera 
 evitando los obstaculos y antes que se  acabe el tiempo.
El usuario se podrá mover hacia adelante con la tecla w, girar hacia la derecha con la tecla d y girar hacia la izquierda con la tecla a.
## Reglas
El usuario cuenta con 100 segundos para llegar a la meta y deberá de evitar los obstaculos, ya que al 
momento de chocar con alguno perderá y el juego se reiniciará.
También en el momento de que se acabe el tiempo el juego se reiniciará.
