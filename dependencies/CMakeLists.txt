include(FetchContent)

### SFML ###

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)
add_subdirectory(sfml)

### IMGUI ###

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.7
)

FetchContent_MakeAvailable(imgui)

### IMGUI-SFML ###

FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
  GIT_TAG v3.0
)
add_subdirectory(imgui-sfml)