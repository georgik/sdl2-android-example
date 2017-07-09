# SDL2 Android Example

Read article at blog: http://georgik.rocks

Source code:

 - the code is assembled of several pieces available on GitHub

## Build

List of build commands for each library. Building libraries one-by-one might help you to identify
potential problems during compilation.

Commands:

  ```
  gradle :SDL2:distributeLib
  gradle :zip:distributeLib
  gradle :png:distributeLib
  gradle :SDL2_image:distributeLib
  gradle installDebug
  ```

