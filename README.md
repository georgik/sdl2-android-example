# SDL2 Android Example

Read article at blog: http://georgik.rocks/tag/sdl2/

Source code:

 - the code is assembled of several pieces available on GitHub

## Dependencies

Libraries were assembled from:

- libzip - derrived from https://github.com/julienr/libzip-android
- libSDL2_png - derrived from https://github.com/julienr/libpng-android
    - applied patch - https://github.com/julienr/libpng-android/issues/6
    - renamed to SDL2_png, because of problem with png library in API level 19 - http://georgik.rocks/sdl2-for-android-api-level-19/
- libSDL2_jpeg - derrived from https://www.libsdl.org/projects/SDL_image/libs/
    - renamed to SDL2_jpeg from jpeg, because of library name collision in Android 
    https://stackoverflow.com/questions/11613040/why-does-jpeg-decompress-create-crash-without-error-message    


## Build

List of build commands for each library. Building libraries one-by-one might help you to identify
potential problems during compilation.

Commands:

  ```
  gradle distributeLib
  gradle installDebug
  ```

If you want to build library one by one, then you can specify name of library as module name for Gradle

  ```
  gradle :SDL2:distributeLib
  gradle :zip:distributeLib
  gradle :SDL2_png:distributeLib
  gradle :SDL2_jpeg:distributeLib
  gradle :SDL2_image:distributeLib
  gradle installDebug
  ```

