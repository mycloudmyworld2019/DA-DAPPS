/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/DA-DAPPSio.hpp>

class [[DA-DAPPSio::contract]] snapshot_test : public DA-DAPPSio::contract {
public:
   using DA-DAPPSio::contract::contract;

   [[DA-DAPPSio::action]]
   void increment( uint32_t value );

   struct [[DA-DAPPSio::table("data")]] main_record {
      uint64_t           id         = 0;
      double             index_f64  = 0.0;
      long double        index_f128 = 0.0L;
      uint64_t           index_i64  = 0ULL;
      uint128_t          index_i128 = 0ULL;
      DA-DAPPSio::checksum256 index_i256;

      uint64_t                  primary_key()const    { return id; }
      double                    get_index_f64()const  { return index_f64 ; }
      long double               get_index_f128()const { return index_f128; }
      uint64_t                  get_index_i64()const  { return index_i64 ; }
      uint128_t                 get_index_i128()const { return index_i128; }
      const DA-DAPPSio::checksum256& get_index_i256()const { return index_i256; }

      EOSLIB_SERIALIZE( main_record, (id)(index_f64)(index_f128)(index_i64)(index_i128)(index_i256) )
   };

   using data_table = DA-DAPPSio::multi_index<"data"_n, main_record,
      DA-DAPPSio::indexed_by< "byf"_n,    DA-DAPPSio::const_mem_fun< main_record, double,
                                                           &main_record::get_index_f64 > >,
      DA-DAPPSio::indexed_by< "byff"_n,   DA-DAPPSio::const_mem_fun< main_record, long double,
                                                           &main_record::get_index_f128> >,
      DA-DAPPSio::indexed_by< "byi"_n,    DA-DAPPSio::const_mem_fun< main_record, uint64_t,
                                                           &main_record::get_index_i64 > >,
      DA-DAPPSio::indexed_by< "byii"_n,   DA-DAPPSio::const_mem_fun< main_record, uint128_t,
                                                           &main_record::get_index_i128 > >,
      DA-DAPPSio::indexed_by< "byiiii"_n, DA-DAPPSio::const_mem_fun< main_record, const DA-DAPPSio::checksum256&,
                                                           &main_record::get_index_i256 > >
   >;
};