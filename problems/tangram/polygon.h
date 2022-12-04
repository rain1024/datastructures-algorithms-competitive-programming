#pragma once

#include <string>
#include <vector>

#define mp std::make_pair
#define point std::pair<float, float>

using namespace std;

struct Color {
  float r;
  float g;
  float b;
};

class COLORS {
 public:
  static const Color RED, BLACK, WHITE, PINK, PURPLE, GREEN, BLUE, YELLOW,
      AMBER, CYAN, GRAY, LIGHT_GRAY;
};

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
const Color COLORS::GRAY = {0.62f, 0.62f, 0.62f};
const Color COLORS::LIGHT_GRAY = {0.96f, 0.96f, 0.96f};

class Polygon {
 public:
  vector<point> vertices;
  string id;
  Color color;
  point velocity;
  point position;
  int iter;

  Polygon(){};

  Polygon(std::string id, std::vector<point> v, Color color) {
    this->id = id;
    this->vertices = v;
    this->color = color;
    this->velocity = mp(0.0, 0.0);
    this->position = mp(0.0, 0.0);
    this->iter = 0;
  }

  void SetVelocity(point velocity) { this->velocity = velocity; }

  void SetRandomVelocity(){
    float vx = ((rand() % 1000) - 500) * 0.00001;
    float vy = ((rand() % 1000) - 500) * 0.00001;
    vx *= 2;
    vy *= 2;
    this->velocity = mp(vx, vy);
  }

  void display() {
    glBegin(GL_POLYGON);
    point screen_translate = mp(-0.5, -0.7);
    float vx = this->velocity.first;
    float vy = this->velocity.second;
    this->iter += 1;
    this->position = mp(this->velocity.first + this->position.first,
                        this->velocity.second + this->position.second);
    if(this->position.first > 1.1 || this->position.first < -1.1){
      vx = -this->velocity.first;
    }
    if(this->position.second > 1.1 || this->position.second < -1.1){
      vy = -this->velocity.second;
    }
    if(this->iter > 1000){
      this->position = mp(0.0, 0.0);
    }
    this->velocity = mp(vx, vy);
    cout << this->id << endl;
    cout << "(x, y) = " << this->position.first << ", " << this->position.second
         << endl;
    glColor3f(this->color.r, this->color.g, this->color.b);

    for (auto p : this->vertices) {
      float x = p.first + screen_translate.first + this->position.first;
      float y = p.second + screen_translate.second + this->position.second;

      glVertex2d(x, y);
    }
    glEnd();
  }
};