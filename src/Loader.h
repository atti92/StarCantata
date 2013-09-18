#ifndef LOADER_H
#define LOADER_H

#include "irrlicht.h"

#define PATH_MAP "./data/maps/"
#define PATH_SPACESHIP "./data/spaceships/"

class Loader{
private:
    static irr::u32 nLoaded;
public:
    Loader();
    ~Loader();
    virtual void* load(irr::io::path path);
};

#endif // LOADER_H
