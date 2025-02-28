#ifndef command-packet 
#define command-packet 

#include "command-header.h"

typedef struct{
 uint8_t destinationModule;
 uint8_t commandCode;
 union {
   struct {
     int depth;
   } general;
   struct {
     int speed;
     int angle;
   } driving;
   struct {
     int index;
     int AngleX;
     int AngleY;
   } head;
   struct {
     int audioIndex; 
   } audio;
 } params;

 uint16_t checksum;
} packet;

#endif
