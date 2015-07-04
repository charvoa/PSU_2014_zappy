//
// SoundManager.hh for  in /home/nicolaschr/Work/PSU_2014_zappy/sources/graph/Sound
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jul  4 17:09:20 2015 Nicolas Charvoz
// Last update Sat Jul  4 17:09:21 2015 Nicolas Charvoz
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
