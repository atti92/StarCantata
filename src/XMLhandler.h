#include "../pugixml/pugixml.hpp"
#include "User.h"
#include "Celestial.h"

class XMLhandler
{
private:
	pugi::xml_document doc;
	pugi::xml_parse_result result;
public:
	void loadMap(const char* path, User &user);
	void addChild(SOB* parent, pugi::xml_node parentnode, User &user);
};
