#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
    // Create a video mode object
    VideoMode vm(1920, 1080);
    // Create and open a window for the game
    RenderWindow window(vm, "Pong", Style::Fullscreen);
    int score = 0;
    int score2 = 0;
    int lives = 3;
    int lives2 = 3;

    bool pausa = true;

    // Create a bat at the bottom center of the screen
    Bat bat(20, 1080 / 2);
    Bat bat2(1900, 1080 / 2);

    // Create a ball
    Ball ball(1920 / 2, 1080/2);

    // Create a Text object called HUD
    Text hud;
    // A cool retro-style font
    Font font;
    font.loadFromFile("fonts/8bit.ttf");
    // Set the font to our retro-style
    hud.setFont(font);
    // Make it nice and big
    hud.setCharacterSize(25);
    // Choose a color
    hud.setFillColor(Color::White);
    hud.setPosition(20, 20);
    // Here is our clock for timing everything
    Clock clock;
    
    std::stringstream go;
           go << "Game Over";
          // hud.setString(go.str());

           std::stringstream Es;
           Es << "Entre to start";
           hud.setString(Es.str());

        
           
          

           


    while (window.isOpen())
    {
        /*
        Handle the player input
        ****************************
        ****************************
        ****************************
        */
       
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            pausa = false;
        }
        
        if (pausa != true)
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    // Quit the game when the window is closed
                    window.close();
            }

            // Handle the player quitting
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }

            // Handle the pressing and releasing of the arrow keys
            //Bat controls
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                bat.moveUp();
            }
            else
            {
                bat.stopUp();
            }

            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                bat.moveDown();
            }
            else
            {
                bat.stopDown();
            }
            //Bat2 Controls
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                bat2.moveUp();
            }
            else
            {
                bat2.stopUp();
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                bat2.moveDown();
            }
            else
            {
                bat2.stopDown();
            }
            /*
            Update the bat, the ball and the HUD
            *****************************
            *****************************
            *****************************
            */

            // Update the delta time
            Time dt = clock.restart();

            bat.update(dt);
            bat2.update(dt);
            ball.update(dt);

            // Update the HUD text
            std::stringstream ss;
            ss << "Score: " << score << " Lives: " << lives << "                          Score2: " << score2 << " Lives 2: " << lives2;
            hud.setString(ss.str());

           

            // Handle ball hitting the right
            if (ball.getPosition().left > window.getSize().x)
            {

                // Reverse the ball direction
                ball.reboundLeft();
                //Remove a life2
                lives2--;
                //Update Score1
                score++;
                // Check for zero lives p1
                if (lives2 < 1) {
                    // reset the score
                    score = 0;
                    // reset the lives
                    lives = 3;
                    // reset the score2
                    score2 = 0;
                    // reset the lives2
                    lives2 = 3;

                    pausa = true;
                    
                    hud.setString(go.str());
                }
                

            }

            // Handle ball hitting the left
            if (ball.getPosition().left < 0)
            {

                // Reverse the ball direction
                ball.reboundLeft();
                //Remove a life
                lives--;
                //Update Score2
                score2++;
                // Check for zero lives p1
                if (lives < 1) {
                    // reset the score
                    score = 0;
                    // reset the lives
                    lives = 3;
                    // reset the score2
                    score2 = 0;
                    // reset the lives2
                    lives2 = 3;

                    pausa = true;
                    window.draw(hud);
                    hud.setString(go.str()); 
                }
            }

            // Handle ball hitting top and bottom
            if (ball.getPosition().top < 0 || ball.getPosition().top + ball.getPosition().height>window.getSize().y)
            {
                ball.reboundSides();
            }

            // Has the ball hit the bat?
            if (ball.getPosition().intersects(bat.getPosition()))
            {
                // Hit detected so reverse the ball and score a point
                ball.reboundBat();
            }

            // Has the ball hit the bat2?
            if (ball.getPosition().intersects(bat2.getPosition()))
            {
                // Hit detected so reverse the ball and score a point
                ball.reboundBat();
            }
            /*
            Draw the bat, the ball and the HUD
            *****************************
            *****************************
            *****************************
             */
            
            if (Keyboard::isKeyPressed(Keyboard::Return))
            {
                pausa = true;

                Time dt = clock.restart();
            }
        }
            window.clear();
            window.draw(hud);
            window.draw(bat.getShape());
            window.draw(bat2.getShape());
            window.draw(ball.getShape());
            window.display();
       

       
    }
    return 0;
}