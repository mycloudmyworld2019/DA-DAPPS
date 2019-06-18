/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>

class [[DA-DAPPSio::contract]] payloadless : public DA-DAPPSio::contract {
public:
   using DA-DAPPSio::contract::contract;

   [[DA-DAPPSio::action]]
   void doit();
};
