//
// Created by yuvalshechter on 27/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "Server.h"
#include "MySerialServer.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "CacheManager.h"
#include "MyTestClientHandler.h"
#include "OA.h"

namespace  Boot {
class Main{
public:
  Main(){};
  ~Main(){};
  void main(int args){
    MyParallellServer mps;
    //FileCacheManager<string, string> cm;
    OA sr;
    MyClientHandler *mtch = new MyClientHandler(&sr);
    mps.open(args, mtch);
  };
};
};

#endif //EX4_BOOT_H
