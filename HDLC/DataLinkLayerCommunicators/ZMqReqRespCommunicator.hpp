#pragma once

#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqCommunicator.hpp>

class ZMqReqRespCommunicator final: public ZMqCommunicator
{
public:
   ZMqReqRespCommunicator();
   virtual ~ZMqReqRespCommunicator();

   void setupSend(const std::string& address) override;
   void setupReceive(const std::string& address) override;
   bool send(const std::string &address, const HDLCFrameBodyPtr frame) override;
   HDLCFramePtr receive(const std::string &address) override;
};
