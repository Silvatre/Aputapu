#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
	 // Create the main window
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Window");
	sf::Clock Clock;

	// OpenGL settings
	// Set color and depth clear value
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);

	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f);

    // Start main loop
    bool Running = true;
    while (Running)
    {
		// Checking if the key is being hold
		const sf::Input& Input = App.GetInput();
		if(Input.IsKeyDown(sf::Key::A))
		{
			sf::Clock CLK;
			while(CLK.GetElapsedTime() < 2.f)
			{}
			App.Close();
			Running = false;
		}

		sf::Event Event;
		while (App.GetEvent(Event))
		{
			if(Event.Type == sf::Event::Resized)
				glViewport(0, 0, Event.Size.Width, Event.Size.Height);

			// Window closed
			if (Event.Type == sf::Event::Closed)
			{
				App.Close();
				Running = false;
			}

			// Escape key pressed
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
			{
				App.Close();
				Running = false;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.f, 0.f, -200.f);
		glRotatef(Clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
		glRotatef(Clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
		glRotatef(Clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

		glBegin(GL_QUADS);

			glVertex3f(-50.f, -50.f, -50.f);
			glVertex3f(-50.f,  50.f, -50.f);
			glVertex3f( 50.f,  50.f, -50.f);
			glVertex3f( 50.f, -50.f, -50.f);

			glVertex3f(-50.f, -50.f, 50.f);
			glVertex3f(-50.f,  50.f, 50.f);
			glVertex3f( 50.f,  50.f, 50.f);
			glVertex3f( 50.f, -50.f, 50.f);

			glVertex3f(-50.f, -50.f, -50.f);
			glVertex3f(-50.f,  50.f, -50.f);
			glVertex3f(-50.f,  50.f,  50.f);
			glVertex3f(-50.f, -50.f,  50.f);

			glVertex3f(50.f, -50.f, -50.f);
			glVertex3f(50.f,  50.f, -50.f);
			glVertex3f(50.f,  50.f,  50.f);
			glVertex3f(50.f, -50.f,  50.f);

			glVertex3f(-50.f, -50.f,  50.f);
			glVertex3f(-50.f, -50.f, -50.f);
			glVertex3f( 50.f, -50.f, -50.f);
			glVertex3f( 50.f, -50.f,  50.f);

			glVertex3f(-50.f, 50.f,  50.f);
			glVertex3f(-50.f, 50.f, -50.f);
			glVertex3f( 50.f, 50.f, -50.f);
			glVertex3f( 50.f, 50.f,  50.f);

		glEnd();



        App.Display();
    }

    return EXIT_SUCCESS;
}