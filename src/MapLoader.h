#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Loader.h"
#include "SpaceObject.h"
#include "Map.h"

class MapLoader : public Loader{
private:
  Map* map_;
public:
  MapLoader();
  ~MapLoader();
  virtual void load(irr::io::path path);
  void addChild(SpaceObject* parent, pugi::xml_node parentnode);
  Map* getMap() const;
};

#endif
