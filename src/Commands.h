#include "irrlicht.h"
#include "User.h"

//TODO:
//More Commands
enum CommandName
{
    COMMAND_NONE    = 0,
    COMMAND_HELP    = 1,
    COMMAND_SPAWN   = 3
};

enum CommandType
{
    NONE_COMMAND        = 0,
    USER_COMMAND        = 1,
    MODERATOR_COMMAND   = 2,
    ADMIN_ONLY_COMMAND  = 3
};

class Command
{
public:
    static bool run(Command com, const irr::core::array<irr::core::stringc> args, User *user = 0);
    static void help(const irr::core::array<irr::core::stringc> args);
    static void spawn(const irr::core::array<irr::core::stringc> args, User *user);
};
