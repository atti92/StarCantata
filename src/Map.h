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
    void saveMapToXml(irr::io::path path);
    void loadMapFromXml(irr::io::path path);
    void addToList();
    void addObject(SpaceObject* object);
    void removeObject(SpaceObject* object);
    void removeObject(GUID guid);
    irr::u16 getId();
};

#endif // MAP_H
