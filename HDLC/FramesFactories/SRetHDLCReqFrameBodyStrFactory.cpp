#include "SRetHDLCReqFrameBodyStrFactory.hpp"

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameI_Calibrate() const
{
   return {"3 10 31 0 0 " };
}

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameU_LinkEstablishment() const
{
   return { "3 93 " };
}

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameXID_DummyScan() const
{
   return { "ff bf 81 f0 8 1 2 33 33 3 2 ff ff " };
}

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameXID_DeviceScan() const
{
   return { "ff bf 81 f0 8 1 2 0 0 3 2 0 0 " };
}

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameXID_AddressAssignment() const
{
   return {"ff bf 81 f0 11 1 9 4e 4b 34 "
           "36 35 30 30 30 30 2 1 3 4 1 1 " };
}

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameXID_3GPPReleaseId() const
{
   return { "3 bf 81 f0 3 5 1 8 " };
}

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameXID_AISGProtocolVersion() const
{
   return { "3 bf 81 f0 3 14 1 2 " };
}

std::string SRetHDLCReqFrameBodyStrFactory::get_FrameXID_HDLCParameters() const
{
   return { "3 bf 81 80 12 5 4 f0 2d 0 0 6 4 f0 2d 0 0 7 1 1 8 1 1 "};
}
