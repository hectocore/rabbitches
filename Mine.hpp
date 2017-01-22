//
// Mine.hpp for mine in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
// 
// Started on  Sun Jan 22 02:20:38 2017 Jean Francois Durand
// Last update Sun Jan 22 13:01:37 2017 Jean Francois Durand
//

#ifndef MINE_H_
# define MINE_H_

#include "IEntity.hpp"

class		Mine: public IEntity
{
public:
  Mine(unsigned int const & x, unsigned int const & y, sf::Texture const &,
       sf::Texture const & Exposionn);
  ~Mine();
  Mine(Mine const &);
  Mine&		operator=(Mine const &);
  unsigned int	getDamages() const;
  void		setDamages(unsigned int const &);
  sf::Sprite	getSprite() const;
  void		updateSprite();
  unsigned int	getX() const;
  unsigned int	getY() const;
  void		setPos(unsigned int, unsigned int);
  sf::Sprite	getRectSprite();
  void		updateRectSprite();
  unsigned int	getFrame() const;

protected:
  unsigned int		_damages;
  sf::IntRect		_rect_exp;
  sf::Sprite		_sprite_exp;
};

#endif	/* !MINE */
