#include <iostream>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(), "code here", sf::Style::Fullscreen);
	char a[3];
	int index = 0;
	std::string string;

  	while(window.isOpen())
  	{	
		sf::Font font;
		font.loadFromFile("17498.ttf");
		sf::Text text("", font, 10);
		text.setFillColor(sf::Color(0, 255, 255));
		std::ifstream g("abcd.txt");
		g.seekg(0, g.end);
		int len = g.tellg();  		 	

  		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
    			
	                if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) 
	                {   
	                    window.clear();       
	                    g.seekg(index, g.beg);
	                    g.read(a, 3);
	                    string += a;
	                    index += 3;
	                    text.setString(string);
	                    window.draw(text);
	                }  
            		/*if (event.key.code == sf::Keyboard::Backspace)
            		{
            			window.clear();
            			g.seekg(index - 3, g.beg);
	                    g.read(a, 3);
	                    string = string - a;
	                    index -= 3;
	                    text.setString(string);
	                    window.draw(text);


            		}*/
           		
            }
       		window.display();

	}

}
	return 0;
}
