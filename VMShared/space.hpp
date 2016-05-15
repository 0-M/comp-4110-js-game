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
class SpaceObject: public sf::drawable {
 public:
    /**
     * Default constructor.
     * @param N/A
     * @return N/A
     */
    SpaceObject();
    /**
     * Constructor with parameters to set variables.
     * @param double velocity, double mass, double locationX, double locationY
     * @return N/A
     */
    SpaceObject(double velocity, double mass, double locX, double locY);
    /**
     * Destructor. Doesn't do anything at the moment.
     * @param N/A
     * @return N/A
     */
    ~SpaceObject();
    /**
     * setter for velocity
     * @param N/A
     * @return N/A
     */
    void setVelocity(double velocity);
    /**
     * setter for mass
     * @param double velocity
     * @return N/A
     */
    void setMass(double mass);
    /**
     * setter for locationX
     * @param double mass
     * @return N/A
     */
    void setlocationX(double locationX);
    /**
     * setter for locationY
     * @param double locationX
     * @return N/A
     */
    void setlocationY(double locationY);
    /**
     * Getter for velocity
     * @param N/A
     * @return double
     */
    double getVelocity() const;
    /**
     * Getter for mass
     * @param N/A
     * @return double
     */
    double getMass() const;
    /**
     * Getter for locationX
     * @param N/A
     * @return double
     */
    double getlocationX() const;
    /**
     * Getter for locationY
     * @param N/A
     * @return double
     */
    double getlocationY() const;

 private:
    double velocity_;    //< Movement speed. Updates based on force.
    const double mass_;  //< Mass for calculating force. Does not update.
    double locationX_;        //< X Location relative to the SFML window.
    double locationY_;        //< Y Location relative to the SFML window.
    /**
     * draw function overwritten from the drawable class.
     * @param sf::RenderTarget& target, sf::RenderStates states
     * @return N/A
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

/******************************** BODY **********************************/
/**
 * Represents moving bodies in the universe, including the sun and the planets
 * Handles taking in parameter data to initialize SpaceObject variables
 * Handles movement within the sfml window, does so in increments of seconds
 */
class Body: public SpaceObject {
 public:
    /**
     * Default constructor for the body, will call the constructor for
     * SpaceObject, and will use overloaded insertion operator to get info from
     * file.
     */
    Body();

    /**
     * Insertion operator will now take info from file and initialize variables
     * with it.
     * @param istream & in, const Body & b
     * @return istream &
     */
    friend istream & operator >> (istream & in, const Body & b);

    /**
     * Takes a time paramter (double seconds) and moves the Body object given its
     * internal velocity for that much time
     * @param double seconds
     * @return N/A
     */
    void step(double seconds);

 private:
    sf::Texture texture_;   //< Texutre from the image of a solar body
    sf::Sprite sprite_;     //< Will hold the texture and move across screen
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
    //! \return     none
    //!
    //! Constructs a star object
    Star(double x, double y, double mass);

 private:
    double diameter_;  //< diameter of the star
}
//!
//! A universe class that holds all the Star objects
//! and SpaceObjects and handles updating the universe
//!
class Universe {
 public:
    //! \brief Universe constructor
    //!
    //! \param total_time total time the simulation should run for
    //! \param change_time length of each tick
    //! \return none
    //!
    //! Constructs a universe object
    Universe(double total_time, double change_time);
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

 private:
    double elapsed_time_;  //< how much time has passed since the start
    double total_time_;  //< amount of time the simulation should run for
    double change_time_;  //< amount of time in each tick of the simulation
    vector<Star> stars_;  //< vector of Star objects
    vector<SpaceObject> planets_;  //< vector of SpaceObjects
}

}  // namespace space

#endif  // SPACE_H
