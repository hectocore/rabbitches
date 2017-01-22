//
// main.cpp for main in /home/durand_2/rendu/Piscine_cpp/cpp_gkrellm
//
// Made by Jean Francois Durand
// Login   <durand_2@epitech.net>
//
// Started on  Sat Jan 21 17:59:32 2017 Jean Francois Durand
// Last update Sun Jan 22 11:15:48 2017 Jean Francois Durand
//

#include <stdlib.h>
#include <time.h>
#include "Game_Information.hpp"

int	main()
{
  Game	game;

  srand(time(NULL));
  while (game.getState() != Game::END)
    {
      if (game.getState() == Game::MENU)
      	game.Menu();
      if (game.getState() == Game::GAME)
	game.Start();
    }
}
