#include "ZMqReqRespTestCommunicator.hpp"
#include <MessagingPattern/ZeroMqUtils.hpp>
#include <HDLC/HDLCFrameBodyInterpreter.hpp>
#include <Utils/Functions.hpp>

using namespace convert;

namespace
{
constexpr int NUM_OF_IO_THREADS = 1;
}

ZMqReqRespTestCommunicator::ZMqReqRespTestCommunicator()
: context_{NUM_OF_IO_THREADS}
, requestSocket_{context_, zmq::socket_type::req}
, responseSocket_{context_, zmq::socket_type::rep}
{
   LOG(trace);
}

ZMqReqRespTestCommunicator::~ZMqReqRespTestCommunicator()
{
   LOG(trace);
}

void ZMqReqRespTestCommunicator::setupSend(const std::string& address)
{
   LOG(debug) << "on " << address;
   requestSocket_.connect("ipc://" + address);
}

void ZMqReqRespTestCommunicator::setupReceive(const std::string& address)
{
   LOG(debug) << "from " << address;
   responseSocket_.bind ("ipc://" + address);
}

bool ZMqReqRespTestCommunicator::send(const std::string &address, HDLCFrameBodyPtr frame)
{
   const std::string sentMessage = toString(frame->build());
   LOG(debug) << "Sending on " << address << " " << sentMessage;
   return s_send(requestSocket_, sentMessage);
}

HDLCFramePtr ZMqReqRespTestCommunicator::receive(const std::string &address)
{
   std::string message = s_recv(responseSocket_);
   LOG(debug) << "Received Message: " << message;
   return std::make_shared<HDLCFrame>(HDLCFrameBodyInterpreter().apply(message));
}