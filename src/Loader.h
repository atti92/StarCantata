#ifndef LOADER_H
#define LOADER_H

#include "irrlicht.h"
#include "pugixml.hpp"

#define PATH_MAP "./data/maps/"
#define PATH_SPACESHIP "./data/spaceships/"

class Loader{
protected:
  static irr::u32 nLoaded;
  pugi::xml_document doc_;
  pugi::xml_parse_result result_;
public:
  Loader();
  ~Loader();
  virtual void load(irr::io::path path);
};

#endif // LOADER_H
