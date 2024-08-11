#include <SFML/Graphics.hpp>
#include<iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(60);

    sf::Sprite player;
    sf::Texture playerTex;
    playerTex.loadFromFile("assets/PersonTex/walk.png");

    player.setTexture(playerTex);
    player.setTextureRect(sf::IntRect(0,128,64,64)); //set x, y, width, height
    player.setScale(sf::Vector2f(3,3));

    while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        {
            int xTexture = 0;
            xTexture = (int)player.getPosition().x / 10 % 8;  //divde 10 to slow down 10 times
            xTexture *= 64;
            //std::cout << xTexture << std::endl;

            player.setTextureRect(sf::IntRect(xTexture, 192, 64, 64)); //set x, y, width, height
            player.move(5, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            int xTexture = 0;
            xTexture = (int)player.getPosition().x / 10 % 8;  //divde 10 to slow down 10 times
            xTexture *= 64;
            std::cout << xTexture << std::endl;

            player.setTextureRect(sf::IntRect(xTexture, 64, 64, 64)); //set x, y, width, height
            player.move(-5, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            int xTexture = 0;
            xTexture = (int)player.getPosition().y / 10 % 8;  //divde 10 to slow down 10 times
            xTexture *= 64;
            //std::cout << xTexture << std::endl;

            player.setTextureRect(sf::IntRect(xTexture, 0, 64, 64)); //set x, y, width, height
            player.move(0, -5);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            int xTexture = 0;
            xTexture = (int)player.getPosition().y / 10 % 8;  //divde 10 to slow down 10 times
            xTexture *= 64;
            std::cout << xTexture << std::endl;

            player.setTextureRect(sf::IntRect(xTexture, 128, 64, 64)); //set x, y, width, height
            player.move(0, 5);
        }

        //get player position
        sf::Vector2f position = player.getPosition();

        //border collision detection
        //if (position.x < 0) player.setPosition(0, position.y);
        //if (position.y < 0) player.setPosition(position.x, 0);
        //if (position.x + player.getTextureRect().width * 3 /2 > window.getSize().x)
        //    player.setPosition(window.getSize().x - player.getTextureRect().width * 2, position.y);
        //if (position.y + player.getTextureRect().height * 3 / 2 > window.getSize().y)
        //    player.setPosition(position.x, window.getSize().y - player.getTextureRect().height * 2);

        //bug : left-up,left-down,right-up,right-down would make the sprite is out of the window

        float playerWidth = player.getTextureRect().width * player.getScale().x;
        float playerHeight = player.getTextureRect().height * player.getScale().y;
        float windowWidth = window.getSize().x;
        float windowHeight = window.getSize().y;

        if (position.x < 0)
            position.x = 0;
        if (position.x + playerWidth > windowWidth)
            position.x = windowWidth - playerWidth;

        if (position.y < 0)
            position.y = 0;
        if (position.y + playerHeight > windowHeight)
            position.y = windowHeight - playerHeight;

        player.setPosition(position);

        window.clear(sf::Color::White);  //clear the screen
        window.draw(player);
        window.display();
    }

    return 0;
}