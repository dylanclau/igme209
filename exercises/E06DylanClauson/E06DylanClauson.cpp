#include <SFML/Graphics.hpp>

using namespace sf;

void drawSpheal(RenderWindow& window)
{
    // draw base
    sf::CircleShape base(50.f);
    base.setFillColor(sf::Color(148, 172, 214));
    base.setPosition(600.f, 600.f);
    window.draw(base);
}

int main()
{
    RenderWindow window(VideoMode(800, 600), "My window");

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "Close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(); // Clear the window with the background color
        drawSpheal(window); // Call the separate function to draw the rectangle
        window.display(); // Update the window with what we've drawn
    }

    return 0;
}