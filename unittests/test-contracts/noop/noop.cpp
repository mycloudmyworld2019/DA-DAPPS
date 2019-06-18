/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#include "noop.hpp"

using namespace DA-DAPPSio;

void noop::anyaction( name                       from,
                      const ignore<std::string>& type,
                      const ignore<std::string>& data )
{
   require_auth( from );
}
