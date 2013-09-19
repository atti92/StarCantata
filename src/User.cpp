#include "User.h"
#include "Commands.h"

void User::keys(myEventReceiver& receiver)  // Movement
{
  switch (this->gui->getFocusElementId()) {
    case GUI_NONE:
      if(receiver.IsKeyDown(irr::KEY_SUBTRACT)){
          myCamera->moveCameraZ(1000 * dtime);
        }
      else if(receiver.IsKeyDown(irr::KEY_ADD)){
          myCamera->moveCameraZ(-1000 * dtime);
        }
      if(receiver.IsKeyDown(irr::KEY_DIVIDE)){
          myCamera->rotCameraZ(PI/10 * dtime);
        }
      else if(receiver.IsKeyDown(irr::KEY_MULTIPLY)){
          myCamera->rotCameraZ(-PI/10 * dtime);
        }
      if(receiver.IsKeyDown(irr::KEY_NUMPAD4)){
          myCamera->rotCameraY(PI/10 * dtime);
        }
      else if(receiver.IsKeyDown(irr::KEY_NUMPAD6)){
          myCamera->rotCameraY(-PI/10 * dtime);
        }
      if(receiver.IsKeyDown(irr::KEY_KEY_W)|| receiver.IsKeyDown(KEY_UP)){
          myShip->Thrust(DIR_FORWARD);
        }
      else if(receiver.IsKeyDown(irr::KEY_KEY_S)|| receiver.IsKeyDown(KEY_DOWN)){
          myShip->Thrust(DIR_BACKWARD);
        }
      if((receiver.IsKeyDown(irr::KEY_NUMPAD5)) && (myCamera->getCameraRotation() != 0 || myCamera->getCameraYRotation() != 0)){  //reset camera
          myCamera->setCameraRotation(-PI/10);
          myCamera->setCameraDistance(1000);
          myCamera->setCameraYRotation(0);
        }
      if(receiver.IsKeyDown(irr::KEY_KEY_A) || receiver.IsKeyDown(KEY_LEFT))
        myShip->Turn(DIR_ANTI_CLOCKWISE);
      else if(receiver.IsKeyDown(irr::KEY_KEY_D)|| receiver.IsKeyDown(KEY_RIGHT))
        myShip->Turn(DIR_CLOCKWISE);
      if(receiver.IsKeyDown(irr::KEY_RETURN))
        {
          this->gui->env->setFocus(this->gui->env->getRootGUIElement()->getElementFromId(GUI_CHAT_EDITBOX)); //give the chatbox focus
          this->gui->env->getFocus()->setText(L""); //clear editbox
          receiver.changeKey(irr::KEY_RETURN);
        }
      break;
    case GUI_CHAT_EDITBOX:
      if(receiver.IsKeyDown(irr::KEY_RETURN))
        {
          core::stringw chatmessage = this->gui->env->getFocus()->getText();
          //TODO

          this->gui->env->getFocus()->setText(L""); //clear editbox
          this->gui->env->setFocus(0); //clear focus
          receiver.changeKey(irr::KEY_RETURN);

          if(!checkCommand(chatmessage))
            {
            }
        }
    default:
      break;
    }
}

const bool User::checkCommand(const stringc text)
{
  irr::core::array<stringc> args;

  if(text[0] == '.')
    {
      Command act;
      text.split(args, " ");
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
      Commands::run(act, args, this);
      return true;
    }

  //TODO
  //send message etc...
  return false;
}

void User::refreshCamera()
{
  myDisplay->camera->setPosition(myShip->getPosition() + vector3df(myCamera->getCameraDistance()*sin(myCamera->getCameraRotation())*sin(myCamera->getCameraYRotation()), myCamera->getCameraDistance()*cos(myCamera->getCameraRotation()), myCamera->getCameraDistance()*sin(myCamera->getCameraRotation())*cos(myCamera->getCameraYRotation())));
  myDisplay->camera->setTarget(myShip->getPosition());

  core::stringw tmp = (stringw)"FPS: [" + (stringw)round32(1/dtime) + "] Speed: [" + (stringw)round32(myShip->getMovSpeedValue());
  tmp += (stringw)"] Position: [" + (stringw)round32(myShip->getPosition().X) + (stringw)" " + (stringw)round32(myShip->getPosition().Z) + (stringw)"]";
  myDisplay->device->setWindowCaption(tmp.c_str());
}

User::User()
{
  myDisplay = new Display();
  myCamera = new Camera();
  SpaceShip* ship = new SpaceShip(0, *myDisplay, vector3df(100, 0, 100));
  assignShip(ship);
  myDisplay->addObject(ship);
  time = myDisplay->device->getTimer()->getTime();
}

void User::timings()
{
  const u32 now = myDisplay->device->getTimer()->getTime();
  dtime = (f32)(now - time) / 1000.f; // Time in seconds
  time = now;
}


