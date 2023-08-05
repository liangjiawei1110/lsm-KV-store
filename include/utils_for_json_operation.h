#ifndef _Utils_For_Time_Json_H_
#define _Utils_For_Time_Json_H_

#include "command.h"
#include "json.h"
using json = nlohmann::json;

std::shared_ptr<Command> JSONtoCommand(json command_JSON);

#endif