#pragma once

#include <memory>
#include <HDLC/IHDLCCommunicator.hpp>
#include <TestUtils/Fixtures/BaseFixtureWithDB.hpp>

class BaseFixtureWithDBAndHDLC : public BaseFixtureWithDB
{
protected:
   BaseFixtureWithDBAndHDLC(
       const Database::ValueType inDB,
       std::vector<IHDLCCommunicatorPtr> hdlcComm
   )
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicators_{hdlcComm} {}
   
    std::vector<IHDLCCommunicatorPtr> hdlcCommunicators_;
};

