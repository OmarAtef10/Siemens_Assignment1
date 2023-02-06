cmake_minimum_required(VERSION 3.19)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment1 main.cpp Frame.cpp Frame.h PacketReader.cpp PacketReader.h PacketAnalyzer.cpp PacketAnalyzer.h EthernetFrame.cpp EthernetFrame.h ECPRIFrame.cpp ECPRIFrame.h FrameFactory.cpp FrameFactory.h PacketWriter.cpp PacketWriter.h)