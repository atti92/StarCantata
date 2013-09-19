/*


using namespace irr;
using namespace core;
using namespace gui;
using namespace scene;

//DO NOT DELETE till we have fixed all cpp files.

Display::Display()
{
  device = createDevice( video::EDT_OPENGL, dimension2d<u32>(800, 600), 16, false, false, true, &receiver);
  //To-do: error reporting!
  driver = device->getVideoDriver();
  smgr = device->getSceneManager();
  guienv = device->getGUIEnvironment();
  camera = smgr->addCameraSceneNode();
  camera->setFOV(irr::core::PI/5.0f);
  device->setWindowCaption(L"Star Cantata Production");
  smgr->setAmbientLight(video::SColorf(0.05f, 0.05f, 0.05f, 1.0f));

}
void Display::refreshObjects(const f32 frameTime, const u32 time)
{
  for(u32 i = 0; i < objects.size(); i++)
    {
      objects[i]->refresh(frameTime, time);
    }
}

*/
