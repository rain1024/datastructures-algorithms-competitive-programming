#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#include <iostream>
#include <string>
#include <utility>
#include <vector>
// #include <GL/freeglut.h>
// #include <GL/glew.h>
// #include <GL/freeglut.h>
// #include <OpenGL/gltex.h>

#define mp std::make_pair
#define point std::pair<float, float>

using namespace std;

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

struct Color {
  float r;
  float g;
  float b;
};

class COLORS {
 public:
  static const Color RED, BLACK, WHITE, PINK, PURPLE, GREEN, BLUE, YELLOW,
      AMBER, CYAN;
};
// Color COLORS::RED = 4;
const Color COLORS::WHITE = {1.0f, 1.0f, 1.0f};
const Color COLORS::BLACK = {0.0f, 0.0f, 0.0f};
const Color COLORS::RED = {0.96, 0.26f, 0.21f};
const Color COLORS::PINK = {0.91f, 0.12f, 0.39f};
const Color COLORS::PURPLE = {0.61f, 0.15f, 0.69f};
const Color COLORS::GREEN = {0.30f, 0.69f, 0.31f};
const Color COLORS::BLUE = {0.13f, 0.59f, 0.95f};
const Color COLORS::YELLOW = {1.00f, 0.92f, 0.23f};
const Color COLORS::AMBER = {1.00f, 0.76f, 0.03f};
const Color COLORS::CYAN = {0.00f, 0.74f, 0.83f};

void init() {
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("TANGRAMS");
  Color c = COLORS::BLACK;
  glClearColor(c.r, c.g, c.b, 1.0);
  glMatrixMode(GL_PROJECTION);
}

class Polygon {
 public:
  std::vector<point> vertices;
  Color color;

  Polygon(std::vector<point> v, Color color) {
    this->vertices = v;
    this->color = color;
  }

  void display() {
    glBegin(GL_POLYGON);
    glColor3f(this->color.r, this->color.g, this->color.b);
    for (auto p : this->vertices) {
      glVertex2d(p.first - 0.5, p.second - 0.7);
    }
    glEnd();
  }
};

void drawText(std::string text, int x, int y) {
  // glLoadIdentity();
  gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
  Color c = COLORS::RED;
  glColor3f(c.r, c.g, c.b);
  glRasterPos2f(x, y);
  for (auto c : text) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
  }
}

class Game {
 public:
  vector<Polygon> polygons;
  Game(vector<Polygon> polygons) { this->polygons = polygons; };
  void display() {
    for (auto p : this->polygons) {
      p.display();
    }
  }
};

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  std::vector<point> vertices;

  vertices = {mp(0.25, 0), mp(0.25, 0.5), mp(0.5, 0.75), mp(0.75, 0.5),
              mp(0.75, 0)};
  Polygon p1 = Polygon(vertices, COLORS::GREEN);

  vertices = {mp(0, 0), mp(0, 0.25), mp(0.25, 0.5), mp(0.25, 0)};
  Polygon p2 = Polygon(vertices, COLORS::PINK);

  vertices = {mp(0.75, 0), mp(0.75, 0.5), mp(1, 0.25), mp(1, 0)};
  Polygon p3 = Polygon(vertices, COLORS::RED);

  vertices = {mp(0.5, 0.75), mp(0.75, 1), mp(1, 0.75), mp(1, 0.25)};
  Polygon p4 = Polygon(vertices, COLORS::BLUE);

  vertices = {mp(0, 0.25), mp(0, 0.75), mp(0.5, 1.25), mp(0.75, 1)};
  Polygon p5 = Polygon(vertices, COLORS::CYAN);

  vertices = {mp(0.5, 1.25), mp(1, 1.25), mp(1, 0.75)};
  Polygon p6 = Polygon(vertices, COLORS::YELLOW);

  vertices = {mp(0, 0.75), mp(0, 1.25), mp(0.5, 1.25)};
  Polygon p7 = Polygon(vertices, COLORS::AMBER);

  vector<Polygon> polygons = {p1, p2, p3, p4, p5, p6, p7};

  Game game = Game(polygons);
  game.display();
  drawText("TANGRAMS", 250.0f, 50.0f);

  glFlush();
}

void reshape() { std::cout << "Reshape " << std::endl; }

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);

  init();
  glutDisplayFunc(display);
  // glutReshapeFunc(reshape);

  glutMainLoop();
  return 0;
}
