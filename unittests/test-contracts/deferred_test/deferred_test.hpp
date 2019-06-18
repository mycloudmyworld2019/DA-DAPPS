/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>
#include <vector>

class [[DA-DAPPSio::contract]] deferred_test : public DA-DAPPSio::contract {
public:
   using DA-DAPPSio::contract::contract;

   [[DA-DAPPSio::action]]
   void defercall( DA-DAPPSio::name payer, uint64_t sender_id, DA-DAPPSio::name contract, uint64_t payload );

   [[DA-DAPPSio::action]]
   void deferfunc( uint64_t payload );
   using deferfunc_action = DA-DAPPSio::action_wrapper<"deferfunc"_n, &deferred_test::deferfunc>;

   [[DA-DAPPSio::action]]
   void inlinecall( DA-DAPPSio::name contract, DA-DAPPSio::name authorizer, uint64_t payload );

   [[DA-DAPPSio::on_notify("DA-DAPPSio::onerror")]]
   void on_error( uint128_t sender_id, DA-DAPPSio::ignore<std::vector<char>> sent_trx );
};
