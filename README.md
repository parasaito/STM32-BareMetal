# STM32-BareMetal

This repository contains example programs using STM32 series of microcontrollers.

The repository is divided into several branches exploring different family of MCUs.

This project only uses direct register level programming, no hosted environments like FreeRTOS has been used. The two popular frameworks used in bare-metal programming on ST ARM uCs are :

1. CMSIS (Cortex M Software Interface Standard) : Enforce by ARM, standard abstraction layer. 
2. ST HAL : The Hardware Abstraction Layer by ST. Provides API for most interfaces and drivers on microcontrollers.

# Toolchain Setup

These include a set of tools for cross-compiling, flashing and remote debugging the MCU

- ARM GNU Toolchain
- GNU Make
- OpenOCD
- Cland (recommended) : The clangd language server provides powerful intellisense for code completion 
- Bear (optional) : Used to create compilation database for clangd server
- Editor :
    This is a subjective choice. If you don't have strong feelings for a particular editor, VSCode from Microsoft is highly recommended. Neovim with an appropriate setup is also great, however, this article would only discuss VSCode as the editor with it's powerful yet easy-to-use extensions to make code editing and debugging a breeze

## Linux

Linux/UNIX like environments would be used regardless of which OS you are using, as it provides the most complete set of tools.

1. Begin by visiting [ARM GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) webpage and download the latest toolchain for your system.

    The archive contains precompiled binaries for the cross compiler, assembler, linker. Extract the archive at a location of your choice. Add the `bin` directory your `PATH`. You can follow as below : 
    
    `$ EDITOR=vim sudoedit /etc/environment`

    Add an environment variable such as :

    `ARM_BAREMETAL=/path/to/toolchain/bin`

    In your default shell config, such as **.bashrc**, export this environment variable to `PATH`

    `export PATH="$ARM_BAREMETAL:$PATH"`

    `$ source ~/.bashrc`

    Check successful PATH entry by entering

    `$ arm-none-eabi-gcc --version`

2. Install `opencocd` and `bear` from your distro's repository 

    - For Debian based distros like Ubuntu:

        `sudo apt install openocd bear`

    - For Red Hat based distros like Fedora:

        `sudo dnf install openocd bear`

        `sudo yum install openocd bear`
    
    - On Arch:

        `sudo pacman -Sy openocd bear`
    

## Windows
Whether you use WSL2 or native binaries using cygwin, the instructions are similar to the Linux.

Word of caution : As of writing this, pre-compiled binaries for mingw is only available x86/x64 systems.

While Windows is perfectly capable of development using cygwin like environments like MSYS2, it is still recommended to use a Linux VM such as **WSL2**


## macOS

Instructions WIP












