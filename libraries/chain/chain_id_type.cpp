/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */

#include <DA-DAPPSio/chain/chain_id_type.hpp>
#include <DA-DAPPSio/chain/exceptions.hpp>

namespace DA-DAPPSio { namespace chain {

   void chain_id_type::reflector_init()const {
      DA-DAPPS_ASSERT( *reinterpret_cast<const fc::sha256*>(this) != fc::sha256(), chain_id_type_exception, "chain_id_type cannot be zero" );
   }

} }  // namespace DA-DAPPSio::chain

namespace fc {

   void to_variant(const DA-DAPPSio::chain::chain_id_type& cid, fc::variant& v) {
      to_variant( static_cast<const fc::sha256&>(cid), v);
   }

   void from_variant(const fc::variant& v, DA-DAPPSio::chain::chain_id_type& cid) {
      from_variant( v, static_cast<fc::sha256&>(cid) );
   }

} // fc
