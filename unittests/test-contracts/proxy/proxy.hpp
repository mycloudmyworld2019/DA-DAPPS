/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>
#include <DA-DAPPSio/singleton.hpp>
#include <DA-DAPPSio/asset.hpp>

// Extacted from DA-DAPPSio.token contract:
namespace DA-DAPPSio {
   class [[DA-DAPPSio::contract("DA-DAPPSio.token")]] token : public DA-DAPPSio::contract {
   public:
      using DA-DAPPSio::contract::contract;

      [[DA-DAPPSio::action]]
      void transfer( DA-DAPPSio::name        from,
                     DA-DAPPSio::name        to,
                     DA-DAPPSio::asset       quantity,
                     const std::string& memo );
      using transfer_action = DA-DAPPSio::action_wrapper<"transfer"_n, &token::transfer>;
   };
}

// This contract:
class [[DA-DAPPSio::contract]] proxy : public DA-DAPPSio::contract {
public:
   proxy( DA-DAPPSio::name self, DA-DAPPSio::name first_receiver, DA-DAPPSio::datastream<const char*> ds );

   [[DA-DAPPSio::action]]
   void setowner( DA-DAPPSio::name owner, uint32_t delay );

   [[DA-DAPPSio::on_notify("DA-DAPPSio.token::transfer")]]
   void on_transfer( DA-DAPPSio::name        from,
                     DA-DAPPSio::name        to,
                     DA-DAPPSio::asset       quantity,
                     const std::string& memo );

   [[DA-DAPPSio::on_notify("DA-DAPPSio::onerror")]]
   void on_error( uint128_t sender_id, DA-DAPPSio::ignore<std::vector<char>> sent_trx );

   struct [[DA-DAPPSio::table]] config {
      DA-DAPPSio::name owner;
      uint32_t    delay   = 0;
      uint32_t    next_id = 0;

      EOSLIB_SERIALIZE( config, (owner)(delay)(next_id) )
   };

   using config_singleton = DA-DAPPSio::singleton< "config"_n,  config >;

protected:
   config_singleton _config;
};
