#include "RoundTripHDLCCommunicatorStub.hpp"
#include <Utils/Functions.hpp>

using namespace convert;

namespace test
{

RoundTripHDLCCommunicatorStub::RoundTripHDLCCommunicatorStub()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

RoundTripHDLCCommunicatorStub::~RoundTripHDLCCommunicatorStub()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

void RoundTripHDLCCommunicatorStub::setupSend(const std::string& address)
{
   LOG(info) << "Not implemented test function";
}

void RoundTripHDLCCommunicatorStub::setupReceive(const std::string& address)
{
   LOG(info) << "Not implemented test function";
}

bool RoundTripHDLCCommunicatorStub::send(const std::string &address, HDLCFrameBodyPtr frame)
{
   hdlcFrameBody_ = frame;
   const std::string sentMessage = toString(hdlcFrameBody_->build());
   LOG(info) << "Sending on " << address << " " << sentMessage;
   return true;
}

HDLCFramePtr RoundTripHDLCCommunicatorStub::receive(const std::string &address)
{
   return std::make_shared<HDLCFrame>(hdlcFrameBody_);
}
}
