/*
** menu.cpp for cpp_gkrellm in /home/wluc/Epitech/GGJ/cpp_gkrellm
**
** Made by William LUC
** Login   <luc_w@epitech.net>
**
** Started on  Sat Jan 21 22:02:05 2017 William LUC
// Last update Sun Jan 22 14:32:20 2017 Jean Francois Durand
*/


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game_Information.hpp"
#include "IButton.hpp"
#include <iostream>

void            Game::Menu()
{
  sf::Texture   _tex;
  sf::Event     event;
  Button        play(sf::Vector2i(0, 325), sf::Vector2i(500, 100), Game::GameState::GAME);
  Button        quit(sf::Vector2i(0, 515), sf::Vector2i(500, 100), Game::GameState::END);
  sf::Music     music;

  window.clear();
  Draw_Rectangle_one();
  if (!music.openFromFile("resources/MineRabbit-ScreenTitle.flac"))
  {
    std::cerr << "Fail to load menu music" << std::endl;
    return ;
  }
  _tex.loadFromFile("resources/Menu.png");
  sf::Sprite    _sprite(_tex);
  window.draw(_sprite);
  window.display();
  music.play();
  while (window.isOpen() && getState() == MENU)
    {
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    {
	      window.close();
	      music.stop();
	      _gameState = END;
	    }
	}
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        play.collides(sf::Mouse::getPosition(window)))
	{
	  _gameState = play.getState();
	  wave = 1;
	  music.stop();
	  Mines.erase(Mines.begin(), Mines.end());
          Bunnies.erase(Bunnies.begin(), Bunnies.end());
	  return ;
	}
      else  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
		quit.collides(sf::Mouse::getPosition(window)))
	{
	  _gameState = quit.getState();
	  music.stop();
	  return;
	}
    }
}
