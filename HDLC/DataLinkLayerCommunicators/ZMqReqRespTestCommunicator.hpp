#pragma once

#include <HDLC/IHDLCCommunicator.hpp>
#include <MessagingPattern/ZeroMqUtils.hpp>

class ZMqReqRespTestCommunicator final: public IHDLCCommunicator
{
public:
   ZMqReqRespTestCommunicator();

   void setupReceive(const std::string& address);
   void setupSend(const std::string& address);
   bool send(const std::string &address, const HDLCFrameBodyPtr frame) override;
   HDLCFramePtr receive(const std::string &address) override;
   HDLCFramePtr communicate(const std::string& address, HDLCFrameBodyPtr frame) override;

   virtual ~ZMqReqRespTestCommunicator();
private:
   zmq::context_t context_;
   zmq::socket_t requestSocket_;
   zmq::socket_t responseSocket_;
};