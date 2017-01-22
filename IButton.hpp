#pragma once

#include <SFML/Graphics.hpp>
#include "Game_Information.hpp"

class Button
{
protected:
  sf::Color _color;
  sf::Vector2i _pos;
  sf::Vector2i _size;
  bool _selected;
  Game::GameState           _i;

public:
  explicit Button(sf::Vector2i const& pos,
	 sf::Vector2i const& size, Game::GameState);
  virtual ~Button();
  sf::Rect<int> _hbox;

public:
  void select();
  Game::GameState   getState()const;
  void unselect();
  void setPos(sf::Vector2i const&, sf::Vector2i const&);
  sf::Vector2i getPos() const;
  bool isSelected();
  bool collides(sf::Vector2i const&);
};
