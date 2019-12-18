#pragma once

#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqCommunicator.hpp>

class ZMqPubSubCommunicator final: public ZMqCommunicator
{
public:
   ZMqPubSubCommunicator(zmq::socket_type messageType);
   virtual ~ZMqPubSubCommunicator();

   bool send(const std::string &address, HDLCFrameBodyPtr frame) override;
   HDLCFramePtr receive(const std::string &address) override;
};
