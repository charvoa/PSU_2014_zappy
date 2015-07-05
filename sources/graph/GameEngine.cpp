//
// GameEngine.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun 22 17:36:22 2015 Nicolas Girardot
// Last update Sun Jul  5 16:37:51 2015 Nicolas Girardot
//

#include "GameEngine.hh"
#include <SDL/SDL_image.h>

Sound&	GameEngine::_sound = Sound::getInstance();

GameEngine::GameEngine() {
  _gMap = NULL;
  _sound.initialize();
  _sound.registerSound("./Sound/main_theme.mp3", "main");
}

GameEngine::~GameEngine() {
  SDL_DestroyWindow(_window);
  SDL_Quit();
  TTF_Quit();
  IMG_Quit();
  _socket->closeSocket();
}

SDL_Renderer &GameEngine::getRenderer()
{
  return (*_renderer);
}

void		GameEngine::getSpeed(int s)
{
  _speed = s;
}

SDL_Window &GameEngine::getWindow()
{
  return (*_window);
}

SDL_Surface &GameEngine::getSurface()
{
  return (*_surface);
}

void	GameEngine::broadcast(std::tuple<int, std::string> &tuple)
{
  for(std::list<IACharacter *>::iterator it = _players.begin(); it != _players.end() ; it++)
    {
      if (std::get<0>(tuple) == (*it)->getId())
	{
	  (*it)->broadcast();
	}
    }
}

void	GameEngine::updateLvl(int id, int lvl)
{
  for(std::list<IACharacter *>::iterator it = _players.begin(); it != _players.end() ; it++)
    {
      if (id == (*it)->getId())
	{
	  (*it)->setLVL(lvl);
	}
    }
}

void	GameEngine::updateTeamInfo(std::string &name, int a, int b)
{
  _hud->updateTeamInfo(name, a, b);
}

void	GameEngine::addEgg(std::vector<int> &att)
{
  Egg *egg = new Egg(att);
  std::string result;
  std::stringstream sstm;
  sstm << "Player" << att.at(1) << " laid an Egg";
  result = sstm.str();
  _hud->update_info(result);
  _eggs.push_back(egg);
}

void	GameEngine::endGame(std::string &team)
{
  std::stringstream sstm;

  sstm << "Team " << team << " has won the game : GeeeeGeeee";
  std::string result;
  result = sstm.str();
  _hud->update_info(result);
}

void	GameEngine::deleteEgg(int id, int i)
{
  std::list<Egg *>::iterator it = _eggs.begin();
  while (it != _eggs.end())
    {
      if (id == (*it)->getID())
	{
	  _eggs.erase(it++);
	  std::string result;
	  std::stringstream sstm;
	  if (i == 1)
	    sstm << "Egg" << id << " just hatched ! It's a Girl";
	  else
	    sstm << "OH NO ! EGG" << id << " IS BEING USED FOR AN OMELETTE";
	  result = sstm.str();
	  _hud->update_info(result);
	}
      else
	++it;
    }
}

void	GameEngine::addIncant(int x, int y)
{
  _cases.at(y).at(x)->setIncant(true);
}

void	GameEngine::endIncant(std::vector<int> &v)
{
  _cases.at(v.at(1)).at(v.at(0))->setIncant(false);
}

void	GameEngine::deletePlayer(int id)
{
  std::list<IACharacter *>::iterator it = _players.begin();
  while (it != _players.end())
    {
      if (id == (*it)->getId())
	{
	  _players.erase(it++);
	  std::string result;
	  std::stringstream sstm;
	  sstm << "Player" << id << " has died of hunger.";
	  result = sstm.str();
	  _hud->update_info(result);
	}
      else
	++it;
    }
}

void	GameEngine::addPlayer(std::vector<int> &args, std::string &teamName)
{
  IACharacter *player = new IACharacter(args, teamName);
  std::string result;
  std::stringstream sstm;
  sstm << "Player" << player->getId() << " Joined the arena";
  result = sstm.str();
  _hud->update_info(result);
  _players.push_back(player);
}

void	GameEngine::updateInventory(std::vector<int> &inv)
{
  for(std::list<IACharacter *>::iterator it = _players.begin(); it != _players.end() ; it++)
    {
      if (inv.at(0) == (*it)->getId())
	{
	  (*it)->updateInventory(inv);
	  if (inv.at(0) == _idFocus)
	    {
	      _hud->updateInventory((*it));
	    }
	}
    }
}

void	GameEngine::updatePlayer(std::vector<int> &args)
{
  int	id = args.at(0);
  for(std::list<IACharacter *>::iterator it = _players.begin(); it != _players.end() ; it++)
    {
      if (id == (*it)->getId())
	{
	  (*it)->updateAtt(args);
	  if (_idFocus == id)
	    {
	      _focus = (*it)->getPosition();
	    }
	}
    }
}

bool	GameEngine::initialize()
{
  _window = SDL_CreateWindow("Zappy - La Pintade 2015", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN );
  if (!_window)
    std::cout << "Error on Windows Create" << std::endl;
  else
    _renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
  _mousePos = Position(10, 10);
  _hud = new HUD(_renderer);
  _sound.playMusic("main", 1);
  _socket->writeOnSocket("sgt\r\n");;
  return true;
}

void	GameEngine::updateTime(int i)
{
  std::stringstream sstm;
  sstm.str("");
  sstm.clear();
  if (i == 1)
    {
      if (_speed == 1)
	sstm << "sst " << 10 << "\r\n";
      else
	sstm << "sst " << _speed + 10 << "\r\n";
      _socket->writeOnSocket(sstm.str());
    }
  else
    {
      if (_speed <= 10)
	sstm << "sst " << 1 << "\r\n";
      else
	sstm << "sst " << _speed - 10 << "\r\n";
      _socket->writeOnSocket(sstm.str());
    }
}

bool	GameEngine::update()
{
  this->_socket->selectSocket();
  _hud->update();
  getMousePos();
  while (SDL_PollEvent(&_event))
    {
      if (_event.type == SDL_KEYDOWN)
	{
	  switch(_event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      return false;
	      break;
	    case SDLK_UP:
	      _idFocus = -1;
	      if (_focus._y <= 0)
		_focus._y = _gMap->getHeight() - 1;
	      else
		_focus._y -= 1;
	      break;
	    case SDLK_KP_PLUS:
	      updateTime(1);
	      break;
	    case SDLK_KP_MINUS:
	      updateTime(0);
	      break;
	    case SDLK_DOWN:
	      _idFocus = -1;
	      if (_focus._y >= _gMap->getHeight() - 1)
		_focus._y = 0;
	      else
		_focus._y += 1;
	      break;
	    case SDLK_RIGHT:
	      _idFocus = -1;
	      if (_focus._x >= _gMap->getWidth() - 1)
		_focus._x = 0;
	      else
		_focus._x += 1;
	      break;
	    case SDLK_LEFT:
	      _idFocus = -1;
	      if (_focus._x <= 0)
		_focus._x = _gMap->getWidth() - 1;
	      else
		_focus._x -= 1;
	      break;
	    default:
	      break;
	    }
	}
      if (_event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (_event.button.button == SDL_BUTTON_LEFT)
	    setLocked();
	}
      if (_event.type == SDL_QUIT)
	return false;
    }
  return true;
}

void	GameEngine::createMap(std::vector<std::string> &parse)
{
  int	x;
  int	y;
  std::string strx;
  std::string stry;
  std::vector<Case *> tmp;

  strx = parse.at(0);
  stry = parse.at(1);
  x = stoi(strx);
  y = stoi(stry);
  _focus = (*new Position(x / 2, y / 2));
  for (int ybis = 0; ybis <= y - 1; ybis++)
    {
      for (int xbis = 0; xbis <= x - 1; xbis++)
	{
	  tmp.push_back(new Case(0, 0, 0, 0, 0, 0, 0));
	}
      _cases.push_back(tmp);
      tmp.clear();
    }
  if (this)
    _gMap = new GraphMap(x, y, _renderer);
}

void	GameEngine::setLocked()
{
  int	a;
  int	b;
  SDL_GetMouseState(&a, &b);
  Position pos(a, b);
  std::stringstream sstm;
  if (isEventOnMap(a, b) == true)
    {
      std::pair<int, int> posfocus(_focus._x, _focus._y);
      std::pair<int, int> pai = determinePosClicked(posfocus, a, b);
      for (std::list<IACharacter *>::iterator it = _players.begin(); it != _players.end() ; it++)
	{
	  if ((*it)->getPosition()._x == pai.first && (*it)->getPosition()._y == pai.second)
	    {
	      _idFocus = (*it)->getId();
	      _focus = (*it)->getPosition();
	      _hud->updateInventory(*it);
	      sstm << "tin " << (*it)->getTeam() << "\r\n";
	      _socket->writeOnSocket(sstm.str());
	    }
	}
      _hud->updateLocked(pai.first, pai.second, _cases.at(pai.second).at(pai.first));
      pai = determinePosClickedOnGUI(a, b);
      if (_idFocus != -1)
	_gMap->setLocked(pai.first, pai.second);
    }
}

void	GameEngine::getMousePos()
{
  int	a;
  int	b;
  SDL_GetMouseState(&a, &b);
  if ((a - 150) / 100 == _mousePos._x && (b - 150) / 100 == _mousePos._y);
  else
    {
        if (isEventOnMap(a, b) == true)
	  {
	    std::pair<int, int> posfocus(_focus._x, _focus._y);
	    std::pair<int, int> pai = determinePosClicked(posfocus, a, b);
	    if (pai.first >= _gMap->getWidth() || pai.second >= _gMap->getHeight());
	    else
	      {
		Position current(pai.first, pai.second);
		_mousePos = current;
		_hud->updateCase(_mousePos);
	      }
	  }
    }
}

void	GameEngine::setCase(std::vector<std::string> &content)
{
  _cases.at(stoi(content.at(1))).at(stoi(content.at(0)))->setAll(stoi(content.at(3)),
								 stoi(content.at(4)),
								 stoi(content.at(5)),
								 stoi(content.at(6)),
								 stoi(content.at(7)),
								 stoi(content.at(8)),
								 stoi(content.at(2)));
}

void	GameEngine::draw()
{
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
  _hud->draw(_renderer);
  if (_gMap != NULL)
    _gMap->draw(_renderer, _focus, _cases, _players, _eggs);
  SDL_RenderPresent(_renderer);
}

void	GameEngine::run(const char *ip, int port)
{
  this->_socket = new Socket(ip, port, this);
  _socket->writeOnSocket("GRAPHIC\n");
  initialize();
  while (this->update())
    draw();
}

bool		GameEngine::isEventOnMap(int xClick, int yClick)
{
  if (xClick < 150 || yClick < 150 || xClick > 850 || yClick > 850)
    return false;
  return true;
}

std::pair<int, int> GameEngine::determinePosClicked(std::pair<int,int> & center, int xClick, int yClick)
{
  int x;
  int y;
  int posX;
  int posY;

  posX = (xClick - 150) / (700 / 7);
  posY = (yClick - 150) / (700 / 7);
  x = (center.first - 3 + posX) % _gMap->getWidth();
  y = (center.second - 3 + posY) % _gMap->getHeight();
  if (x < 0)
    x = _gMap->getWidth() + x;
  if (y < 0)
    y = _gMap->getHeight() + y;

  return (std::pair<int, int>(x, y));
}

std::pair<int , int> GameEngine::determinePosClickedOnGUI(int xClick, int yClick)
{
  int posX;
  int posY;
  posX = (xClick - 150) / (700 / 7);
  posY = (yClick - 150) / (700 / 7);
  return (std::pair<int, int>(posX, posY));
}
