// "Copyright 2016 <Copyright Zachary Krausman>"
#include "guitar_string_class.hpp"
#include <SFML/Graphics.hpp>

#include <SFML/System.hpp>

#include <SFML/Audio.hpp>

#include <SFML/Window.hpp>
#include <math.h>

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>



namespace GuitarHero {


static std::vector<sf::Int16> makeSamplesFromString(GuitarString * gs) {
    std::vector<sf::Int16> samples;
    gs->pluck();
    int duration = 8;
    for (int i = 0 ; i < 44100 * duration ; i++) {
        gs->tic();
        samples.push_back(gs->sample());
    }
    return samples;
}

}  // namespace GuitarHero


int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero Lite");
    sf::Event event;
    std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
    std::vector<std::vector<sf::Int16> > x(37);
    std::vector<sf::SoundBuffer> y(37);
    std::vector<sf::Sound> z(37);

    for (int i = 0; i < 37; i++) {
        GuitarHero::GuitarString gs(110.0 * pow(2.0, (i/12.0)));
        x[i] = makeSamplesFromString(&gs);
    }

    for (int i = 0; i < 37; i++) {
        sf::SoundBuffer t;
        t.loadFromSamples(&x[i][0], x[i].size(), 2, 44100);
        y[i] = t;
    }

    for (int i = 0; i < 37; i++) {
        sf::Sound t;
        t.setBuffer(y[i]);
        z[i] = t;
    }



    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered: {
                char temp = event.text.unicode;
                std::size_t found = keyboard.find(temp);
                // std::cout << event.key.code << std::endl;
                if (found != std::string::npos) {
                    std::cout << found << std::endl;
                    z[found].play();
                }
                break;
            }

            default:

                break;
            }

            window.clear();
            window.display();
        }
    }

    return 0;
}

