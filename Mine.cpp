//
// Mine.cpp for Mine in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
// 
// Started on  Sun Jan 22 02:34:43 2017 Jean Francois Durand
// Last update Sun Jan 22 08:12:12 2017 Jean Francois Durand
//

#include "Mine.hpp"

Mine::Mine(unsigned int const & x, unsigned int const & y, sf::Texture const & MineTexture,
	   sf::Texture const & Explosion)
{
  this->_damages = 1;
  this->_x = x - 10;
  this->_y = y - 10;
  this->_frame = 0;
  this->_rect = sf::IntRect(0, 0, 21, 21);
  this->_sprite = sf::Sprite(MineTexture, this->_rect);
  this->_sprite.setPosition(sf::Vector2f(_x, _y));
  this->_rect_exp = sf::IntRect(0, 0, 80, 80);
  this->_sprite_exp = sf::Sprite(Explosion, this->_rect_exp);
  this->_sprite_exp.setPosition(sf::Vector2f(_x, _y));
}

Mine::~Mine() {}

Mine::Mine(Mine const & other)
{
  this->_damages = other._damages;
  this->_x = other._x;
  this->_y = other._y;
  this->_frame = 0;
  this->_rect = sf::IntRect(0, 0, 21, 21);
  this->_sprite = other._sprite;
  this->_sprite.setPosition(sf::Vector2f(_x, _y));
  this->_rect_exp = sf::IntRect(0, 0, 80, 80);
  this->_sprite_exp = other._sprite_exp;
  this->_sprite_exp.setPosition(sf::Vector2f(_x, _y));
}

Mine&		Mine::operator=(Mine const & other)
{
  if (this != &other)
    {
      this->_damages = other._damages;
      this->_x = other._x;
      this->_y = other._y;
      this->_frame = 0;
      this->_rect = sf::IntRect(0, 0, 21, 21);
      this->_sprite = other._sprite;
      this->_sprite.setPosition(sf::Vector2f(_x, _y));
      this->_rect_exp = sf::IntRect(0, 0, 80, 80);
      this->_sprite_exp = other._sprite_exp;
      this->_sprite_exp.setPosition(sf::Vector2f(_x, _y));
    }
  return *this;
}

unsigned int	Mine::getDamages() const
{
  return _damages;
}

void		Mine::setDamages(unsigned int const & damages)
{
  _damages = damages;
}

sf::Sprite	Mine::getSprite() const
{
  return _sprite;
}

void		Mine::updateSprite()
{
  if (_frame == 2)
    _frame = 0;
  _rect = sf::IntRect((21 * _frame), 0, 21, 21);
  _sprite.setTextureRect(_rect);
  _frame = _frame + 1;
}

unsigned int	Mine::getX() const
{
  return this->_x;
}

unsigned int	Mine::getY() const
{
  return this->_y;
}

void		Mine::updateRectSprite()
{
  _rect_exp = sf::IntRect((80 * _frame), 0, 80, 80);
  _sprite_exp.setTextureRect(_rect_exp);
  _frame = _frame + 1;
}

sf::Sprite	Mine::getRectSprite()
{
  updateRectSprite();
  return _sprite_exp;
}

unsigned int	Mine::getFrame() const
{
  return _frame;
}

void		Mine::setPos(unsigned int x, unsigned int y)
{
  _sprite_exp.setPosition(sf::Vector2f(x, y));
}
