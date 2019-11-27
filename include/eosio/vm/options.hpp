#pragma once

#include <cstdint>

namespace eosio { namespace vm {

struct options {
   std::uint64_t max_mutable_global_bytes;
   std::uint32_t max_table_elements;
   std::uint32_t max_section_elements;
   std::uint32_t max_type_section_elements;
   std::uint32_t max_import_section_elements;
   std::uint32_t max_function_section_elements;
   std::uint32_t max_global_section_elements;
   std::uint32_t max_export_section_elements;
   std::uint32_t max_element_section_elements;
   std::uint32_t max_data_section_elements;
   // code is the same as functions
   // memory and tables are both 1.
   std::uint32_t max_element_segment_elements;
   std::uint32_t max_data_segment_bytes;
   std::uint32_t max_linear_memory_init;
   std::uint64_t max_func_local_bytes;
   std::uint32_t max_local_sets;
   std::uint32_t max_nested_structures;
   std::uint32_t max_br_table_elements;
   // The maximum length of symbols used for import and export
   std::uint32_t max_symbol_bytes;
   std::uint32_t max_memory_offset;
   // Can mutable globals be exported
   bool forbid_export_mutable_globals = false;
   // Very strange non-conforming behavior
   bool allow_code_after_function_end = false;
   // Whether limits types such as for tables and memory are restricted to a
   // single byte 0|1 (matching the spec) or can be a 32-bit value.
   bool allow_u32_limits_flags = false;
   // Determines whether an local set of size 0 with an invalid type should be accepted.
   bool skip_typecheck_empty_local_set = false;
};

struct default_options {
};

struct eosio_options {
   static constexpr std::uint32_t max_mutable_global_bytes = 1024;
   static constexpr std::uint32_t max_table_elements = 1024;
   // maximum_section_elements in nodeos is a lie.
   static constexpr std::uint32_t max_section_elements = 8191;
   static constexpr std::uint32_t max_function_section_elements = 1023;
   static constexpr std::uint32_t max_import_section_elements = 1023;
   static constexpr std::uint32_t max_element_segment_elements = 8191;
   static constexpr std::uint32_t max_data_segment_bytes = 8191;
   static constexpr std::uint32_t max_linear_memory_init = 64*1024;
   static constexpr std::uint32_t max_func_local_bytes = 8192;
   static constexpr std::uint32_t max_local_sets = 1023;
   static constexpr std::uint32_t eosio_max_nested_structures = 1023;
   static constexpr std::uint32_t max_br_table_elements = 8191;
   static constexpr std::uint32_t max_symbol_bytes = 8191;
   static constexpr std::uint32_t max_memory_offset = (33*1024*1024 - 1);

   static constexpr bool forbid_export_mutable_globals = true;
   static constexpr bool allow_code_after_function_end = true;
   static constexpr bool allow_u32_limits_flags = true;
   static constexpr bool skip_typecheck_empty_local_set = true;
};

}}
