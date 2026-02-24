add_executable(obuchaika 
    main.cpp
    menu_function.cpp
    menu_items.cpp
)

target_include_directories(obuchaika PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})