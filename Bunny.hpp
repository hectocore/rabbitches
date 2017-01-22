//
// Bunny.hpp for Bunny in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
// 
// Started on  Sat Jan 21 17:17:27 2017 Jean Francois Durand
// Last update Sun Jan 22 02:29:29 2017 Jean Francois Durand
//

#ifndef BUNNY_H_
# define BUNNY_H_

#include "IEntity.hpp"

class		Bunny: public IEntity
{
public:
  Bunny(unsigned int const & bunny_life, sf::Texture const &);
  ~Bunny();
  Bunny(Bunny const &);
  Bunny&	operator=(Bunny const &);
  int		getHP() const;
  void		setHP(unsigned int const &HP);
  sf::Sprite	getSprite() const;
  void		updateSprite();
  unsigned int	getX() const;
  unsigned int	getY() const;

private:
  unsigned int	_hp; // point de vie du lapin
};

#endif	/* !BUNNY_H_ */
