#include "Gui.h"
#include "Globals.h"
#include "Commands.h"

using namespace irr;
using namespace core;
using namespace gui;

Gui::Gui()
{
  guiElement_ = 0;
}

void Gui::createChatWindow()
{
  sIGfx->getGuiEnvironment()->addEditBox(L"Press Enter to type in text",
                                         rect<s32>(50, 500, 350, 520), false, 0, GUI_CHAT_EDITBOX);
}

IGUIElement* Gui::getFocusElement ()
{
  return sIGfx->getGuiEnvironment ()->getFocus ();
}

GUIElementId Gui::getFocusElementId()
{
  if(sIGfx->getGuiEnvironment()->getFocus() == 0)
    return GUI_NONE;
  return (GUIElementId) sIGfx->getGuiEnvironment()->getFocus()->getID();
}

bool Gui::checkCommand(stringw text)
{
  array<stringc> args;
  stringc textc = static_cast<stringc> text;
  if(textc[0] == '.')
  {
    CommandName act;
    textc.split(args, " ");
    act = COMMAND_NONE;
    if(args[0].equals_ignore_case(".help"))
    {
      act = COMMAND_HELP;
    }
    else if(args[0].equals_ignore_case(".commands"))
    {
      act = COMMAND_HELP;
    }
    else if(args[0].equals_ignore_case(".spawn"))
    {
      act = COMMAND_SPAWN;
    }
    //TODO:
    //more commands
    args.erase(0);
    Command::run(act, args);
    return true;
  }

  //TODO
  //send message etc...
  return false;
}

