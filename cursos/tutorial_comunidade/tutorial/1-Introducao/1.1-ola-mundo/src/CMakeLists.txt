add_executable(HelloWorld)

target_sources(
  HelloWorld
  PRIVATE
    main.cpp
)

target_compile_features(
  HelloWorld
  PRIVATE
    cxx_std_17
)
