#include <TestUtils/Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/RoundTripHDLCTestCommunicatorStub.hpp>
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqReqRespTestCommunicator.hpp>

BaseFixtureWithDBAndHDLC::BaseFixtureWithDBAndHDLC(
        const Database::ValueType inDB, std::vector<IHDLCCommunicatorPtr> hdlcComm)
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicators_{hdlcComm}
{}
