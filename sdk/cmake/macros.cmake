function(generate_config_header)
    configure_file(${CMAKE_SOURCE_DIR}/kernel/config.h.in ${CMAKE_SOURCE_DIR}/kernel/config.h @ONLY)
endfunction(generate_config_header)