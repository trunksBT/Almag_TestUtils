#include "ZMqPubSubCommunicator.hpp"
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZeroMqUtils.hpp>
#include <Utils/Functions.hpp>
#include <HDLC/HDLCFrameBodyInterpreter.hpp>

using namespace convert;

namespace
{
constexpr uint8_t IS_ON{ 1 };
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

bool ZMqPubSubCommunicator::send(const std::string& address, HDLCFrameBodyPtr frame)
{
   LOG(debug) << "on " << address;
   socket_.bind("ipc://" + address);

   bool sentState{ true };
   const std::string sentMessage = toString(frame->build());
   LOG(debug) << "Message: " << sentMessage;

   sentState &= s_send(socket_, sentMessage);
   sentState &= s_send(socket_, sentMessage, zmq::send_flags::sndmore);
   return sentState;
}

HDLCFramePtr ZMqPubSubCommunicator::receive(const std::string &address)
{
   socket_.connect(address);
   socket_.setsockopt(ZMQ_SUBSCRIBE, address.data(), IS_ON);

   std::string message = s_recv(socket_);
   LOG(debug) << "Received Message: " << message;
   return std::make_shared<HDLCFrame>(HDLCFrameBodyInterpreter().apply(message));
}
