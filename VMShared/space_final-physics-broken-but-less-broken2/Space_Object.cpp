#include "space.hpp"

namespace space {

SpaceObject::SpaceObject(): x_velocity_(0.0), y_velocity_(0.0)
, ux_velocity_(0.0), uy_velocity_(0.0), mass_(0.0), x_(0.0), y_(0.0)
, ux_(0.0), uy_(0.0) {}

SpaceObject::SpaceObject(double x_velocity, double y_velocity
  , double ux_velocity, double uy_velocity, double mass, double x, double y
  , double ux,  double uy): x_velocity_(x_velocity), y_velocity_(y_velocity)
  , ux_velocity_(ux_velocity), uy_velocity_(uy_velocity), mass_(mass)
  , x_(x), y_(y), ux_(ux), uy_(uy) {}

SpaceObject::~SpaceObject() {}

void SpaceObject::setX_Velocity(double x_velocity) {x_velocity_ = x_velocity;}
void SpaceObject::setY_Velocity(double y_velocity) {y_velocity_ = y_velocity;}
void SpaceObject::setUx_Velocity(double ux_velocity) {
  ux_velocity_ = ux_velocity;
}
void SpaceObject::setUy_Velocity(double uy_velocity) {
  uy_velocity_ = uy_velocity;
}
void SpaceObject::setMass(double mass) {mass_ = mass;}
void SpaceObject::setX(double x) {x_ = x;}
void SpaceObject::setY(double y) {y_ = y;}
void SpaceObject::setUx(double ux) {ux_ = ux;}
void SpaceObject::setUy(double uy) {uy_ = uy;}

double SpaceObject::getX_Velocity() const {return x_velocity_;}
double SpaceObject::getY_Velocity() const {return y_velocity_;}
double SpaceObject::getUx_Velocity() const {return ux_velocity_;}
double SpaceObject::getUy_Velocity() const {return uy_velocity_;}
double SpaceObject::getMass() const {return mass_;}
double SpaceObject::getX() const {return x_;}
double SpaceObject::getY() const {return y_;}
double SpaceObject::getUx() const {return ux_;}
double SpaceObject::getUy() const {return uy_;}
double SpaceObject::getRadius() const {return radius_;};


}  // namespace space
