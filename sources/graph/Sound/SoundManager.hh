//
// SoundManager.hh for SoundManager in /home/antgar/rendu/cpp_bomberman/Sound
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Wed May 13 03:58:34 2015 Antoine Garcia
// Last update Wed May 27 17:09:03 2015 Nicolas Charvoz
//

#ifndef SOUNDMANAGER_HH_
# define SOUNDMANAGER_HH_

#include <map>
#include <string>
#include "./inc/fmod.h"

class	Sound
{
  std::map<std::string, std::string> _sounds;
  std::map<std::string, FMOD_CHANNEL *> _plays;
  Sound(){};
  ~Sound(){};
  Sound(Sound const&);
  Sound&	operator=(Sound&);
  FMOD_SYSTEM	*_system;

public:
  static Sound&	getInstance();
  void		initialize();
  void		registerSound(const std::string &filename, const std::string &title);
  void		playMusic(const std::string &title, int repeat = 0);
  void		playSound(const std::string &sound);
  void		Pause(const std::string &title);
};

#endif
