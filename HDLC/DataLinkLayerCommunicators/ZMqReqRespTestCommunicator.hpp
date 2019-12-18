#pragma once

#include <HDLC/IHDLCCommunicator.hpp>
#include "ZeroMqUtils.hpp"

class ZMqReqRespTestCommunicator final: public IHDLCCommunicator
{
public:
   ZMqReqRespTestCommunicator();
   virtual ~ZMqReqRespTestCommunicator();

   bool send(const std::string &address, const HDLCFrameBodyPtr frame) override;
   HDLCFramePtr receive(const std::string &address) override;

private:
   zmq::context_t context_;
   zmq::socket_t requestSocket_;
   zmq::socket_t responseSocket_;
};