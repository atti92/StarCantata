#include "../pugixml/pugixml.hpp"
#include "User.h"
#include "Celestial.h"

class XmlHandler
{
private:
    pugi::xml_document doc_;
    pugi::xml_parse_result result_;
public:
	void loadMap(const char* path, User &user);
    void addChild(SpaceObject* parent, pugi::xml_node parentnode, User &user);
};
