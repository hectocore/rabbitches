//
// IButton.cpp for IButton in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
// 
// Started on  Sun Jan 22 10:43:02 2017 Jean Francois Durand
// Last update Sun Jan 22 10:44:24 2017 Jean Francois Durand
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "IButton.hpp"

Button::Button(sf::Vector2i const& pos,
	       sf::Vector2i const& size, Game::GameState i)
{
  _i = i;
  _pos = pos;
  _size = size;
  _selected = false;
  _hbox = sf::Rect<int>(pos, size);
}

bool Button::isSelected()
{
  return _selected;
}

void Button::select()
{
  _selected = true;
}

void Button::unselect()
{
  _selected = false;
}

void Button::setPos(sf::Vector2i const& pos, sf::Vector2i const& size)
{
  _pos = pos;
  _size = size;
  _hbox = sf::Rect<int>(pos, size);
}

bool Button::collides(sf::Vector2i const& pos)
{
  return (_hbox.contains(pos));
}

Game::GameState Button::getState() const
{
  return _i;
}

Button::~Button()
{

}
