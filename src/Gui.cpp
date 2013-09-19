#include "Gui.h"
#include "Globals.h"

Gui::Gui()
{
  guiElement_ = 0;
}

void Gui::createChatWindow()
{
  sIGfx->getGuiEnvironment()->addEditBox(L"Press Enter to type in text",
                                         rect<s32>(50, 500, 350, 520), false, 0, GUI_CHAT_EDITBOX);
}

GUIElementId Gui::getFocusElementId()
{
  if(sIGfx->getGuiEnvironment()->getFocus() == 0)
    return GUI_NONE;
  return (GUIElementId) sIGfx->getGuiEnvironment()->getFocus()->getID();
}

