//
// Start.cpp for Start in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
//
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
//
// Started on  Sun Jan 22 12:18:04 2017 Jean Francois Durand
// Last update Sun Jan 22 15:07:26 2017 Jean Francois Durand
//

#include <iostream>
#include <algorithm>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Game_Information.hpp"

void		Game::Display()
{
  for (std::list<Bunny>::iterator it = Bunnies.begin(); it != Bunnies.end(); ++it)
    window.draw((*it).getSprite());
  for (std::list<Mine>::iterator it = Mines.begin(); it != Mines.end(); ++it)
    {
      if ((*it).getDamages() != 0)
	window.draw((*it).getSprite());
      else
	{
	  if ((*it).getFrame() == 10)
	    it = Mines.erase(it);
	  else
	    window.draw((*it).getRectSprite());
	}
    }
}

void		Game::Manage_entities(sf::Texture const & BunnyTexture,
				      sf::Texture const & MineTexture,
				      sf::Clock & addclock,
				      sf::Texture const & ExplTexture)
{
  if (addclock.getElapsedTime().asSeconds() > 4.0f - (wave / 3.0f))
    {
      Bunny	add(1, BunnyTexture);
      if (nbr_bunnies <= (wave * 10))
	Bunnies.push_back(add);
      nbr_bunnies = nbr_bunnies + 1;
      addclock.restart();
    }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && nbr_bunnies > 0)
    {
      sf::Vector2i Pos = sf::Mouse::getPosition(window);
      if (Pos.y > 250 && Pos.y < 750 && nbr_mines <= (wave * 12))
	{
	  nbr_mines = nbr_mines + 1;
	  Mine		mine(Pos.x, Pos.y,
      			     MineTexture, ExplTexture);
	  Mines.push_back(mine);
	}
    }
}

bool		Game::check_end()
{
  for (std::list<Bunny>::iterator it = Bunnies.begin(); it != Bunnies.end(); ++it)
    {
      if ((*it).getY() > 700)
	{
	  _gameState = MENU;
	  return true;
	}
    }
  return false;
}

void		Game::check_collision()
{
  for (std::list<Mine>::iterator it = Mines.begin(); it != Mines.end(); ++it)
    {
      for (std::list<Bunny>::iterator it2 = Bunnies.begin(); it2 != Bunnies.end(); ++it2)
	{
	  if (((*it2).getY() + 41 > (*it).getY()) && (((*it2).getX() > (*it).getX() - 25))
	      && (((*it2).getX() < (*it).getX() + 15)))
	    {
	      sound.play();
	      (*it).setDamages(0);
	      (*it).setPos((*it).getX() - 30, (*it).getY() - 30);
	      it2 = Bunnies.erase(it2);
	    }
	}
    }
}

void		Game::Manage_game(sf::Texture BunnyTexture,
				  sf::Clock & add, sf::Clock & anim,
				  sf::Texture MineTexture, sf::Texture ExplTexture,
				  sf::Sprite &Herb)
{
  if (check_end() == true)
    return;
  window.clear();
  window.draw(Background);
  if (anim.getElapsedTime().asSeconds() > 0.3f - (wave / 10.0f))
    {
      for (std::list<Bunny>::iterator it = Bunnies.begin(); it != Bunnies.end(); ++it)
	(*it).updateSprite();
      for (std::list<Mine>::iterator it = Mines.begin(); it != Mines.end(); ++it)
	(*it).updateSprite();
      check_collision();
      Herb.setTextureRect(sf::IntRect((_frame * 500), 0, 500, 230));
      _frame += 1;
      if (_frame == 6)
	_frame = 0;
      anim.restart();
    }
  Manage_entities(BunnyTexture, MineTexture, add, ExplTexture);
  Display();
  Draw_Rectangle_one();
  window.draw(Herb);
  window.display();
}

void		Game::Initalization(sf::Texture &BunnyTexture, sf::Texture &MineTexture,
				    sf::Texture &ExplTexture, sf::Sprite &Herb,
				    sf::Texture &HerbTexture)
{
  if (!BunnyTexture.loadFromFile("resources/bunnies.png") ||
      !MineTexture.loadFromFile("resources/mine.png") ||
      !HerbTexture.loadFromFile("resources/HerbeAnimation.png") ||
      !ExplTexture.loadFromFile("resources/explosion.png"))
    throw std::runtime_error("Error while getting images");
  nbr_bunnies = 0;
  nbr_mines = 0;
  Herb = sf::Sprite(HerbTexture, sf::IntRect(0, 0, 500, 230));
  Herb.setPosition(sf::Vector2f(0, 0));
}

void		Game::Start()
{
  sf::Texture	BunnyTexture;
  sf::Texture	MineTexture;
  sf::Texture	ExplTexture;
  sf::Texture	HerbTexture;
  sf::Clock	add;
  sf::Clock	anim;
  sf::Sprite	Herb;
  sf::Music     music;

  if (!music.openFromFile("resources/MineRabbit-InGame.flac"))
    {
      std::cerr << "Fail to load game music" << std::endl;
      return ;
    }
  music.play();
  Initalization(BunnyTexture, MineTexture, ExplTexture, Herb, HerbTexture);
  window.draw(Background);
  while (window.isOpen() && getState() == GAME)
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
	  if (event.type == sf::Event::Closed)
	    {
	      window.close();
	      _gameState = END;
	    }
        }
      Manage_game(BunnyTexture, add, anim, MineTexture, ExplTexture, Herb);
      if (nbr_bunnies != 0 && Bunnies.size() == 0)
	{
	  wave += 1;
	  _gameState = MENU;
	  Mines.erase(Mines.begin(), Mines.end());
	  Bunnies.erase(Bunnies.begin(), Bunnies.end());
	}
    }
  if (nbr_bunnies != 0 && Bunnies.size() == 0 && _gameState == MENU)
    _gameState = GAME;
}
