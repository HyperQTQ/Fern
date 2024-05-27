# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-src"
  "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-build"
  "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-subbuild/cli-populate-prefix"
  "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-subbuild/cli-populate-prefix/tmp"
  "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-subbuild/cli-populate-prefix/src/cli-populate-stamp"
  "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-subbuild/cli-populate-prefix/src"
  "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-subbuild/cli-populate-prefix/src/cli-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-subbuild/cli-populate-prefix/src/cli-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/gridlink/CLionProjects/Fern/cmake-build-debug/_deps/cli-subbuild/cli-populate-prefix/src/cli-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
