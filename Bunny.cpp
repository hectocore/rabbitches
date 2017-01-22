//
// Bunny.cpp for Bunny.cpp in /home/lewita_l/Rendu/piscine_cpp/Rush/cpp_gkrellm
// 
// Made by Lisa Lewitanski
// Login   <lewita_l@epitech.net>
// 
// Started on  Sat Jan 21 17:24:42 2017 Lisa Lewitanski
// Last update Sun Jan 22 10:24:46 2017 Jean Francois Durand
// Last update Sun Jan 22 01:17:11 2017 Jean Francois Durand
//

#include <iostream>
#include "Bunny.hpp"

Bunny::Bunny(unsigned int const & bunny_life, sf::Texture const & BunnyTexture)
{
  this->_hp = bunny_life;
  this->_x = (rand() % 25 * 18) + 32;
  this->_y = 0;
  this->_frame = 0;
  this->_rect = sf::IntRect(0, 0, 31, 41);
  this->_sprite = sf::Sprite(BunnyTexture, this->_rect);
  this->_sprite.setPosition(sf::Vector2f(_x, _y));
}

Bunny::~Bunny()
{
}

Bunny::Bunny(Bunny const & other)
{
  this->_hp = other._hp;
  this->_x = other._x;
  this->_y = other._y;
  this->_frame = other._frame;
  this->_rect = other._rect;
  this->_sprite = other._sprite;
  this->_sprite.setPosition(sf::Vector2f(_x, _y));
}

Bunny&	Bunny::operator=(Bunny const &other)
{
  if (this != &other)
    {
      this->_hp = other._hp;
      this->_x = other._x;
      this->_y = other._y;
      this->_frame = other._frame;
      this->_rect = other._rect;
      this->_sprite = other._sprite;
      this->_sprite.setPosition(sf::Vector2f(_x, _y));
    }
  return *this;
}

int		Bunny::getHP() const
{
  return this->_hp;
}

void		Bunny::setHP(unsigned int const & HP)
{
  this->_hp = HP;
}

void		Bunny::updateSprite()
{
  if (_frame == 3)
    _frame = 0;
  _rect = sf::IntRect((31 * _frame), 0, 31, 41);
  _sprite.setTextureRect(_rect);
  _frame = _frame + 1;
  _sprite.setPosition(sf::Vector2f(_x, _y + 10));
  _y = _y + 10;
}

sf::Sprite	Bunny::getSprite() const
{
  return _sprite;
}

unsigned int		Bunny::getX() const
{
  return this->_x;
}

unsigned int		Bunny::getY() const
{
  return this->_y;
}
