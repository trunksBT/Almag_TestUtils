#pragma once

#include <memory>
#include <Utils/TypeAliases.hpp>

struct BuiltFrameStr_ExpectedFrameStr
{
   const std::string builtFrameStr;
   const std::string expectedFrameStr;
};

struct CommandsToExpectedFrame
{
   const StringsMatrix inCommands;
   const std::string expectedHdlcFrame;
};

struct ReceivedCommand_ExpectedFrameHexes
{
   const StringsMatrix inCommands;
   const Hexes expectedFrameHexes;
};

struct ExpectedValue_ReceivedString
{
   const Hexes expectedHexes;
   const std::string receivedString;
};

struct ExpectedHexes
{
   std::shared_ptr<HDLCFrameBody> sentFrame;
   const Hexes expectedHexes;
};
