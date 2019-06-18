#! /bin/bash

OPT_LOCATION=$HOME/opt

binaries=(
   cleos
   DA-DAPPSio-abigen
   DA-DAPPSio-launcher
   DA-DAPPSio-s2wasm
   DA-DAPPSio-wast2wasm
   DA-DAPPSiocpp
   keosd
   nodeos
   DA-DAPPSio-applesdemo
)

if [ -d $OPT_LOCATION/DA-DAPPSio ]; then
   printf "Do you wish to remove this install? (requires sudo)\n"
   select yn in "Yes" "No"; do
      case $yn in
         [Yy]* )
            if [ "$(id -u)" -ne 0 ]; then
               printf "\nThis requires sudo, please run ./DA-DAPPSio_uninstall.sh with sudo\n\n"
               exit -1
            fi

            pushd $HOME &> /dev/null
            pushd opt &> /dev/null
            rm -rf DA-DAPPSio
            # Handle cleanup of directories created from installation
            if [ "$1" == "--full" ]; then
               if [ -d ~/Library/Application\ Support/DA-DAPPSio ]; then rm -rf ~/Library/Application\ Support/DA-DAPPSio; fi # Mac OS
               if [ -d ~/.local/share/DA-DAPPSio ]; then rm -rf ~/.local/share/DA-DAPPSio; fi # Linux
            fi
            popd &> /dev/null
            pushd bin &> /dev/null
            for binary in ${binaries[@]}; do
               rm ${binary}
            done
            popd &> /dev/null
            pushd lib/cmake &> /dev/null
            rm -rf DA-DAPPSio
            popd &> /dev/null

            break;;
         [Nn]* )
            printf "Aborting uninstall\n\n"
            exit -1;;
      esac
   done
fi

if [ -d "/usr/local/DA-DAPPSio" ]; then
   printf "Do you wish to remove this install? (requires sudo)\n"
   select yn in "Yes" "No"; do
      case $yn in
         [Yy]* )
            if [ "$(id -u)" -ne 0 ]; then
               printf "\nThis requires sudo, please run ./DA-DAPPSio_uninstall.sh with sudo\n\n"
               exit -1
            fi

            pushd /usr/local &> /dev/null
            pushd opt &> /dev/null
            rm -rf DA-DAPPSio
            # Handle cleanup of directories created from installation
            if [ "$1" == "--full" ]; then
               if [ -d ~/Library/Application\ Support/DA-DAPPSio ]; then rm -rf ~/Library/Application\ Support/DA-DAPPSio; fi # Mac OS
               if [ -d ~/.local/share/DA-DAPPSio ]; then rm -rf ~/.local/share/DA-DAPPSio; fi # Linux
            fi
            popd &> /dev/null
            pushd bin &> /dev/null
            for binary in ${binaries[@]}; do
               rm ${binary}
            done
            popd &> /dev/null
            pushd lib/cmake &> /dev/null
            rm -rf DA-DAPPSio
            popd &> /dev/null

            break;;
         [Nn]* )
            printf "Aborting uninstall\n\n"
            exit -1;;
      esac
   done
fi
