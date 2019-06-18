/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once

#include <DA-DAPPSio/chain/types.hpp>
#include <DA-DAPPSio/chain/contract_types.hpp>

namespace DA-DAPPSio { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_DA-DAPPSio_newaccount(apply_context&);
   void apply_DA-DAPPSio_updateauth(apply_context&);
   void apply_DA-DAPPSio_deleteauth(apply_context&);
   void apply_DA-DAPPSio_linkauth(apply_context&);
   void apply_DA-DAPPSio_unlinkauth(apply_context&);

   /*
   void apply_DA-DAPPSio_postrecovery(apply_context&);
   void apply_DA-DAPPSio_passrecovery(apply_context&);
   void apply_DA-DAPPSio_vetorecovery(apply_context&);
   */

   void apply_DA-DAPPSio_setcode(apply_context&);
   void apply_DA-DAPPSio_setabi(apply_context&);

   void apply_DA-DAPPSio_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace DA-DAPPSio::chain
