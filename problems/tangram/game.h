#pragma once
#include <iostream>
#include <vector>

#include "polygon.h"

// using namespace std;

class Game {
 public:
  std::vector<Polygon> polygons;
  Polygon target;

  Game() {
    std::vector<point> vertices;
    float vx, vy;

    vertices = {mp(0.25, 0), mp(0.25, 0.5), mp(0.5, 0.75), mp(0.75, 0.5),
                mp(0.75, 0)};
    Polygon p1 = Polygon("1", vertices, COLORS::GREEN);

    vertices = {mp(0, 0), mp(0, 0.25), mp(0.25, 0.5), mp(0.25, 0)};
    Polygon p2 = Polygon("2", vertices, COLORS::PINK);

    vertices = {mp(0.75, 0), mp(0.75, 0.5), mp(1, 0.25), mp(1, 0)};
    Polygon p3 = Polygon("3", vertices, COLORS::RED);

    vertices = {mp(0.5, 0.75), mp(0.75, 1), mp(1, 0.75), mp(1, 0.25)};
    Polygon p4 = Polygon("4", vertices, COLORS::BLUE);

    vertices = {mp(0, 0.25), mp(0, 0.75), mp(0.5, 1.25), mp(0.75, 1)};
    Polygon p5 = Polygon("5", vertices, COLORS::CYAN);

    vertices = {mp(0.5, 1.25), mp(1, 1.25), mp(1, 0.75)};
    Polygon p6 = Polygon("6", vertices, COLORS::YELLOW);
    
    vertices = {mp(0, 0.75), mp(0, 1.25), mp(0.5, 1.25)};
    Polygon p7 = Polygon("7", vertices, COLORS::AMBER);

    vertices = {mp(0, 0), mp(0, 1.25), mp(1, 1.25), mp(1, 0)};
    this->target = Polygon("target", vertices, COLORS::LIGHT_GRAY);

    std::vector<Polygon> polygons = {p1, p2, p3, p4, p5, p6, p7};
    this->polygons = polygons;
    for(auto &p: this->polygons){
      p.SetRandomVelocity();
    }
  };
  void display() {
    cout << "Call from Game::display -> Game Display" << endl;
    this->target.display();
    for (auto &p : this->polygons) {
      p.display();
    }
  }

  void Run() { cout << "Running" << endl; }
};