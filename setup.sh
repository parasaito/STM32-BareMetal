#! /bin/bash

set -e

if [ ! -d "STM32-CMSIS-Pack" ]; then
    git clone --recurse-submodules https://github.com/parasaito/STM32-CMSIS-Pack
fi

DEFAULT_SHELL=$(echo $SHELL)

RC_FILE_PATH=""

case "$DEFAULT_SHELL" in
    /bin/bash|/usr/bin/bash)
        RC_FILE_PATH="$HOME"/.bashrc
        ;;
    /bin/zsh|/usr/bin/zsh)
        RC_FILE_PATH="$HOME/.zshrc"
        ;;
    *)
        echo "Unsupported shell: $DEFAULT_SHELL Please create a pull request"
        exit 1
        ;;
esac

echo "export CMSIS_STM=\"$PWD/STM32-CMSIS-Pack\"" >> "$RC_FILE_PATH"

echo "Sucessfully exported CMSIS Pack path, now run:"
echo "\"source ${RC_FILE_PATH}\""
