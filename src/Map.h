#ifndef MAP_H
#define MAP_H

#include "irrlicht.h"
#include "SpaceObject.h"

class Map{
private:
  irr::u16 id_;
  irr::io::path mapXmlPath_;
  irr::core::array<SpaceObject*> objects_;
public:
  Map(irr::u16 id = 0);
  Map(const Map& other);
  ~Map();
  void saveMapToXml(const irr::io::path& path);
  void loadMapFromXml(const irr::io::path& path);
  void addToList();
  void addObject(const SpaceObject* object);
  void removeObject(const SpaceObject* object);
  void removeObject(const GUID& guid);
  irr::u16 getId() const;
  SpaceObject* getObject(const GUID& guid);
  void updateAll();
  const irr::core::array<SpaceObject*>& getObjectList() const;
};

#endif // MAP_H
