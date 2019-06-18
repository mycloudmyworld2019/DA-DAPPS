/**
 *  @file
 *  @copyright defined in DA-DAPPS/LICENSE
 */
#pragma once
#include <vector>
#include <string>

namespace DA-DAPPSio { namespace chain {

std::vector<uint8_t> wast_to_wasm( const std::string& wast );
std::string  wasm_to_wast( const std::vector<uint8_t>& wasm, bool strip_names );
std::string  wasm_to_wast( const uint8_t* data, uint64_t size, bool strip_names );

} } /// DA-DAPPSio::chain
