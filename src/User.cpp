#include "User.h"
#include "Commands.h"
#include "Globals.h"

using namespace irr;
using namespace core;
using namespace scene;

//NEED COMPLETE REWRITE, move keys to MyEventReceiver.cpp

User::User()
{
  SpaceShip* ship = new SpaceShip(0, vector3df(100, 0, 100));
  assignShip (ship);
  sIGfx->getObjectMgr ()->addObject (ship);
}

void User::assignShip (SpaceShip *spaceShip)
{
  spaceShip_ = spaceShip;
  sIGfx->getCamera ()->attach (spaceShip);
}

SpaceShip* User::getSpaceShip ()
{
  return spaceShip_;
}

bool User::isKeyPressed (EKEY_CODE key)
{
  return sIGfx->getEventReceiver ()->isKeyDown (key);
}

void User::manageControls ()
{
  u32 frameTime = sIGfx->getFrameTime ();
  switch (sIGfx->getGui ()->getFocusElementId())
  {
    case GUI_NONE:
      if(isKeyPressed(irr::KEY_SUBTRACT))
      {
        sIGfx->getCamera ()->move (vector3df(0, 0, -1), frameTime);
      }
      else if(isKeyPressed (irr::KEY_ADD))
      {
        sIGfx->getCamera ()->move (vector3df(0, 0, 1), frameTime);
      }
      if(isKeyPressed (irr::KEY_DIVIDE))
      {
        sIGfx->getCamera ()->rotate (vector3df(0, 0, 1), frameTime);
      }
      else if(isKeyPressed (irr::KEY_MULTIPLY))
      {
        sIGfx->getCamera ()->rotate (vector3df(0, 0, -1), frameTime);
      }
      if(isKeyPressed (irr::KEY_NUMPAD4))
      {
        sIGfx->getCamera ()->rotate (vector3df(0, 1, 0), frameTime);
      }
      else if(isKeyPressed (irr::KEY_NUMPAD6))
      {
        sIGfx->getCamera ()->rotate (vector3df(0, -1, 0), frameTime);
      }
      if(isKeyPressed(irr::KEY_KEY_W)|| isKeyPressed(KEY_UP))
      {
        spaceShip_->thrust(DIR_FORWARD);
      }
      else if(isKeyPressed(irr::KEY_KEY_S)|| isKeyPressed(KEY_DOWN))
      {
        spaceShip_->thrust(DIR_BACKWARD);
      }
      if(isKeyPressed(irr::KEY_NUMPAD5)){  //reset camera
        sIGfx->getCamera ()->reset(false);
      }
      if(isKeyPressed(irr::KEY_KEY_A) || isKeyPressed(KEY_LEFT))
        spaceShip_->turn(DIR_ANTI_CLOCKWISE);
      else if(isKeyPressed(irr::KEY_KEY_D)|| isKeyPressed(KEY_RIGHT))
        spaceShip_->turn(DIR_CLOCKWISE);
      if(isKeyPressed(irr::KEY_RETURN))
      {
        sIGfx->getGuiEnvironment ()->setFocus(sIGfx->getGuiEnvironment ()->getRootGUIElement()->getElementFromId(GUI_CHAT_EDITBOX)); //give the chatbox focus
        sIGfx->getGuiEnvironment ()->getFocus()->setText(L""); //clear editbox
        sIGfx->getEventReceiver ()->changeKey(irr::KEY_RETURN);
      }
      break;
    case GUI_CHAT_EDITBOX:
      if(isKeyPressed(irr::KEY_RETURN))
      {
        stringw chatmessage = sIGfx->getGuiEnvironment ()->getFocus()->getText();
        //TODO

        sIGfx->getGuiEnvironment ()->getFocus()->setText(L""); //clear editbox
        sIGfx->getGuiEnvironment ()->setFocus(0); //clear focus
        sIGfx->getEventReceiver ()->changeKey(irr::KEY_RETURN);
        sIGfx->getGui ()->checkChatCommand(chatmessage);
      }
      break;
  }
}


