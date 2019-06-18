/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>

class [[DA-DAPPSio::contract]] test_api_multi_index : public DA-DAPPSio::contract {
public:
   using DA-DAPPSio::contract::contract;

   [[DA-DAPPSio::action("s1g")]]
   void idx64_general();

   [[DA-DAPPSio::action("s1store")]]
   void idx64_store_only();

   [[DA-DAPPSio::action("s1check")]]
   void idx64_check_without_storing();

   [[DA-DAPPSio::action("s1findfail1")]]
   void idx64_require_find_fail();

   [[DA-DAPPSio::action("s1findfail2")]]
   void idx64_require_find_fail_with_msg();

   [[DA-DAPPSio::action("s1findfail3")]]
   void idx64_require_find_sk_fail();

   [[DA-DAPPSio::action("s1findfail4")]]
   void idx64_require_find_sk_fail_with_msg();

   [[DA-DAPPSio::action("s1pkend")]]
   void idx64_pk_iterator_exceed_end();

   [[DA-DAPPSio::action("s1skend")]]
   void idx64_sk_iterator_exceed_end();

   [[DA-DAPPSio::action("s1pkbegin")]]
   void idx64_pk_iterator_exceed_begin();

   [[DA-DAPPSio::action("s1skbegin")]]
   void idx64_sk_iterator_exceed_begin();

   [[DA-DAPPSio::action("s1pkref")]]
   void idx64_pass_pk_ref_to_other_table();

   [[DA-DAPPSio::action("s1skref")]]
   void idx64_pass_sk_ref_to_other_table();

   [[DA-DAPPSio::action("s1pkitrto")]]
   void idx64_pass_pk_end_itr_to_iterator_to();

   [[DA-DAPPSio::action("s1pkmodify")]]
   void idx64_pass_pk_end_itr_to_modify();

   [[DA-DAPPSio::action("s1pkerase")]]
   void idx64_pass_pk_end_itr_to_erase();

   [[DA-DAPPSio::action("s1skitrto")]]
   void idx64_pass_sk_end_itr_to_iterator_to();

   [[DA-DAPPSio::action("s1skmodify")]]
   void idx64_pass_sk_end_itr_to_modify();

   [[DA-DAPPSio::action("s1skerase")]]
   void idx64_pass_sk_end_itr_to_erase();

   [[DA-DAPPSio::action("s1modpk")]]
   void idx64_modify_primary_key();

   [[DA-DAPPSio::action("s1exhaustpk")]]
   void idx64_run_out_of_avl_pk();

   [[DA-DAPPSio::action("s1skcache")]]
   void idx64_sk_cache_pk_lookup();

   [[DA-DAPPSio::action("s1pkcache")]]
   void idx64_pk_cache_sk_lookup();

   [[DA-DAPPSio::action("s2g")]]
   void idx128_general();

   [[DA-DAPPSio::action("s2store")]]
   void idx128_store_only();

   [[DA-DAPPSio::action("s2check")]]
   void idx128_check_without_storing();

   [[DA-DAPPSio::action("s2autoinc")]]
   void idx128_autoincrement_test();

   [[DA-DAPPSio::action("s2autoinc1")]]
   void idx128_autoincrement_test_part1();

   [[DA-DAPPSio::action("s2autoinc2")]]
   void idx128_autoincrement_test_part2();

   [[DA-DAPPSio::action("s3g")]]
   void idx256_general();

   [[DA-DAPPSio::action("sdg")]]
   void idx_double_general();

   [[DA-DAPPSio::action("sldg")]]
   void idx_long_double_general();

};
