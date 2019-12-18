#include "ZMqPubSubCommunicator.hpp"
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZeroMqUtils.hpp>
#include <Utils/Functions.hpp>
#include <HDLC/HDLCFrameBodyInterpreter.hpp>

using namespace convert;

namespace
{
constexpr int NUM_OF_IO_THREADS{ 1 };
constexpr uint8_t IS_ON{ 1 };
inline bool isLastMessage(int msgCount, int numberOfMessages)
{
   return msgCount == numberOfMessages-1;
}
}

ZMqPubSubCommunicator::ZMqPubSubCommunicator(zmq::socket_type messageType)
: ZMqCommunicator{messageType}
{
   LOG(trace);
}

ZMqPubSubCommunicator::~ZMqPubSubCommunicator()
{
   LOG(trace);
}

void ZMqPubSubCommunicator::setupSend(const std::string& address)
{
   LOG(debug) << "on " << address;
   requestSocket_.bind("ipc://" + address);
}

void ZMqPubSubCommunicator::setupReceive(const std::string& address)
{
   requestSocket_.connect(address);
   requestSocket_.setsockopt(ZMQ_SUBSCRIBE, address.data(), IS_ON);
}

bool ZMqPubSubCommunicator::send(const std::string& address, HDLCFrameBodyPtr frame)
{
   bool sentState{ true };
   const std::string sentMessage = toString(frame->build());
   LOG(debug) << "Sending on " << address << " " << sentMessage;

   sentState &= s_send(requestSocket_, sentMessage);
   sentState &= s_send(requestSocket_, sentMessage, zmq::send_flags::sndmore);
   return sentState;
}

HDLCFramePtr ZMqPubSubCommunicator::receive(const std::string &address)
{
   std::string message = s_recv(responseSocket_);
   LOG(error) << "Received Message: " << message;
   return std::make_shared<HDLCFrame>(HDLCFrameBodyInterpreter().apply(message));
}
