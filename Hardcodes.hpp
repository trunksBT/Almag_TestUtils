#pragma once

#include <string>
#include <filesystem>

using namespace std::string_literals;

namespace hardcodes
{
namespace IOPaths
{

const std::filesystem::path ROOT_FOLDER_PATH = std::filesystem::current_path();
const std::filesystem::path RELATIVE_PATH = "/test/TestUtils/BuffersForIOTests";
const std::filesystem::path TEST_BUFFERS_PATH = ROOT_FOLDER_PATH.string() + RELATIVE_PATH.string();

const std::string BUFFER_TO_SEND_VAL_1 = TEST_BUFFERS_PATH.string() + "/ToSend1.txt"s;
const std::string BUFFER_TO_SEND_VAL_2 = TEST_BUFFERS_PATH.string() + "/ToSend2.txt"s;
const std::string BUFFER_TO_SEND_VAL_3 = TEST_BUFFERS_PATH.string() + "/ToSend3.txt"s;

const std::string ADDRESS_OF_PORT_FOR_ZERO_MQ = "/home/pkorycin/ZeroMqBuffer"s;

const std::string IOPATHS_1_UK = "/IOPaths_1";
const std::string IOPATHS_2_UK = "/IOPaths_2";
const std::string IOPATHS_3_UK = "/IOPaths_3";
const std::string IOPATHS_5_UK = "/IOPaths_5";
const std::string IOPATHS_OT = "IOPaths";

}  // namespace IOPaths
}  // namespace hardcodes

