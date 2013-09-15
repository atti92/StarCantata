#include "XMLhandler.h"
#include <iostream>

void XMLhandler::loadMap(const char* path, User &user)
{
	result = doc.load_file(path);
    irr::ILogger* logger = user.display().Device ()->getLogger ();
    if(!result)
    {
        logger->log("Failed to load Map file!", ELL_ERROR);
        return;
    }
    logger->log("Loaded Map file!", ELL_INFORMATION);
	pugi::xml_node solsys = doc.child("solsys");
	addChild(0, solsys, user);

}



void XMLhandler::addChild(SOB* parent, pugi::xml_node parentnode, User &user)
{
	Display* display = &user.display();
	for (pugi::xml_node node = parentnode.first_child(); node; node = node.next_sibling())
	{
		SOB * newObj = 0;
		if(strcmp(node.name(),"sun") == 0)
		{
			newObj = new Sun(node.attribute("type").as_int(), *display, node.attribute("scale").as_float(), vector3df(node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("z").as_float()), vector3df(node.attribute("rotx").as_float(), node.attribute("roty").as_float(), node.attribute("rotz").as_float()), SColorf(node.attribute("colR").as_float(), node.attribute("colG").as_float(), node.attribute("colB").as_float()), node.attribute("lightrange").as_float());

		}
		else if(strcmp(node.name(),"planet") == 0)
		{
			newObj = new Planet(node.attribute("type").as_int(), *display, node.attribute("scale").as_float(), vector3df(node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("z").as_float()), vector3df(node.attribute("rotx").as_float(), node.attribute("roty").as_float(), node.attribute("rotz").as_float()));
		}
		else if(strcmp(node.name(),"moon") == 0)
		{
			newObj = new Moon(node.attribute("type").as_int(), *display, node.attribute("scale").as_float(), vector3df(node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("z").as_float()), vector3df(node.attribute("rotx").as_float(), node.attribute("roty").as_float(), node.attribute("rotz").as_float()));
		}
		else if(strcmp(node.name(),"asteroid") == 0)
		{
			newObj = new Moon(node.attribute("type").as_int(), *display, node.attribute("scale").as_float(), vector3df(node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("z").as_float()), vector3df(node.attribute("rotx").as_float(), node.attribute("roty").as_float(), node.attribute("rotz").as_float()));
		}
		if(newObj){
			if(node.attribute("orbit").as_bool() == true)
				newObj->setOrbit(parent, node.attribute("maja").as_float(), node.attribute("foci").as_float(), node.attribute("phase").as_float());
			newObj->setRotationSpeed(vector3df(node.attribute("rotspx").as_float(),node.attribute("rotspy").as_float(),node.attribute("rotspz").as_float()));
			newObj->setMass(node.attribute("mass").as_float());
			display->addObject(newObj);
		}
		addChild(newObj, node, user);
	}
}
