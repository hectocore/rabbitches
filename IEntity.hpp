//
// IEntity.hpp for IEntity in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
// 
// Started on  Sat Jan 21 16:19:03 2017 Jean Francois Durand
// Last update Sun Jan 22 02:51:49 2017 Jean Francois Durand
// Last update Sun Jan 22 00:28:40 2017 Jean Francois Durand
//

#ifndef IENTITY_H_
# define IENTITY_H_

#include <SFML/Graphics.hpp>

class		IEntity
{
public:
  virtual unsigned int 	getX() const = 0;
  virtual unsigned int 	getY() const = 0;
  virtual sf::Sprite	getSprite() const = 0;
  virtual void		updateSprite() = 0;

protected:
  unsigned int	_x;
  unsigned int	_y;
  unsigned int	_frame;
  sf::IntRect	_rect;
  sf::Sprite	_sprite;
};

#endif	/* !IENTITY_H_ */
