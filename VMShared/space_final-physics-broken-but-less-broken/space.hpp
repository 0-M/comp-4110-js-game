/**
 * @file space.hpp
 * @copyright 2016
 * @author Zachary Krausman and Daniel MacMillan
 * @date 4/22/16
 * @version 1
 *
 * @brief header class for final project
 *
 */
#ifndef SPACE_H
#define SPACE_H
#include <boost/lexical_cast.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>


namespace space {
/***************************** SPACEOBJECT ********************************/
/**
 * SpaceObject class which all the space objects inherit from.
 * Holds position, velocity, and mass data as well as
 */
class SpaceObject : public sf::Drawable {
 public:
    /**
     * Default constructor.
     * @param N/A
     * @return N/A
     */
    SpaceObject();
    /**
     * Constructor with parameters to set variables.
     * @param double velocity, double mass, double x, double y, double uX,
     * double uY
     * @return N/A
     */
    SpaceObject(double x_velocity, double y_velocity, double ux_velocity,
                double uy_velocity, double mass, double x, double y, double ux,
                double uy);
    /**
     * Destructor. Doesn't do anything at the moment.
     * @param N/A
     * @return N/A
     */
    ~SpaceObject();
    /**
     * setter for x_velocity
     * @param double x_velocity
     * @return N/A
     */
    void setX_Velocity(double x_velocity);
    /**
     * setter for y_velocity
     * @param double y_velocity
     * @return N/A
     */
    void setY_Velocity(double y_velocity);
    /**
     * setter for ux_velocity
     * @param double x_velocity
     * @return N/A
     */
    void setUx_Velocity(double ux_velocity);
    /**
     * setter for uy_velocity
     * @param double ux_velocity
     * @return N/A
     */
    void setUy_Velocity(double uy_velocity);
    /**
     * setter for mass
     * @param double mass
     * @return N/A
     */
    void setMass(double mass);
    /**
     * setter for x_
     * @param double x
     * @return N/A
     */
    void setX(double x);
    /**
     * setter for y_
     * @param double y
     * @return N/A
     */
    void setY(double y);
    /**
     * setter for ux_
     * @param double x
     * @return N/A
     */
    void setUx(double ux);
    /**
     * setter for uy_
     * @param double y
     * @return N/A
     */
    void setUy(double uy);
    /**
     * Getter for x_velocity
     * @param N/A
     * @return double
     */
    double getX_Velocity() const;
    /**
     * Getter for y_velocity
     * @param N/A
     * @return double
     */
    double getY_Velocity() const;
    /**
     * Getter for ux_velocity
     * @param N/A
     * @return double
     */
    double getUx_Velocity() const;
    /**
     * Getter for uy_velocity
     * @param N/A
     * @return double
     */
    double getUy_Velocity() const;
    /**
     * Getter for mass
     * @param N/A
     * @return double
     */
    double getMass() const;
    /**
     * Getter for x
     * @param N/A
     * @return double
     */
    double getX() const;
    /**
     * Getter for y
     * @param N/A
     * @return double
     */
    double getY() const;
    /**
     * Getter for ux
     * @param N/A
     * @return double
     */
    double getUx() const;
    /**
     * Getter for uy
     * @param N/A
     * @return double
     */
    double getUy() const;
    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const {};
 protected:
    double x_velocity_;    //< x-speed that works with SFML
    double y_velocity_;    //< y-speed that works with SFML
    double ux_velocity_;  //< x-speed relative to real life
    double uy_velocity_;  //< y-speed relative to real life
    double mass_;         //< Mass for calculating force.
    double radius_;       //< Radius of object
    double x_;            //< X Location relative to the SFML window.
    double y_;            //< Y Location relative to the SFML window.
    double ux_;           //< X Location relative to actual universe size
    double uy_;           //< Y Location relative to actual universe size
};

//!
//! A star class
//!
class Star : public SpaceObject {
  public:
    //! \brief Star constructor
    //!
    //! \param  x x-coordinate of star
    //! \param  y y-coordinate of star
    //! \param  mass mass of star
    //! \param  radius radius of the star
    //! \return     none
    //!
    //! Constructs a star object
    Star(double x, double y, double mass, double radius);
    //! \brief draw functions
    //!
    //! \param  target render target
    //! \param  states render states
    //! \return     none
    //!
    //! Draws the star object
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    sf::Color col_; //< the stars color
    sf::CircleShape star_; //< the circle representing the star
};

class Body: public SpaceObject {
  public:
    /**
     * Default constructor for the body, will call the constructor for
     * SpaceObject, and will use overloaded insertion operator to get info from
     * file.
     * @param N/A
     * @return N/A
     */
    //Body();

    /**
     * Constructor which will initialize setup for image, texture, and sprite
     *
     * @param std::string file_name
     * @return N/A
     */
    Body(double x_velocity, double y_velocity, double ux_velocity,
         double uy_velocity, double mass, double x, double y, double ux,
         double uy, std::string file_name);

    /**
     * Insertion operator will now take info from file and initialize variables
     * with it.
     * @param istream & in, const Body & b
     * @return istream &
     */
    //friend std::istream & operator >>(istream & in, const Body & b);

    /**
     * Takes a time paramter (double seconds) and moves the Body object given its
     * internal velocity for that much time
     * @param double seconds
     * @return N/A
     */
    void step(double seconds);

    sf::Sprite getSprite() const {
        return sprite_;
    }
    void setSpritePos(double x, double y) {
        sprite_.setPosition(sf::Vector2f(x, y));
    }


    /**
     *
     *
     *
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    Body(const Body &bSource);
  private:
    sf::Texture texture_;   //< Texture from the image of a solar body
    sf::Sprite sprite_;     //< Will hold the texture and move across screen
};

//!
//! A universe class that holds all the Star objects
//! and SpaceObjects and handles updating the universe
//!
class Universe : public sf::Drawable {
  public:
    //! \brief Universe constructor
    //!
    //! \param total_time total time the simulation should run for
    //! \param change_time length of each tick
    //! \return none
    //!
    //! Constructs a universe object
    Universe(double total_time, double change_time, std::string file_name,
             double win_x, double win_y);
    //! \brief calculates forces function
    //! \return none
    //!
    //! calculates the forces on and updates the velocity of each body
    void calcForces();
    //! \brief trandlate coordinates function
    //! \return none
    //!
    //! changes from coordinate system in file to SFML system
    void translateCoordinates();
    //! \brief monitor time function
    //! \return none
    //!
    //! prints the time to screen and closes the simulation
    //! if the amount of time specified in the command line has passed
    void monitorTime();
    //! \brief updates the universe file with final simulation state
    //! \return none
    //!
    //! saves the final state of the universe to a file
    void updateUniverse();
    //! \brief returns the time elapsed
    //! \return none
    //!
    //! returns the time elapsed
    double getTimeElapsed();
    //! \brief overloaded stream insertion operator
    //! \return ostream reference
    friend std::istream& operator >> (std::istream& is, Universe& uni);
    //! \brief inherited draw function definitiion
    //! \return none
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  private:
    int number_planets_;
    std::string temp_;
    double elapsed_time_;  //< how much time has passed since the start
    double total_time_;  //< amount of time the simulation should run for
    double change_time_;  //< amount of time in each tick of the simulation
    std::vector<Star> stars_;  //< vector of Star objects
    std::vector<Body> planets_;  //< vector of SpaceObjects
    std::string file_name_;
    bool end_sim_;
    double solar_system_size_, win_x_, win_y_;
    sf::Text text_;
    sf::Font font_;
};

}  // namespace space

#endif  // SPACE_H
