/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>

class [[DA-DAPPSio::contract]] noop : public DA-DAPPSio::contract {
public:
   using DA-DAPPSio::contract::contract;

   [[DA-DAPPSio::action]]
   void anyaction( DA-DAPPSio::name                       from,
                   const DA-DAPPSio::ignore<std::string>& type,
                   const DA-DAPPSio::ignore<std::string>& data );
};
