/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>

class [[DA-DAPPSio::contract]] test_api_db : public DA-DAPPSio::contract {
public:
   using DA-DAPPSio::contract::contract;

   [[DA-DAPPSio::action("pg")]]
   void primary_i64_general();

   [[DA-DAPPSio::action("pl")]]
   void primary_i64_lowerbound();

   [[DA-DAPPSio::action("pu")]]
   void primary_i64_upperbound();

   [[DA-DAPPSio::action("s1g")]]
   void idx64_general();

   [[DA-DAPPSio::action("s1l")]]
   void idx64_lowerbound();

   [[DA-DAPPSio::action("s1u")]]
   void idx64_upperbound();

   [[DA-DAPPSio::action("tia")]]
   void test_invalid_access( DA-DAPPSio::name code, uint64_t val, uint32_t index, bool store );

   [[DA-DAPPSio::action("sdnancreate")]]
   void idx_double_nan_create_fail();

   [[DA-DAPPSio::action("sdnanmodify")]]
   void idx_double_nan_modify_fail();

   [[DA-DAPPSio::action("sdnanlookup")]]
   void idx_double_nan_lookup_fail( uint32_t lookup_type );

   [[DA-DAPPSio::action("sk32align")]]
   void misaligned_secondary_key256_tests();

};
