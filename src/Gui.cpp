#include "Gui.h"
GUI::GUI()
{
	user = 0;
	env = 0;
}
GUI::GUI(User& user)
{
	this->user = &user; 
	Display display = user.display();
	env = display.device->getGUIEnvironment();
}

void GUI::createChatWindow()
{
    env->addEditBox(L"Press Enter to type in text", rect<s32>(50, 500, 350, 520), false, 0, GUI_CHAT_EDITBOX);
}

GUIElementId GUI::getFocusElementId()
{
    if(this->env->getFocus() == 0)
        return GUI_NONE;
    return (GUIElementId) this->env->getFocus()->getID();
}

