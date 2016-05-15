/*Copyright 2016 Daniel MacMillan and Zachary Krausman*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include "space.hpp"

/**
 * Would have tested the lower cases if they were applicable
 */
// BOOST_AUTO_#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
TEST_CASE(StepFunction) {
  // Dummy test for later when we get around to finalizing step function
  // BOOST_CHECK(add(2,2) == 4);
// }

// BOOST_AUTO_TEST_CASE(UniverseToSFML) {
  // Dummy test for when we get around to finalizing updateUniverse
  // BOOST_CHECK(add(2,2) == 4);
// }

/**
 * Checks when calcForces function works
 */
BOOST_AUTO_TEST_CASE(VelocityFromNewtonsLaw) {
  sf::Font font;
  if (!font.loadFromFile("arial.ttf")) {
      std::cout << "no font found" << std::endl;
  }
  space::Universe y(1000.0, 1000.0, "planets.txt", 800, 800);
  y.translateCoordinates();

  sf::RenderWindow window(sf::VideoMode(800, 800), "SimulationEnds");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    y.updateUniverse();
    window.close();
  }
  BOOST_CHECK(y.getPlanets()[0].getUx_Velocity() == 2.9800e+04);
}

/**
 * Test if the simulation ends when the time is supposed to run out.
 * Check if that error is thrown
 */
BOOST_AUTO_TEST_CASE(SimulationEnds) {
  sf::Font font;
  if (!font.loadFromFile("arial.ttf")) {
      std::cout << "no font found" << std::endl;
  }
  space::Universe y(1000.0, 1000.0, "planets.txt", 800, 800);

  y.translateCoordinates();
  bool wentThroughSimulation = 0;
  sf::RenderWindow window(sf::VideoMode(800, 800), "SimulationEnds");
  while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
              window.close();
      }
      BOOST_CHECK_NO_THROW(y.monitorTime());
      window.clear();
      y.updateUniverse();
      window.display();
      window.close();
  }
  wentThroughSimulation = 1;
  BOOST_CHECK(wentThroughSimulation == true);
}

/**
 * Checks for error when there is no gif to be found
 */
BOOST_AUTO_TEST_CASE(BadGifName) {
  space::Body b(0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, "meh.gif");
  BOOST_CHECK_THROW(b, std::runtime_error);
}
