set(APP_EXE "CRayTracing")

add_executable(${APP_EXE} main.c)

file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE HEADERS "*.h")

target_sources(${APP_EXE}
        PRIVATE
        "${SOURCES}"
        PUBLIC
        "${HEADERS}"
        )

target_compile_options(${APP_EXE}
        PRIVATE
        "${MY_OPTIONS}"
        "$<$<CONFIG:Debug>:${MY_DEBUG_OPTIONS}>"
        "$<$<CONFIG:Release>:${MY_RELEASE_OPTIONS}>"
        )

target_link_libraries(${APP_EXE}
        PRIVATE
		"$<$<CONFIG:Debug>:asan>"
        "$<$<CONFIG:Debug>:ubsan>"
        app
        m # math lib
        )

#set(INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR} CACHE PATH "Installation directory for executables")
install(TARGETS ${APP_EXE} RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)

#message(STATUS "ASSEMBLING SOME FILES: ${SOURCES}")
foreach (SOURCE ${SOURCES})
#    get_filename_component(SOURCE_NAME "${SOURCE}" NAME) # not used
    file(RELATIVE_PATH SOURCE_PATH "${CMAKE_SOURCE_DIR}/src" "${SOURCE}")
    message(STATUS Assembling..."${SOURCE_PATH}")
    add_custom_command(TARGET ${APP_EXE}
            POST_BUILD
            COMMAND make ARGS "${SOURCE_PATH}.s"
            )
endforeach (SOURCE)

#vedi cmake get_filename_component e file
#https://stackoverflow.com/questions/39027269/cmake-convert-relative-path-to-absolute-path-with-build-directory-as-current-d