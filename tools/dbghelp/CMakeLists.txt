
if(NOT CMAKE_CROSSCOMPILING)
    add_definitions(-DDBGHELP_STATIC_LIB)

    if(ARCH STREQUAL "i386")
        add_definitions(-D_X86_)
    endif()

    include_directories(
        ${REACTOS_SOURCE_DIR}/tools
        ${REACTOS_SOURCE_DIR}/include/reactos/libs/zlib)

    list(APPEND SOURCE
        compat.c
        dbghelp.c
        dwarf.c
        module.c
        pe_module.c
        source.c
        stabs.c
        storage.c
        symbol.c
        type.c)

    if(ARCH STREQUAL "i386")
        list(APPEND SOURCE cpu_i386.c)
    endif()

    add_library(dbghelphost ${SOURCE})
endif()
