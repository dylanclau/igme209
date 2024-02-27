#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

float rotation = 0.0f;

void DrawSpheal(sf::RenderWindow& window) {
    // ear pt 1
    sf::CircleShape ear(45.f);
    ear.setFillColor(sf::Color(74, 124, 188));
    ear.setPosition(500.f, 100.f);
    window.draw(ear);

    // body
    sf::CircleShape body(250.f);
    body.setFillColor(sf::Color(164, 186, 223));
    body.setPosition(400.f, 100.f);
    window.draw(body);

    // ear pt 2
    ear.setPosition(655.f, 115.f);
    window.draw(ear);
    ear.setFillColor(sf::Color(164, 186, 223));
    ear.setPosition(650.f, 120.f);
    window.draw(ear);

    // fin 1
    sf::CircleShape fin(40.f);
    fin.setFillColor(sf::Color(235, 222, 185));
    fin.setRotation(-20);
    fin.setScale(3, 1);
    fin.setPosition(375, 500);
    window.draw(fin);

    // belly
    sf::CircleShape belly(55.f);
    belly.setFillColor(sf::Color(249, 242, 226));
    belly.setScale(4, 3);
    belly.setRotation(35);
    belly.setPosition(515.f, 155.f);
    window.draw(belly);
    // fill in
    belly.setFillColor(sf::Color(249, 242, 226));
    belly.setScale(1.6, 0.7);
    belly.setRotation(100);
    belly.setPosition(490.f, 245.f);
    window.draw(belly);

    // fin 2
    fin.setFillColor(sf::Color(249, 242, 226));
    fin.setRotation(30);
    fin.setScale(3, 1);
    fin.setPosition(675, 450);
    window.draw(fin);

    // teeth
    sf::CircleShape tooth(40.f, 3);
    tooth.setFillColor(sf::Color(254, 254, 254));
    tooth.setRotation(-50);
    tooth.setPosition(390.f, 300.f);
    window.draw(tooth);
    tooth.setRotation(-60);
    tooth.setPosition(523.f, 333.f);
    window.draw(tooth);

    // mouth
    // mouth left
    sf::CircleShape mouthL(15.f);
    mouthL.setFillColor(sf::Color(164, 186, 223));
    mouthL.setRotation(10);
    mouthL.setScale(4, 3);
    mouthL.setPosition(400.f, 190.f);
    window.draw(mouthL);
    // mouth right
    sf::CircleShape mouthR(18.f);
    mouthR.setFillColor(sf::Color(164, 186, 223));
    //mouthR.setRotation(5);
    mouthR.setScale(4, 3);
    mouthR.setPosition(500.f, 200.f);
    window.draw(mouthR);

    // eyes
    // black
    sf::CircleShape eye(30.f);
    eye.setFillColor(sf::Color(0, 0, 0));
    eye.setRotation(-45);
    eye.setScale(1, 0.6);
    eye.setPosition(450.f, 200.f);
    window.draw(eye);
    eye.setScale(1, 1);
    eye.setPosition(565.f, 215.f);
    window.draw(eye);
    // grey
    eye.setFillColor(sf::Color(96, 96, 96));
    eye.setRotation(-45);
    eye.setScale(0.5, 0.4);
    eye.setPosition(462.f, 200.f);
    window.draw(eye);
    eye.setScale(0.5, 0.5);
    eye.setPosition(594.f, 223.f);
    window.draw(eye);
    // white
    eye.setFillColor(sf::Color(254, 254, 254));
    eye.setRotation(-65);
    eye.setScale(0.5, 0.4);
    eye.setPosition(474.f, 196.f);
    window.draw(eye);
    eye.setScale(0.5, 0.5);
    eye.setPosition(585.f, 210.f);
    window.draw(eye);

    // spots
    sf::CircleShape spot(30.f);
    spot.setFillColor(sf::Color(254, 254, 254));
    spot.setScale(1.5, 1);
    spot.setRotation(50);
    spot.setPosition(805, 200);
    window.draw(spot);
    spot.setScale(0.75, 0.5);
    spot.setPosition(800, 310);
    window.draw(spot);
    spot.setScale(1.075, 0.75);
    spot.setPosition(850, 365);
    window.draw(spot);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Drawing");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(96, 96, 96)); // clear the window with color(255,255,255)
        DrawSpheal(window);
        window.display(); // display the window
    }

    return 0;
}