#include "irrlicht.h"
#include "User.h"

//TODO:
//More Commands
enum Command
{
    COMMAND_NONE = 0,
    COMMAND_HELP = 1,
    COMMAND_SPAWN
};

class Commands
{
public:
    static bool run(Command com, const irr::core::array<irr::core::stringc> args, User *user = 0);
    static void help(const irr::core::array<irr::core::stringc> args);
    static void spawn(const irr::core::array<irr::core::stringc> args, User *user);
};
