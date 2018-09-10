cmake_minimum_required(VERSION 3.4.1)

set(distribution_DIR ../../../../libs)

include_directories(libs/include)


add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
             src/main/cpp/lamemp3encoder.cpp
             )


# 坑点，注意路径正确性
add_library(mp3lame STATIC IMPORTED)
set_target_properties(mp3lame
  PROPERTIES IMPORTED_LOCATION
  ${distribution_DIR}/armeabi-v7a/libmp3lame.a)




find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )



target_link_libraries( # Specifies the target library.
                       native-lib
                       # 坑点，不要忘记添加这儿
                       mp3lame

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )