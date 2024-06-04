This have been implemented in SFML since https://github.com/SFML/SFML/pull/3057.

SFML-2.1-RAWINPUT
=================

This is a windows implementation of raw mouse input.
Raw mouse input is data given from directly from the HID, bypassing the OS.

I hope more people could port this to OSX or Linux as it has to be cross platform to go into SFML.

How to use it
-----------------
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Title");
    
    /*
	 *	false(default): (no events are fired)
	 *	true: Register raw input for mice(events are fired)
	 */
  	window.setRelativeMouseMode(true);

You can toggle it anytime you want. 

