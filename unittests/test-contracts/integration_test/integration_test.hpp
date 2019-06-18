/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>

class [[DA-DAPPSio::contract]] integration_test : public DA-DAPPSio::contract {
public:
   using DA-DAPPSio::contract::contract;

   [[DA-DAPPSio::action]]
   void store( DA-DAPPSio::name from, DA-DAPPSio::name to, uint64_t num );

   struct [[DA-DAPPSio::table("payloads")]] payload {
      uint64_t              key;
      std::vector<uint64_t> data;

      uint64_t primary_key()const { return key; }

      EOSLIB_SERIALIZE( payload, (key)(data) )
   };

   using payloads_table = DA-DAPPSio::multi_index< "payloads"_n,  payload >;

};
