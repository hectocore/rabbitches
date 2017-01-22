//
// Game_Information.hpp for Game_Information in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
//
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
//
// Started on  Sat Jan 21 23:06:21 2017 Jean Francois Durand
// Last update Sun Jan 22 15:07:58 2017 Jean Francois Durand
//

#ifndef GAME_INFORMATION_HPP_
# define GAME_INFORMATION_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include "Bunny.hpp"
#include "Mine.hpp"

class		Game
{
public:
  Game();
  ~Game();
  Game(Game const & other);
  Game&			operator=(Game const & other);
  void			Start();
  void			Manage_entities(sf::Texture const &, sf::Texture const &,
					sf::Clock &, sf::Texture const &);
  void			Manage_game(sf::Texture BunnyTexture, sf::Clock & add,
				    sf::Clock & anim, sf::Texture MineTexture,
				    sf::Texture ExplTexture, sf::Sprite &Herb);
  void			Initalization(sf::Texture &Bunny, sf::Texture &Mine,
				      sf::Texture &Expl, sf::Sprite &Herb, sf::Texture &);
  void			Display();
  void			Menu();
  bool			check_end();
  void			check_collision();
  enum			GameState
    {
      MENU,
      GAME,
      END
    };
  GameState		getState() const;
  void			setState(GameState const &);
  void                  Draw_Rectangle_one();
  void                  affWave();

protected:
  unsigned int		wave;
  GameState		_gameState;
  sf::RenderWindow	window;
  std::list<Bunny>	Bunnies;
  std::list<Mine>	Mines;
  sf::Texture		BackTexture;
  sf::Sprite		Background;
  unsigned int		nbr_bunnies;
  unsigned int		nbr_mines;
  unsigned int		_frame;
  sf::SoundBuffer       buffer;
  sf::Sound		sound;
};

#endif // !GAME_INFORMATION_HPP_
