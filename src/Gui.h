#ifndef GUI_H
#define GUI_H

#include "User.h"

enum GUIElementId{
    GUI_NONE = 0,
    GUI_CHAT_EDITBOX = 1386
};

class Gui
{
private:
    irr::core::array<irr::gui::IGUIElement*> guiElement_;
public:
    Gui();
	void createChatWindow();
    irr::gui::IGUIElement* getFocusElement();
};

#endif
