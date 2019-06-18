/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <fc/crypto/sha256.hpp>

struct hello;

namespace DA-DAPPSio {

   class net_plugin_impl;
   struct handshake_message;

   namespace chain_apis {
      class read_only;
   }

namespace chain {

   struct chain_id_type : public fc::sha256 {
      using fc::sha256::sha256;

      template<typename T>
      inline friend T& operator<<( T& ds, const chain_id_type& cid ) {
        ds.write( cid.data(), cid.data_size() );
        return ds;
      }

      template<typename T>
      inline friend T& operator>>( T& ds, chain_id_type& cid ) {
        ds.read( cid.data(), cid.data_size() );
        return ds;
      }

      void reflector_init()const;

      private:
         chain_id_type() = default;

         // Some exceptions are unfortunately necessary:
         template<typename T>
         friend T fc::variant::as()const;

         friend class DA-DAPPSio::chain_apis::read_only;

         friend class DA-DAPPSio::net_plugin_impl;
         friend struct DA-DAPPSio::handshake_message;

         friend struct ::hello; // TODO: Rushed hack to support bnet_plugin. Need a better solution.
   };

} }  // namespace DA-DAPPSio::chain

namespace fc {
  class variant;
  void to_variant(const DA-DAPPSio::chain::chain_id_type& cid, fc::variant& v);
  void from_variant(const fc::variant& v, DA-DAPPSio::chain::chain_id_type& cid);
} // fc
