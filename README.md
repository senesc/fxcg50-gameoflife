# [WIP] fxcg50-gameoflife

Implementation of Connor's Game of Life for the Casio FX-CG50 calculator.

## Installing

~~To install the Game of Life on your FX-CG50, download the .g3a application from the latest release, then upload it to the root directory of your calculator. Done!~~  
This won't be available until the first release; until then, you'll have to build from source.

## Building
In order to build from source, the following prerequisites are needed:
- make
- sh3eb-elf toolchain, for which an outdated version is available from [AUR](https://aur.archlinux.org/packages/sh3eb-elf-gcc). However, it is recommended to use the latest version. More info is available on the [PrizmSKD Setup Guide](https://prizm.cemetech.net/Tutorials/PrizmSDK_Setup_Guide/)
- mkg3a, obtainable from [Gitlab](https://gitlab.com/taricorp/mkg3a) or [AUR](https://aur.archlinux.org/packages/mkg3a)  

All of these need to be in your PATH.
<!-- TODO: do they really need to be in PATH? -->
<!-- TODO: add at least some pointers for poor windows users -->

To build, clone this repository and navigate to the top level folder. Then download the libfxcg submodule with ```git submodule update --init --recursive``` and run `make -C ./external/libfxcg/` to build the library.  
Finally, run `make` and, if no errors arise, `fxcg50-gameoflife.g3a` will be built in the `build` directory

### Debugging
To compile the debug build and get extra diagnostics (although it is undocumented as of now) run `make` with the flag `DEBUG=1`
