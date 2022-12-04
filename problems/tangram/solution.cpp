#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "game.h"
#include "polygon.h"

#define mp std::make_pair
#define point std::pair<float, float>

using namespace std;

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

Game game;

void init() {
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("TANGRAMS");
  Color c = COLORS::BLACK;
  glClearColor(c.r, c.g, c.b, 1.0);
  glMatrixMode(GL_PROJECTION);
  game = Game();
}

void drawText(std::string text, int x, int y) {
  gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
  Color c = COLORS::RED;
  glColor3f(c.r, c.g, c.b);
  glRasterPos2f(x, y);
  for (auto c : text) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  cout << "Call display " << endl;
  game.display();
  drawText("TANGRAMS", 250.0f, 50.0f);
  glLoadIdentity();
  glutSwapBuffers();
}

void reshape() { std::cout << "Reshape " << std::endl; }

void GameLoop(int){
  std::cout << "Game Loop " << std::endl;
  glutPostRedisplay();
  glutTimerFunc(1000/60, GameLoop, 0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  init();
  glutDisplayFunc(display);
  // glutReshapeFunc(reshape);
  
  glutTimerFunc(3000, GameLoop, 0);
  glutMainLoop();
  // cout << "Timer after MainLoop" << endl;
  // glutTimerFunc(3000, GameLoop, 0);
  
  return 0;
}
