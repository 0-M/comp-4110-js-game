// Copyright 2016 Zachary Krausman and Daniel MacMillan
#include "space.hpp"
#include <stdlib.h>
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
namespace space {

Universe::Universe(double total_time, double change_time,
                   std::string file_name,
                   double win_x, double win_y) : total_time_(total_time),
    change_time_(change_time), file_name_(file_name), win_x_(win_x),
    win_y_(win_y) {
    if(!(std::cin >> number_planets_)) {
        throw("Failed to load number_planets_ from file");
        exit(1);
    }
    if(!(std::cin >> solar_system_size_)) {
        throw("Failed to load solar_system_size_ from file");
        exit(1);
    }
    for(int i = 0; i < number_planets_; i++) {
        std::string temp_fname;
        double un_x_pos, un_y_pos, un_x_vel, un_y_vel, mass_temp;
        std::cin >> un_x_pos >> un_y_pos >> un_x_vel >> un_y_vel >> mass_temp >>
                 temp_fname;
        Body temp(0, 0, un_x_vel, un_y_vel, mass_temp, 0, 0, un_x_pos, un_y_pos,
                  temp_fname);
        planets_.push_back(temp);
        //std::cout << temp_fname << std::endl;
    }
    srand(time(NULL));
    for (int i = 0; i < rand() % ((int(win_x + win_y)) / 20) + 50; i++) {
        Star temp(rand() % 800, rand() % 800, 0, rand() % 4);
        stars_.push_back(temp);
    }
    end_sim_ = 0;
    elapsed_time_ = 0;
    if(!font_.loadFromFile("arial.ttf")) {
        std::cout << "no font found" << std::endl;
    }

    text_.setFont(font_);
    text_.setString("Time: " + boost::lexical_cast<std::string>(elapsed_time_));
    text_.setCharacterSize(24);
    text_.setStyle(sf::Text::Bold);
    text_.setColor(sf::Color::White);
    text_.move(50, 50);

}

void Universe::calcForces() {
    std::vector<Body>::iterator bodies_itr_1;
    std::vector<Body>::iterator bodies_itr_2;
    double g_const = 6.67e-11;
    for(bodies_itr_1 = planets_.begin();bodies_itr_1 != planets_.end();++bodies_itr_1)
    {
            double net_f_x = 0;
            double net_f_y = 0;
            double a_x = 0,a_y = 0;
            for(bodies_itr_2 = planets_.begin();bodies_itr_2 != planets_.end();++bodies_itr_2)
            {
                if(bodies_itr_2 != bodies_itr_1)
                {
                    double dx = 0,dy = 0;
                    double f,r;
                    dx = (bodies_itr_1->getUx() - bodies_itr_2->getUx());
                    dy = (bodies_itr_1->getUy() - bodies_itr_2->getUy());
                    r = sqrt(pow(dx,2) + pow(dy,2));
                    f = (g_const * bodies_itr_1->getMass() * bodies_itr_2->getMass())/(pow(r,2));
                    net_f_x = net_f_x + (f * (dx/r));
                    net_f_y = net_f_y + (f * (dy/r));
                }
            }
            a_x = net_f_x/(bodies_itr_1->getMass());
            a_y = net_f_y/(bodies_itr_1->getMass());
            bodies_itr_1->setUx_Velocity(bodies_itr_1->getUx_Velocity() + a_x * change_time_);
            bodies_itr_1->setUy_Velocity(bodies_itr_1->getUy_Velocity() + a_y * change_time_);
    }
    }

void Universe::translateCoordinates() {
    for(int i = 0; i < number_planets_; i++) {
       // if(planets_[i].getUx() < 0)
       // {
       //     planets_[i].setX(((planets_[i].getUx() / solar_system_size_) * win_x_ / 2));
       // }
       // else
       // {
        planets_[i].setX((((planets_[i].getUx() / solar_system_size_) * win_x_ / 2) +
        (win_x_ / 2)));
       // }
       // if(planets_[i].getUy() < 0)
       // {
        //            planets_[i].setY(((planets_[i].getUy() / solar_system_size_) * win_y_ / 2));
       // }
       // else
       // {
        planets_[i].setY((((planets_[i].getUy() / solar_system_size_) * win_y_ / 2) +
        (win_y_ / 2)));
      //  }

        planets_[i].setSpritePos(planets_[i].getX(), planets_[i].getY());
       // std::cout << "x: " << planets_[i].getX() << std::endl;
       // std::cout << "y: " << planets_[i].getY() << std::endl;
       if(i == 0)
       {
            std::cout << "ux: " << planets_[i].getUx() << std::endl;
            std::cout << "uy: " << planets_[i].getUy() << std::endl;
       }

    }

}

void Universe::monitorTime() {
    text_.setString("Time: " + boost::lexical_cast<std::string>(elapsed_time_));
    if(elapsed_time_ >= total_time_) {
        std::ofstream file;
        file.open(file_name_.c_str(), std::ofstream::out | std::ofstream::trunc);
        file << number_planets_ << std::endl;
        file << solar_system_size_ << std::endl;
        std::vector<Body>::iterator bodies_itr = planets_.begin();
        for(bodies_itr; bodies_itr != planets_.end(); ++bodies_itr)
        {
            file << bodies_itr->getUx() << " "
            << bodies_itr->getUy() << " "
            << bodies_itr->getUx_Velocity() << " "
            << bodies_itr->getUy_Velocity() << " "
            << bodies_itr->getMass() << " "
            << bodies_itr->getGifName().c_str() << std::endl;
        }
        file.close();
        exit(0);
    }
}

void Universe::updateUniverse() {
    // Note to self: ux/uy_dpt calc in the constructor and make a bodies var for it

    // calculate forces
    calcForces();

    // convert ux/uy_velocity to sfml size
    std::vector<Body>::iterator bodies_itr = planets_.begin();
    for(bodies_itr; bodies_itr != planets_.end(); ++bodies_itr) {
       bodies_itr->step(change_time_);
    }
    translateCoordinates();
    elapsed_time_ = elapsed_time_ + change_time_;
    monitorTime();
    // rewrite to the txt file all the info now that it is updated
}

std::istream& operator >> (std::istream& is, Universe& uni) {
    is >> uni.temp_;
    return is;
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text_);
    for(int i = 0; i < number_planets_; i++) {
        target.draw(planets_[i]);
    }
    for(int i = 0; i < stars_.size(); i++) {
        target.draw(stars_[i]);
    }
}

}
