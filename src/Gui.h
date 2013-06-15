#ifndef GUI_H
#define GUI_H

#include "User.h"

enum GUIElementId{
    GUI_NONE = 0,
    GUI_CHAT_EDITBOX = 1386
};

class User;
class GUI
{
private:
	User* user;
public:
	irr::gui::IGUIEnvironment* env;
	GUI();
	GUI(User& user);
	void createChatWindow();
    GUIElementId getFocusElementId();
};

#endif
