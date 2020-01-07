#include "RoundTripHDLCTestCommunicatorStub.hpp"
#include <Utils/Functions.hpp>

using namespace convert;

namespace test
{

RoundTripHDLCTestCommunicatorStub::RoundTripHDLCTestCommunicatorStub()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

RoundTripHDLCTestCommunicatorStub::~RoundTripHDLCTestCommunicatorStub()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

void RoundTripHDLCTestCommunicatorStub::setupSend(const std::string& address)
{
   LOG(info) << "Not implemented test function";
}

void RoundTripHDLCTestCommunicatorStub::setupReceive(const std::string& address)
{
   LOG(info) << "Not implemented test function";
}

bool RoundTripHDLCTestCommunicatorStub::send(const std::string &address, HDLCFrameBodyPtr frame)
{
   hdlcFrameBody_ = frame;
   const std::string sentMessage = toString(hdlcFrameBody_->build());
   LOG(info) << "Sending on " << address << " " << sentMessage;
   return true;
}

HDLCFramePtr RoundTripHDLCTestCommunicatorStub::receive(const std::string &address)
{
   return std::make_shared<HDLCFrame>(hdlcFrameBody_);
}

HDLCFramePtr RoundTripHDLCTestCommunicatorStub::communicate(
   const std::string& address, HDLCFrameBodyPtr frame)
{
   throw std::runtime_error("Not implemented yet");
}

}
