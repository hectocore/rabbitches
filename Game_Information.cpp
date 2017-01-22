//
// Game_Information.cpp for Game_Information in /home/lewita_l/Rendu/piscine_cpp/Rush/cpp_gkrellm
// 
// Made by Lisa Lewitanski
// Login   <lewita_l@epitech.net>
// 
// Started on  Sat Jan 21 18:38:37 2017 Lisa Lewitanski
// Last update Sun Jan 22 15:08:11 2017 Jean Francois Durand
// Last update Sat Jan 21 23:10:57 2017 Jean Francois Durand
//

#include <SFML/Graphics.hpp>
#include "Game_Information.hpp"

Game::Game()
{
  this->wave = 1;
  this->_gameState = MENU;
  this->window.create(sf::VideoMode(500, 800), "RABBITCHIES");
  this->window.setFramerateLimit(30);
  if (!BackTexture.loadFromFile("resources/background.png"))
    throw std::runtime_error("Error while getting images");
  Background.setTexture(BackTexture);
  this->_frame = 0;
  if (!buffer.loadFromFile("resources/explosion.flac"))
    throw std::runtime_error("Error while getting sound");
  sound.setBuffer(buffer);
}

Game::~Game()
{
}

Game::Game(Game const & other)
{
  this->wave = other.wave;
  this->_gameState = other.getState();
}

Game&	Game::operator=(Game const & other)
{
  if (this != &other)
    {
      this->wave = other.wave;
      this->_gameState = other.getState();
    }
  return *this;
}

Game::GameState		Game::getState() const
{
  return _gameState;
}

void			Game::setState(Game::GameState const & state)
{
  _gameState = state;
}

void                    Game::Draw_Rectangle_one()
{
  sf::RectangleShape	rectangle(sf::Vector2f(500, 50));
  std::string		texte;
  std::string		texte2;
  sf::Font		font;

  rectangle.setPosition(sf::Vector2f(0, 0));
  rectangle.setFillColor(sf::Color(0, 00, 0));
  if (!font.loadFromFile("resources/8bitfont.ttf"))
    throw std::runtime_error("Error while getting font");
  texte = "Wave  ";
  texte2 = texte.append(std::to_string(this->wave));
  sf::Text	text(texte, font);
  text.setCharacterSize(40);
  text.setStyle(sf::Text::Italic);
  text.setFillColor(sf::Color::White);
  text.setPosition(140, 0);
  window.draw(rectangle);
  window.draw(text);
}
