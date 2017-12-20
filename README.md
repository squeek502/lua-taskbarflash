# taskbarflash

Lua module for Windows that can flash the taskbar icon and/or window of the current Lua console window

```lua
local taskbarflash = require('taskbarflash')

-- continuously flash the taskbar icon until the window is focused
taskbarflash()
```

## Building
To build taskbarflash, you'll need to install [`cmake`](https://cmake.org), some version of [Visual Studio](https://www.visualstudio.com/), and have a Lua `.lib` file that [can be found by `cmake`](https://cmake.org/cmake/help/v3.0/module/FindLua.html) (preferably built with the same compiler you're using to build this module).

### Using `cmake-gui`
- Run `cmake-gui`
- Browse to the taskbarflash directory and also set the build directory (typically just add `/build` to the source directory path)
- Click *Configure*
- Select the Generator and hit *Finish*
- Hit Generate and then Open Project to open the project in Visual Studio
- Build the project in Visual Studio as normal

### Using `cmake`
Open a command line in the `taskbarflash` directory and do the following:
```sh
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
If needed, you can specify a [generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) by doing `cmake -G "Visual Studio 14 2015 Win64" ..` instead of `cmake ..`

## API Reference

`require('taskbarflash')` will return a callable table with more precise functions as keys.

### `taskbarflash([nflashes = 0, flashrate = 0])`
Flashes the Lua process' taskbar icon (but not window) `nflashes` times every `flashrate` milliseconds, or until the window is focused. When `nflashes` is `0`, it will flash indefinitely until the window is focused. When `flashrate` is `0`, it will use the default cursor blink rate of the system.

**Aliases:** `taskbarflash.tray`, `taskbarflash.taskbar`

### `taskbarflash.window([nflashes = 0, flashrate = 0])`
Flashes the Lua process' window (but not taskbar icon) `nflashes` times every `flashrate` milliseconds, or until the window is focused. When `nflashes` is `0`, it will flash indefinitely until the window is focused. When `flashrate` is `0`, it will use the default cursor blink rate of the system.

**Aliases:** `taskbarflash.caption`

### `taskbarflash.all([nflashes = 0, flashrate = 0])`
Flashes the Lua process' window **and** taskbar icon `nflashes` times every `flashrate` milliseconds, or until the window is focused. When `nflashes` is `0`, it will flash indefinitely until the window is focused. When `flashrate` is `0`, it will use the default cursor blink rate of the system.
