#include "Loader.h"
#include "Globals.h"

using namespace irr;


void Loader::load (io::path path)
{
  result_ = doc_.load_file(path.c_str ());
  irr::ILogger* logger = sIGfx->getDevice ()->getLogger ();
  if(!result_)
  {
    logger->log("Failed to load Xml file!", ELL_ERROR);
    return;
  }
  logger->log("Loaded Xml file!", ELL_INFORMATION);
}
